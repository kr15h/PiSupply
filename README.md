PiSupply
========

A C++ program that handles the [Pi Supply](http://www.pi-supply.com) switch.

Instructions
============

1. Log in to your Raspberry Pi via SSH<br>
```
ssh pi@111.222.333.444
```

2. Make sure that you have git installed<br>
```
sudo apt-get install git-core
sudo apt-get update
sudo apt-get upgrade
```

3. Go to home directory and Install [WiringPi](http://wiringpi.com)<br>
```
cd /home/pi
git clone git://git.drogon.net/wiringPi
cd wiringPi
git pull origin
./build
```

4. Go to home directory again and clone this repo.<br>
```
cd /home/pi
git clone https://github.com/kr15h/PiSupply.git
```

5. Enter the newly created PiSupply directory and Compile using GCC.<br>
```
cd PiSupply
gcc -o PiSupply -I/usr/local/include -L/usr/local/lib -lwiringPi main.cpp
```

6. Launch application and see if it works. The code inside main.cpp uses GPIO pin 7 to listen for the soft shutdown signal.<br>
```
sudo ./PiSupply
```

Launch in Background
====================

You might be interested to launch this in background so you can launch other apps and services. I doubt that the PiSupply could be the only reason for using the Raspberry Pi. To launch the application in background, use the following command:<br>
```
nohup sudo ./PiSupply &
```

In my case I've added this to a startup shell script so it is launched when my RPi boots up. I won't explain it here now, there are a lot of different ways to do that.

Hope this will be useful for somebody.
