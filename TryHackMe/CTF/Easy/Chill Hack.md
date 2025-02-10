![[Pasted image 20241118095615.png]]

![[Pasted image 20241118095721.png]]


```
─# gobuster dir -u http://10.10.31.63 -w /usr/share/wordlists/dirb/big.txt
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.31.63
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Timeout:                 10s
===============================================================
2025/01/10 02:34:13 Starting gobuster in directory enumeration mode
===============================================================
/.htaccess            (Status: 403) [Size: 276]
/.htpasswd            (Status: 403) [Size: 276]
/css                  (Status: 301) [Size: 308] [--> http://10.10.31.63/css/]
/fonts                (Status: 301) [Size: 310] [--> http://10.10.31.63/fonts/]
/images               (Status: 301) [Size: 311] [--> http://10.10.31.63/images/]
/js                   (Status: 301) [Size: 307] [--> http://10.10.31.63/js/]
/secret               (Status: 301) [Size: 311] [--> http://10.10.31.63/secret/]
/server-status        (Status: 403) [Size: 276]
Progress: 19791 / 20470 (96.68%)===============================================================
2025/01/10 02:34:16 Finished
====================================
```

User Flag
```

```

Root Flag
```

```