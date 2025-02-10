## Enumeration

#### System

Enumerate OS Information 
```
ls -al /etc/*-release
```

#### Users 

List mailbox users 
```bash
ls -lh /var/mail
```

List installed applications on a Debian based machine
```bash
ls -al /usr/bin
ls -al /sbin/
dpkg -l 
```

Display any currently logged on users. 
A tty console means a user is directory logged into the machine. 
A pts console means that a user is logged in over the network. 
```bash
who
```

Display who is logged in and what commands they're running at that time. 
```bash 
w
```

Print current users details 
```bash 
id
```

See who logged in last and for how long 
```bash 
last
```
#### Networking

Display processes  using TCP 
```bash
netstat -plt 
```

Display network connections using both UDP and TCP
```bash
netstat -atupn
```

List open files utilizing a port
```bash
lsof -i 
```


#### Running Services

Display a pretty version of processes
```bash 
ps axf
```

Display processes created by a certain user
```bash 
ps -ef | grep <username>
```

