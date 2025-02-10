## H4cked


It seems like our machine got hacked by an anonymous threat actor. However, we are lucky to have a .pcap file from the attack. Can you determine what happened? Download the .pcap file and use Wireshark to view it.  
```

```
``

The attacker is trying to log into a specific service. What service is this?  
```
FTP
```
``
There is a very popular tool by Van Hauser which can be used to brute force a series of services. What is the name of this tool?  
```
hydra
```
``
The attacker is trying to log on with a specific username. What is the username?  
```
Jenny
```
``
What is the user's password?  


```
password123
```
``
What is the current FTP working directory after the attacker logged in?  
![[current_directory.png]]

The attacker uploaded a backdoor. What is the backdoor's filename?  
```
shell.php
```
``
The backdoor can be downloaded from a specific URL, as it is located inside the uploaded file. What is the full URL?  
```
http://pentestmonkey.net/tools/php-reverse-shell
```
``
Which command did the attacker manually execute after getting a reverse shell?  
```
whoami
```
``
What is the computer's hostname?
```
wir3
```
``
Which command did the attacker execute to spawn a new TTY shell?
```
python -c 'import pty; pty.spawn("/bin/sh")'
```
``
Which command was executed to gain a root shell?  
```
sudo su
```
``
The attacker downloaded something from GitHub. What is the name of the GitHub project?  
```
Reptile
```
``
The project can be used to install a stealthy backdoor on the system. It can be very hard to detect. What is this type of backdoor called?```

```
Rootkit
```

#### Hack you way back into the machine


Run Hydra (or any similar tool) on the FTP service. The attacker might not have chosen a complex password. You might get lucky if you use a common word list.  

![[hydra_brute_force.png]]

Change the necessary values inside the web shell and upload it to the webserver  

```

```

Create a listener on the designated port on your attacker machine. Execute the web shell by visiting the .php file on the targeted web server.  

```

```

Become root!  

```

```

Read the flag.txt file inside the Reptile directory
```

```
