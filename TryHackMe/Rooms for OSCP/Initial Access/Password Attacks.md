

## Password Profiling 1 

Default Password - Worth trying before performing a dictionary attack. 

#### Combined Wordlists

Combine multiple word list files into one
```bash
cat file1.txt file2.txt > combined_list.txt
```

Remove any duplicate words in a combined wordlist
```bash
sort combined_list.txt | uniq -u > cleaned_combined-list.txt
```


#### Customized Wordlists

Use the cewl command to crawl a website for common and pertinent words 
w - write contents to a file
m - Gather words longer than 5 characters
d - the depth of the web crawl
```bash
cewl -w list.txt -d 5 -m 5 <url>
```

Generate a username list with the username generator python script
```bash
git clone https://github.com/therodri2/username_generator.git
cd username_generator

echo "Jordan Trelford" > user.lst
python3 username_generator.py -w user.lst
```

## Password Profiling 2 

##### Keyspace Technique

Generate a wordlist with crunch
 2 - minimum 2 words
 2 - maximum 2 words
 01234abcd - the characters to include into the wordlist
```bash
crunch 2 2 01234abcd -o crunch.txt
```

Use the CUPP script to generate a wordlist
```bash
git clone https://github.com/Mebus/cupp.git
cd cupp 
python3 cupp.py -i 
```



## Offline Attacks - Dictionary and Brute Force

#### Dictionary Attack

**Steps for Cracking a Hash Offline** 
1. What type of hash is it? 
2. What wordlist or mode can be used to crack the hash

Identify hashes by using **hash-identifier** or **hashid**

Crack hashes using hashcat
a - the attack mode is a dictionary attack
m - specify the hash type to crack, in this case 0 is for md5
```bash
hashcat -a 0 -m 0 <hash> <path_to_wordlist>
```

#### Brute-Force Attack

Using hash cat to generate a wordlist
a - setting the attack mode to brute force, with 3
?d* - Tells the brute force attack to use digits
stdout - prints the result to the terminal
```bash
hashcat -a 3 ?d?d?d?d --stdout
```

#### Offline Attacks - Rule Based

Rule Based Attacks - Hybrid Attacks

Create a wordlist from one single word 
The wordlist is single passwor list 
The rule used is best64, which are the best 64 passwords ? 
print the output, from the output count the number of lines
```
john --wordlist=single-password-list.txt --rules=best64 --stdout | wc -l 

JumboSingle
o1
o2
i1
i2
o1
i1
o2
i2
best64
d3ad0ne
dive
InsidePro
T0XlC
rockyou-30000
specific
ShiftToggle
Split
Single
Extra
OldOffice
Single-Extra
Wordlist
ShiftToggle
Multiword
best64
Jumbo
KoreLogic
T9
hashcat
```


Custom Rules

Edit the john configuration file 
The combination must include a single word followed by one digit
With a Special Symbol at the beginning of the password
```
nano /opt/john/john.conf

[List.Rules:THM-Password-Attacks]
Az"[0-9]" ^[!@$#]
```


#### Online Password Attacks

```
cewl -m 8 -w clinic.txt http://10.10.38.224/
```

```
ftp 10.10.38.224 

username: anonymous
password: 
cd files 
get flag.txt 
exit 
cat falg.txt
```

```
john --wordlist=clinic.txt --rules=THM-Password-Attacks --stdout > john_clinic.txt
```

