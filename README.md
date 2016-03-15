# Lamp
## Introduction
First Proof of Concepts after lot of TeX generation  
This project is intended to create an Internet of Things for Amirkabir University of Technology. This project uses [KAA](https://kaaproject.org) as the middle server.
![Lamp Project Architecture](http://www.googledrive.com/host/0B33KzMHyLoH2eVNHWFJZdmthOVk/Lamp-Architecture.jpg)

## How we did this awesome project :D
1. main.c contains source code for simple turn on and off of the lamp.
2. Using KAA for turning the light on
  1. Created lamp application in the KAA server.
  2. Created **mandatory** notification topic for our lamp.
  3. Registered our notification topic in the endpoint groups.

## How we learn to do this awesome project :D
* This guide is useful for learning UNIX C Serial Programming: [UNIX Serial C Programming](https://www.cmrr.umn.edu/~strupp/serial.html)
* This guide is useful for connecting your application to KAA server: [Your first KAA application](https://docs.kaaproject.org/display/KAA/Your+first+Kaa+application)
* You need this for emulating serial port: [Null modem emulator](https://github.com/freemed/tty0tty)

## Contributors
* [Prof. Bahador Bakhshi](http://ceit.aut.ac.ir/~bakhshis/)
* [Parham Alvani](http://1995parham.github.io/)
* [Iman Tabrizian](https://github.com/Tabrizian)
