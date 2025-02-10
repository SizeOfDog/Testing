

Nmap scan all ports
```
root@ip-10-10-103-119:~# nmap -p- 10.10.55.130 
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-11 15:20 GMT
Nmap scan report for 10.10.55.130
Host is up (0.00024s latency).
Not shown: 65530 closed ports
PORT      STATE SERVICE
21/tcp    open  ftp
22/tcp    open  ssh
80/tcp    open  http
111/tcp   open  rpcbind
34462/tcp open  unknown
MAC Address: 02:5C:8A:E7:5A:7B (Unknown)

Nmap done: 1 IP address (1
```

Scan open ports
```
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-11 15:22 GMT
Nmap scan report for 10.10.55.130
Host is up (0.00018s latency).

PORT    STATE SERVICE VERSION
21/tcp  open  ftp     vsftpd 3.0.2
22/tcp  open  ssh     OpenSSH 6.7p1 Debian 5+deb8u8 (protocol 2.0)
| ssh-hostkey: 
|   1024 56:50:bd:11:ef:d4:ac:56:32:c3:ee:73:3e:de:87:f4 (DSA)
|   2048 39:6f:3a:9c:b6:2d:ad:0c:d8:6d:be:77:13:07:25:d6 (RSA)
|   256 a6:69:96:d7:6d:61:27:96:7e:bb:9f:83:60:1b:52:12 (ECDSA)
|_  256 3f:43:76:75:a8:5a:a6:cd:33:b0:66:42:04:91:fe:a0 (ED25519)
80/tcp  open  http    Apache httpd
|_http-server-header: Apache
|_http-title: Purgatory
111/tcp open  rpcbind 2-4 (RPC #100000)
| rpcinfo: 
|   program version    port/proto  service
|   100000  2,3,4        111/tcp   rpcbind
|   100000  2,3,4        111/udp   rpcbind
|   100000  3,4          111/tcp6  rpcbind
|   100000  3,4          111/udp6  rpcbind
|   100024  1          34462/tcp   status
|   100024  1          34523/udp6  status
|   100024  1          44462/udp   status
|_  100024  1          58268/tcp6  status
MAC Address: 02:5C:8A:E7:5A:7B (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 9.13 seconds
```


Use gobuster to scan dir
```
root@ip-10-10-103-119:~# gobuster dir -u http://10.10.55.130 -w /usr/share/wordlists/dirb/big.txt 
===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.55.130
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 199]
/.htaccess            (Status: 403) [Size: 199]
/island               (Status: 301) [Size: 235] [--> http://10.10.55.130/island/]
/server-status        (Status: 403) [Size: 199]
Progress: 20469 / 20470 (100.00%)
===============================================================
Finished
===============================================================
```

Secret found in dir /island
```
vigilante
```


Ran the gobuster command against the directory island/2100
I used the directory-list-2.3-big.txt list and the wildcard simple along with the word .ticket as an extension found from the page source of 2100
```
┌──(root㉿kali)-[/usr/…/wordlists/seclists/Discovery/Web-Content]
└─# gobuster dir -u http://10.10.102.168/island/2100 -w directory-list-2.3-big.txt -x *.ticket
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.102.168/island/2100
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                directory-list-2.3-big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Extensions:              *.ticket
[+] Timeout:                 10s
===============================================================
2025/01/11 18:18:03 Starting gobuster in directory enumeration mode

```

When you navigate to the url green_arrow.ticket there's a message with a secret
```
RTy8yhBQdscX
```

When you convert it from base64 you get the password
```
!#th3h00d
```

Attempt to FTP into the server using the credentials found
```
ftp 10.10.102.168 
vigilante
!#th300d
```