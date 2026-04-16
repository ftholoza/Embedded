CC = avr-gcc
OBJCOPY = avr-objcopy
AVRDUDE = avrdude

SRC_FILE = ex01.c
ELF_FILE = ex01.elf
HEX_FILE = ex01.hex
BIN_FILE = ex01.bin

MCU = atmega328p
F_CPU = 16000000UL

CFLAGS = -Wall -Wextra
CFLAGS += -mmcu=$(MCU)
CFLAGS += -DF_CPU=$(F_CPU)

all: hex flash

hex: $(HEX_FILE)

$(ELF_FILE): $(SRC_FILE)
	$(CC) $(CFLAGS) -o $(ELF_FILE) $(SRC_FILE)

$(BIN_FILE): $(ELF_FILE)
	$(OBJCOPY) -O binary $(ELF_FILE) $(BIN_FILE)

$(HEX_FILE): $(BIN_FILE)
	$(OBJCOPY) -I binary -O ihex $(BIN_FILE) $(HEX_FILE)

flash: $(HEX_FILE)
	$(AVRDUDE) -p $(MCU) -c arduino -P /dev/ttyUSB0 -b 115200 -U flash:w:$(HEX_FILE):i

clean:
	rm -f $(ELF_FILE) $(BIN_FILE) $(HEX_FILE)

.PHONY: all hex flash clean

