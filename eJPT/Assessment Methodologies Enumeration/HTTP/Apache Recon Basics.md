

### Tools
nmap
msfconsole
curl
wget
browsh
lynx

### Commands

Get Banner Info with nmap
```
nmap target_ip -p 80 -sV --script banner
```

Get http version with metasploit
```
msfconsole
use auxiliary/scanner/http/http_version
set rhosts target_ip
options
run 
```

Get page content in html
```
curl target_ip 
```

Retrieve files on web page
```
wget target_ip
```

Render page in command line
```
browsh --startup-url target_ip
```

Parses text from web page for easy read
```
lynx url+target_ip 
```

Brute force directories with msfconsole
```
msfconsole 
use auxiliary/scanner/http/brute_dirs
show options
set rhosts target_ip
options
run
```


Scan subdirecties with dirb
```
dirb http://target_ip /usr/share/metasploit-framework/wordlists/directory.txt
```

Scan url for robot.txt file with msfconsole
```
msfconsole
use axuiliary/scanner/http/robots_txt
show options
set rhosts target_ip 
options 
run 
```


#### Notes
Robots.txt - a text file the outlines to search engines which subdirectories to not read. 

## Lab

192.144.157.3

### Questions
1.  Which web server software is running on the target server and also find out the version using nmap.

```
nmap -sS -sV -p 80 192.144.157.3

80/tcp open  http    Apache httpd 2.4.18 ((Ubuntu))                                                                                                           
```

2.  Which web server software is running on the target server and also find out the version using suitable metasploit module.

```
use auxiliary(scanner/http/http_version)
set RHOSTS 192.144.157.3
exploit 

[+] 192.144.157.3:80 Apache/2.4.18 (Ubuntu)
```

3.  Check what web app is hosted on the web server using curl command.

```
curl -v http://192.144.157.3

> GET / HTTP/1.1
> Host: 192.144.157.3
> User-Agent: curl/7.81.0
> Accept: */*
> 
* Mark bundle as not supporting multiuse
< HTTP/1.1 200 OK
< Date: Mon, 15 Jul 2024 12:47:29 GMT
< Server: Apache/2.4.18 (Ubuntu)
< Last-Modified: Sat, 24 Nov 2018 06:09:42 GMT
< ETag: "2c39-57b62f2149580"
< Accept-Ranges: bytes
< Content-Length: 11321
< Vary: Accept-Encoding
< Content-Type: text/html
< 

```

4.  Check what web app is hosted on the web server using wget command.

```
wget -dv http://192.144.157.3

---request begin---
GET / HTTP/1.1
Host: 192.144.157.3
User-Agent: Wget/1.21.2
Accept: */*
Accept-Encoding: identity
Connection: Keep-Alive

---request end---
HTTP request sent, awaiting response... 
---response begin---
HTTP/1.1 200 OK
Date: Mon, 15 Jul 2024 12:49:29 GMT
Server: Apache/2.4.18 (Ubuntu)
Last-Modified: Sat, 24 Nov 2018 06:09:42 GMT
ETag: "2c39-57b62f2149580"
Accept-Ranges: bytes
Content-Length: 11321
Vary: Accept-Encoding
Keep-Alive: timeout=5, max=100
Connection: Keep-Alive
Content-Type: text/html
```

5.  Check what web app is hosted on the web server using browsh CLI based browser.

```

```

6.  Check what web app is hosted on the web server using lynx CLI based browser.

```

```

7.  Perform bruteforce on webserver directories and list the names of directories found. Use brute_dirs metasploit module.

```
auxiliary(scanner/http/brute_dirs)
set RHOSTS 192.144.157.3
exploit 

[+] Found http://192.144.157.3:80/dir/ 200
[+] Found http://192.144.157.3:80/src/ 200
```

8.  Use the directory buster (dirb) with tool/usr/share/metasploit-framework/data/wordlists/directory.txt dictionary to check if any directory is present in the root folder of the web server. List the names of found directories.

```
dirb  http://192.144.157.3 -r  /usr/share/metasploit-framework/data/wordlists/directory.txt


START_TIME: Mon Jul 15 18:28:00 2024
URL_BASE: http://192.144.157.3/
WORDLIST_FILES: /usr/share/dirb/wordlists/common.txt
OPTION: Not Recursive

-----------------

GENERATED WORDS: 4612                                                          

---- Scanning URL: http://192.144.157.3/ ----
+ http://192.144.157.3/cgi-bin/ (CODE:403|SIZE:296)                                                                                                                    
==> DIRECTORY: http://192.144.157.3/data/                                                                                                                              
==> DIRECTORY: http://192.144.157.3/dir/                                                                                                                               
+ http://192.144.157.3/index (CODE:200|SIZE:11321)                                                                                                                     
+ http://192.144.157.3/index.html (CODE:200|SIZE:11321)                                                                                                                
+ http://192.144.157.3/robots (CODE:200|SIZE:107)                                                                                                                      
+ http://192.144.157.3/robots.txt (CODE:200|SIZE:107)                                                                                                                  
+ http://192.144.157.3/server-status (CODE:403|SIZE:301)                                                                                                               
==> DIRECTORY: http://192.144.157.3/src/ 
```

9.  Which bot is specifically banned from accessing a specific directory?

```
http://192.144.157.3/robots.txt

BadBot
```
### Answers
1. http  Apache httpd 2.3.18
2. Apache 2.3.18
3. curl
4. wget
5. browsh
6. lynx 
7. target_ip/dir , target_ip/src
8. 
9. badbot can't access no badbot dir 
