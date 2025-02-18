
In this challenge we will look at the basics of SMB server reconnaissance. Please start the lab and answer the following questions:

Questions

1. Find the OS version of samba server using rpcclient.
```
 rpcclient --no-pass 192.109.31.3  -d 3 -V   
```
   
2. Find the OS version of samba server using enum4Linux.
```
 enum4linux -a 192.109.31.3 

    SAMBA-RECON    Wk Sv PrQ Unx NT SNT samba.recon.lab
        platform_id     :       500
        os version      :       6.1
        server type     :       0x809a03   
```
   
3. Find the server description of samba server using smbclient.
```

```
   
4. Is NT LM 0.12 (SMBv1) dialects supported by the samba server? Use appropriate nmap script.
 ```
nmap 192.109.31.3 --script smb-protocols.nse

yes

Host script results:
| smb-protocols: 
|   dialects: 
|     NT LM 0.12 (SMBv1) [dangerous, but default]
|     2.02
|     2.10
|     3.00
|     3.02
|_    3.11
```
   
   
5. Is SMB2 protocol supported by the samba server? Use smb2 metasploit module.
```
use auxiliary(scanner/smb/smb2)
set RHOSTS 192.109.31.3
exploit 

nmap 192.109.31.3 --script smb-os-discovery.nse

Host script results:
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: victim-1
|   NetBIOS computer name: SAMBA-RECON\x00
|   Domain name: \x00
|   FQDN: victim-1
|_  System time: 2024-07-14T23:58:56+00:00
[+] 192.109.31.3:445      - 192.109.31.3 supports SMB 2 [dialect 255.2] and has been online for 3712632 hours
```
   
6. List all users that exists on the samba server  using appropriate nmap script.
   
```
 nmap 192.109.31.3 --script smb-enum-users.nse
 
Host script results:
| smb-enum-users: 
|   SAMBA-RECON\admin (RID: 1005)
|     Full name:   
|     Description: 
|     Flags:       Normal user account
|   SAMBA-RECON\aisha (RID: 1004)
|     Full name:   
|     Description: 
|     Flags:       Normal user account
|   SAMBA-RECON\elie (RID: 1002)
|     Full name:   
|     Description: 
|     Flags:       Normal user account
|   SAMBA-RECON\emma (RID: 1003)
|     Full name:   
|     Description: 
|     Flags:       Normal user account
|   SAMBA-RECON\john (RID: 1000)
|     Full name:   
|     Description: 
|     Flags:       Normal user account
|   SAMBA-RECON\shawn (RID: 1001)
|     Full name:   
|     Description: 
|_    Flags:       Normal user account
```
   
7. List all users that exists on the samba server  using smb_enumusers metasploit modules.
```
use auxiliary(scanner/smb/smb_enumusers) 
set RHOSTS 192.109.31.3
exploit 

[+] 192.109.31.3:139      - SAMBA-RECON [ john, elie, aisha, shawn, emma, admin ] ( LockoutTries=0 PasswordMin=5 )
```
   
8. List all users that exists on the samba server  using enum4Linux.
```
 enum4linux -U 192.109.31.3
 
  ============================= 
|    Users on 192.109.31.3    |
 ============================= 
index: 0x1 RID: 0x3e8 acb: 0x00000010 Account: john     Name:   Desc: 
index: 0x2 RID: 0x3ea acb: 0x00000010 Account: elie     Name:   Desc: 
index: 0x3 RID: 0x3ec acb: 0x00000010 Account: aisha    Name:   Desc: 
index: 0x4 RID: 0x3e9 acb: 0x00000010 Account: shawn    Name:   Desc: 
index: 0x5 RID: 0x3eb acb: 0x00000010 Account: emma     Name:   Desc: 
index: 0x6 RID: 0x3ed acb: 0x00000010 Account: admin    Name:   Desc: 

user:[john] rid:[0x3e8]
user:[elie] rid:[0x3ea]
user:[aisha] rid:[0x3ec]
user:[shawn] rid:[0x3e9]
user:[emma] rid:[0x3eb]
user:[admin] rid:[0x3ed]
enum4linux complete on Mon Jul 15 00:18:07 2024
```
   
9. List all users that exists on the samba server  using rpcclient.
```
rpcclient -U "" -N 192.109.31.3
enumdomusers
```
   
10. Find SID of user “admin” using rpcclient.
```
rpcclient -U "" -N 192.109.31.3

admin S-1-5-21-4056189605-2085045094-1961111545-1005 (User: 1)
```