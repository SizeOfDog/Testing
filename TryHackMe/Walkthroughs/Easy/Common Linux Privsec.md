

## Enumeration 


#### Questions


First, lets SSH into the target machine, using the credentials [user3:password.](user3:password.) This is to simulate getting a foothold on the system as a normal privilege user.

What is the target's hostname?  
```
hostname

polobox
```

Look at the output of /etc/passwd how many "user[x]" are there on the system?  
```
hostname

8
```

How many available shells are there on the system?  
```

```

What is the name of the bash script that is set to run every 5 minutes by cron?  
```

```

What critical file has had its permissions changed to allow some users to write to it?  
```

```


## Abusing SUID/GUID Files

To search for files that contain a SUID bit set use this command
```
find / -perm -u=s -type f 2>/dev/null
```

#### Questions


## Exploring Writeable /etc/passwd


```

```
#### Questions

Having read the information above, what direction privilege escalation is this attack?  
```

```

Before we add our new user, we first need to create a compliant password hash to add! We do this by using the command: **"openssl passwd -1 -salt [salt] [password]"**
```

```

What is the hash created by using this command with the salt, **"new"** and the password **"123"**?  
```
new:$1$new$p7ptkEKU1HnaHpRtzNizS1:0:0:root:/root:/bin/bash
```

Great! Now we need to take this value, and create a new root user account. What would the /etc/passwd entry look like for a root user with the username "new" and the password hash we created before?