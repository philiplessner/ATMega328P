FILENAME   = led
BUILDDIR    = $(CURDIR)/bin
PORT       = /dev/ttyUSB0
DEVICE     = atmega328p
PROGRAMMER = stk500v1
BAUD       = 19200
CLOCK      = F_CPU=8000000
COMPILE    = avr-g++ -Wall -O2 -std=c++11 -I.  -D $(CLOCK) -mmcu=$(DEVICE)
LDFLAGS = -Wl,-Map,$(BUILDDIR)/$(FILENAME).map 
LDFLAGS += -Wl,--gc-sections 

.PHONY: compile flash clean

default: compile flash clean

compile:
	mkdir -p $(BUILDDIR)
	$(COMPILE) -c $(FILENAME).cpp -o $(BUILDDIR)/$(FILENAME).o
	$(COMPILE) $(LDFLAGS) -o $(BUILDDIR)/$(FILENAME).elf $(BUILDDIR)/$(FILENAME).o
	avr-objcopy -j .text -j .data -O ihex $(BUILDDIR)/$(FILENAME).elf $(BUILDDIR)/$(FILENAME).hex 
	avr-size --format=avr --mcu=$(DEVICE) $(BUILDDIR)/$(FILENAME).elf
	avr-objdump -S $(BUILDDIR)/$(FILENAME).elf > $(BUILDDIR)/$(FILENAME).lst

flash:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(BUILDDIR)/$(FILENAME).hex:i

clean:
	rm -rf $(BUILDDIR)
