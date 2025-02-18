
- Nmap is free and open source
- Enumeration - To gather as much information as possible in an active way

#### Commands

Scan specific target
```
nmap <target_ip_address>
```

If target is blocking pinging, use -Pn command
```
nmap -Pn <target_ip_address>
```

Enumerate services version
```
nmap -sV <target_ip_address>
```

Enumerate OS version
```
nmap -O <target_ip_address>
```

Print nmap scan to output
```
nmap <target_ip_address> -oX <file_name>
```

## Quiz

Which one of the following Nmap scans can be used to output scan results in to XML?

	nmap -sV -O 10.10.10.1 -oX output


## Lab

A Kali GUI machine and a target machine are provided to you. The target machine is running a Windows Firewall. 

Your task is to discover available live hosts and their open ports using Nmap and identify the running services and applications.

Instructions:

- Your Kali machine has an interface with IP address 10.10.X.Y. Run “ip addr” to know the values of X and Y.
- The IP address of the target machine is mentioned in the file “/root/Desktop/target”
- Do not attack the gateway located at IP address 192.V.W.1 and 10.10.X.1

