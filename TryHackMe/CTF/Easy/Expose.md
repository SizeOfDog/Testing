
https://tryhackme.com/r/room/expose

Scan all ports for target 
```
└─# nmap -p-  10.10.101.190  -T 4 -v
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-12-17 02:53 UTC
Initiating Ping Scan at 02:53
Scanning 10.10.101.190 [4 ports]
Completed Ping Scan at 02:53, 0.10s elapsed (1 total hosts)
Initiating Parallel DNS resolution of 1 host. at 02:53
Completed Parallel DNS resolution of 1 host. at 02:53, 0.01s elapsed
Initiating SYN Stealth Scan at 02:53
Scanning 10.10.101.190 [65535 ports]
Discovered open port 21/tcp on 10.10.101.190
Discovered open port 22/tcp on 10.10.101.190
Discovered open port 53/tcp on 10.10.101.190
SYN Stealth Scan Timing: About 21.66% done; ETC: 02:55 (0:01:52 remaining)
SYN Stealth Scan Timing: About 40.43% done; ETC: 02:56 (0:01:34 remaining)
SYN Stealth Scan Timing: About 56.06% done; ETC: 02:56 (0:01:14 remaining)
SYN Stealth Scan Timing: About 70.27% done; ETC: 02:56 (0:00:52 remaining)
Discovered open port 1883/tcp on 10.10.101.190
SYN Stealth Scan Timing: About 81.46% done; ETC: 02:56 (0:00:35 remaining)
Discovered open port 1337/tcp on 10.10.101.190
Completed SYN Stealth Scan at 02:56, 180.69s elapsed (65535 total ports)
Nmap scan report for 10.10.101.190
Host is up (0.11s latency).
Not shown: 65530 closed tcp ports (reset)
PORT     STATE SERVICE
21/tcp   open  ftp
22/tcp   open  ssh
53/tcp   open  domain                                
1337/tcp open  waste                                 
1883/tcp open  mqtt                                  

Read data files from: /usr/share/nmap
Nmap done: 1 IP address (1 host up) scanned in 180.92 seconds
           Raw packets sent: 71188 (3.132MB) | Rcvd: 70208 (2.808MB)

```

Scan specific open tcp ports
```
└─# nmap -sVC -p 21,22,53,1337,1883 10.10.101.190
Starting Nmap 7.94SVN ( https://nmap.org ) at 2024-12-17 02:57 UTC
Nmap scan report for 10.10.101.190
Host is up (0.098s latency).
PORT     STATE SERVICE                 VERSION
21/tcp   open  ftp                     vsftpd 2.0.8 or later
|_ftp-anon: Anonymous FTP login allowed (FTP code 230)
| ftp-syst:
|   STAT:
| FTP server status:
|      Connected to ::ffff:10.6.22.157
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 3
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status                                      
22/tcp   open  ssh                     OpenSSH 8.2p1 Ubuntu 4ubuntu0.7 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey:                                       
|   3072 83:d6:5f:7d:f0:90:4c:74:14:8c:68:9f:3c:cf:22:08 (RSA)
|   256 56:64:a7:6d:28:f3:dd:cf:43:c1:d0:85:db:aa:3b:1f (ECDSA)
|_  256 34:f9:e5:30:65:60:70:f3:61:48:5b:c4:90:55:2c:e9 (ED25519)
53/tcp   open  domain                  ISC BIND 9.16.1 (Ubuntu Linux)
| dns-nsid:                                          
|_  bind.version: 9.16.1-Ubuntu
1337/tcp open  http                    Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: EXPOSED                                
1883/tcp open  mosquitto version 1.6.9
| mqtt-subscribe:                                    
|   Topics and their most recent payloads: 
|     $SYS/broker/bytes/sent: 4
|     $SYS/broker/heap/maximum: 49688
|     $SYS/broker/load/messages/sent/15min: 0.07
|     $SYS/broker/load/connections/15min: 0.07
|     $SYS/broker/version: mosquitto version 1.6.9
|     $SYS/broker/load/messages/received/15min: 0.07
|     $SYS/broker/uptime: 1188 seconds
|     $SYS/broker/store/messages/bytes: 180
|     $SYS/broker/messages/received: 1
|     $SYS/broker/messages/sent: 1
|     $SYS/broker/load/connections/5min: 0.20
|     $SYS/broker/load/messages/sent/5min: 0.20
|     $SYS/broker/load/messages/received/1min: 0.91
|     $SYS/broker/load/sockets/5min: 0.20
|     $SYS/broker/load/sockets/1min: 0.91
|     $SYS/broker/load/messages/received/5min: 0.20
|     $SYS/broker/load/sockets/15min: 0.07
|     $SYS/broker/load/bytes/sent/15min: 0.27
|     $SYS/broker/load/bytes/received/15min: 1.19
|     $SYS/broker/bytes/received: 18
|     $SYS/broker/load/connections/1min: 0.91
|     $SYS/broker/load/bytes/received/1min: 16.45
|     $SYS/broker/load/bytes/sent/5min: 0.79
|     $SYS/broker/load/messages/sent/1min: 0.91
|     $SYS/broker/load/bytes/received/5min: 3.53
|_    $SYS/broker/load/bytes/sent/1min: 3.65
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

```

```
gobuster dir -u http://10.10.101.190:1337 -w big.txt 

http://10.10.101.190:1337/phpmyadmin/
/admin_101   
/javascript
/admin
```