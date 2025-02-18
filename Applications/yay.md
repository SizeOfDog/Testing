
## Install Yay

https://itsfoss.com/install-yay-arch-linux/


```
sudo pacman -Syu
sudo pacman -S --needed base-devel git
```


```
git clone https://aur.archlinux.org/yay.git && \
cd yay && \
makepkg -si && \ 
yay --version
```