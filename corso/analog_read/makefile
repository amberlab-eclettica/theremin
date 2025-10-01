FQBN = arduino:avr:nano
PORT = /dev/ttyUSB0
BUILD_DIR = build
SKETCH = analog_read.ino
BAUD = 9600

all:
	arduino-cli compile --fqbn $(FQBN) --output-dir $(BUILD_DIR) $(SKETCH)

upload: all
	arduino-cli upload -p $(PORT) --fqbn $(FQBN) --input-dir $(BUILD_DIR)
	arduino-cli monitor -p $(PORT) -c baudrate=$(BAUD)

clean:
	rm -rf $(BUILD_DIR)

list:
	arduino-cli board list
