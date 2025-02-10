
## Shell Overview

What is the command-line interface that allows users to interact with an operating system?  
```
Shell
```

What process involves using a compromised system as a launching pad to attack other machines in the network?  
```
pivoting
```

What is a common activity attackers perform after obtaining shell access to escalate their privileges?
```
Privilege Escalation
```

## Reverse Shell 

What type of shell allows an attacker to execute commands remotely after the target connects back?  
```
reverse shell
```

What tool is commonly used to set up a listener for a reverse shell?
```
netcat
```

## Bind Shell

What type of shell allows an attacker to execute commands remotely after the target connects back?  
```
bind shell
```

What tool is commonly used to set up a listener for a reverse shell?
```
1024
```

## Shell Listeners

Rlwrap - Allows for better interaction through a shell
the history function ? and arrow keys are supported
```
rlwrap nc -lvnp 443 
```

ncat - Created by the same team behind nmap, allows for ssl connections. 
```
ncat --ssl lvnp 4444
```

socat - Creates a socket connection on the a machine
-d -d is for verbose
```
 socat -d -d TCP-LISTEN:443 STDOUT
```
#### Questions

Which flexible networking tool allows you to create a socket connection between two data sources?  
```
socat
```

Which command-line utility provides readline-style editing and command history for programs that lack it, enhancing the interaction with a shell listener?  
```
rlwrap
```

What is the improved version of Netcat distributed with the Nmap project that offers additional features like SSL support for listening to encrypted shells?
```
socat
```
## Shell Payloads

Which Python module is commonly used for managing shell commands and establishing reverse shell connections in security assessments?  
```
subprocess
```

What shell payload method in a common scripting language uses the `exec`, `shell_exec`, `system`, `passthru`, and `popen` functions to execute commands remotely through a TCP connection?  
```
php
```

Which scripting language can use a reverse shell by exporting environment variables and creating a socket connection?
```
python
```

## Web Shell

What vulnerability type allows attackers to upload a malicious script by failing to restrict file types?  
```
unrestricted file upload
```

What is a malicious script uploaded to a vulnerable web application to gain unauthorized access?
```
web shell
```
## Practical Task

## Conclusion