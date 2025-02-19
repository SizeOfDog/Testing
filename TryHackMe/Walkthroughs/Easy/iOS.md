https://tryhackme.com/room/iosanalysis


## iOS Pairing

- Restricted Mode - Won't allow data to pass out or or in the IPhone without unlocking it. 
- Iphones use trusted certificates to sync with devices. 
- A private key is stored on the IPhone's hardware, generated via both the remote device and the iphone itself. 

## Preserving Evidence

## The iOS Filesystem

**APFS (IPhone's File System)** 

- Full Disk Encryption 
- Smarter Data Management
- Uses the GPT partition structure
- Integrity Checks via checksums
- crash protection mechanisms 

**APFS Domains**

- Data - Stores application data, settings, and user files
- Cache  - Stores temporary files such as cached files from the web browser
- System  - Essential files for the operating system. Usually read-only
- Share  - Shareable data between applications

Plists - property lists, files that store iOS objects, this includes; Strings, Numbers, Data, Arrays and Dicts. 

SQLite - Stores phots, text messages, contacts and voicemails
## Artefacts 

**Directories**

- /var/mobile - contains user data and application storage
- /var/keychains - Passwords, certificates, encryption keys and tokens
- /var/logs - System, application, debugging and update logs
- /var/db - System, application and metadata databases

## Analysis

**libimobiledevice**

- Creates a backup in  a non human readable format 
- Can encrypt and backup either parts of the mobile device or it's entirety 
- An application like ideviceuback can be used to convert the non readable data into readable data.

Turn on encryption when creating a backup

```
idevicebackup2 -i encryption on
```

Create a full backup at the location specified

```
idevicebackup2 backup --full ./backup
```

## Practical Operational Timely Manner

