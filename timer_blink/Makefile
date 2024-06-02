FILENAME   = main
PORT       = /dev/ttyUSB0
DEVICE     = atmega328p
PROGRAMMER = stk500v1
BAUD       = 19200
CLOCK      = F_CPU=8000000
COMPILE    = avr-gcc -Wall -Os -D $(CLOCK) -mmcu=$(DEVICE)


default: compile upload clean

compile:
	$(COMPILE) -c $(FILENAME).c -o $(FILENAME).o
	$(COMPILE) -o $(FILENAME).elf $(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(FILENAME).elf $(FILENAME).hex 
	avr-size --format=avr --mcu=$(DEVICE) $(FILENAME).elf

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex
