#### Tools
nmap

#### Commands

Enumerate http 
```
nmap target_ip -sV -p 80 --script http-enum
```

Get http headers
```
nmap target_ip -sV -p 80 --script http-headers
```

Get http methods
```
nmap target_ip -sV -p 80 --script http-methods
```

Using WebDAV get authoring and versioning
```
nmap target_ip -sV -p 80 --script http-webdav-scan --script-args http-methods.url-path=/webdav
```


## Lab

### Objectives
1.  Identify IIS Server
```
nmap -sS -sV 10.4.21.186 

80/tcp   open  http          Microsoft IIS httpd 10.0
```
   
2.  Get webserver header details
```
nmap -sS -sV 10.4.21.186 --script http-headers.nse

80/tcp   open  http          Microsoft IIS httpd 10.0
| http-headers: 
|   Cache-Control: private
|   Content-Type: text/html; charset=utf-8
|   Location: /Default.aspx
|   Server: Microsoft-IIS/10.0
|   Set-Cookie: ASP.NET_SessionId=ygxjoxqgst35y2mjflyvrk4y; path=/; HttpOnly; SameSite=Lax
|   X-AspNet-Version: 4.0.30319
|   Set-Cookie: Server=RE9UTkVUR09BVA==; path=/
|   X-XSS-Protection: 0
|   X-Powered-By: ASP.NET
|   Date: Mon, 15 Jul 2024 12:28:51 GMT
|   Connection: close
|   Content-Length: 130
|   
|_  (Request type: GET)
|_http-server-header: Microsoft-IIS/10.0

```
   
3.  Enumerated HTTP methods
```
nmap -sS -sV 10.4.21.186 --script http-enum.nse 

80/tcp   open  http          Microsoft IIS httpd 10.0
| http-enum: 
|   /content/: Potentially interesting folder
|   /downloads/: Potentially interesting folder
|_  /webdav/: Potentially interesting folder
|_http-server-header: Microsoft-IIS/10.0

```
   
4.  Detect WebDAV configuration - etc.
```
nmap 10.4.21.186 --script http-webdav-scan.nse

80/tcp   open  http          Microsoft IIS httpd 10.0
|_http-server-header: Microsoft-IIS/10.0
| http-webdav-scan: 
|   Server Type: Microsoft-IIS/10.0
|   Allowed Methods: OPTIONS, TRACE, GET, HEAD, POST, COPY, PROPFIND, LOCK, UNLOCK
|   Server Date: Mon, 15 Jul 2024 12:32:00 GMT
|   WebDAV type: Unknown
|_  Public Options: OPTIONS, TRACE, GET, HEAD, POST, PROPFIND, PROPPATCH, MKCOL, PUT, DELETE, COPY, MOVE, LOCK, UNLOCK

```
   

### Completed
1. IIS httpd 10.0 version  with downloads, contents and wedav folder
2. Some cookie information
3. Risky Methods: trace, copy, propfind, lock, unlock, proppatch, mkloc, put, delete, move
4. Allowed Methods: options, trace, get, head, post, copy, propfind, lock, unlock