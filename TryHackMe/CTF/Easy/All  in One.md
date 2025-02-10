
https://tryhackme.com/r/room/allinonemj

Scan all ports on target machine
```
┌──(root㉿kali)-[~]
└─# nmap -p- 10.10.86.193 
Starting Nmap 7.93 ( https://nmap.org ) at 2025-01-11 20:16 UTC
Nmap scan report for ip-10-10-86-193.eu-west-1.compute.internal (10.10.86.193)
Host is up (0.010s latency).
Not shown: 65532 closed tcp ports (reset)
PORT   STATE SERVICE
21/tcp open  ftp
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:DB:14:65:0E:0B (Unknown)
```

Identify the version and possible vulnerabilities on the target machine
Using nmap to scan ports 21,22 and 80. 
```
└─# nmap -p 21,22,80 -sVC 10.10.86.193         
Starting Nmap 7.93 ( https://nmap.org ) at 2025-01-11 20:17 UTC
Nmap scan report for ip-10-10-86-193.eu-west-1.compute.internal (10.10.86.193)
Host is up (0.00023s latency).

PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.3
|_ftp-anon: Anonymous FTP login allowed (FTP code 230)
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.164.171
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 e25c3322765c9366cd969c166ab317a4 (RSA)
|   256 1b6a36e18eb4965ec6ef0d91375859b6 (ECDSA)
|_  256 fbfadbea4eed202b91189d58a06a50ec (ED25519)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: Apache2 Ubuntu Default Page: It works
MAC Address: 02:DB:14:65:0E:0B (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel
```

The FTP service allows anonymous logins
SSH is running OpenSSH  7.6p1
HTTP is running Apache 2.4.29

I attempted to sign into the ftp server using the anonymous user 
Although the connection was a success I believe there wasn't any content in the directory
```
ftp 10.10.86.193 
user: anonymous
dir
```

The server at port 80 is hosting a wordpress site
A couple of possible notable users are elyana and i7m4d but this might go nowhere and could be part of the setting up the room. 


Enumerate through root directory of the target website
```
─(root㉿kali)-[~]
└─# gobuster dir -u http://10.10.86.193 -w /usr/share/wordlists/dirb/big.txt 
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.86.193
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Timeout:                 10s
===============================================================
2025/01/11 20:28:11 Starting gobuster in directory enumeration mode
===============================================================
/.htaccess            (Status: 403) [Size: 277]
/.htpasswd            (Status: 403) [Size: 277]
/server-status        (Status: 403) [Size: 277]
/wordpress            (Status: 301) [Size: 316] [--> http://10.10.86.193/wordpress/]
Progress: 20469 / 20470 (100.00%)===============================================================
2025/01/11 20:28:14 Finished
===============================================================
                                                                 
```


Enumerate through the found wordpress directory
```
┌──(root㉿kali)-[~]
└─# gobuster dir -u http://10.10.86.193/wordpress/ -w /usr/share/wordlists/dirb/big.txt
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.86.193/wordpress/
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Timeout:                 10s
===============================================================
2025/01/11 21:05:02 Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 277]
/.htaccess            (Status: 403) [Size: 277]
/wp-admin             (Status: 301) [Size: 325] [--> http://10.10.86.193/wordpress/wp-admin/]
/wp-content           (Status: 301) [Size: 327] [--> http://10.10.86.193/wordpress/wp-content/]
/wp-includes          (Status: 301) [Size: 328] [--> http://10.10.86.193/wordpress/wp-includes/]
===============================================================
2025/01/11 21:05:05 Finished
===============================================================
```
wp-admin
wp-content
wp-includes

Attempt to brute force wordpress admin site with hydra
This didn't reveal any verified credentials
```
hydra -l names.txt -P /usr/share/wordlists/rockyou.txt 10.10.86.193 http-post-form "/wordpress/wp-admin:>"
```
I looked up the next step in a writeup 

Wordpress's host plugins  can be utilized to  exploit the web server
If you view the web page source of the root wordpress website you can view these plugins. 
```
link rel='stylesheet' id='twentytwenty-print-style-css'  href='http://10.10.86.193/wordpress/wp-content/themes/twentytwenty/print.css?ver=1.5' media='print' />
<script src='http://10.10.86.193/wordpress/wp-includes/js/jquery/jquery.js?ver=1.12.4-wp' id='jquery-core-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/mail-masta/lib/subscriber.js?ver=5.5.1' id='subscriber-js-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/mail-masta/lib/jquery.validationEngine-en.js?ver=5.5.1' id='validation-engine-en-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/mail-masta/lib/jquery.validationEngine.js?ver=5.5.1' id='validation-engine-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/reflex-gallery/scripts/flexslider/jquery.flexslider-min.js?ver=5.5.1' id='flexSlider-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/reflex-gallery/scripts/prettyphoto/jquery.prettyPhoto.js?ver=5.5.1' id='prettyPhoto-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/plugins/reflex-gallery/scripts/galleryManager.js?ver=5.5.1' id='galleryManager-js'></script>
<script src='http://10.10.86.193/wordpress/wp-content/themes/twentytwenty/assets/js/index.js?ver=1.5' id='twentytwenty-js-js' async></script>
<link rel="https://api.w.org/" href="http://10.10.86.193/wordpress/index.php/wp-json/" /><link rel="EditURI" type="application/rsd+xml" title="RSD" href="http://10.10.86.193/wordpress/xmlrpc.php?rsd" />
<link rel="wlwmanifest" type="application/wlwmanifest+xml" href="http://10.10.86.193/wordpress/wp-includes/wlwmanifest.xml" /> 
```