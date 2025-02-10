

## Intro to POC Scripting

#### Example - The Starting Point

What is the target's platform and version number?  
```
nmap -p 80 -sV -sC 10.10.47.26 

80/tcp open  http    MiniServ 1.580 (Webmin httpd)
| http-robots.txt: 1 disallowed entry 
|_/
|_http-title: Login to Webmin

```

```
webmin 1.580
```

What is the associated CVE for this platform?  
```
searchsploit 1.580

---------------------------------------------- ---------------------------------
 Exploit Title                                |  Path
---------------------------------------------- ---------------------------------
Webmin 1.580 - '/file/show.cgi' Remote Comman | unix/remote/21851.rb
---------------------------------------------- ---------------------------------


find / -name 21851.rb -type f  2>/dev/null

/opt/exploitdb/exploits/unix/remote/21851.rb

-------------------------------------------------------

nano 218551.rb
```

```
CVE-2012-2982
```

Which file does the vulnerability exist in?  
```
file/show.cgi
```

What program/command would be the most effective to use in this exploit
```
system shell
```

#### Translating Metasploit Module Code

What's the original disclosure date of this exploit?  
```
September 6 2012
```

What HTTP response code do we expect after the initial POST request?  
```
302
```

What does sid stand for and what is it's purpose?  
```
Session ID, authentication
```

In the check function, what is it doing to the cookies?  
```
format
```

In the second request of the check function, what **method** is piped into the command?
```
rand_text_alphanumeric
```

#### Converting Ruby to Python

Which HTTP response header allows us to send an authenticated POST request?  
```

```

Which is the correct method for formatting cookies in this example?

r.headers().replace().split().strip()

r.headers().split().strip()

a = r.cookies()

b = a.strip()
```

```

What data type does the payload need to be?
```

```

Why do we need to use "bash -c exec" instead of just "bash -i"
```

```

What is the purpose of "<&1" in the payload function?
```

```

#### Final Exploit and Test

#### Common Mistakes

#### Thoughts and Resources

