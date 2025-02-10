
## Wreath

#### Enumeration

Target IP Address 
```
10.200.81.200
```

```
nmap -p 1-15000 -T 4 -v 10.200.81.200 
```

**Questions** 

How many of the first 15000 ports are open on the target?  
```

```

Perform a service scan on these open ports.  
```

```

What OS does Nmap think is running?  
```

```

Okay, we know what we're dealing with.

Open the IP in your browser -- what site does the server try to redirect you to?
```

```

You will have noticed that the site failed to resolve. Looks like Thomas forgot to set up the DNS!

Add it to your hosts file manually. This can be accomplished by editing the `/etc/hosts` file on Linux/MacOS, or `C:\Windows\System32\drivers\etc\hosts` on Windows, to include the IP address, followed by a tab, then the domain name. **Note:** this _must_ be done as root/Administrator.

It should look something like this when done, although the _IP address and domain name will be different_:

`10.10.10.10 example.thm`

Reload the webpage -- it should now resolve, but it will give you a different error related to the TLS certificate. This occurs because the box is not really connected to the internet and so cannot have a signed TLS certificate. In this instance it is safe to click "Advanced" -> "Accept Risk"; however, you should never do this in the real world.  

In real life we would perform a "footprinting" phase of the engagement at this point. This essentially involves finding as much public information about the target as possible and noting it down. You never know what could prove useful!  

Read through the text on the page. What is Thomas' mobile phone number?
```

```

Let's have a look at the highest open port.  

Look back at your service scan results: what server version does Nmap detect as running here?
```

```

Put your answer to the last question into Google.

It appears that this service is vulnerable to an unauthenticated remote code execution exploit!

What is the CVE number for this exploit?
```

```

We have everything we need to break into this machine, so let's get going!