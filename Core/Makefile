
all:
	tup

upload:
	cd Build/Platforms/Arduino/UnoR3; \
	avrdude -F -V -c arduino -p ATMEGA328P -P /dev/cu.usbmodem1411 -b 115200 -U flash:w:gazebo.hex
