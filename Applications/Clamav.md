

**Install clamav**
clamav is part of the extra repo so it must be installed via yay
```
sudo yay -S clamav
```

Update fresh clam av database
```
freshclam
```

Allow clamav to automatically update the database
There's a check 12 times per day
```
sudo systemctl enable --now clamav-freshclam.service
```


#### Scanning files

Scan a file using the clamscan cli tool
```
clamscan <file-name>
```

Utilize hash database to use with clamscan
```
clamscan -d <database_name> <file_name>
```

Check for malicious files recursively 
recursive - check subdir and files
infected - only displays output for infected files
```
clamscan --recursive --infected <dir_path>
```