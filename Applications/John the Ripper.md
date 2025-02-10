
Crack SSH Keys
```bash
ssh2john <rsa_key_file> > hash.txt
/usr/sbin/john hash.txt --wordlist=<wordlist>
```


#### Configuration File

John the Ripper has config file located at /etc/john/john.conf 
There's a "List.Rules" section that contains predefined rules that can be used when cracking passwords

To list some default rules from John the Ripper, use the command below. 
```bash
cat /etc/john/john.conf|grep "List.Rules:" | cut -d"." -f3 | cut -d":" -f2 | cut -d"]" -f1 | awk NF
```



```

```