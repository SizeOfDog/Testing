
## General Commands 

Display all of the strings found in a file
```
strings <file_name>
```

Measure how many lines are in a file
```
Measure-Object -Line
```

## Enumeration
#### Domain Controller Specific

List all AD Users
```powershell
Get-ADUser -Filter *
```

List out system information related to the domain on the target machine
```powershell
systeminfo | findstr Domain
```


#### Antivirus Scanning

Confirm whether Windows Defender is running or not
```powershell
Get-Service WinDefend
```

Confirm which features are enabled for Windows Defender
```powershell
Get-MpComputerStatus 
```

Get information on past alerts created by the windows defender service
```powershell
Get-MpThreat
```
#### Firewall and Network 

This list is long and extensive, it may be a good idea to filter them via if they're Enabled
```powershell
Get-NetFirewallRule | select DisplayName, Enabled, Description
```

Command that can be used to test what inbound ports are open for connection
```powershell
 Test-NetConnection -ComputerName 127.0.0.1 -Port 80
```

List the current listening and active connections
a - is for all
n - is to not resolve names
o - is to display the process ID
b - list the binary
```powershell
netstat -abno
```

Attempt a DNS Zone transfer with the dig command
```powershell
dig -t AXFR <domain_name> @<dns_server>
```

Check active shared folders 
```powershell
net share
```


```

```

#### Applications and Services

List out the currently installed applications on a target machine
```powershell
 wmic product get name,version
```

List out running services on a windows machine
These don't include non running services that could be potentially turned on to be exploited ? 
```powershell
net start
```

Get the path of the service executable
```powershell
 wmic service where "name like '<service_name>'" get Name,PathName
```

List all processes running
```
Get-Process * 
```


Get process information of the executable file
```
Get-Process -Name <service_name>
```

Get port information of the process
```
netstat -nao | findstr "Listening" | findstr "<process_id_of_service>"
```

Domain Transfer
```powershell
nslookup.exe
-> server <target_ip>
-> ls -d <domain_name>
```

Query target machine for SNMP related information
snmpcheck may not be currently installed on the machien. 
It can be installed via gitlab.com. 
```
./snmpcheck-1.9.rb <ip_address> -c <shared_folder_name>
```
#### Updates

Check installed updates
```powershell
wmic qfe get Caption,Description
```

#### Users and Groups

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

List out users on a windows machine, their last logon date along with their name
```
Get-LocalUser | select LastLogon, Name
```



## Privilege Escalation

## Local Persistence

## Lateral Movement and Pivoting

## Data Exfiltration 

