
## Network Infra

DMZ - The subnet between the internal network and public network. Often used to allow services to interact with unfiltered traffic. 

## AD Env

Confirm whether a machine is connected to a Domain
```
systeminfo
systeminfo | findstr Domain
```


#### Questions 

**Is the attached machine part of the AD environment? (Y|N)**  
```
Y
```

If it is part of an AD environment, **what is the domain name of the AD?**
```
thmredteam.com
```

## Users and Groups Management

#### AD Service Accounts

Built in local users - Accounts used to manage the local system, not part of the AD env. 

Domain User Accounts - Has access to the domain with verified credentials, for example a random employee of the company. 

AD Managed Service Accounts - User accounts allowed to manage AD services. 

Domain Administrators - Have authorization over all configuration inside of the domain.

#### AD Admin Accounts

Domain Admins - Access to all resources
Enterprise Admins - Available in the forest root ? 
Schema - Can modify the Domain/forest (does this mean services can't be created ? Only Altered ? )
Server Operators - Manage domain Servers
Account Operators - Can manage non privileged users

List out all AD Accounts
```powershell
Get-ADUser -Filter *
```

List out users with specific OU
In this case the organizational units are users, thmredteam and com 
```powershell
Get-ADUser -Filter * -SearchBase "CN=Users,DC=THMREDTEAM,DC=COM"
```


#### Questions 

Use the Get-ADUser -Filter * -SearchBase command to list the available user accounts within THM OU in the thmredteam.com domain. How many users are available?

```
6
```

Once you run the previous command, what is the UserPrincipalName (email) of the admin account?

```
thmadmin@thmredteam.com
```


## Host Security Solutions 1


Confirm whether Windows Defender is running or not
```powershell
Get-Service WinDefend
```

Confirm which features are enabled for Windows Defender
```powershell
Get-MpComputerStatus 
```

List out which Firewall Services are enabled
```powershell 
 Get-NetFirewallProfile
 Get-NetFirewallProfile | Format-Table Name, Enabled
```

List out all the firewall rules
This list is long and extensive, it may be a good idea to filter them via if they're Enabled
```powershell
Get-NetFirewallRule | select DisplayName, Enabled, Description
```

Command that can be used to test what inbound ports are open for connection
```powershell
 Test-NetConnection -ComputerName 127.0.0.1 -Port 80
```

#### Questions

Enumerate the attached Windows machine and check whether the host-based firewall is enabled or not! (Y|N)
```
N
```

Using PowerShell cmdlets such Get-MpThreat can provide us with threats details that have been detected using MS Defender. Run it and answer the following: What is the file name that causes this alert to record?
```powershell
Get-MpThreat
PowerView.ps1
```

Enumerate the firewall rules of the attached Windows machine. What is the port that is allowed under the **THM-Connection** rule?

```powershell
 Get-NetFirewallRule | Where-Object DisplayName -EQ "THM-Connection"

Name                  : {B594EB4B-1EFA-4F7A-A0F3-F90818D9B507}
DisplayName           : THM-Connection
Description           : THM-Connection inbound to 17337 Port!
DisplayGroup          :
Group                 :
Enabled               : True
Profile               : Any
Platform              : {}
Direction             : Inbound
Action                : Allow
EdgeTraversalPolicy   : Block
LooseSourceMapping    : False
LocalOnlyMapping      : False
Owner                 :
PrimaryStatus         : OK
Status                : The rule was parsed successfully from the store. (65536)
EnforcementStatus     : NotApplicable
PolicyStoreSource     : PersistentStore
PolicyStoreSourceType : Local
```

## Host Security Solutions 2

List out events that have occurred on the target machine
```powershell 
Get-EventLog -List
```

## Network Security Solutions

## Applications and Services

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

Get process information of the executable file
```powershell
Get-Process -Name <service_name>
```

Get port information of the process
```powershell
netstat -nao | findstr "Listening" | findstr "<process_id_of_service>"
```

Domain Transfer
```powershell
nslookup.exe
-> server <target_ip>
-> ls -d <domain_name>
```