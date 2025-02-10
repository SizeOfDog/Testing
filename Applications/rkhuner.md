Scans files and directories for potential malicious use via rootkits.

Install RKhunter
```
sudo pacman -S rkhunter
```

Update database
```
rkhunter --propupd
```

Run a systems check ?
Checks for rootkits
```
rkhunter --check --sk
```