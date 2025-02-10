
## Installation on Arch Linux

```
sudo yay nordvpn-bin
gpasswd -a <username> nordvpn
sudo systemctl enable --now nordvpnd.service
```

If nordvpn is masked
```
sudo systemctl enable --now nordvpnd
```

On debian based systems nordvpn can be download via a installation script from the nordvpn website. 
```
sh <(curl -sSf https://downloads.nordcdn.com/apps/linux/install.sh)
```

Login to the nordvpn service
```
nordvpn login
```

After opening the link from the terminal copy the link from the browser. 
```
sudo nordvpn login --callback "nordvpn://<rest_of_the_nord_link>"
```

Switch connection from OpenVPN to nordlynx which is improves speed and has lower latency. 
```
sudo nordvpn set technology nordlynx
```

Check the status of the nordvpn service with the native command
```
sudo nordvpn status
```

Connect to a city or country via the nordvpn command. 
```
sudo nordvpn connect <city_or_country>
```

Enable kill switch feature.
If the VPN service fails the internet will be disconnected. 
```
sudo nordvpn set killswitch enabled
```

Enable threat protection for the device. 
This will block some sites that may cause hard to the computer, as well as block ads. 
```
sudo nordvpn set threatprotectionlite enabled
```

Enable nordvpn on startup
```
sudo nordvpn set autoconnect enabled Toronto
```

Configure which DNS server is used by the VPN. 
```
sudo nordvpn set dns 9.9.9.9
```

Display the current settings of nordvpn in the terminal. 
```
sudo nordvpn settings
```

Display different countries that are available to connect to. 
```
sudo nordvpn countries
```