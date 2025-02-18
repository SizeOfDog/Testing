
1. Find the default tcp ports used by smbd.
```
nmap  192.14.86.3

Host is up (0.000010s latency).
Not shown: 998 closed ports
PORT    STATE SERVICE
139/tcp open  netbios-ssn
445/tcp open  microsoft-ds
MAC Address: 02:42:C0:0E:56:03 (Unknown)
```
   
2. Find the default udp ports used by nmbd.
```
nmap -sU -T 4 -F   192.14.86.3

PORT    STATE SERVICE
137/udp open  netbios-ns
MAC Address: 02:42:C0:0E:56:03 (Unknown)
```
   
3. What is the workgroup name of samba server?
```
nmap --script smb-enum-domains.nse 192.14.86.3

Host script results:
| smb-enum-domains: 
|   SAMBA-RECON
|     Groups: Testing
|     Users: john, elie, aisha, shawn, emma, admin
|     Creation time: unknown
|     Passwords: min length: 5; min age: n/a days; max age: n/a days; history: n/a passwords
|     Account lockout disabled
|   Builtin
|     Groups: n/a
|     Users: n/a
|     Creation time: unknown
|     Passwords: min length: 5; min age: n/a days; max age: n/a days; history: n/a passwords
|_    Account lockout disabled
```
   
4. Find the exact version of samba server by using appropriate nmap script.
```
 nmap --script smb-os-discovery.nse 192.14.86.3

Host script results:
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: victim-1
|   NetBIOS computer name: SAMBA-RECON\x00
|   Domain name: \x00
|   FQDN: victim-1
|_  System time: 2024-07-12T11:26:07+00:00
```
   
5. Find the exact version of samba server by using smb_version metasploit module.
```
msf5 auxiliary(scanner/smb/smb_version) > options

Module options (auxiliary/scanner/smb/smb_version):

Name       Current Setting  Required  Description
----       ---------------  --------  -----------
RHOSTS     192.14.86.3      yes       The target address range or CIDR identifier
SMBDomain  .                no        The Windows domain to use for authentication
SMBPass                     no        The password for the specified username
SMBUser                     no        The username to authenticate as
THREADS    1                yes       The number of concurrent threads

msf5 auxiliary(scanner/smb/smb_version) > exploit

[*] 192.14.86.3:445       - Host could not be identified: Windows 6.1 (Samba 4.3.11-Ubuntu)
[*] 192.14.86.3:445       - Scanned 1 of 1 hosts (100% complete)
```
   
6. What is the NetBIOS computer name of samba server? Use appropriate nmap scripts.
```
 nmap --script smb-os-discovery.nse 192.14.86.3
 
Host script results:
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: victim-1
|   NetBIOS computer name: SAMBA-RECON\x00
|   Domain name: \x00
|   FQDN: victim-1
|_  System time: 2024-07-12T11:26:07+00:00
```
   
7. Find the NetBIOS computer name of samba server using nmblookup
```
 nmblookup -A 192.14.86.3

Looking up status of 192.14.86.3
        SAMBA-RECON     <00> -         H <ACTIVE> 
        SAMBA-RECON     <03> -         H <ACTIVE> 
        SAMBA-RECON     <20> -         H <ACTIVE> 
```
   
8. Using smbclient determine whether anonymous connection (null session)  is allowed on the 
   samba server or not.
```
 smbclient --no-pass  -L 192.14.86.3


Sharename       Type      Comment
---------       ----      -------
public          Disk      
john            Disk      
aisha           Disk      
emma            Disk      
everyone        Disk      
IPC$            IPC       IPC Service (samba.recon.lab)
Reconnecting with SMB1 for workgroup listing.

Server               Comment
---------            -------

Workgroup            Master
---------            -------
RECONLABS            SAMBA-RECON
```

9. Using rpcclient determine whether anonymous connection (null session) is allowed on the 
   samba server or not.
```
rpcclient --user RECONLABS\everyone 192.14.86.3
```