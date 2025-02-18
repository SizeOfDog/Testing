#### Alternative Data Stream
	- Attribute of NTFS (New Technology File System)
	- Data Stream 
		- Contains data of the file
	- Resouce Stream
		- Metadata (Information of the data)
	- Used to hide malicious code or executable in files
	- Hide code in resource stream to evade detection



### Tools
winPEAS - Scans which applications can be used to elevate privileges

#### Commands

Create hidden file within file
```
notepad current_file.txt:hidden_file.txt
```

Hide Payload within txt file
```
type payload.exe > cover_file.txt:payload.exe
```

Create symbolic link between wupdate command and secert executable
```
mklink wupdate.exe \path\to\file\file:hidden_file.exe 
```

