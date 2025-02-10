
## Futher Nmap
[https://tryhackme.com/room/furthernmap](https://tryhackme.com/room/furthernmap)

## NMAP 01
[https://tryhackme.com/room/nmap01](https://tryhackme.com/room/nmap01)

How many devices can see the ARP Request?
```
4
```

Did computer6 receive the ARP Request? (Y/N)
```
N
```

How many devices can see the ARP Request?
```
4
```

Did computer6 reply to the ARP Request? (Y/N)
```
Y
```


#### Discovering Live Hosts

What is the type of packet that computer1 sent before the ping?
```
ARP Request
```

What is the type of packet that computer1 received before being able to send the ping?
```
ARP Response
```

How many computers responded to the ping request?
```
1
```

What is the name of the first device that responded to the first ARP Request?
```
router
```

What is the name of the first device that responded to the second ARP Request?
```
computer5
```

Send another Ping Request. Did it require new ARP Requests? (Y/N)
```
N
```

#### Nmap Host Discovery Using ARP


```

```

## Ice
[https://tryhackme.com/room/ice](https://tryhackme.com/room/ice)

#### Recon

Scan target for open ports
```
nmap -p- -T 4 -v 10.10.105.61
```

Once the scan completes, we'll see a number of interesting ports open on this machine. As you might have guessed, the firewall has been disabled (with the service completely shutdown), leaving very little to protect this machine. One of the more interesting ports that is open is Microsoft Remote Desktop (MSRDP). What port is this open on?
```
3389
```

What service did nmap identify as running on port 8000? (First word of this service)
```
Icecast
```

What does Nmap identify as the hostname of the machine? (All caps for the answer)
```
Dark-PC
```

#### Gain Access 

Now that we've identified some interesting services running on our target machine, let's do a little bit of research into one of the weirder services identified: Icecast. Icecast, or well at least this version running on our target, is heavily flawed and has a high level vulnerability with a score of 7.5 (7.4 depending on where you view it). What is the **Impact Score** for this vulnerability? Use [https://www.cvedetails.com](https://www.cvedetails.com) for this question and the next.
```
6.4
```

What is the CVE number for this vulnerability? This will be in the format: CVE-0000-0000
```
CVE-2004-1561
```

fter Metasploit has started, let's search for our target exploit using the command 'search icecast'. What is the full path (starting with exploit) for the exploitation module? If you are not familiar with metasploit, take a look at the [Metasploit](https://tryhackme.com/module/metasploit) module.
```
exploit/windows/http/icecast_header
```


Following selecting our module, we now have to check what options we have to set. Run the command `show options`. What is the only required setting which currently is blank?
```
rhosts
```


```

```

#### Escalate

Woohoo! We've gained a foothold into our victim machine! What's the name of the shell we have now?
```
meterpreter
```


```

```

#### Looting

Prior to further action, we need to move to a process that actually has the permissions that we need to interact with the lsass service, the service responsible for authentication within Windows. First, let's list the processes using the command `ps`. Note, we can see processes being run by NT AUTHORITY\SYSTEM as we have escalated permissions (even though our process doesn't). 
```
ps 

0     0     [System Process]
 4     0     System
 396   696   svchost.exe
 416   4     smss.exe
 548   540   csrss.exe
 596   540   wininit.exe
 608   588   csrss.exe 
 ....
 ...
 ...


```

In order to interact with lsass we need to be 'living in' a process that is the same architecture as the lsass service (x64 in the case of this machine) and a process that has the same permissions as lsass. The printer spool service happens to meet our needs perfectly for this and it'll restart if we crash it! What's the name of the printer service?

Mentioned within this question is the term 'living in' a process. Often when we take over a running program we ultimately load another shared library into the program (a dll) which includes our malicious code. From this, we can spawn a new thread that hosts our shell. 
```
spoolsv.exe
```

Migrate to this process now with the command `migrate -N PROCESS_NAME`
```
migrate -N spoolsv.exe
```

Let's check what user we are now with the command `getuid`. What user is listed?
```
NT AUTHORITY\SYSTEM
```

Now that we've made our way to full administrator permissions we'll set our sights on looting. Mimikatz is a rather infamous password dumping tool that is incredibly useful. Load it now using the command `load kiwi` (Kiwi is the updated version of Mimikatz)
```
load kiwi
```

Loading kiwi into our meterpreter session will expand our help menu, take a look at the newly added section of the help menu now via the command `help`. 
```
creds_all
```

Which command allows up to retrieve all credentials?
```
Password01!
```

Run this command now. What is Dark's password? Mimikatz allows us to steal this password out of memory even without the user 'Dark' logged in as there is a scheduled task that runs the Icecast as the user 'Dark'. It also helps that Windows Defender isn't running on the box ;) (Take a look again at the ps list, this box isn't in the best shape with both the firewall and defender disabled)

#### Post Exploitation

Before we start our post-exploitation, let's revisit the help menu one last time in the meterpreter shell. We'll answer the following questions using that menu.


What command allows us to dump all of the password hashes stored on the system? We won't crack the Administrative password in this case as it's pretty strong (this is intentional to avoid password spraying attempts)
```
hashdump
```

While more useful when interacting with a machine being used, what command allows us to watch the remote user's desktop in real time?
```
screenshare
```

How about if we wanted to record from a microphone attached to the system?
```
record_mic
```

To complicate forensics efforts we can modify timestamps of files on the system. What command allows us to do this? Don't ever do this on a pentest unless you're explicitly allowed to do so! This is not beneficial to the defending team as they try to breakdown the events of the pentest after the fact.
```
timestomp
```

Mimikatz allows us to create what's called a `golden ticket`, allowing us to authenticate anywhere with ease. What command allows us to do this?

Golden ticket attacks are a function within Mimikatz which abuses a component to Kerberos (the authentication system in Windows domains), the ticket-granting ticket. In short, golden ticket attacks allow us to maintain persistence and authenticate as any user on the domain.
```
golden_ticket_create
```

One last thing to note. As we have the password for the user 'Dark' we can now authenticate to the machine and access it via remote desktop (MSRDP). As this is a workstation, we'd likely kick whatever user is signed onto it off if we connect to it, however, it's always interesting to remote into machines and view them as their users do. If this hasn't already been enabled, we can enable it via the following Metasploit module: `run post/windows/manage/enable_rdp`



## RustScan
[https://tryhackme.com/room/rustscan](https://tryhackme.com/room/rustscan)

#### Installing RustScan

#### Accessible 

#### Fast 

#### Extensible 

What is the scripting file config called?
```
.rustscan_scripts.toml
```

Can you run other binaries with RustScan? (T)rue / (F)alse.
```
T
```

Does RutScan support scripts in Javascript? (T)rue / (F)alse.
```
F
```

#### Adaptive

#### Scanning Time 

Try running the scan for all ports.
```
./rustscan  -r 1-65535  -a 10.10.3.36 -- -sV 

PORT   STATE SERVICE REASON         VERSION
22/tcp open  ssh     syn-ack ttl 64 OpenSSH 6.6.1p1 Ubuntu 2ubuntu2.10 (Ubuntu Linux; protocol 2.0)
80/tcp open  http    syn-ack ttl 64 Apache httpd 2.4.7 ((Ubuntu))
MAC Address: 02:D8:F3:FB:5E:C5 (Unknown)
```

After scanning this, how many ports do we find open under 1000?
```
2
```

Perform a service version detection scan, what is the version of the software running on port 22?  
```
6.6.1p1
```

Perform an aggressive scan, what flag isn't set under the results for port 80?  
```
./rustscan  -r 1-65535  -a 10.10.3.36 -- -A 

httponly
```


Using this tool in scanning can save a lot of time! Make sure to use it in your pentest.

#### RustScan Quiz

First, how do you access the help menu?
```
-h
```

Often referred to as "quiet" mode, What switch can do this?
```
-q
```

Which switch can help us to scan for a particular Range?
```
-r
```

What switch would you use to find out RustScan's version?
```
-v 
```

Which switch will help us to select batch size?
```
-b
```

Which switch can set timeout?
```
-t
```
