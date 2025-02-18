
Filter by source address and destination address
```
tshark -r <file_name> -Y 'ip.src==<source_ip_address> &&  ip.dist==<dest_ip_address>"
``` 

Filter by get request method
```
tshark -r <file_name> -Y  'http.reques.method==GET'
```

Filter by fields
```
tshark -r <file_name> -Y  'http.reques.method==GET' -Tfields -e frame.time -e ip.src -e http.request.full_uri
```

Filter by word in line
```
tshark -r <file_name> -Y 'http contains password'
```


## Lab

Questions:  
A:
1. Command to show only the HTTP traffic from a PCAP file?
```
tshark -t <file_name> -Y 
```

3. Command to show only the IP packets sent from IP address 192.168.252.128 to IP address 52.32.74.91?
```
 tshark -r HTTP_traffic.pcap -Y 'ip.src==192.168.252.128 && ip.dst==52.32.74.91'
```

2. Command to print only packets containing GET requests?
```
tshark -r HTTP_traffic.pcap -Y 'http.request.method==GET'
```
    
3. Command to print only packets only source IP and URL for all GET request packets?
```
tshark -r HTTP_traffic.pcap -Y 'http.request.method==GET' -Tfields -e ip.src -e http.request.full_uri
```

Set B:1. 
1. How many HTTP packets contain the "password" string?

2.  What is the destination IP address for GET requests sent for New York Times (www.nytimes.com)?
```

```
    
2. What is the session ID being used by 192.168.252.128 for Amazon India store (amazon.in)?

    
3. What type of OS the machine on IP address 192.168.252.128 is using (i.e. Windows/Linux/MacOS/Solaris/Unix/BSD)? Bonus: Can you also guess the distribution/flavor?

## Commands

#### Y Filters

#### TFields 

