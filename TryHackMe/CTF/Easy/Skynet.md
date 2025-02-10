
```
└─# nmap -p- 10.10.225.55 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 16:52 UTC
Nmap scan report for ip-10-10-225-55.eu-west-1.compute.internal (10.10.225.55)
Host is up (0.0068s latency).
Not shown: 65529 closed tcp ports (reset)
PORT    STATE SERVICE
22/tcp  open  ssh
80/tcp  open  http
110/tcp open  pop3
139/tcp open  netbios-ssn
143/tcp open  imap
445/tcp open  microsoft-ds
MAC Address: 02:FB:55:FC:D9:F5 (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 3.93 seconds

```

```
└─# nmap -p 22,80,110,139,143,445 -sVC 10.10.225.55
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 16:58 UTC
Nmap scan report for ip-10-10-225-55.eu-west-1.compute.internal (10.10.225.55)
Host is up (0.00047s latency).

PORT    STATE SERVICE     VERSION
22/tcp  open  ssh         OpenSSH 7.2p2 Ubuntu 4ubuntu2.8 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 992331bbb1e943b756944cb9e82146c5 (RSA)
|   256 57c07502712d193183dbe4fe679668cf (ECDSA)
|_  256 46fa4efc10a54f5757d06d54f6c34dfe (ED25519)
80/tcp  open  http        Apache httpd 2.4.18 ((Ubuntu))
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Skynet
110/tcp open  pop3        Dovecot pop3d
|_pop3-capabilities: CAPA TOP UIDL PIPELINING AUTH-RESP-CODE SASL RESP-CODES
139/tcp open  netbios-ssn Samba smbd 3.X - 4.X (workgroup: WORKGROUP)
143/tcp open  imap        Dovecot imapd
|_imap-capabilities: LITERAL+ more Pre-login ID have LOGIN-REFERRALS LOGINDISABLEDA0001 listed capabilities OK IDLE SASL-IR IMAP4rev1 post-login ENABLE
445/tcp open  netbios-ssn Samba smbd 4.3.11-Ubuntu (workgroup: WORKGROUP)
MAC Address: 02:FB:55:FC:D9:F5 (Unknown)
Service Info: Host: SKYNET; OS: Linux; CPE: cpe:/o:linux:linux_kernel

Host script results:
| smb2-security-mode: 
|   311: 
|_    Message signing enabled but not required
|_clock-skew: mean: 1h59m59s, deviation: 3h27m50s, median: 0s
| smb-security-mode: 
|   account_used: guest
|   authentication_level: user
|   challenge_response: supported
|_  message_signing: disabled (dangerous, but default)
|_nbstat: NetBIOS name: SKYNET, NetBIOS user: <unknown>, NetBIOS MAC: 000000000000 (Xerox)
| smb-os-discovery: 
|   OS: Windows 6.1 (Samba 4.3.11-Ubuntu)
|   Computer name: skynet
|   NetBIOS computer name: SKYNET\x00
|   Domain name: \x00
|   FQDN: skynet
|_  System time: 2024-11-15T10:58:20-06:00
| smb2-time: 
|   date: 2024-11-15T16:58:20
|_  start_date: N/A

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 12.41 seconds
```



![[Pasted image 20241115174441.png]]

![[Pasted image 20241115174524.png]]


```
enum4linux -a 10.10.204.102
********
       Sharename       Type      Comment 
       ---------       ----      ------- 
       print$          Disk      Printer Drivers  
       anonymous       Disk      Skynet Anonymous Share 
       milesdyson      Disk      Miles Dyson Personal Share 
       IPC$            IPC       IPC Service (skynet server (Samba, Ubuntu))                            │  
Reconnecting with SMB1 for workgroup listing.                                                            │  
       Server               Comment
       Workgroup            Master│
       WORKGROUP            SKYNET│
```

![[Pasted image 20241115174254.png]]

![[Pasted image 20241115174205.png]]

```
smbclient //10.10.204.102/anonymous -N 
dir
get attention.txt
cd logs 
get log1.txt 
get log2.txt 
get log3.txt
```

```
┌──(root㉿6e7549723f35)-[/]  
└─# cat log1.txt    
cyborg007haloterminator  
terminator22596  
terminator219  
terminator20  
terminator1989  
terminator1988  
terminator168  
terminator16  
terminator143  
terminator13  
terminator123!@#  
terminator1056  
terminator101  
terminator10  
terminator02  
terminator00  
roboterminator  
pongterminator  
manasturcaluterminator  
exterminator95  
exterminator200  
dterminator  
djxterminator  
dexterminator  
determinator  
cyborg007haloterminator  
avsterminator  
alonsoterminator  
Walterminator  
79terminator6  
1996terminator
```

![[Pasted image 20241115174137.png]]

```
We have changed your smb password after system malfunction.<br>Password: )s{A&2Z=F^n_E.B`
```

From the SMB share for the user milesdyson
```
┌──(root㉿6e7549723f35)-[~/Downloads]  
└─# cat *.txt    
This is everything I managed to recover from the target machine before my computer crashed... See if you can crack the hash so we can at least salvage a password to try and get back in.  
  
root:x:0:0::/root:/bin/bash  
root:$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/:18576::::::  
  
joker:7bf6d9bb82bed1302f331fc6b816aada  
  
1. Add features to beta CMS /45kra24zxs28v3yd  
2. Work on T-800 Model 101 blueprints  
3. Spend more time with my wife  
5460C85BD858A11475115D2DD3A82333  
root:x:0:0::/root:/bin/bash  
root:$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/:18576::::::  
root:$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/:0:0::/root:/bin/bash
```


```
┌──(root㉿kali)-[~]
└─# smbclient //10.10.229.12/milesdyson -U milesdyson                 
Password for [WORKGROUP\milesdyson]:
Try "help" to get a list of possible commands.
smb: \> dir 
  .                                   D        0  Tue Sep 17 09:05:47 2019
  ..                                  D        0  Wed Sep 18 03:51:03 2019
  Improving Deep Neural Networks.pdf      N  5743095  Tue Sep 17 09:05:14 2019
  Natural Language Processing-Building Sequence Models.pdf      N 12927230  Tue Sep 17 09:05:14 2019
  Convolutional Neural Networks-CNN.pdf      N 19655446  Tue Sep 17 09:05:14 2019
  notes                               D        0  Tue Sep 17 09:18:40 2019
  Neural Networks and Deep Learning.pdf      N  4304586  Tue Sep 17 09:05:14 2019
  Structuring your Machine Learning Project.pdf      N  3531427  Tue Sep 17 09:05:14 2019
```

serenakogan@skynet
```

```
#### Questions

What is Miles password for his emails?
```
cyborg007haloterminator
```

What is the hidden directory?
```
/45kra24zxs28v3yd
```

What is the vulnerability called when you can include a remote file for malicious purposes?
```
remote file inclusion 
```

What is the user flag?  
```

```

What is the root flag?
```

```
