#### Tools
nmap
web browser
whatweb
http 
dirb
browsh 

#### Commands

Get information on web server
```
whatweb target_ip
```

Send http request to get server information
```
http target_ip
```

Directory search with dirb
```
dirb http://target_ip
```

Website enumeration
```
browsh --startup-url http://target_ip/Default.aspx
```

## Lab 

### Tasks
A Kali GUI machine and a target machine running an IIS service are provided to you. The IP address of the target machine is provided in a text file named target placed on the Desktop of the Kali machine (/root/Desktop/target). 

Your task and objective are to fingerprint the service using the tools available on the Kali machine (WhatWeb, Dirb, Browsh) and extract target server information.

