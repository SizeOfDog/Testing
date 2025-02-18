#### Tools 
ip a 
ping 
nmap 

#### Commands
```
nmap target_ip -p 21 --script ftp-anon
```


## Lab VSFTPD Recon:Basics

### Questions
1.  Find the version of vsftpd server.

```
nmap -sS -sV  192.56.240.3

vsftpd 3.0.3
```

2.  Check whether anonymous login is allowed on the ftp server using nmap script.

```
ftp 

21/tcp open  ftp
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
| -rw-r--r--    1 ftp      ftp            33 Dec 18  2018 flag
|_drwxr-xr-x    2 ftp      ftp          4096 Dec 18  2018 pub
```

3.  Fetch the flag from FTP server.

```
ftp 192.56.240.3

username=anonymous
password=

get flag
4267bdfbff77d7c2635e4572519a8b9c
```

### Answers
1. 3.0.3
2. Anonymous login is allowed
3. 4267bdfbff77d7c2635e4572519a8b9c