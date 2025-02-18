#### Tools
ip a
ping 
nmap
nc (netcat)

#### Commands

Connect to ip address through ssh
```
ssh root@target_ip
```

Connect to ip through netcat
May resolve SSH banner for enumeration
```
nc target_ip
```

Enumerate algorithms used to create key
```
nmap target_ip -p 22 --script ssh2-enum-algos
```

Get host key public key ? of target ip
```
nmap target_ip -p 22 --script ssh-hostkey --script-args ssh_hostkey=full
```

Check if there is an authentication method for specific user
```
nmap target_ip -p 22 --script ssh-auth-methods --script-args="ssh.user=student"
```

Login to server using ssh-run script from nmap
```
nmap -p 22 -d -v --script=ssh-run --script-args="ssh-run.cmd=command,ssh-run.username=username,ssh-run.password=password"
```

## Lab

### Questions
1.  What is the version of SSH server.

```
nmap -sSV  192.142.155.3

PORT   STATE SERVICE VERSION
22/tcp open  ssh     OpenSSH 7.2p2 Ubuntu 4ubuntu2.6 (Ubuntu Linux; protocol 2.0)
MAC Address: 02:42:C0:8E:9B:03 (Unknown)
Service Info: OS: Linux; CPE: cpe:/o:linux:linux_kernel
```

2.  Fetch the banner using netcat and check the version of SSH server.

```
nc  192.142.155.3  22

SSH-2.0-OpenSSH_7.2p2 Ubuntu-4ubuntu2.6
```

3.  Fetch pre-login SSH banner.

```
ssh root@192.142.155.3

The authenticity of host '192.142.155.3 (192.142.155.3)' can't be established.
ECDSA key fingerprint is SHA256:dxlBXgBb0Iv5/LmemZ2Eikb5+GLl9CSLf/B854fUeV8.
Are you sure you want to continue connecting (yes/no)? yes
```


4.  How many “encryption_algorithms” are supported by the SSH server.

```
nmap 192.142.155.3 --script ssh2-enum-algos.nse  

Not shown: 999 closed ports
PORT   STATE SERVICE
22/tcp open  ssh
| ssh2-enum-algos: 
|   kex_algorithms: (6)
|       curve25519-sha256@libssh.org
|       ecdh-sha2-nistp256
|       ecdh-sha2-nistp384
|       ecdh-sha2-nistp521
|       diffie-hellman-group-exchange-sha256
|       diffie-hellman-group14-sha1
|   server_host_key_algorithms: (5)
|       ssh-rsa
|       rsa-sha2-512
|       rsa-sha2-256
|       ecdsa-sha2-nistp256
|       ssh-ed25519
|   encryption_algorithms: (6)
|       chacha20-poly1305@openssh.com
|       aes128-ctr
|       aes192-ctr
|       aes256-ctr
|       aes128-gcm@openssh.com
|       aes256-gcm@openssh.com
|   mac_algorithms: (10)
|       umac-64-etm@openssh.com
|       umac-128-etm@openssh.com
|       hmac-sha2-256-etm@openssh.com
|       hmac-sha2-512-etm@openssh.com
|       hmac-sha1-etm@openssh.com
|       umac-64@openssh.com
|       umac-128@openssh.com
|       hmac-sha2-256
|       hmac-sha2-512
|       hmac-sha1
|   compression_algorithms: (2)
|       none
|_      zlib@openssh.com
```

5.  What is the ssh-rsa host key being used by the SSH server.

```
nmap 192.142.155.3 --script ssh-hostkey.nse

PORT   STATE SERVICE
22/tcp open  ssh
| ssh-hostkey: 
|   2048 b0:2b:8d:3e:4c:de:f9:ab:7f:86:47:fd:c8:d2:e0:a8 (RSA)
|   256 75:6f:7d:4e:d7:f7:6d:ec:23:d1:8e:39:76:94:86:8a (ECDSA)
|_  256 58:16:43:a6:65:2c:0b:0a:22:60:86:31:6f:59:38:12 (ED25519)
```

6.  Which authentication method is being used by the SSH server for user “student”.

```
 nmap -p 22 --script ssh-auth-methods --script-args="ssh.user=student" 192.142.155.3

PORT   STATE SERVICE
22/tcp open  ssh
| ssh-auth-methods: 
|_  Supported authentication methods: none_auth
```

7.  Which authentication method is being used by the SSH server for user “admin”.

```
nmap -p 22 --script ssh-auth-methods --script-args="ssh.user=admin" 192.142.155.3

PORT   STATE SERVICE
22/tcp open  ssh
| ssh-auth-methods: 
|   Supported authentication methods: 
|     publickey
|_    password
MAC Address: 02:42:C0:8E:9B:03 (Unknown)
```

8.  Fetch the flag from /home/student/FLAG by using nmap ssh-run script.

```
nmap -p 22 -v -d --script=ssh-run --datadir=./ --script-args="ssh-run.cmd=cat /home/student/FLAG, ssh-run.username=student, ssh-run.password=" 192.142.155.3

e1e3c0c9d409f594afdb18fe9ce0ffec
```

### Answers
1. OpenSSH 7.2p2 Ubuntu 4ubuntu2.6
2. 
3. Welcome to attack defense ssh recon lab!!
4. 6
5. ecdsa-sha2-nistp256
6. 
7. none_auth
8. public key and password

args ssh-run.username    Username to authenticate as
-- @args ssh-run.password    Password to use if using password authentication