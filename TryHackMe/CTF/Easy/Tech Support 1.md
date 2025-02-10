
https://tryhackme.com/r/room/techsupp0rt1

```
└─# nmap -p- 10.10.240.148 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-11 22:39 UTC
Nmap scan report for ip-10-10-240-148.eu-west-1.compute.internal (10.10.240.148)
Host is up (0.0044s latency).
Not shown: 65531 closed tcp ports (reset)
PORT    STATE SERVICE
22/tcp  open  ssh
80/tcp  open  http
139/tcp open  netbios-ssn
445/tcp open  microsoft-ds
MAC Address: 02:89:B4:71:29:6D (Unknown)

```

```
─# nmap -p 22,80,139,445 -sV -sC 10.10.240.148 -v 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-11 22:39 UTC
NSE: Loaded 155 scripts for scanning.
NSE: Script Pre-scanning.
Initiating NSE at 22:39
Completed NSE at 22:39, 0.00s elapsed
Initiating NSE at 22:39
Completed NSE at 22:39, 0.00s elapsed
Initiating NSE at 22:39
Completed NSE at 22:39, 0.00s elapsed
Initiating ARP Ping Scan at 22:39
Scanning 10.10.240.148 [1 port]
Completed ARP Ping Scan at 22:39, 0.04s elapsed (1 total hosts)
Initiating Parallel DNS resolution of 1 host. at 22:39
Completed Parallel DNS resolution of 1 host. at 22:39, 0.00s elapsed
Initiating SYN Stealth Scan at 22:39
Scanning ip-10-10-240-148.eu-west-1.compute.internal (10.10.240.148) [4 ports]
Discovered open port 80/tcp on 10.10.240.148
Discovered open port 22/tcp on 10.10.240.148
Discovered open port 139/tcp on 10.10.240.148
Discovered open port 445/tcp on 10.10.240.148
Completed SYN Stealth Scan at 22:39, 0.03s elapsed (4 total ports)
Initiating Service scan at 22:39
Scanning 4 services on ip-10-10-240-148.eu-west-1.compute.internal (10.10.240.148)
Completed Service scan at 22:40, 11.01s elapsed (4 services on 1 host)
NSE: Script scanning 10.10.240.148.
Initiating NSE at 22:40
Completed NSE at 22:40, 5.30s elapsed
Initiating NSE at 22:40
Completed NSE at 22:40, 0.00s elapsed
Initiating NSE at 22:40
Completed NSE at 22:40, 0.00s elapsed
Nmap scan report for ip-10-10-240-148.eu-west-1.compute.internal (10.10.240.148)
Host is up (0.00047s latency).
PORT    STATE SERVICE     VERSION
22/tcp  open  ssh         OpenSSH 7.2p2 Ubuntu 4ubuntu2.10 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:
|   2048 108af572d7f97e14a5c54f9e978b3d58 (RSA)
|   256 7f10f557413c71dbb55bdb75c976305c (ECDSA)
|_  256 6b4c23506f36007ca67c1173c1a8600c (ED25519)
80/tcp  open  http        Apache httpd 2.4.18 ((Ubuntu))
|_http-title: Apache2 Ubuntu Default Page: It works
|_http-server-header: Apache/2.4.18 (Ubuntu)
| http-methods:
|_  Supported Methods: POST OPTIONS GET HEAD
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp open  netbios-ssn Samba smbd 4.3.11-Ubuntu (workgroup: WORKGROUP)
MAC Address: 02:89:B4:71:29:6D (Unknown)
Service Info: Host: TECHSUPPORT; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb-os-discovery:
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: techsupport
|   NetBIOS computer name: TECHSUPPORT\x00
|   Domain name: \x00
|   FQDN: techsupport
|_  System time: 2024-11-12T04:10:07+05:30
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
|_clock-skew: mean: -1h49m58s, deviation: 3h10m30s, median: 0s
| smb2-time: 
|   date: 2024-11-11T22:40:05
|_  start_date: N/A

```

```
└─# dirb http://10.10.117.20 common.txt -x extensions_common.txt 
-----------------
DIRB v2.22    
By The Dark Raver
-----------------
START_TIME: Tue Nov 12 01:05:16 2024
URL_BASE: http://10.10.117.20/
WORDLIST_FILES: common.txt
EXTENSIONS_FILE: extensions_common.txt | ()(.asp)(.aspx)(.bat)(.c)(.cfm)(.cgi)(.com)(.dll)(.exe)(.htm)(.html)(.inc)(.jhtml)(.jsa)(.jsp)(.log)(.mdb)(.nsf)(.php)(.phtml)(.pl)(.reg)(.sh)(.shtml)(.sql)(.txt)(.xml)(/) [NUM = 29]
-----------------
GENERATED WORDS: 4612                                                          
---- Scanning URL: http://10.10.117.20/ ----
+ http://10.10.117.20/icons/ (CODE:403|SIZE:277)
+ http://10.10.117.20/index.html (CODE:200|SIZE:11321)
+ http://10.10.117.20/index.html (CODE:200|SIZE:11321)
+ http://10.10.117.20/phpinfo.php (CODE:200|SIZE:95020)
+ http://10.10.117.20/phpinfo.php (CODE:200|SIZE:95020)
+ http://10.10.117.20/phpinfo.php/ (CODE:200|SIZE:95342)
+ http://10.10.117.20/server-status (CODE:403|SIZE:277)
+ http://10.10.117.20/server-status/ (CODE:403|SIZE:277)
==> DIRECTORY: http://10.10.117.20/test/
+ http://10.10.117.20/test/ (CODE:200|SIZE:20677)
==> DIRECTORY: http://10.10.117.20/wordpress/                
```

```
enum4linux -a 10.10.240.148

//10.10.240.148/print$  Mapping: DENIED Listing: N/A Writing: N/A
//10.10.240.148/websvr  Mapping: OK Listing: OK Writing: N/A
```

```
smbclient //10.10.240.148 -U guest
ls 
more enter.txt

GOALS
=====
1)Make fake popup and host it online on Digital Ocean server
2)Fix subrion site, /subrion doesn't work, edit from panel
3)Edit wordpress website

IMP
===
Subrion creds
|->admin:7sKvntXdPEJaxazce9PXi24zaFrLiKWCk [cooked with magical formula]
Wordpress creds
|->
/tmp/smbmore.7Xf4du
```

Using the magic recipe in cyber chef 
```
7sKvntXdPEJaxazce9PXi24zaFrLiKWCk -> Scam2021
```

```
http://10.10.117.20/wordpress/wp-login.php?redirect_to=http%3A%2F%2F10.10.117.20%2Fwordpress%2Fwp-admin%2F&reauth=1
```