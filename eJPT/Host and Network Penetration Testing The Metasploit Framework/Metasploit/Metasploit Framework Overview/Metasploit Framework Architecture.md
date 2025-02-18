#### Modules
 - Exploit - Takes advantage of a vuln.
 - Payload - Executed code that is delivered to a target after successful exploitation. 
 - Encoder - Encodes payload to avoid AV/EDR/XDR detection. 
 - NOPS - Ensures payload size are consistent and stable when executed ? 
 - Auxiliary - Used for additional functionality, can't be paired with a payload, like port scanning

#### Payloads
- Non-Staged Payload - Sent along with an exploit
- Staged Payload (2 parts)- 
	- stager, contains payload to establish a connection to the target
	- stage - Download the second payload

#### MSF File System Structure 

- Module Location -> /usr/share/metasploit-framework/modules
- User Modules -> ~/.msf/modules

## Quiz

What programming language is used to develop MSF modules?
	Ruby
What directory is the Metasploit Framework installed in by default on Kali Linux?
	usr/share/metasploit-framework
Encoders are used to encode payloads with the aim of evading signature based AVs.
	True
