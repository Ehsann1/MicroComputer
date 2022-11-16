FILENAME     = /Users/ehsan/Desktop/o/C/Exe/1
PORT         = /dev/cu.usbserial-10
DEVICE       = atmega32a
PROGRAMMER   = stk500
BAUD         = 115200
COMPILE      = avr-gcc -Wall -Os -mmcu=$(DEVICE)
mega32a_In_Ocilator_8MHZF = -U lfuse:w:0xe4:m -U hfuse:w:0xd9:m







default: upload 

upload:
	avrdude -v -p $(DEVICE) -c $(PROGRAMMER) -P $(PORT) -b $(BAUD) -U flash:w:$(FILENAME).hex:i $(mega32a_In_Ocilator_8MHZF)

clean:
	rm $(FILENAME).o
	rm $(FILENAME).elf
	rm $(FILENAME).hex