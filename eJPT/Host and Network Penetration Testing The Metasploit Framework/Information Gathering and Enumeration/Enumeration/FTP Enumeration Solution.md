
## Solution

**Step 1:** Open the lab link to access the Kali GUI instance

**Step 2:** Identify the target IP address

To begin with you will need to identify the target system's IP address, this can be done by running the following command:

**Command:**

```
ifconfig
```

As shown in the following screenshot, locate the IP address associated with the **eth1** interface, the target IP address is the next IP within the subnet.

![Content Image](https://assets.ine.com/content/ptp/AlexisAhmed/VOD-4377/LAB-3862/1.png)

In this case the Kali Linux IP is **192.51.147.2** so the target IP will be **192.51.147.3**.

**Note:** Your target IP address will be different, so make sure to substitute the IP shown in the commands below with the one in your lab.

**Step 3:** FTP enumeration with Metasploit

Before we can begin, we will need to startup the Metasploit Framework console (msfconsole), this can be done by running the following command:

**Command:**

```
msfconsole
```

To begin with, we will need to identify a service version of the FTP server running on the target, this can be done by loading the following module:

**Command:**

```
use auxiliary/scanner/ftp/ftp_version
```

We will now need to configure the module options, more specifically, the target IP option, this can be done by running the following command:

**Command:**

```
set RHOSTS 192.51.147.3
```

We can now run the module by running the following command:

**Command:**

```
run
```

As shown in the following screenshot, the module reveals that the target system is running **ProFTPD 1.3.5a**.

![Content Image](https://assets.ine.com/content/ptp/AlexisAhmed/VOD-4377/LAB-3862/2.png)

We can perform a brute-force on the FTP server to identify legitimate credentials that we can use for authentication, this can be done by loading the **ftp_login** module as follows:

**Command:**

```
use auxiliary/scanner/ftp/ftp_login
```

We will now need to configure the module options, more specifically, the target IP option, this can be done by running the following command:

**Command:**

```
set RHOSTS 192.51.147.3
```

Given that we are performing a brute force attack, we will also need to configure the **USER_FILE** and **PASS_FILE** options.

**Command:**

```
set USER_FILE /usr/share/metasploit-framework/data/wordlists/common_users.txt
```

**Command:**

```
set PASS_FILE /usr/share/metasploit-framework/data/wordlists/unix_passwords.txt
```

We can now run the module by running the following command:

**Command:**

```
run
```

As shown in the following screenshot, after a couple of seconds the brute force attack identifies the credentials **sysadmin/654321**.

![Content Image](https://assets.ine.com/content/ptp/AlexisAhmed/VOD-4377/LAB-3862/3.png)

We can also check if anonymous logons are allowed on the FTP server, this can be done by loading the following command:

**Command:**

```
use auxiliary/scanner/ftp/anonymous
```

We will now need to configure the module options, more specifically, the target IP option, this can be done by running the following command:

**Command:**

```
set RHOSTS 192.51.147.3
```

We can now run the module by running the following command:

**Command:**

```
run
```

As shown in the following screenshot, the module reveals that anonymous FTP logons are not enabled on the FTP server.

![Content Image](https://assets.ine.com/content/ptp/AlexisAhmed/VOD-4377/LAB-3862/4.png)

We can now login to the FTP server with the credentials we obtained from the FTP brute force, this can be done through the use of the FTP client on Kali Linux.

**Command:**

```
ftp 192.51.147.3
```

As shown in the following screenshot, you will be prompted to provide a username and password, supply the credentials we obtained from the brute force attack.

![Content Image](https://assets.ine.com/content/ptp/AlexisAhmed/VOD-4377/LAB-3862/5.png)

As shown in the preceding screenshot, authentication is successful and we are logged in to the FTP server.

## Conclusion

In this lab, we explored the process of performing FTP enumeration with the Metasploit Framework.