# RFID RC522 with Raspebery Pi 3B+
Author: Nguyen Huynh Dang Khoa - Victor Nguyen
February 2020
Major: Embedded System - Computer Science
University: Danang University of Sciences and Technology

## About
This project is to learn about the RFID scanner RC522 which is very popular in the marketplace.  
- I use a library from stm32f4 from the Internet "rfid-rc522" which you can find somewhere, then try to port  
  to stm32f103c8 and Raspberry Pi 3B+ for my personal usage.  
- The SPIRpi library is developed by myself and you can download, redistribute it freely.

## How to use ?
- Just download to your RPi, run Makefile.
- Run "sudo ./build/prog" which is the program to test the RFID.
- Put you RFID card to the scanner and see the result.

## Troubleshoot
- Sometimes you cannot run the program maybe because you haven't enable the SPI bus 0.0
  Try to enable it. Check ls /dev | grep "spidev0.0" to verify this.
- GPIO that i used is GPIO17, you can actually change this.

# Hope you love this.
