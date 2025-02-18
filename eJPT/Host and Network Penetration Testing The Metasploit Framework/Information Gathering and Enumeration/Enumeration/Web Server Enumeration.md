- Servers website content
- Utilizes HTTP 
- HTTP application protocol
- Over port 80
- Apache, Nginx, and Microsoft IIS


Set global rhosts
```
setg RHOSTS <target_ip_address>
```

Enumerate HTTP Version
```
search type:auxiliary name:http
use auxiliary/scanner/http/http_version
exploit
```

Get headers of HTTP service
```
search http_header
use auxiliary/scanner/http/http_header
options
exploit
```

Enumerate robots.txt
```
search robots
use auxiliary/scanner/http/robots_txt
exploit
```

Get index of disallowed directories
```
curl http://<target_ip_address>/<disallow_dir_name>/
```

Brute Force dir
```
search dir_scanner 
use auxiliary/scanner/http/dir_scanner
exploit
```


Brute Force files
```
search files_dir
use auxiliar/scanner/http/files_dir
exploit
```

Brute Force Login
```
search http_login
use auxiliary/scanner/http/http_login
options
set AUTH_URI /secure/
exploit
```

Enumerate Apache server users
```
search apache_userdir_enum
use auxiliary/scanner/http/apache_userdir_enum
```
## Quiz 
What HTTP auxiliary module can be used to perform file brute-force attacks on a web server?

	auxiliar/scanner/http/files_dir
## Lab

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.2. Run "ip addr" to know the values of X and Y.
- The target server should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1
- postgresql is not running by default so Metasploit may give you an error about this when starting

192.78.22.3

In this lab, run the following **auxiliary modules** again the target:
- auxiliary/scanner/http/apache_userdir_enum

```
[+] http://192.78.22.3/ - Users found: admin, backup, bin, daemon, dbadmin, games, gnats, irc, list, lp, mail, man, news, nobody, proxy, rooty, sync, sys, ultra, uucp
```
  
- auxiliary/scanner/http/brute_dirs

```
[+] Found http://192.78.22.3:80/doc/ 200
[+] Found http://192.78.22.3:80/pro/ 200
```
  
- auxiliary/scanner/http/dir_scanner

```
[+] Found http://192.78.22.3:80/cgi-bin/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/data/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/doc/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/downloads/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/icons/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/manual/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/secure/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/uploads/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/users/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/web_app/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/webadmin/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/view/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/webdav/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/webdb/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/webmail/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/~admin/ 404 (192.78.22.3)
[+] Found http://192.78.22.3:80/~nobody/ 404 (192.78.22.3)
```
  
- auxiliary/scanner/http/dir_listing

```

```
  
- auxiliary/scanner/http/http_put

```

```
  
- auxiliary/scanner/http/files_dir

```
[+] Found http://192.78.22.3:80/cgi-bin 301
[+] Found http://192.78.22.3:80/data 301
[+] Found http://192.78.22.3:80/downloads 301
[+] Found http://192.78.22.3:80/doc 301
[+] Found http://192.78.22.3:80/manual 301
[+] Found http://192.78.22.3:80/secure 401
[+] Found http://192.78.22.3:80/users 301
[+] Found http://192.78.22.3:80/uploads 301
[+] Found http://192.78.22.3:80/webdav 401
[+] Found http://192.78.22.3:80/webadmin 301
[+] Found http://192.78.22.3:80/view 301
[+] Found http://192.78.22.3:80/webmail 301
[+] Found http://192.78.22.3:80/~admin 403
[+] Found http://192.78.22.3:80/~bin 403
[+] Found http://192.78.22.3:80/~mail 403
[+] Found http://192.78.22.3:80/~sys 403
[*] Using code '404' as not found for files with extension 
[+] Found http://192.78.22.3:80/cgi-bin 301
[+] Found http://192.78.22.3:80/data 301
[+] Found http://192.78.22.3:80/doc 301
[+] Found http://192.78.22.3:80/downloads 301
[+] Found http://192.78.22.3:80/manual 301
[+] Found http://192.78.22.3:80/secure 401
[+] Found http://192.78.22.3:80/uploads 301
[+] Found http://192.78.22.3:80/users 301
[+] Found http://192.78.22.3:80/view 301
[+] Found http://192.78.22.3:80/webadmin 301
[+] Found http://192.78.22.3:80/webdav 401
[+] Found http://192.78.22.3:80/webmail 301
[+] Found http://192.78.22.3:80/~bin 403
[+] Found http://192.78.22.3:80/~admin 403
[+] Found http://192.78.22.3:80/~mail 403
[+] Found http://192.78.22.3:80/~sys 403
```
  
- auxiliary/scanner/http/http_login

```

```
  
- auxiliary/scanner/http/http_header

```

[+] 192.78.22.3:80       : CONTENT-TYPE: text/html
[+] 192.78.22.3:80       : LAST-MODIFIED: Wed, 27 Feb 2019 04:21:01 GMT
[+] 192.78.22.3:80       : SERVER: Apache/2.4.18 (Ubuntu)
[+] 192.78.22.3:80       : detected 3 headers
```
  
- auxiliary/scanner/http/http_version

```
[+] 192.78.22.3:80 Apache/2.4.18 (Ubuntu)
```
  
- auxiliary/scanner/http/robots_txt

```
[+] Contents of Robots.txt:
# robots.txt for attackdefense 
User-agent: test                     
# Directories
Allow: /webmail

User-agent: *
# Directories
Disallow: /data
Disallow: /secure
```
  