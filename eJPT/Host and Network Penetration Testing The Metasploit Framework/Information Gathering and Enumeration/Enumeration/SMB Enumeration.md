- Shares Files
- Uses port 445 over TCP
- Originally on port 139
- Samba is the linux version of SMB

Set global RHOSTS
```
setg RHOSTS <target_ip_address>
```

Scan SMB server with auxiliary module
```
search type:auxiliary name:smb
use auxiliary/scanner/smb/smb_version
options
exploit
```

Enumerate SMB users
```
search type:auxiliary name:smb
use auxiliary/smb/smb_enumusers
exploit
```

Enumerate Shares
```
search type:auxiliary name:smb_shares
use auxiliary/scanner/smb_enumshares
set ShowFiles true
exploit
```

Brute force SMB login
```
search smblogin
use /auxiliary/scanner/smb/smb_login
set SMBUser admin
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
exploit
```

Login to SMB 
```
smbclient -L \\\\<target_ip_address>\\ -U admin 
smbclient -L \\\\<target_ip_address>\\<user> -U admin 
```

## Quiz

What SMB auxiliary module can be used to enumerate the SMB version?

	auxiliary/scanner/smb/smb_version
## Lab

```
192.53.52.3
```

1. Find the default tcp ports used by smbd.
```
nmap 192.53.52.3
445/tcp open  microsoft-ds   
```
   
2. Find the default udp ports used by nmbd.
```
nmap  192.53.52.3
139/tcp open  netbios-ssn
```
   
3. What is the workgroup name of samba server?
```
nmap -sV 192.53.52.3
workgroup: RECONLABS
```
   
4. Find the exact version of samba server by using appropriate nmap script.
```
nmap -sC -p 445 192.53.52.3  or nmap --script smb-os-discovery.nse  192.53.52.3
Samba 4.3.11-Ubuntu
```
   
5. Find the exact version of samba server by using smb_version metasploit module.
```
auxiliary(scanner/smb/smb_version
host could not be identified: Windows 6.1 (Samba 4.3.11-Ubuntu)
```   
   
6. What is the NetBIOS computer name of samba server? Use appropriate nmap scripts.
```
nmap -sC -p 139 192.53.52.3
SAMBA-RECON
```  
   
7. Find the NetBIOS computer name of samba server using nmblookup
```
nmblookup -A 192.53.52.3  
```   
   
8. Using smbclient determine whether anonymous connection (null session)  is allowed on the samba server or not.
```
smbclient -L 192.53.52.3
yes ? 
```   
   
9. Using rpcclient determine whether anonymous connection (null session) is allowed on the samba server or not.
```

```   
   

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.Z. Run "ip addr" to know the values of X and Y.
- The Target machine should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1

## Lab 

In this challenge we will look at the basics of SMB server reconnaissance. Please start the lab and answer the following questions:

```
192.156.192.3
```

Questions

1. Find the default tcp ports used by smbd.

```
use auxiliary(scanner/portscan/tcp


[+] 192.156.192.3:        - 192.156.192.3:139 - TCP OPEN
[+] 192.156.192.3:        - 192.156.192.3:445 - TCP OPEN
```

2. Find the default udp ports used by nmbd.
```
use auxiliary(scanner/discovery/udp_probe)

[+] Discovered NetBIOS on 192.156.192.3:137 (SAMBA-RECON:<00>:U :SAMBA-RECON:<03>:U :SAMBA-RECON:<20>:U :__MSBROWSE__:<01>:G :RECONLABS:<00>:G :RECONLABS:<1d>:U :RECONLABS:<1e>:G :00:00:00:00:00:00)
```   
   
3. What is the workgroup name of samba server?

```
SAMBA-RECON
```   
   
4. Find the exact version of samba server by using appropriate nmap script.

```

```   
   
5. Find the exact version of samba server by using smb_version metasploit module.

```
use auxiliary(scanner/smb/smb_version) 

[*] 192.156.192.3:445     - Host could not be identified: Windows 6.1 (Samba 4.3.11-Ubuntu)
```
7. What is the NetBIOS computer name of samba server? Use appropriate nmap scripts.
8. Find the NetBIOS computer name of samba server using nmblookup
9. Using smbclient determine whether anonymous connection (null session)  is allowed on the samba server or not.
10. Using rpcclient determine whether anonymous connection (null session) is allowed on the samba server or not.

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.Z. Run "ip addr" to know the values of X and Y.
- The Target machine should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1