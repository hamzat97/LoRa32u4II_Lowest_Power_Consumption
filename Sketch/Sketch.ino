/*
* This sketch allows you to reduce the power consumption of LoRa32u4 II development board and all the boards based on ATMega32U4/16U4 as well as possible in a software way and without needing any library to install. 
*/

#include <avr/wdt.h> // Import AVR Watchdog Library 
#include <avr/sleep.h> // Import AVR Sleep Library        
   
#define VBATPIN A9 // This analog pin is dedicated for battery voltage measurement. LoRa32u4 II is a 3.3V logic board, and this is why a voltage divider by 2 (10 kOhm resistors) is integrated inside it for making the user able to measure voltages between 0V and 6.6V   
float Vbat; // Variable for the voltage battery measurements 

void setup() {  
 Serial.begin(9600); // Open serial port with 9600 bauds
 // Put your setup code here 
}

void loop() {
 // Put your code here 
 SavingPower(); // Call SavingPower function
 Vbat = analogRead(VBATPIN); // Read the battery voltage   
 Vbat *= 3.3; // Multiply by 3.3V, the reference voltage 
 Vbat /= 1023; // Divide by 1023 for converting the value to voltage, the analog-to-digital converter (ADC) assumes 3.3V is 1023
 Vbat *= 2; // We divided by 2, so multiply back    
 Serial.println(" --- Charge Level --- "); 
 Serial.print("Battery Voltage : " ); 
 Serial.print(Vbat); // Print the battery voltage out of the serial monitor 
 Serial.println(" Volts");  
}        

void SavingPower() {  
 // This for loop aims to reduce the power consumption of LoRa32u4 as well as possible for 10 minutes     
 for (int k=0;k<75;k++) {    
                           ACSR |= (1 <<ACD); // Write ACD bit (ACSR Register) to one to switch off the power of the analog comparator. In this case, this is optional because the microcontroller will enter power-down sleep mode and the analog comparator will be disabled automatically  
                           ADCSRA &= ~(1 << ADEN); // Write ADEN bit (ADCSRA Register) to zero to turn off the analog-to-digital converter (ADC) 
                           PRR0 |= (1 << PRADC); // Write PRADC bit (PRR0 Register) to one to shut down the ADC. We have to turn off the analog-to-digital converter (ADC) before shut down      
                           wdt_enable(WDTO_8S); // Enable the watchdog timer for 8 seconds. The values of the time-out period you can choose are : 16ms, 32ms, 64ms, 0.125s, 0.25s, 0.5s, 1s, 2s, 4s and 8s        
                           WDTCSR |= (1 << WDIE); // Use the watchdog timer as a timed interrupt by writing WDIE bit (WDTCSR Register) to one 
                           do {                  
                                set_sleep_mode(SLEEP_MODE_PWR_DOWN); // Power-down sleep mode is set here
                                noInterrupts(); // Disable interrupts             
                                sleep_enable(); // Enable sleep mode by writing SE bit (SMCR Register) to one      
                                interrupts(); // Enable interrupts         
                                sleep_cpu(); // Put the microcontroller into the selected sleep mode 
                                sleep_disable(); // Wake up from sleep mode by writing SE bit (SMCR Register) to zero          
                                interrupts(); // Enable interrupts            
                              } while (0); 
                        }
 PRR0 &= ~(1 << PRADC); // Write PRADC bit (PRR0 Register) to zero to start the analog-to-digital converter (ADC) 
 ADCSRA |= (1 << ADEN); // Write ADEN bit (ADCSRA Register) to one to enable the analog-to-digital converter (ADC)             
 ACSR &= ~(1 << ACD); // Write ACD bit (ACSR Register) to zero to switch on the power of the analog comparator. This is also optional with power-down sleep mode  
}

ISR (WDT_vect) {} // The microcontroller needs this function to use the watchdog timer interrupt. This function is so imprtant to extend the duration of sleep mode more than 8 seconds
