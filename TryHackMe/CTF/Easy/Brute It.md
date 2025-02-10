
I scanned every TCP port of the target machine
2 ports are open, 80 hosting HTTP and port 22 hosting SSH. 
![[Pasted image 20241118203626.png]]


I then use a more aggressive scan specifically on those 2 ports. 
Nothing notable from the SSH service or the web service. 
![[Pasted image 20241118203705.png]]

The next thing to do was enumerate through the web server dirs. 
I've been using gobuster over dirb recently due to the improved speed. 
The only downside of gobuster I find is that it doesn't enumerate the second level of a dir. 
While dirb does this automatically. 
If there is a way to do it with gobuster I've been too lazy to google it. 

Once the command has finished we find an admin dir. 
Navigating to the website we're welcomed with a login page with a username and password. 
![[Pasted image 20241118203918.png]]

Brute forcing takes up a lot of time. Sometimes it depends on the word list you use which determines whether you're able to receive correct credentials. 
By inspecting the page details, we find a note. 
We can now confidently say that there's a user admin and possibly john. 
![[Pasted image 20241118203955.png]]

I used the http-post-form module with Hydra to brute force the web form. 
The password is xavier
![[Pasted image 20241118210322.png]]

Now entering the credentials we're given the web flag. 
Also a download link to an RSA key.
Using John the Ripper we can crack the RSA's passphrase.
first we use ssh2john to convert the rsa key into a hash.
![[Pasted image 20241118211036.png]]

John the Ripper automatically knows that the hash contains a passphrase now that we've converted the file. 
Using the word list rockyou.txt we can brute force the passphrase. 
The passphrase is rockinroll
![[Pasted image 20241118211055.png]]

Now that we have the passphrase we can utilize it sign in to the ssh server. 
First change the permissions of the file to 600. Why ? I really don't know, I suppose that's the format that ssh wants. 
![[Pasted image 20241118212741.png]]

First thing I do once I login is list out the directory. 
We find a user.txt file that can be displayed to the terminal
![[Pasted image 20241118213014.png]]

Now this is interesting. 
When you run the sudo -l command we're told that we can run the cat command as sudo. 
The official tryhackme website says that I should escalate privileges before finding the next flag. Well not specifically but it's implied.
Now, I'm an idiot, but I know that you should be able to cat out any file that's owned by the root with these current permissions. 
So I simply make an obvious guess and try displaying a file in the /root directory  named root.txt
Look at that, the flag. 
![[Pasted image 20241118212511.png]]

Now I'm not good at elevating privileges... there's two things you could do. Install pspy or linpeas to the target machine. Run the command and hope that there are some weaknesses of the current installation. 
Tryhackme hints at using gtfobins to.. do something. But I don't really understand the question it's giving when it mentions to find a form to escalate privileges. 
So I'll look up a write up for the answer.

Not sure where a form was supposed to come into play. 
You can cat out the /etc/shadow file, revealing the roots hashed password. 
Copy that password to the kali machine to use john the ripper on it. 
![[Pasted image 20241118214423.png]]

After running john the ripper on the hash with the wordlist rockyou.txt we're given the password: football
![[Pasted image 20241118214403.png]]

I actually attempted to use the cracked hash as a ssh key file. 
Let's not talk about that... 

You can simply elevate privileges from the user john to root using the su root command. 
Enter in the new found password to be granted access. 
![[Pasted image 20241118214711.png]]

This was probably one of the easier rooms i've done. I'm not sure if that's because I'm getting better or this was just an extremely simple room. I'm also sleep deprived so I'm proud of my self. 
## Reconnaissance

Search for open ports using nmap.  
How many ports are open?
```
2
```

What version of SSH is running?
```
OpenSSH 7.6p1
```

What version of Apache is running?
```
2.4.29
```

Which Linux distribution is running?  
```
Ubuntu
```

Search for hidden directories on web server.  
What is the hidden directory?
```
/admin
```

## Getting a shell

What is the user:password of the admin panel?
```
admin:xavier
```

Crack the RSA key you found.  
What is John's RSA Private Key passphrase?  
```
rockinroll
```

user.txt
```
THM{a_password_is_not_a_barrier}
```

Web flag
```
admin:xavier
```

## Privilege Escalation

Find a form to escalate your privileges.  
What is the root's password?
```

```

root.txt
```

```
