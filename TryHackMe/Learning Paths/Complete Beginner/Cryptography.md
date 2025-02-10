
## Hashing - Crypto 101
#### Key Terms

Encoding - Example, json, just a way data is formatted and presented
Hash - Output of a hash function
Cryptanalysis - Finding vulnerabilities in a crypto algorithm 


**Questions**

Read the words, and understand the meanings!  
Is base64 encryption or encoding?
```
encoding
```

#### What is a Hash Function ? 

A hash function is a calculated fixed output result from an input and a hash algorithm. 
Hash functions are meant to be easily created and hard to resolve when going from the output, back to the input value. 

Hashing is mostly used to store passwords. When a user signs up to a website their password is converted into a hash and stored. That way not even the owners or admins of the application you're using know your password. 

**Hash Collision** - When two inputs have the same hash. This is due to a hash being a fixed size, there are more inputs than outputs. 

------------------------------- 

**Questions**

What is the output size in bytes of the MD5 hash function?
```
16
```
Can you avoid hash collisions? (Yea/Nay)
```
Nay
```

If you have an 8 bit hash output, how many possible hashes are there?
```
256
```

#### Uses for Hashing

**Rainbow Table** - Comparison of hashed to plain text passwords. Generate a table of hashes and their corresponding plain text password instead of cracking the hash itself.

**Salt** - Extra layer of protection for hashed passwords (unique randomly generated number/value). Often unique to each user. Even if two users have the same password, the hash will be different due to salt being added.  

------------------------------- 

**Questions**

Crack the hash "d0199f51d2728db6011945145a1b607a" using the rainbow table manually.
```
basketball
```

Crack the hash "5b31f93c09ad1d065c0491b764d04933" using online tools
```
tryhackme
```

Should you encrypt passwords? Yea/Nay
```
Nay
```

#### Recognizing Password Hashes

Unix Style hash format when opening the /etc/shadow file
`$format$rounds$salt$hash` 

|                             |                                                            |
| --------------------------- | ---------------------------------------------------------- |
| $1$                         | md5crypt, used in Cisco stuff and older Linux/Unix systems |
| $2$, $2a$, $2b$, $2x$, $2y$ | Bcrypt (Popular for web applications)                      |
| $6$                         | sha512crypt (Default for most Linux/Unix systems)          |

------------------------------- 

**Questions**

How many rounds does sha512crypt ($6$) use by default?
```
5000
```

What's the hashcat example hash (from the website) for Citrix Netscaler hashes?
```
https://hashcat.net/wiki/doku.php?id=example_hashes

1765058016a22f1b4e076dccd1c3df4e8e5c0839ccded98ea
```

How long is a Windows NTLM hash, in characters?
```
32
```

#### Password Cracking


------------------------------- 

**Questions**

Crack this hash: $2a$06$7yoU3Ng8dHTXphAg913cyO6Bjs3K5lBnwq5FJyA6d01pMSrddr1ZG
```
hashcat -m 3200  hash.txt  /usr/share/wordlists/rockyou.txt
hashcat -m 3200 --show hash.txt

85208520
```

Crack this hash: 9eb7ee7f551d2f0ac684981bd1f1e2fa4a37590199636753efe614d4db30e8e1
```
hashcat -m 1400  hash.txt  /usr/share/wordlists/rockyou.txt
hashcat -m 1400 --show hash.txt

halloween
```

Crack this hash: `$6$GQXVvW4EuM$ehD6jWiMsfNorxy5SINsgdlxmAEl3.yif0/c3NqzGLa0P.S7KRDYjycw5bnYkF5ZtB8wQy8KnskuWQS3Yr1wQ0`

```
hashcat -m 1800  hash.txt  /usr/share/wordlists/rockyou.txt
hashcat -m 1800 --show hash.txt

spaceman
```

Bored of this yet? Crack this hash: b6b0d451bbf6fed658659a9e7e5598fe
https://hashes.com/en/decrypt/hash
```
funforyou
```

#### Hashing for Integrity Checking

HMAC - used to verify the authenticity and integrity of data. 

------------------------------- 

**Questions**

What's the SHA1 sum for the amd64 Kali 2019.4 ISO? [http://old.kali.org/kali-images/kali-2019.4/](http://old.kali.org/kali-images/kali-2019.4/)
```
186c5227e24ceb60deb711f1bdc34ad9f4718ff9
```

What's the hashcat mode number for HMAC-SHA512 (key = $pass)?
```
1750
```
## John the Ripper

#### John Who

#### Setting up John the Ripper 

What is the most popular extended version of John the Ripper?
```
Jumbo John
```
#### Wordlists

What website was the rockyou.txt wordlist created from a breach on?
```
rockyou.com
```

#### Cracking Basic Hashes

Example usage of John the Ripper
`john --format=<format> --wordlist=<file_to_wordlist> <file_path_to_crack>`

List out possible formats to use with john the ripper
`john --list=formats | grep <format>`

hash identifier python script
```
wget https://gitlab.com/kalilinux/packages/hash-identifier/-/raw/kali/master/hash-id.py
```

Or there's a program that comes pre installed with kali linux called 
hash-identifier

-------------

What type of hash is hash1.txt?  
```
hash-identifier 2e728dd31fb5949bc39cac5a9f066498

MD5
```

What is the cracked value of hash1.txt?  
```
john --format=raw-md5 --wordlist=~/Downloads/SecLists/Passwords/Leaked-Databases/rockyou.txt hash1.txt

biscuit
```

What type of hash is hash2.txt?
```
hash-identifier 1A732667F3917C0F4AA98BB13011B9090C6F8065

SHA1
```

What is the cracked value of hash2.txt  
```
john --format=raw-sha1 --wordlist=~/Downloads/SecLists/Passwords/Leaked-Databases/rockyou.txt hash2.txt

kangeroo
```

What type of hash is hash3.txt?
```
hash-identifier D7F4D3CCEE7ACD3DD7FAD3AC2BE2AAE9C44F4E9B7FB802D73136D4C53920140A

sha256
```

What is the cracked value of hash3.txt
```
john --format=raw-sha256 --wordlist=~/Downloads/SecLists/Passwords/Leaked-Databases/rockyou.txt hash3.txt

microphone
```

What type of hash is hash4.txt?
```
hash-identifier c5a60cc6bbba781c601c5402755ae1044bbf45b78d1183cbf2ca1c865b6c792cf3c6b87791344986c8a832a0f9ca8d0b4afd3d9421a149d57075e1b4e93f90bf

whirlpool
```

What is the cracked value of hash4.txt
```
john --format=whirlpool --wordlist=~/Downloads/SecLists/Passwords/Leaked-Databases/rockyou.txt hash4.txt

colossal
```

#### Cracking Windows Authentication Hashes

Authentication Hashes - The hashed passwords that are stored on a operating system. To get these passwords you need to be a privileged user. 

Modern Windows Systems Utilize NTHash  (New Technology Hash) to store passwords, or NTLM hashes. 

What do we need to set the "format" flag to, in order to crack this?  
```
NT
```

What is the cracked value of this password?
```
john --format=nt --wordlist=SecLists/Passwords/Leaked-Databases/rockyou.txt ntlm_1605054722641.txt

mushroom
```

#### Cracking /etc/shadow Hahses

John needs both a copy of the passwd file and the shadow file to crack linux operating system hashes
`unshadow <path-to-passwd-file> <path-to-shadow-file> ` 

What is the root password?
```
echo "root:x:0:0::/root:/bin/bash" > passwd.txt
echo "root:$6$Ha.d5nGupBm29pYr$yugXSk24ZljLTAZZagtGwpSQhb3F2DOJtnHrvk7HI2ma4GsuioHp8sm3LJiRJpKfIf7lZQ29qgtH17Q/JDpYM/:18576::::::" > shadow.txt
unshadow passwd.txt shadow.txt > unshadowed
john --wordlist=SecLists/Passwords/Leaked-Databases/rockyou.txt --format=sha512crypt unshadowed.txt
```

![[Pasted image 20241006152131.png]]


#### Single Crack Mode

Single Crack Mode / Word Mangling - John will sometimes use information contained in a user's username to create a possible password if no password file is given. 
(Example, the username Mark, will produce the random passwords Marcus1, MarCUS2, etc)

`john --single --format=<hash-format> <path-to-hash>`

Gecos - Certain detailed information that is held in the /etc/shadow or /etc/passwd file. They're delineated by colons.

What is Joker's password?
```
john --single --format=raw-md5 hash7_1605054793656.txt

Jok3r
```

#### Custom Rules

What do custom rules allow us to exploit?  
```
password complexity predictability
```

What rule would we use to add all capital letters to the end of the word?
```
Az"[A-Z]"
```

What flag would we use to call a custom rule called "THMRules"
```
--rule=THMRules
```

#### Cracking Password Protected Zip Files



#### Cracking Password Protected RAR Archives

#### Cracking SSH Keys with John

#### Further Reading


## Encryption - Crypto 101

