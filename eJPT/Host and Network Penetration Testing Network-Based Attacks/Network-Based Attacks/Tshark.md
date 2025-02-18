
Check tshark Version
```
tshark -v
```

List interfaces 
```
tshark -D 
```

Attempt to capture interface traffic
```
tshark -i <interface>
```

Display packet capture via file
```
tshark -r <pcap_capture>
```

Get Hierarchy of protocols
```
tshark -r <pcap_file> -z io,phs -q
```
## Tools

- tshark

## Lab

#### Set A
1. Which version of Tshark is installed in the lab? 
```
2.6.1 
```
   
2. Find all Tshark supported network interfaces for monitoring 
```
1. eth0
2. any
3. lo (Loopback)
4. ip_vti0
5. nflog
6. nfqueue
7. ciscodump (Cisco remote capture)
8. randpkt (Random packet generator)
9. sshdump (SSH remote capture)
10. udpdump (UDP Listener remote capture)
```
   
3. What is the Tshark command to sniff on eth0? Why did this command fail?
```
tshark -i eth0
```
The command failed because I'm not a root user
#### Set B

1. Tshark supports PCAP files. The lab environment has a sample file: HTTP_traffic.pcap. How can you read this file in Tshark and display the packet list on the console?
```
tshark -r <pcap_file_name>   
```
   
2. How can you find the total number of packets in HTTP_traffic.pcap?

On the left side of the output file it displays the packet number. 
   
3. Tshark command to read the first 100 packets only from HTTP_traffic.pcap?

```
tshark -c 100 -r <pcap_filename>
```

4. Print the list of protocols in HTTP_traffic.pcap

```
tshark -r HTTP_traffic.pcap | awk '{print $6}' | sort |  uniq
```