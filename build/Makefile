###############################################################################
# Makefile for project 
###############################################################################

## General options
PROJECT = 
MCU = ATmega32
COMPILER = "WinAVR"
TARGET = Debug
SHELL = C:\windows\system32\cmd.exe

## Tools general options
CCFLAGS=-Wall -gdwarf-2 -fsigned-char -MD -MP -DF_CPU=1000000 -O1 -mmcu=atmega32
LDFLAGS=-mmcu=atmega32

## Processing Tools
CC=avr-gcc.exe
ASM=avr-gcc.exe
LD=avr-gcc.exe
#  C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/Debug.elf: TOOL=LD
#  Post: $(OBJ) avr-objcopy -O ihex -R .eeprom "./Debug.elf" "./Debug.hex"
#  Post: $(OBJ) avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex "./Debug.elf" "./Debug.eep" || exit 0 
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/main.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/main.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/gpio.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/gpio.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/batv.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/batv.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/spix.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/spix.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/wait.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/wait.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/amux.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/amux.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/adcx.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/adcx.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/sseg.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/sseg.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/uart.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/uart.c
#     C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATMEGA32/Debug/cmdx.o: TOOL=CC
#        C:/users/admin/Temp/a9793c7ed60745bd9474cc87e25af027/ATmega32/cmdx.c

# Build tree:
all:	Debug

Debug:	Debug.elf

Debug.elf:	main.o gpio.o batv.o spix.o wait.o amux.o adcx.o sseg.o uart.o cmdx.o 
	$(LD) $(LDFLAGS)  -o "./Debug.elf" "main.o" "gpio.o" "batv.o" "spix.o" "wait.o" "amux.o" "adcx.o" "sseg.o" "uart.o" "cmdx.o"
	$(OBJ) avr-objcopy -O ihex -R .eeprom "./Debug.elf" "./Debug.hex"
	$(OBJ) avr-objcopy -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex "./Debug.elf" "./Debug.eep" || exit 0 

main.o:	../main.c 
	$(CC) $(CCFLAGS)  -o "main.o" -c "../main.c"

gpio.o:	../gpio.c 
	$(CC) $(CCFLAGS)  -o "gpio.o" -c "../gpio.c"

batv.o:	../batv.c 
	$(CC) $(CCFLAGS)  -o "batv.o" -c "../batv.c"

spix.o:	../spix.c 
	$(CC) $(CCFLAGS)  -o "spix.o" -c "../spix.c"

wait.o:	../wait.c 
	$(CC) $(CCFLAGS)  -o "wait.o" -c "../wait.c"

amux.o:	../amux.c 
	$(CC) $(CCFLAGS)  -o "amux.o" -c "../amux.c"

adcx.o:	../adcx.c 
	$(CC) $(CCFLAGS)  -o "adcx.o" -c "../adcx.c"

sseg.o:	../sseg.c 
	$(CC) $(CCFLAGS)  -o "sseg.o" -c "../sseg.c"

uart.o:	../uart.c 
	$(CC) $(CCFLAGS)  -o "uart.o" -c "../uart.c"

cmdx.o:	../cmdx.c 
	$(CC) $(CCFLAGS)  -o "cmdx.o" -c "../cmdx.c"

# tidy - delete all temporary files which are not involved in the target generation
tidy:
	rm -rf ./main.d
	rm -rf ./gpio.d
	rm -rf ./batv.d
	rm -rf ./spix.d
	rm -rf ./wait.d
	rm -rf ./amux.d
	rm -rf ./adcx.d
	rm -rf ./sseg.d
	rm -rf ./uart.d
	rm -rf ./cmdx.d

# cleanup - delete all generated files
clean:	tidy
	rm -rf Debug.elf
	rm -rf main.o
	rm -rf gpio.o
	rm -rf batv.o
	rm -rf spix.o
	rm -rf wait.o
	rm -rf amux.o
	rm -rf adcx.o
	rm -rf sseg.o
	rm -rf uart.o
	rm -rf cmdx.o
