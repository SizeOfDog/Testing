https://tryhackme.com/room/introtoav
## Antivirus Software

- Modern antivirus software looks for malware based on predefined signatures and patterns. 
- Antivirus software performs scanning, detecting and removing malicious files.
- McAfee starting the fist AV software in 1987. 
- Modern AVs support features that include Anti-exploitation, antivirus, firewall, encryption tools, etc

## Antivirus Features

Antivirus engines - Responsible for finding and removing malicious software. 

Scanner - Automated and manual scan of files to check for malicious file types. 

Detection Techniques -
- Signature based detection - searching for malicious patterns
- Heuristic based detection - uses behavioural methods to analyze files
- Dynamic detection - Monitors the system calls, and analyzes these calls and API in a isolated env. 

Compressors and Archives - A feature where the AV will decompress and check encrypted filed

PE Parsing and Unpackers
 - Malicious users utilize packers to shrink the initial payload to hide from AV solutions. 
 - AVs must use unpackers to unpack or decompress files. 
 - AVs must have PE header parser features, which is used to verify the legitimacy of a PE file or program. 

Emulators - A sandbox that runs programs to analyze the execution. Doing so checks for any malicious actions taken by the program, these include API calls, windows registry changes, memory dumps, web requests. 

Other common features 
 - Self protection driver 
 - Firewall and network inspection 
 - Command line and GUI tools
 - Management console
 - A daemon or service

## AV Static Detection 

#### Static Detection

- Static detection looks for matching techniques, checksums, finding a string, sequence of bytecode values, crypto hashes.  

#### ClamAV 

- ClamAV can be used to detect malicious files via static analysis. 
- ClamAV can use custom databases to scan files. 
- It can also be used with yara rules to scan for malicious files.
- In yara rules file types can be specified by checking the magic numbers in a file (The first couple of bytes)

## Other Detection Techniques

#### Dynamic Detection 

- The use of sandboxing and emulators while running files, checking for windows API calls and registry changes. 
- Malicious actors get around this by not executing malicious code while in the virtual environment. Once the program knows its not in an isolated environment it will run the malicious parts of the code. 

#### Heuristic and Behavioural Detection

- Heuristic is the process of decompiling, decompressing and unpacking code to its original source code. Only then does it try and match other source codes to verify if the file is malicious or not. 
- Behavioural is the process of removing software when it matches certain activities found from previous analyzed malware. 
## AV Testing and Fingerprinting

#### ShareEDRChecker 

- Used to check what AV or EDR applications are installed on  a system
- The program checks registry keys, ddl files, metadata, files and directories