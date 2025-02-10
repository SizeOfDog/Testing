
Back up, restore, and encryption software CLI

Initialize back up repo
```
borg init
```

Create backup from folder path 
```
borg create <repo_path>::<name_of_backup> <directory_to_backup>
```

Extract and decrypt backup 
```
borg extract <repo_path>::<name_of_backup>
```