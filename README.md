# David Morton Update (Aug 2023)

During July of 2023, I spent some time trying to get this working for the macbook8,1 (Early 2015). I was unsuccessful, and kind of got tired of working on it. Given all the other issues with Linux on this machine (including non-functional Bluetooth, keyboard and trackpad failure upon resume, general overheating issues), I'm going to let my computer live out it's happy days as a Macbook.

Honestly, I started this whole project because I figured that OpenCore Patcher was going to run out of runway on Intel machines before my machine was kaput, but given that my computer is over 8 years old now, it's probably close to time to get a new machine anyways. 

For anyone who wants to work on this, I've taken some copious [notes](https://github.com/DavidMorton/macbook12-audio-driver/blob/master/info/notes.md) on all the steps I took, and I might have been close, but then I'd have so much other work to do to get it working, that in the end, it's just not worth it at this point in my life. 

Good luck!

# Original README

Work in progress audio driver for the 12" MacBook9,1 (2016) and Macbook10,1 (2017) that's largely based on davidjo's [snd_hda_macbookpro](https://github.com/davidjo/snd_hda_macbookpro)  
Note: the Macbook8,1 (2015) is not supported. 

Driver builds successfully on kernels 5.0 to 5.16 (haven't tested on earlier kernels)  
At this time, only the speakers work with this driver (no wired headphone support)  
In order to use wired headphones, you must switch between this driver and the stock kernel driver  

**Terminology**   
headphones == wired headphones (not bluetooth)  
speaker driver == this driver   
headphone driver == stock kernel driver  


Compiling and installing driver:
-------------

**fedora package install**
```
dnf install wget symlinks make gcc kernel-devel
```
**ubuntu package install**  
```
apt install wget symlinks make gcc linux-headers-generic
```
**arch package install**  
```
pacman -S wget symlinks make gcc linux-headers
```
**build driver**  
```
git clone https://github.com/leifliddy/macbook12-audio-driver.git  
cd macbook12-audio-driver/
# run the following command as root or with sudo
./install.cirrus.driver.sh
reboot
```

At this point, the speakers should (hopefully) be working. You can stop here if you don't plan on using headphones.

Following the steps below to switch between the speaker and heaphone drivers results in subpar sounding speakers.  
If you want to use headphones, I would recommend that you run the **switch.audio.driver.sh** script and reboot.  
Perform the same steps again when you want to use the speakers.  


Switching between the speaker and headphone drivers:
-----------
Things get a bit convoluted here....


**Edit /etc/pulse/default.pa**  (to be able to reload the sound modules without rebooting)  
   With the changes listed in the **pulse_audio_configs/default.pa** file

**Activate PulseAudio Changes**  
```
sudo chmod -x /usr/bin/pulseaudio
sudo killall -9 pulseaudio
sudo chmod +x /usr/bin/pulseaudio
pulseaudio --start  # as normal user
```
Note: might be easier to just reboot  


**Use provided support scripts to switch between the speaker and headphone driver**  
1. **switch.audio.driver.sh** (run as root or with sudo)  
   Script will toggle between the headphone and speaker driver, but won't work if active audio streams are present.  


2. **pulse.switch.audio.sh** (run as normal user)  
   Script will also toggle between the speaker and headphone driver and will work if active audio streams are present.   
   Since this script calls **switch.audio.driver.sh**, the normal user running this script must have the necessary sudo rights.  
   ie:  
   **/etc/sudoers**   
   youruser ALL=(ALL) NOPASSWD: /usr/local/bin/switch.audio.driver.sh 

   Note: **pulse.switch.audio.sh** works perfectly on Fedora 31. Had trouble getting it to work reliably on Ubuntu 19.04  
