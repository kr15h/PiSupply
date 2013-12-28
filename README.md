PiSupply
========

A C++ program that handles the [Pi Supply](http://www.pi-supply.com) switch.

Instructions
============

1. Log in to your Raspberry Pi via SSH
...
ssh pi@your-pi-ip-or-host
...
2. Make sure that you have git installed
sudo apt-get install git-core
sudo apt-get update
sudo apt-get upgrade

3. Go to home directory and Install [http://wiringpi.com](WiringPi)
cd /home/pi
git clone git://git.drogon.net/wiringPi
cd wiringPi
git pull origin
./build

4. Go to the PiSupply  directory and clone this repo
cd /home/pi/PiSupply
git clone https://github.com/kr15h/PiSupply.git

5. Compile using GCC 
cd PiSupply
gcc -o piSupply -I/usr/local/include -L/usr/local/lib -lwiringPi main.cpp

6. Launch application and see if it works. The code inside main.cpp uses GPIO pin 7 to listen for the soft shutdown signal.
sudo ./piSupply

Launch in Background
====================

You might be interested to launch this in background so you can launch other apps and services. I doubt that the PiSupply could be the only reason for using the Raspberry Pi. To launch the application in background, use the following command:
nohup sudo ./piSupply &

In my case I've added this to a startup shell script so it is launched when my RPi boots up. I won't explain it here now, there are a lot of different ways to do that.

Hope this will be useful for somebody.
