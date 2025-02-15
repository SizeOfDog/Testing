
## Processes

- represents the execution of a program. 

**Components**

- Private Virtual Address Space - Where the process is allocated in memory
- Executable Program - Code and data stored in the address space 
- Open Handles - Resources accessible to the process
- Security Context - An Access token, specifying process authorization
- Process ID - unique ID
- Threads - Section  of a process scheduled for execution ?

**Address Space Components**

- Code - code to be executed 
- Global Variables - stored variables 
- Process Heap - Defines the heap where the data is stored
- Process Resources - Defines other resources of the process ? 
- Environment Block - Data structures to define process info


## Threads

- Control execution, specifically for processes 
- In my terms I would say it's the underlying middle man between a process and whatever that process is reaching out to do. A tube, transfer device or launching off pad. 

**Components** 

- Stack - Data relevant to a specific thread
- Thread Local Storage - pointers for allocating storage to a unique data env
- Stack Argument - Unique value assigned to each thread
- Context Structure - Hold machine register values maintained by the kernel 

## Virtual Memory

- Virtual memory is used to handle collisions that may happen with physical memory. 
- Sometimes memory will be transferred to the disk, when more virtual memory is being used than physical memory being allocated. 
- The lower half of memory is used by applications, while the upper half is being used by the operating system. 

## Dynamic Link Libraries

- A piece of code that can be used by multiple programs at the same time. 
- Great for code reuse, efficiency, memory usage, and reduced disk space
- DDLs are loaded by load-time dynamic linking or run time dynamic linking
- Load time dynamic linking involves loading a header file/the library into the code before hand. 
- Run time dynamic linking includes loading the DDL during execution using the LoadLibrary and GetProcAddress functions. 


## Portable Execution Format

- Defines the information about the executable
- Defines how data structure is stored in memory

**Headers**

- DOS Header - defines the type of file
- DOS Stub - Runs at the beginning of the file, has a compatibility message.
- PE File Header - Contains information headers, the file format, signature and image file header. The PE file header starts with a "PE", most content is non human readable. 
- Image Optional Header - Important part of the PE file header ? 
- Data Dictionaries - Point to the image data directory structure
- Section Table - Defines the available sections in the table

**Sections**

- text - contains the executable code and entry point
- data - contains initialized data
- rdata or idata - contains imports
- reloc  - contains relocation information
- rsc  - Contains application resources
- debug - contains debug information

## Interacting with Windows Internals

- Windows Internals are often interacted by utilizing the windows API 
- The Switching Point - When a processor switches between kernel and user mode, depending on the access requested
- User Mode - no direct access to hardware, creates a process in private virtual address space, access to owned memory locations ? 
- Kernel Mode - Direct hardware access, access to entire physical memory, ran in a single virtual address space

