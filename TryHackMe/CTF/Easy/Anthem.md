
https://tryhackme.com/r/room/anthem


```
└─# nmap -p- 10.10.25.172
Starting Nmap 7.93 ( https://nmap.org ) at 2024-12-10 00:06 UTC
Nmap scan report for ip-10-10-25-172.eu-west-1.compute.internal (10.10.25.172)
Host is up (0.00089s latency).
Not shown: 65532 filtered tcp ports (no-response)
PORT     STATE SERVICE
80/tcp   open  http
3389/tcp open  ms-wbt-server
5985/tcp open  wsman
MAC Address: 02:47:8D:CC:DA:8D (Unknown)

```

robots.txt pathway 
```
UmbracoIsTheBest!

# Use for all search robots
User-agent: *

# Define the directories not to crawl
Disallow: /bin/
Disallow: /config/
Disallow: /umbraco/
Disallow: /umbraco_client/

```
#### Questions

**Website Analysis**

Let's run nmap and check what ports are open.
```

```

What port is for the web server?
```

```

What port is for remote desktop service?
```

```

What is a possible password in one of the pages web crawlers check for?

What CMS is the website using?

What is the domain of the website?

What's the name of the Administrator  

Can we find find the email address of the administrator?

**Spot the Flags**


**Final Stage**