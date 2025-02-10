
Nmap scan all parts of target
```
└─# nmap -p- -T 4 -v  10.10.136.125
Starting Nmap 7.93 ( https://nmap.org ) at 2024-12-11 00:46 UTC
Initiating ARP Ping Scan at 00:46
Scanning 10.10.136.125 [1 port]
Completed ARP Ping Scan at 00:46, 0.17s elapsed (1 total hosts)
Initiating Parallel DNS resolution of 1 host. at 00:46
Completed Parallel DNS resolution of 1 host. at 00:46, 0.00s elapsed
Initiating SYN Stealth Scan at 00:46
Scanning ip-10-10-136-125.eu-west-1.compute.internal (10.10.136.125) [65535 ports]
Discovered open port 22/tcp on 10.10.136.125
Discovered open port 80/tcp on 10.10.136.125
Discovered open port 37370/tcp on 10.10.136.125
Completed SYN Stealth Scan at 00:46, 4.40s elapsed (65535 total ports)
Nmap scan report for ip-10-10-136-125.eu-west-1.compute.internal (10.10.136.125)
Host is up (0.0074s latency).
Not shown: 65532 closed tcp ports (reset)
PORT      STATE SERVICE
22/tcp    open  ssh
80/tcp    open  http
37370/tcp open  unknown
MAC Address: 02:D8:A0:4E:F9:97 (Unknown)

```

Scan individual ports for service version and scripting
```
PORT      STATE SERVICE VERSION
22/tcp    open  ssh     OpenSSH 8.2p1 Ubuntu 4ubuntu0.5 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 c2842ac1225a10f16616dda0f6046295 (RSA)
|   256 429e2ff63e5adb51996271c48c223ebb (ECDSA)
|_  256 2ea0a56cd983e0016cb98a609b638672 (ED25519)
80/tcp    open  http    Apache httpd 2.4.41 ((Ubuntu))
|_http-title: Site doesn't have a title (text/html).
| http-methods: 
|_  Supported Methods: POST OPTIONS HEAD GET
|_http-server-header: Apache/2.4.41 (Ubuntu)
37370/tcp open  ftp     vsftpd 3.0.3
MAC Address: 02:D8:A0:4E:F9:97 (Unknown)
Service Info: OSs: Linux, Unix; CPE: cpe:/o:linux:linux_kernel
```

Utilize gobuster to enumerate the web page directories. 
```
└─# gobuster dir -u http://10.10.136.125 -w /usr/share/wordlists/dirb/big.txt  
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.136.125
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Timeout:                 10s
===============================================================
2024/12/11 00:50:20 Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 278]
/.htaccess            (Status: 403) [Size: 278]
/gallery              (Status: 301) [Size: 316] [--> http://10.10.136.125/gallery/]
/pricing              (Status: 301) [Size: 316] [--> http://10.10.136.125/pricing/]
/server-status        (Status: 403) [Size: 278]
/static               (Status: 301) [Size: 315] [--> http://10.10.136.125/static/]
===============================================================
2024/12/11 00:50:22 Finished
===============================================================
                                                                   
```


https://tryhackme.com/r/room/valleype