
#### Blog

root.txt

Scan with nmap all ports, assume the host is live
I want verbose output with a timing template of 4 
```
nmap -p- -Pn -T 4 -v 10.10.126.117 


PORT    STATE SERVICE
22/tcp  open  ssh
80/tcp  open  http
139/tcp open  netbios-ssn
445/tcp open  microsoft-ds
MAC Address: 02:E9:9D:34:29:85 (Unknown)
```

There's a directory listing in the robots.txt dir 
the directory is wp-admin
Possibly brute forcing it may reveal obvious credentials
Might be beneficial to find a authorized username first before brute forcing
```
nmap -p 22,80,139,445 -sV -sC -O 10.10.126.117

22/tcp  open  ssh         OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 57:8a:da:90:ba:ed:3a:47:0c:05:a3:f7:a8:0a:8d:78 (RSA)
|   256 c2:64:ef:ab:b1:9a:1c:87:58:7c:4b:d5:0f:20:46:26 (ECDSA)
|_  256 5a:f2:62:92:11:8e:ad:8a:9b:23:82:2d:ad:53:bc:16 (EdDSA)
80/tcp  open  http        Apache httpd 2.4.29 ((Ubuntu))
|_http-generator: WordPress 5.0
| http-robots.txt: 1 disallowed entry 
|_/wp-admin/
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: Billy Joel&#039;s IT Blog &#8211; The IT blog
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp open  netbios-ssn Samba smbd 4.7.6-Ubuntu (workgroup: WORKGROUP)
MAC Address: 02:E9:9D:34:29:85 (Unknown)
Warning: OSScan results may be unreliable because we could not find at least 1 open and 1 closed port
Aggressive OS guesses: Linux 3.8 (95%), Linux 3.1 (95%), Linux 3.2 (95%), AXIS 210A or 211 Network Camera (Linux 2.6.17) (94%), ASUS RT-N56U WAP (Linux 3.4) (93%), Linux 3.16 (93%), Linux 2.6.32 (92%), Linux 2.6.39 - 3.2 (92%), Linux 3.1 - 3.2 (92%), Linux 3.2 - 4.8 (92%)
No exact OS matches for host (test conditions non-ideal).
Network Distance: 1 hop
Service Info: Host: BLOG; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_nbstat: NetBIOS name: BLOG, NetBIOS user: <unknown>, NetBIOS MAC: <unknown> (unknown)
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.7.6-Ubuntu)
|   Computer name: blog
|   NetBIOS computer name: BLOG\x00
|   Domain name: \x00
|   FQDN: blog
|_  System time: 2024-09-06T12:41:13+00:00
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| smb2-security-mode: 
|   2.02: 
|_    Message signing enabled but not required
| smb2-time: 
|   date: 2024-09-06 13:41:13
|_  start_date: 1600-12-31 23:58:45

```


Running dirb reveals possible directories
```
dirb http://10.10.230.112/ 

---- Scanning URL: http://10.10.230.112/ ----
==> DIRECTORY: http://10.10.230.112/0/                                                                                                                        
+ http://10.10.230.112/admin (CODE:302|SIZE:0)                                                                                                            
+ http://10.10.230.112/atom (CODE:301|SIZE:0)                                                                                                                    
+ http://10.10.230.112/dashboard (CODE:302|SIZE:0)                                                                                                                
==> DIRECTORY: http://10.10.230.112/embed/                                                                             
+ http://10.10.230.112/favicon.ico (CODE:200|SIZE:0)                                                                                                           
==> DIRECTORY: http://10.10.230.112/feed/                                                                                                                      
+ http://10.10.230.112/index.php (CODE:301|SIZE:0)                                                                                                             
+ http://10.10.230.112/login (CODE:302|SIZE:0)                                                                                                                 
+ http://10.10.230.112/page1 (CODE:301|SIZE:0)                                                                                                                    
+ http://10.10.230.112/rdf (CODE:301|SIZE:0)                                                                                                                     
+ http://10.10.230.112/robots.txt (CODE:200|SIZE:67)                                                                                                              
+ http://10.10.230.112/rss (CODE:301|SIZE:0)                                                                                                                      
+ http://10.10.230.112/rss2 (CODE:301|SIZE:0)                                                                                                                     
+ http://10.10.230.112/server-status (CODE:403|SIZE:278)                                                                                                       
==> DIRECTORY: http://10.10.230.112/wp-admin/                                                                                                                    
==> DIRECTORY: http://10.10.230.112/wp-content/                                                                                                                   
==> DIRECTORY: http://10.10.230.112/wp-includes/       
```

==DIRECTORY: http://10.10.230.112/wp-admin/ ==
==DIRECTORY: http://10.10.230.112/wp-content/ ==
==DIRECTORY: http://10.10.230.112/wp-includes/==

When navigating to http://blog.thm/feed, a file is downloaded. 
The file is just the raw html of the main page

Running a wordpress scanner module with msfconsole reveals the usernames of billy and his mother. 
This usernames could possibly be used to brute force the admin page 
Chances are his mother doesn't have an account for the admin page. 
It would be wise to focus on Billy's username for now. 
```
systemctl start postgresql && msfconsole -q 
use auxiliary/scanner/http/wordpress_scanner 
setg rhsots 10.10.230.112
exploit 

[*] Trying 10.10.230.112
[+] 10.10.230.112 - Detected Wordpress 5.0
[*] 10.10.230.112 - Enumerating Themes
[*] 10.10.230.112 - Progress  0/2 (0.0%)
[*] 10.10.230.112 - Finished scanning themes
[*] 10.10.230.112 - Enumerating plugins
[*] 10.10.230.112 - Progress   0/57 (0.0%)
[*] 10.10.230.112 - Finished scanning plugins
[*] 10.10.230.112 - Searching Users
[+] 10.10.230.112 - Detected user: Billy Joel with username: bjoel
[+] 10.10.230.112 - Detected user: Karen Wheeler with username: kwheel
[*] 10.10.230.112 - Finished scanning users
[*] 10.10.230.112 - Finished all scans
[*] Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed

```

==Username: bjoel==

user.txt
```

```

Where was user.txt found?
```

```

What CMS was Billy using?
```

```

What version of the above CMS was being used?
```

```
#### Credits
