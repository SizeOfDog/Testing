#### MSF Module Variables

LHOST - Local IP address
LPORT - Local Port 
RHOST - Remote IP Address or Target IP Address
RHOSTS - Multiple Remote Address 
RPORT - Remote Port 

#### Commands 

In MSF Console search for exploits by cve date, module type, and os type
```
search cve:2017 type:exploit platform:windows
```

## Quiz

Which one of the following MSFconsole commands can be used to set the global variable value for the RHOSTS option?

	setg RHOSTS 10.10.10.20

What MSFconsole search query can be used to limit the results to only display modules compatible with Windows?

	search type:exploit platform:windows