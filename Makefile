CFLAGS=-Iinclude -mmcu=atmega32 -DF_CPU=1000000 -Os -Wall -Werror

ADFLAGS=-c usbasp -p m32 -U lfuse:w:0xff:m -U hfuse:w:0xC9:m

ELFFILE=build/bms.elf
HEXFILE=build/bms.hex

all: $(HEXFILE) Makefile

$(HEXFILE): $(ELFFILE) Makefile
	rm -f $@
	avr-objcopy -j .text -j .data -O ihex $< $@

$(ELFFILE): Makefile source/*.c include/*.h
	avr-gcc $(CFLAGS) -o $@ source/*.c

clean:
	rm -f $(ELFFILE) $(HEXFILE)

prog: $(HEXFILE) Makefile
	sudo avrdude $(ADFLAGS) -U flash:w:$(HEXFILE):i

serial: prog
	sudo pk2serial

