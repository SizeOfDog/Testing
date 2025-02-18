
1. List all available shares on the samba server using Nmap script.
```
nmap 192.252.59.3 --script smb-enum-shares.nse


Host script results:
| smb-enum-shares: 
|   account_used: guest
|   \\192.252.59.3\IPC$: 
|     Type: STYPE_IPC_HIDDEN
|     Comment: IPC Service (samba.recon.lab)
|     Users: 1
|     Max Users: <unlimited>
|     Path: C:\tmp
|     Anonymous access: READ/WRITE
|     Current user access: READ/WRITE
|   \\192.252.59.3\aisha: 
|     Type: STYPE_DISKTREE
|     Comment: 
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\samba\aisha
|     Anonymous access: <none>
|     Current user access: <none>
|   \\192.252.59.3\emma: 
|     Type: STYPE_DISKTREE
|     Comment: 
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\samba\emma
|     Anonymous access: <none>
|     Current user access: <none>
|   \\192.252.59.3\everyone: 
|     Type: STYPE_DISKTREE
|     Comment: 
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\samba\everyone
|     Anonymous access: <none>
|     Current user access: <none>
|   \\192.252.59.3\john: 
|     Type: STYPE_DISKTREE
|     Comment: 
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\samba\john
|     Anonymous access: <none>
|     Current user access: <none>
|   \\192.252.59.3\public: 
|     Type: STYPE_DISKTREE
|     Comment: 
|     Users: 0
|     Max Users: <unlimited>
|     Path: C:\samba\public
|     Anonymous access: READ/WRITE
|_    Current user access: READ/WRITE
```
   
2. List all available shares on the samba server using smb_enumshares Metasploit module.
```
use auxiliary/scanner/smb/smb_enumshares/
set RHOSTS 192.252.59.3
exploit
```

3. List all available shares on the samba server using enum4Linux.
```
enum4linux -S 192.252.59.3

 ========================== 
|    Target Information    |
 ========================== 
Target ........... 192.252.59.3
RID Range ........ 500-550,1000-1050
Username ......... ''
Password ......... ''
Known Usernames .. administrator, guest, krbtgt, domain admins, root, bin, none


 ==================================================== 
|    Enumerating Workgroup/Domain on 192.252.59.3    |
 ==================================================== 
[+] Got domain/workgroup name: RECONLABS

 ===================================== 
|    Session Check on 192.252.59.3    |
 ===================================== 
[+] Server 192.252.59.3 allows sessions using username '', password ''

 =========================================== 
|    Getting domain SID for 192.252.59.3    |
 =========================================== 
Domain Name: RECONLABS
Domain Sid: (NULL SID)
[+] Can't determine if host is part of domain or part of a workgroup

 ========================================= 
|    Share Enumeration on 192.252.59.3    |
 ========================================= 

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

[+] Attempting to map shares on 192.252.59.3
//192.252.59.3/public   Mapping: OK, Listing: OK
//192.252.59.3/john     Mapping: DENIED, Listing: N/A
//192.252.59.3/aisha    Mapping: DENIED, Listing: N/A
//192.252.59.3/emma     Mapping: DENIED, Listing: N/A
//192.252.59.3/everyone Mapping: DENIED, Listing: N/A
//192.252.59.3/IPC$     [E] Can't understand response:
NT_STATUS_OBJECT_NAME_NOT_FOUND listing \*
enum4linux complete on Mon Jul 15 00:39:52 2024
```
   
4. List all available shares on the samba server using smbclient.
```
smbclient --no-pass -L 192.252.59.3

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
   
5. Find domain groups that exist on the samba server by using enum4Linux.
```
 enum4linux -G 192.252.59.3

[+] Got domain/workgroup name: RECONLABS
```
   
6. Find domain groups that exist on the samba server by using rpcclient.
```
rpcclient -U "" -N 192.252.59.3
enumdomgroups


group:[Maintainer] rid:[0x3ee]
group:[Reserved] rid:[0x3ef]

```
   
7. Is samba server configured for printing?
```
rpcclient -U "" -N 192.252.59.3
enumprinters

No printers returned.
```
   
8. How many directories are present inside share “public”?
```
smbclient //192.252.59.3/public -N 
ls 

2 
```
   
9. Fetch the flag from samba server.
```
smbclient //192.252/59.3/public -N 
ls
cd secret
more flag

03ddb97933e716f5057a18632badb3b4
```
   