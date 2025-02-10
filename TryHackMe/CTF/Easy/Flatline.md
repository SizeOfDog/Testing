https://tryhackme.com/r/room/flatline

```
┌──(root㉿kali)-[~]
└─# nmap -p 3389,8021 -sVC 10.10.48.23
Starting Nmap 7.93 ( https://nmap.org ) at 2025-02-03 18:29 UTC
Nmap scan report for ip-10-10-48-23.eu-west-1.compute.internal (10.10.48.23)
Host is up (0.0024s latency).

PORT     STATE SERVICE          VERSION
3389/tcp open  ms-wbt-server    Microsoft Terminal Services
| rdp-ntlm-info: 
|   Target_Name: WIN-EOM4PK0578N
|   NetBIOS_Domain_Name: WIN-EOM4PK0578N
|   NetBIOS_Computer_Name: WIN-EOM4PK0578N
|   DNS_Domain_Name: WIN-EOM4PK0578N
|   DNS_Computer_Name: WIN-EOM4PK0578N
|   Product_Version: 10.0.17763
|_  System_Time: 2025-02-03T18:29:50+00:00
|_ssl-date: 2025-02-03T18:29:52+00:00; 0s from scanner time.
| ssl-cert: Subject: commonName=WIN-EOM4PK0578N
| Not valid before: 2025-02-02T18:22:28
|_Not valid after:  2025-08-04T18:22:28
8021/tcp open  freeswitch-event FreeSWITCH mod_event_socket
MAC Address: 02:7F:75:A1:F5:5B (Unknown)
Service Info: OS: Windows; CPE: cpe:/o:microsoft:windows

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 18.22 seconds
                                                             
```
