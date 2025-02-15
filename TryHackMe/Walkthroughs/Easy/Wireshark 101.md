
https://tryhackme.com/room/wireshark

## Filtering Captures

Filtering by IP address
Both source and destination 
```
ip.src == <source_ip> and ip.dst == <dst_ip>
```

Filter by port
```
tcp.port eq <port_num> or <protocl_name>
```