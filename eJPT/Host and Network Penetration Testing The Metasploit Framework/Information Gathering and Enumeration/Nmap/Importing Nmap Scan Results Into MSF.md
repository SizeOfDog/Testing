
Create new workspace
```
workspace -a <workspace_name>
```

Import scan results 
```
db_import <nmap_path>
```

Test that data has been imported by running the **hosts** command
```
hosts
```

Display the **services** from the nmap file
```
services
```

Create new workspace for nmap scan 
```
workspace -a nmap
```

Initiate nmap scan from msfconsole
```
db_nmap -Pn -sV -O <target_ip_address>
```

The same results are displayed as if you were running the namp command in the regular terminal

List out vulns of nmap scan
```
vulns
```

## Tools
- msfconsole
- db_map

## Quiz
Which one of the following MSFconsole commands can be used to import external Nmap scan results in to the Metasploit Framework database?

	db_import


## Lab