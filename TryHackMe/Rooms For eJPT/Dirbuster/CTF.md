fdk****
## OverPass


Scan target with nmap
```
nmap -p- -T 4 10.10.58.193

22/tcp open  ssh        
80/tcp open  http
```

Scan the open ports against specific versions and scripts
```

PORT   STATE SERVICE VERSION 
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0) 
| ssh-hostkey: 
|   2048 37:96:85:98:d1:00:9c:14:63:d9:b0:34:75:b1:f9:57 (RSA) 
|   256 53:75:fa:c0:65:da:dd:b1:e8:dd:40:b8:f6:82:39:24 (ECDSA) 
|_  256 1c:4a:da:1f:36:54:6d:a6:c6:17:00:27:2e:67:75:9c (ED25519) 
80/tcp open  http    Golang net/http server (Go-IPFS json-rpc or InfluxDB API) 
|_http-favicon: Unknown favicon MD5: 0D4315E5A0B066CEFD5B216C8362564B 
|_http-title: Overpass 
| http-methods: 
|_  Supported Methods: GET HEAD POST OPTIONS 
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```


```
http://10.10.58.193/aboutus/

Ninja - Lead Developer
Pars - Shibe Enthusiast and Emotional Support Animal Manager
Szymex - Head Of Security
Bee - Chief Drinking Water Coordinator
MuirlandOracle - Cryptography Consultant
```

![[Pasted image 20241005204256.png]]

![[Pasted image 20241005211222.png]]

![[Pasted image 20241005211326.png]]