#### Password Hashes
	- Hashed passwords are stored in the Security Accounts Manager Database
	- Hashing is to generate a new value using a hashing algorithm 
	- Local Secuirty Authoirty verifies user credentials
	- Windows 2003 uses two different Hashes
		- LM
		- NTLM 
	- Windows LM is disabled since Win 2003

#### Security Account Manager
	- Database for managing user accounts and passwords
	- All passwords are hashed in the SAM
	- SAM cannot be copied while the computer is on
	- Attackers use in-memory techniques to dump hashes
	- SAM database is encrypted with a syskey

#### LM (LanMan)
	- Default hashing algorithm 
	- Hashing Steps: 
		- Two seven character chunks are created
		- All characters are made into uppercase
		- Each chunk is then hashed separatley  with DES 
	- LM are weak

#### NTLM (NTHash)
	- Collection of authentication protocols
	- NTLM is used from windows vista onwards
	- Original password is disposed of
	- Hashed by MD4 algorithm
	- NTLM vs LM
		- Does not split password into chuncks
		- case sensitive 
		- Allows the use of symbols and unicode characters

## Labs
