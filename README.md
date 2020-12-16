# LoRa32u4II_Lowest_Power_Consumption
This Arduino sketch allows you, as a user of LoRa32u4 II development board, to reduce the energy consumption as well as possible, when that is required for expanding the lifespan of batteries. Besides that, this sketch is flexible because you won't need any power management library, and all you have to do is to upload this sketch to LoRa32u4 II board after making the necessary modifications that allow it to be adapted with your own application. You can reduce the power consumption of LoRa32u4 II board much more by turning off the regulator, but the aim of this work is to reduce its power consumption just by a software way for a remote management of energy consumption without any human interference. Lots of comments are added with the purpose of making the sketch completely easier for you to understand. 

This Arduino sketch is developed using ATMega32U4/16U4 Datasheet ([click here](http://ww1.microchip.com/downloads/en/devicedoc/atmel-7766-8-bit-avr-atmega16u4-32u4_datasheet.pdf)), this is why it can be used to reduce the power consumption of every board based on ATMega32U4/16U4 AVR microcontrollers by a software way. Also, it has been tested and verified successfully using BSFrance LoRa32u4 II V1.2 and Arduino IDE 1.8.8 release. 

LoRa32u4 II development boards have a power pin (BAT+) that makes you able to measure the battery voltage and know its state of charge. In this sketch for example, we measure the battery voltage at every 10 minutes. For more information about LoRa32u4 II board, click [here](http://www.diymalls.com/index.php?route=product/product&product_id=88).
## What do you need to do before using the sketch ?
First, you have to install adafruit driver (adafruit_drivers.exe in Software Tools folder) if you're running Windows on your computer in order to be able to upload the sketch to LoRa32u4 II using the mini USB cable. On the other hand, you don't have to install this driver if you're using a Linux computer. After that, you should copy the content of hardware folder (in Software Tools folder) into Documents/Arduino/hadrware folder, and if this last one doesn't already exist, so just copy hardware folder into Documents/Arduino, where libraries folder does exist. This step will make you able to use all the capabilities of LoRa library in your sketch and you will find LoRa32u4 II board in Tools/Board when you need to upload the Arduino sketch into it. In addition to that, you will find some examples inside this library that will help you understand how we use LoRa32u4 II to communicate with other devices using the same protocol (Software Tools\hardware\BSFrance\avr\LoRa\examples). Finally, I think beyond that the uploading of the sketch speaks for itself.  

Finally, I remain at your entire disposal, just contact me at my academic mail h.taous@ump.ac.ma if you have any questions or if you need any kind of assistance.
