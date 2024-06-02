#!/usr/bin/env bash
avr-g++ -mmcu=atmega328p -O2 -std=c++11 -I. -c led.cpp -o bin/led.o
avr-g++ -mmcu=atmega328p  bin/led.o -o bin/led.elf
avr-objcopy -O ihex bin/led.elf bin/led.hex
