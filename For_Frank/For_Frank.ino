int speakerPin = 11;
int ledPin = 8;
int length = 15; // the number of notes
char notes[] = "ccggaagffeeddc "; // a space represents a rest
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
int ledState = LOW;
long previousMillis = 0;
long interval = 900;
int intruptpin = 9;
volatile int state = LOW;

void playTone(int tone, int duration)
{
	for (long i = 0; i < duration * 1000L; i += tone * 2)
	{
		digitalWrite(speakerPin, HIGH);
		delayMicroseconds(tone);
		digitalWrite(speakerPin, LOW);
		delayMicroseconds(tone);
	}
}

void playNote(char note, int duration)
{
	char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
	int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };

	// play the tone corresponding to the note name
	for (int i = 0; i < 8; i++)
	{
		if (names[i] == note)
		{
			playTone(tones[i], duration);
		}
	}
}

void blink()
{
	state = !state;
	digitalWrite(intruptpin, state);


}

void setup()
{
	pinMode(speakerPin, OUTPUT);
	pinMode (ledPin, OUTPUT);
	pinMode(intruptpin, OUTPUT);
	attachInterrupt(0, blink, HIGH);
}

void loop()
{
	unsigned long currentMillis = millis();
	for (int i = 0; i < length; i++)
	{
		if (notes[i] == ' ')
		{
			delay(beats[i] * tempo); // rest
		}
		else
		{
			playNote(notes[i], beats[i] * tempo);
		}

		// pause between notes
		if (currentMillis - previousMillis > interval)
		{
			previousMillis = currentMillis;
			if (ledState == LOW)
			{
				ledState = HIGH;
			}
			else
			{
				ledState = LOW;
			}
			digitalWrite (ledPin, ledState);

		}
	}
}
