
If you run systeminfo you'll be able to see the windows machine version
```
C:\Users\Administrator>systeminfo

Host Name:                 EC2AMAZ-I8UHO76
OS Name:                   Microsoft Windows Server 2016 Datacenter
OS Version:                10.0.14393 N/A Build 14393
```

I list out the users using net user. There are only two users on the machine that could've logged in last, I suspect it's the administrator. 
```
PS C:\Users\Administrator> Get-LocalUser

Name           Enabled Description
----           ------- -----------
Administrator  True    Built-in account for administering the computer/domain
DefaultAccount False   A user account managed by the system.
Guest          True    Built-in account for guest access to the computer/domain
Jenny          True
John           True
```

List out all users with their lastlogon and name with  the Get-LocalUser command. 
```
PS C:\Users\Administrator> Get-LocalUser | select LastLogon, Name

LastLogon            Name
---------            ----
1/22/2025 1:29:13 PM Administrator
                     DefaultAccount
                     Guest
                     Jenny
3/2/2019 5:48:32 PM  John
```

List out the users that are part of the localgroup Administrators
```
PS C:\Users\Administrator> net localgroup Administrators
Alias name     Administrators
Comment        Administrators have complete and unrestricted access to the computer/domain

Members

-------------------------------------------------------------------------------
Administrator
Guest
Jenny
The command completed successfully.
```

The the directory C:\Users\Administrator\Downloads\
```
Administrator:500:NO PASSWORD*********************:31D6CFE0D16AFA21B73C59D7E02A89C0:::
Guest:501:NO PASSWORD*********************:NO PASSWORD*********************:::
trinity:1002:NO PASSWORD*********************:A4A9436B46F7E948A2427335B6322C5C:::
HomeGroupUser$:1006:NO PASSWORD*********************:E37B4DD2729A37EB5C581C8B9D70153C:::
```

List scheduled tasks to look for the malicious task
```
PS C:\Users\Administrator> Get-ScheduledTask

TaskPath                                       TaskName                          State
--------                                       --------                          -----
\                                              Amazon Ec2 Launch - Instance I... Disabled
\                                              check logged in                   Ready
\                                              Clean file system                 Ready
\                                              falshupdate22                     Ready
\                                              GameOver                          Ready
\                                              update windows                    Ready
```

Display what actions the malicious task is executing. 
```
PS C:\Users\Administrator> $task = Get-ScheduledTask | Where TaskName -eq "Clean file system"
PS C:\Users\Administrator> $task.Actions


Id               :
Arguments        : -l 1348
Execute          : C:\TMP\nc.ps1
WorkingDirectory :
PSComputerName   :
```
##### Questions

Whats the version and year of the windows machine?  
```
Windows Server 2016
```

Which user logged in last?  
```
Administrator
```

When did John log onto the system last?
Answer format: MM/DD/YYYY H:MM:SS AM/PM
```
02/02/2019
```

What IP does the system connect to when it first starts?  
```
10.34.2.3
```

What two accounts had administrative privileges (other than the Administrator user)?
Answer format: username1, username2
```
Jenny, Guest
```

Whats the name of the scheduled task that is malicous.  
```
Clean file system
```

What file was the task trying to run daily?  
```
nc.ps1
```

What port did this file listen locally for?  
```
1348
```

When did Jenny last logon?  
```

```

At what date did the compromise take place?
Answer format: MM/DD/YYYY
```

```

During the compromise, at what time did Windows first assign special privileges to a new logon?
Answer format: MM/DD/YYYY HH:MM:SS AM/PM
```

```

What tool was used to get Windows passwords?  
```

```

What was the attackers external control and command servers IP?  
```

```

What was the extension name of the shell uploaded via the servers website?  
```

```

What was the last port the attacker opened?  
```

```

Check for DNS poisoning, what site was targeted?
```

```
