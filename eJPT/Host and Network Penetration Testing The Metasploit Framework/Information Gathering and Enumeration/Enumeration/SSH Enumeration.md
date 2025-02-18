
## Quiz 

## Lab

```
192.185.195.3
```

In this lab, run the following auxiliary modules against the target:

- auxiliary/scanner/ssh/ssh_version
```
SSH server version: SSH-2.0-OpenSSH_7.9p1 Ubuntu-10 ( service.version=7.9p1 openssh.comment=Ubuntu-10 service.vendor=OpenBSD service.family=OpenSSH service.product=OpenSSH service.cpe23=cpe:/a:openbsd:openssh:7.9p1 os.vendor=Ubuntu os.family=Linux os.product=Linux os.version=19.04 os.cpe23=cpe:/o:canonical:ubuntu_linux:19.04 service.protocol=ssh fingerprint_db=ssh.banner )
```
  
- auxiliary/scanner/ssh/ssh_login
```
sysadmin:hailey
```
  

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.2. Run "ip addr" to know the values of X and Y.
- The target server should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1
- Use **/usr/share/metasploit-framework/data/wordlists/common_users.txt** username dictionary
- Use **/usr/share/metasploit-framework/data/wordlists/common_passwords.txt** password dictionary