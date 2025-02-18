- Simple Mail Transfer Protocol 
- 25 By default or on 465/587 securely

## Quiz

## Lab

```
192.214.98.3
```

In this challenge we will look at the basics of Postfix SMTP server reconnaissance. Please start the lab and answer the following questions:

Questions

1. What is the SMTP server name and banner.
```
auxiliary(scanner/smtp/smtp_version)
92.214.98.3:25 SMTP 220 openmailbox.xyz ESMTP Postfix: Welcome to our mail server.\x0d\x0a
```
   
2. Connect to SMTP service using netcat and retrieve the hostname of the server (domain name).
```
nc 192.75.219.3 25

220 openmailbox.xyz ESMTP Postfix: Welcome to our mail server.
```
   
3. Does user “admin” exist on the server machine? Connect to SMTP service using netcat and check manually

yes
```
VRFY admin@openmailbox.xyz

252 2.0.0 admin
```
   
4. Does user “commander” exist on the server machine? Connect to SMTP service using netcat and check manually.

no
```
VRFY commander@openmailbox.xyz
550 5.1.1 <commander>: Recipient address rejected: User unknown in local recipient tabl
```
   
5. What commands can be used to check the supported commands/capabilities? Connect to SMTP service using telnet and check.
   

```
telnet 192.75.219.3 25 
HELO openmailbox.zyx
```
   
6. How many of the common usernames present in the dictionary /usr/share/commix/src/txt/usernames.txt exist on the server. Use smtp-user-enum tool for this task.
```
192.214.98.3:25 Users found: admin, administrator, mail, postmaster, sales, support, www-data
```
   
7. How many common usernames present in the dictionary /usr/share/metasploit-framework/data/wordlists/unix_users.txt exist on the server. Use suitable metasploit module for this task.
```
192.214.98.3:25 Users found: , admin, administrator, backup, bin, daemon, games, gnats, irc, list, lp, mail, man, news, nobody, postmaster, proxy, sync, sys, uucp, www-data
```
   
8. Connect to SMTP service using telnet and send a fake mail to root user.
```

```
   
9. Send a fake mail to root user using sendemail command.
```

```

Instructions: 

- This lab is dedicated to you! No other users are on this network :)
- Once you start the lab, you will have access to a root terminal of a Kali instance
- Your Kali has an interface with IP address 192.X.Y.Z. Run "ip addr" to know the values of X and Y.
- The Target machine should be located at the IP address 192.X.Y.3.
- Do not attack the gateway located at IP address 192.X.Y.1