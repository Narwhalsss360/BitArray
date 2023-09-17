/*
	Using BitArray saves on memory,	instead of 1 byte for 1 boolean, 1 byte for 8 booleans.
	Best savings on multi-dimensional arrays.
*/

#include <BitArray.h>

#define BAUDRATE 115200
#define BUTTON_COUNT 10

//Array of pins that buttons are on. Do this to get button pin from index
byte buttonPins[BUTTON_COUNT] = { 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };

//Array of BUTTON_COUNT bits
BitArray<BUTTON_COUNT> bits;

void setup() {
	Serial.begin(115200);

	//Setting each pin as input pullup.
	for (int iPin = 0; iPin < BUTTON_COUNT; iPin++) {
		pinMode(buttonPins[iPin], INPUT_PULLUP);
	}
}

void loop() {
	readButtons();
	showButtonStates();
}

void readButtons() {
	for (int iButton = 0; iButton < BUTTON_COUNT; iButton++) {
		//Getting pin from button index.
		int pin = buttonPins[BUTTON_COUNT];
		bool state = digitalRead(pin);

		//!state because pin is input pullup and pushed means GND.
		bits.set(iButton, !state);
	}
}

void showButtonStates() {
	for (int iState = 0; iState < BUTTON_COUNT; iState++) {
		Serial.print("Button ");
		Serial.print(iState);
		Serial.print(" -> ");

		if (bits.get(iState)) {
			Serial.println("pushed");
		} else {
			Serial.println("released");
		}
	}
	Serial.println("-----------------");
	Serial.println();
}