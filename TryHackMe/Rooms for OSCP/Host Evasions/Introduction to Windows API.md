
## Subsystem and Hardware Interaction

#### Questions

Does a process in the user mode have direct hardware access? (Y/N)
```
N
```

Does launching an application as an administrator open the process in kernel mode? (Y/N)
```
N
```

## Components of the Windows API

- API  - a term to describe any interaction with the Windows 32 API ? 
- Header files or Imports -  Defines libraries to be imported, defined by header files ? e.g. <name_of_header.h>
- Core DDLs  - Four DLLs that define call structure ? KERNEL32, USER32, ADVAPI32, not contained in a single subsystem
- Supplemental DLLs - Controls separate subsystems of the Windows OS
- Call Structures - Defines the API call itself ? I'm assuming a skeleton or a function with optional parameters ? 
- API Calls  - When the API is used within a program, by utilizing it's address from a pointer
- In/Out Parameters - parameter values by the call structures

## OS Libraries

- API calls reside in memory, which require a pointer to a memory address
- These memory addresses are blocked by Address Space Layout Randomization (ASLR)


#### Windows Header File

- Windows utilizes a header file, the windows.h file, to implement or resolve ASLR ? 
- Is this just an easy method to implement ASLR, I didn't think ASLR was an issue, more so a security feature


#### P/Invoke 

- Allows the access of structs, callback and functions in unmanaged code ? 
- Does this mean imported libraries and modules into the user created application? 
- It does, specifically objects like DLLs. 

## API Call Structure

**Modifying Characters**

- A - Represents an 8-bit character set with ANSI encoding
- W - Represents a Unicode encoding
- Ex - Provides extended functionality or in/out parameters to the API call. 

## .NET and Powershell API Implementations

- intPtr creates a new pointer for the API call. 
- You import a DLL file using DLLImport, then create a API call be utilizing a a function from that import. That function can then be called in program as a API call. 

## Community Abused API Calls

**Useful API Calls for Malicious Actors**

- LoadLibraryA - Maps a specified DLL into the address space, as seen in previous tasks
- GetUserNameA - Get the username of whoever launched the thread 
- GetComputerNameA -  Get the computer's name
- GetVersionExA - Get the version of the OS
- GetModuleFileNameA - Get the full path name of the module 
- GetStartupInfoA - Get startupinfo
- GetModuleHandle -  ??????? 
- GetProcAddress - Returns the address of an exported DLL function
- VirtualProtect - Changes the protection on a region of memory in the virtual address space 


## Malware Case Study

