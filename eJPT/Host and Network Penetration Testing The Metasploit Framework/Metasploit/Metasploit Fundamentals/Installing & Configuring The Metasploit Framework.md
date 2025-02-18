- Distributed by Rapid7 
- Available on Windows and Linux 

#### The Metasploit Framework Database

- Used to track all of your assessments, host data scans
- Postgresql is the primary database
- Scan results are stored in the database

#### Installation Steps

- Update repo and upgrade our Metasploit Framework
- Start and enable postgresql service
- Initialize the Postgresql database

#### Commands

Manage the metasploit framework database
```
sudo msfdb
```

Start the Metasploit Framework Database
```
sudo msfdb init
```

Re-initialize the Metasploit Framework Database
```
sudo msfdb reinit
```

## Quiz

Which one of the following commands can be used to setup and initialize the Metasploit Framework database?

	sudo msfdb init