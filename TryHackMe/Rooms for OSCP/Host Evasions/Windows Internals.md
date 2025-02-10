
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
