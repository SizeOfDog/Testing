
## Introduction

What command would you use to start the PowerShell interactive command line?
```
powershell.exe
```

## Purpose

In SSH key-based authentication, which key does the client need?
```
private key
```

## Linux Enumeration

List mailbox users 
```bash
ls -lh /var/mail
```

List installed applications on a Debian based machine
```bash
ls -al /usr/bin
ls -al /sbin/
dpkg -l 
```

Display any currently logged on users. 
A tty console means a user is directory logged into the machine. 
A pts console means that a user is logged in over the network. 
```bash
who
```

Display who is logged in and what commands they're running at that time. 
```bash 
w
```

Print current users details 
```bash 
id
```

See who logged in last and for how long 
```bash 
last
```

Display processes  using TCP 
```bash
netstat -plt 
```

Display network connections using both UDP and TCP
```bash
netstat -atupn
```

List open files utilizing a port
```bash
lsof -i 
```

List out all processes running on the machine
```
ps -ef
ps -e 
ps -el 
```

Display a pretty version of processes
```
ps axf
```

#### Questions

What is the name of the Linux distribution used in the VM?
```
Ubuntu
```

What is its version number?  
```
20.04.4
```

What is the name of the user who last logged in to the system?
```
randa
```

What is the highest listening TCP port number?
```
6667
```

What is the program name of the service listening on it?
```
inspircd
```

There is a script running in the background. Its name starts with `THM`. What is the name of the script?
```
THM-24765.sh
```

## Windows Enumeration 


Check installed updates
```powershell
wmic qfe get Caption,Description
```

List what privileges are given to the current user
```powershell
whoami /priv
```

List out which groups the current user belongs to
```powershell
whoami /groups 
```

List users on the current machine
```powershell
net user
```

List the groups available on Domain Joined Machine
```powershell
net group
```

List out local groups on the machine
```powershell
net localgroup
```

List out users that belong to a specific group
```powershell
net localgroup <group_name>
```

View the local settings on a machine
```powershell
net accounts
```

List out the settings when the machine is connected to a Domain
```powershell
net accounts /domain
```

List the current listening and active connections
a - is for all
n - is to not resolve names
o - is to display the process ID
b - list the binary
```powershell
netstat -abno
```

#### Questions 

What is the full OS Name?
```
Microsoft Windows Server 2019 Datacenter
```

What is the OS Version?
```
10.0.17763
```

How many hotfixes are installed on this MS Windows Server?  
```
30
```

What is the lowest TCP port number listening on the system?  
```
22
```

What is the name of the program listening on that port?
```
sshd.exe
```

## DNS, SMB, SNMP

Attempt a DNS Zone transfer with the dig command
```powershell
dig -t AXFR <domain_name> @<dns_server>
```

Check active shared folders 
```powershell
net share
```

Query target machine for SNMP related information
```
./snmpcheck-1.9.rb 10.10.177.242 -c public
```

## More Tools for Windows


Process Hacker

GhostPack Seatbelt