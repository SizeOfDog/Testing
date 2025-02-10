Scan the target IP address for open ports
```
└─# nmap -p- 10.10.110.134 
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 11:46 UTC
Nmap scan report for ip-10-10-110-134.eu-west-1.compute.internal (10.10.110.134)
Host is up (0.014s latency).
Not shown: 65533 closed tcp ports (reset)
PORT   STATE SERVICE
22/tcp open  ssh
80/tcp open  http
MAC Address: 02:52:58:88:6D:1B (Unknown)

Nmap done: 1 IP address (1 host up) scanned in 3.89 seconds

```

Check the versioning of the services running on the ports. 
Check if any scripts are applicable to the open ports. 
```
└─# nmap -sVC 10.10.110.134
Starting Nmap 7.93 ( https://nmap.org ) at 2024-11-15 11:48 UTC
Nmap scan report for ip-10-10-110-134.eu-west-1.compute.internal (10.10.110.134)
Host is up (0.012s latency).
Not shown: 998 closed tcp ports (reset)
PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.8 (Ubuntu Linux; protocol 2.0)
| ssh-hostkey: 
|   2048 581475691ea9595fb23a691c6c785c27 (RSA)
|   256 23f5fbe757c2a53ec226290e74db37c2 (ECDSA)
|_  256 f19bb58ab929aab6aaa2524a6e6595c5 (ED25519)
80/tcp open  http    Apache httpd 2.4.18 ((Ubuntu))
|_http-server-header: Apache/2.4.18 (Ubuntu)
|_http-title: Can You Find Them All?
MAC Address: 02:52:58:88:6D:1B (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel

Service detection performed. Please report any incorrect results at https://nmap.org/submit/ .
Nmap done: 1 IP address (1 host up) scanned in 9.48 seconds

```

Check the page source of the index page
```
pokemon:hack_the_pokemon
```

SSH into the target machine using the
```
ssh pokemon@10.10.110.134
password: hack_the_pokemon
```

Navigate through the home dir of the pokemon user.
There's a file that I'm able to open with some simple no usable code. 
ash : pikapika looks like a credential
```
cd ~/Videos/Gotta/Catch/Them/ALL!
cat Could_this_be_what_Im_looking_for\?.cplusplus 

# include <iostream>

int main() {
        std::cout << "ash : pikapika"
        return 0;
}
```

When I cat out the passwd file we can see that there's a user with the name ash. 
It would be worth attempting to sign in with these credentials
```
cat /etc/passwd 

pokemon:x:1000:1000:root,,,:/home/pokemon:/bin/bash
sshd:x:121:65534::/var/run/sshd:/usr/sbin/nologin
ash:x:1001:1001::/home/ash:
```

After signing in with the new found credentials we're able to open up a file called root-pokemon in the home dir. 
```
ssh ash@10.10.110.134
password: pikapika

cd /home
cat roots-pokemon.txt
```

Using the pokemon user we can further enumerate through the dirs using the find command. 
By simply searching for the word water or water-type with wild card identifiers on either end of the string we can find the next flag. 
The flag is located in /var/www/html/ 
You can cat out of the contents of the file to display some nonsense. 
When passing the contents through a caesar cipher decoder we're able to find the real meaning of the text. 
```
pokemon@root:~/Videos/Gotta/Catch/Them/ALL!$ find / -name *water* 2>/dev/null 

/var/www/html/water-type.txt
/proc/sys/vm/watermark_scale_factor
/usr/share/glib-2.0/schemas/org.compiz.water.gschema.xml
/usr/share/app-install/desktop/gwaterfall:gwaterfall.desktop
/usr/bin/intel_watermark
/usr/lib/libreoffice/share/config/wizard/web/styles/water.css
/usr/lib/libreoffice/share/config/wizard/form/styles/water.css

pokemon@root:~/Videos/Gotta/Catch/Them/ALL!$ cat /var/www/html/water-type.txt

Ecgudfxq_EcGmP{Ecgudfxq}

caesar cipher rotations 12 -> Squirtle_SqUaD{Squirtle}
```

We can then search for the fire-type text file. 
Again, nonsense, until you pass the text through a hash analyzer or recognize the format of the string. 
It's in base64 and can be decoded within the terminal/shell or with a cyberchef in the browser.
```
pokemon@root:~/Videos/Gotta/Catch/Them/ALL!$ find / -name *fire-type* 2>/dev/null 

/etc/why_am_i_here?/fire-type.txt

pokemon@root:~/Videos/Gotta/Catch/Them/ALL!$ cat /etc/why_am_i_here?/fire-type.txt

UDBrM20wbntDaGFybWFuZGVyfQ==
```

```
echo UDBrM20wbntDaGFybWFuZGVyfQ== | base64 -d 

P0k3m0n{Charmander}
```

This last one I must've missed the first time around after enumerating the directories as the pokemon user. 
Unzip the file without any issue then cat the contents of the newly unzipped file. 
```
pokemon@root:~/Desktop$ unzip P0kEmOn.zip 
pokemon@root:~/Desktop/P0kEmOn$ cat grass-type.txt 
50 6f 4b 65 4d 6f 4e 7b 42 75 6c 62 61 73 61 75 72 7d

pokemon@root:~/Desktop/P0kEmOn$ echo -n "50 6f 4b 65 4d 6f 4e 7b 42 75 6c 62 61 73 61 75 72 7d" | xxd -r -p 

PoKeMoN{Bulbasaur}
```

#### Questions


Find the Grass-Type Pokemon
```
PoKeMoN{Bulbasaur}
```

Find the Water-Type Pokemon  
```
Squirtle_SqUaD{Squirtle}
```

Find the Fire-Type Pokemon  
```
P0k3m0n{Charmander}
```

Who is Root's Favorite Pokemon?  
```
Pikachu!
```

Congratulations! Thank You So Much For Completing The Pokemon Room