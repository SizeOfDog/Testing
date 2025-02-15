https://tryhackme.com/room/operatingsystemsecurity


#### Questions

Which of the following is **not** an operating system?

- AIX
- Android
- Chrome OS
- Solaris
- Thunderbird

```
Thunderbird
```


Which of the following is a strong password, in your opinion?

- iloveyou
- 1q2w3e4r5t
- LearnM00r
- qwertyuiop

```
LearnM00r
```


Based on the top 7 passwords, let’s try to find Johnny’s password. What is the password for the user `johnny`?
```
abc123
```

Once you are logged in as Johnny, use the command `history` to check the commands that Johnny has typed. We expect Johnny to have mistakenly typed the `root` password instead of a command. What is the root password?
```
happyHack!NG
```

While logged in as Johnny, use the command `su - root` to switch to the `root` account. Display the contents of the file `flag.txt` in the `root` directory. What is the content of the file?
```
THM{YouGotRoot}
```