// Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       SOS.ino
    Created:	12.01.2019 14:33:06
    Author:     DEXTER10\bodil
*/

// Define User Types below here or use a .h file
//
int pulse = 250;
String mrs_start = "-.-.-";
String mrs_S = "---";
String mrs_O = "...";
String mrs_stop = ".-.-.";
String mrs_chr_end = " ";
String mrs_wrd_end = "_";


// Define Function Prototypes that use User Types below here or use a .h file
//


// Define Functions below here or use other .ino or cpp files
//
void morseLong(uint8_t pin)
{
	Serial.print("-");
	blinkLED(pin, pulse * 3);
}

void morseShort(uint8_t pin)
{
	Serial.print(".");
	blinkLED(pin, pulse);
}

void morseCharEnd()
{
	Serial.print(" ");
	delay(pulse * 2);
}

void morseWordEnd()
{
	Serial.print(" ");
	delay(pulse * 2);
}
void blinkLED(uint8_t pin, int length)
{
	digitalWrite(pin, HIGH);
	delay(length);
	digitalWrite(pin, LOW);
	delay(pulse);
}


String mrs_message = "";
int index = 0;
// The setup() function runs once each time the micro-controller starts
void setup()
{
	Serial.begin(115200);
	pinMode(LED_BUILTIN, OUTPUT);
	mrs_message = mrs_start + mrs_chr_end + mrs_wrd_end + mrs_chr_end;
	mrs_message += mrs_S + mrs_chr_end + mrs_O + mrs_chr_end + mrs_S + mrs_chr_end + mrs_wrd_end + mrs_chr_end;
	mrs_message += mrs_S + mrs_chr_end + mrs_O + mrs_chr_end + mrs_S + mrs_chr_end + mrs_wrd_end + mrs_chr_end;
	mrs_message += mrs_S + mrs_chr_end + mrs_O + mrs_chr_end + mrs_S + mrs_chr_end + mrs_wrd_end + mrs_chr_end;
	mrs_message += mrs_stop;

}

// Add the main program code into the continuous loop() function
void loop()
{
	if (index < mrs_message.length())
	{
		char chr = mrs_message[index];
		switch (chr)
		{
		case '.': morseShort(LED_BUILTIN); break;
		case '-': morseLong(LED_BUILTIN); break;
		case ' ': morseCharEnd(); break;
		case '_': morseWordEnd(); break;
		}
		index++;
	}
	else
	{
		Serial.println();
		delay(pulse * 13);
		index = 0;
	}
}
