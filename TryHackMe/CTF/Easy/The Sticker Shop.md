
```
nmap -p 8080,22 -sVC 10.10.201.157 

PORT     STATE SERVICE    VERSION
22/tcp   open  ssh        OpenSSH 8.2p1 Ubuntu 4ubuntu0.9 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   3072 b2548ce2d767ab8f90b36f52c2733769 (RSA)
|   256 1429ec3695e56449393fb4ecca5fee78 (ECDSA)
|_  256 19eb1fc9679201610c14fe714b0d5040 (ED25519)
8080/tcp open  http-proxy Werkzeug/3.0.1 Python/3.8.10
| fingerprint-strings: 
|   GetRequest: 
|     HTTP/1.1 200 OK
|     Server: Werkzeug/3.0.1 Python/3.8.10
|     Date: Wed, 11 Dec 2024 11:12:37 GMT
|     Content-Type: text/html; charset=utf-8
|     Content-Length: 1655
|     Connection: close
|     <!DOCTYPE html>
|     <html>
|     <head>
|     <title>Cat Sticker Shop</title>
|     <style>
|     body {
|     font-family: Arial, sans-serif;
|     margin: 0;
|     padding: 0;
|     header {
|     background-color: #333;
|     color: #fff;
|     text-align: center;
|     padding: 10px;
|     header ul {
|     list-style: none;
|     padding: 0;
|     header li {
|     display: inline;
|     margin-right: 20px;
|     header a {
|     text-decoration: none;
|     color: #fff;
|     font-weight: bold;
|     .content {
|     padding: 20px;
|_    .product {
|_http-title: Cat Sticker Shop
|_http-server-header: Werkzeug/3.0.1 Python/3.8.10
| http-methods: 
|_  Supported Methods: HEAD OPTIONS GET
1 service unrecognized despite returning data. If you know the service/version, please submit the following fingerprint at https://nmap.org/cgi-bin/submit.cgi?new-service :
SF-Port8080-TCP:V=7.93%I=7%D=12/11%Time=675973A6%P=x86_64-pc-linux-gnu%r(G
SF:etRequest,726,"HTTP/1\.1\x20200\x20OK\r\nServer:\x20Werkzeug/3\.0\.1\x2
SF:0Python/3\.8\.10\r\nDate:\x20Wed,\x2011\x20Dec\x202024\x2011:12:37\x20G
SF:MT\r\nContent-Type:\x20text/html;\x20charset=utf-8\r\nContent-Length:\x
SF:201655\r\nConnection:\x20close\r\n\r\n<!DOCTYPE\x20html>\n<html>\n<head
SF:>\n\x20\x20\x20\x20<title>Cat\x20Sticker\x20Shop</title>\n\x20\x20\x20\
SF:x20<style>\n\x20\x20\x20\x20\x20\x20\x20\x20body\x20{\n\x20\x20\x20\x20
SF:\x20\x20\x20\x20\x20\x20\x20\x20font-family:\x20Arial,\x20sans-serif;\n
SF:\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20margin:\x200;\n\x20\x20
SF:\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20padding:\x200;\n\x20\x20\x20\x2
SF:0\x20\x20\x20\x20}\n\x20\x20\x20\x20\x20\x20\x20\x20header\x20{\n\x20\x
SF:20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20background-color:\x20#333;\n\
SF:x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20color:\x20#fff;\n\x20\x2
SF:0\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20text-align:\x20center;\n\x20\x
SF:20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20padding:\x2010px;\n\x20\x20\x
SF:20\x20\x20\x20\x20\x20}\n\x20\x20\x20\x20\x20\x20\x20\x20header\x20ul\x
SF:20{\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20list-style:\x20non
SF:e;\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20padding:\x200;\n\x2
SF:0\x20\x20\x20\x20\x20\x20\x20}\n\x20\x20\x20\x20\x20\x20\x20\x20header\
SF:x20li\x20{\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20display:\x2
SF:0inline;\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20margin-right:
SF:\x2020px;\n\x20\x20\x20\x20\x20\x20\x20\x20}\n\x20\x20\x20\x20\x20\x20\
SF:x20\x20header\x20a\x20{\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x
SF:20text-decoration:\x20none;\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x
SF:20\x20color:\x20#fff;\n\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20\x20
SF:font-weight:\x20bold;\n\x20\x20\x20\x20\x20\x20\x20\x20}\n\x20\x20\x20\
SF:x20\x20\x20\x20\x20\.content\x20{\n\x20\x20\x20\x20\x20\x20\x20\x20\x20
SF:\x20\x20\x20padding:\x2020px;\n\x20\x20\x20\x20\x20\x20\x20\x20}\n\x20\
SF:x20\x20\x20\x20\x20\x20\x20\.product\x20{\n\x20\x20\x20\x20\x20\x20\x20
SF:\x20\x20\x20\x20\x20bo");
MAC Address: 02:E0:88:52:1B:F7 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

```