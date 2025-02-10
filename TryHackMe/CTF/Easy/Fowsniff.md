

```
└─# nmap -p-  10.10.221.252 
Starting Nmap 7.93 ( https://nmap.org ) at 2025-02-03 04:58 UTC
Nmap scan report for ip-10-10-221-252.eu-west-1.compute.internal (10.10.221.252)
Host is up (0.0056s latency).
Not shown: 65531 closed tcp ports (reset)
PORT    STATE SERVICE
22/tcp  open  ssh
80/tcp  open  http
110/tcp open  pop3
143/tcp open  imap
MAC Address: 02:3B:6F:E1:62:A9 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 3.75 seconds

```


```
┌──(root㉿kali)-[~]
└─# nmap -p 22,80,110,143 -sVC  10.10.221.252
Starting Nmap 7.93 ( https://nmap.org ) at 2025-02-03 04:59 UTC
Nmap scan report for ip-10-10-221-252.eu-west-1.compute.internal (10.10.221.252)
Host is up (0.00026s latency).

PORT    STATE SERVICE VERSION
22/tcp  open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.4 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 903566f4c6d295121be8cddeaa4e0323 (RSA)
|   256 539d236734cf0ad55a9a1174bdfdde71 (ECDSA)
|_  256 a28fdbae9e3dc9e6a9ca03b1d71b6683 (ED25519)
80/tcp  open  http    Apache httpd 2.4.18 ((Ubuntu))
| http-robots.txt: 1 disallowed entry 
|_/
|_http-title: Fowsniff Corp - Delivering Solutions
|_http-server-header: Apache/2.4.18 (Ubuntu)
110/tcp open  pop3    Dovecot pop3d
|_pop3-capabilities: SASL(PLAIN) AUTH-RESP-CODE PIPELINING UIDL USER RESP-CODES CAPA TOP
143/tcp open  imap    Dovecot imapd
|_imap-capabilities: more Pre-login have LITERAL+ listed post-login capabilities ID IMAP4rev1 OK IDLE SASL-IR LOGIN-REFERRALS AUTH=PLAINA0001 ENABLE
MAC Address: 02:3B:6F:E1:62:A9 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 7.23 seconds
```


```
a92b8a29ef1183192e3d35187e0cfabd
```

```
roflcopter
```