/*
 * IRremote: IRsendRawDemo - demonstrates sending IR codes with sendRaw
 * An IR LED must be connected to Arduino PWM pin 3.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 *
 * IRsendRawDemo - added by AnalysIR (via www.AnalysIR.com), 24 August 2015
 *
 * This example shows how to send a RAW signal using the IRremote library.
 * The example signal is actually a 32 bit NEC signal.
 * Remote Control button: LGTV Power On/Off. 
 * Hex Value: 0x20DF10EF, 32 bits
 * 
 * It is more efficient to use the sendNEC function to send NEC signals. 
 * Use of sendRaw here, serves only as an example of using the function.
 * 
 */

#define BUTTON 8
#define BUTTON2 9
#include <IRremote.h>

IRsend irsend;

void setup()
{pinMode(BUTTON, INPUT);
pinMode(BUTTON2, INPUT);
Serial.begin(9600);
}

void loop() {
  int Buttonstate = digitalRead(BUTTON);
  int Button2state = digitalRead(BUTTON2);
  int khz = 38; // 38kHz carrier frequency for the NEC protocol
  unsigned int irSignal[] = {2000, 5150, 450, 950, 400, 1950, 450, 900, 450, 1950, 400, 1950, 450, 900, 450, 1950, 400, 950, 450}; 
  unsigned int irSignalBack[] = {2050, 5150, 500, 1850, 450, 950, 450, 1900, 450, 900, 500, 850, 500, 1900, 450, 900, 450, 1900, 450, 
2050, 5100, 500, 1900, 450, 1950, 400, 1950, 500, 1900, 450, 900, 450, 900, 450, 900, 450, 900, 500, 
2050, 5150, 400, 2000, 450, 1900, 500, 1900, 450, 1950, 450, 850, 500, 850, 500, 900, 450, 900, 450, 
2000, 5150, 450, 1950, 450, 1900, 450, 1950, 450, 1900, 450, 900, 450, 900, 500, 900, 450, 900, 450, 
2000, 5150, 450, 1950, 450, 1900, 500, 1900, 500, 1900, 450, 850, 500, 850, 500, 900, 450, 900, 450, 
2000, 5150, 450, 1950, 450, 1900, 500, 1900, 450, 1950, 450, 850, 450, 900, 500, 900, 450, 900, 450, 
2050, 5150, 400, 2000, 450, 1900, 500, 1900, 450, 1950, 450, 850, 500, 850, 500, 900, 450, 900, 450, 
2000, 5150, 450, 1950, 450, 1900, 450, 1950, 450, 1900, 450, 900, 450, 900, 500, 900, 450, 900, 450, 
2050, 5150, 450, 1900, 500, 1900, 450, 1950, 450, 1900, 450, 900, 450, 900, 450, 900, 500, 850, 500, 
2050, 5100, 500, 1900, 450, 1950, 450, 1900, 500, 1900, 400, 950, 450, 900, 450, 900, 450, 900, 500, 
2050, 5100, 500, 1900, 450, 1950, 450, 1900, 500, 1900, 400, 950, 450, 900, 500, 850, 500, 850, 500, 
2000, 5150, 500, 1900, 450, 1900, 500, 1900, 450, 1950, 450, 850, 500, 850, 500, 900, 450, 900, 450, 
2000, 5150, 450, 1950, 450, 1950, 400, 1950, 450, 1950, 400, 950, 450, 900, 450, 900, 450, 900, 450, 
2050, 5150, 400, 1950, 500, 1900, 450, 1900, 500, 1950, 450, 850, 450, 900, 500, 900, 450, 900, 450, 
2050, 5150, 450, 1900, 500, 1900, 450, 1900, 500, 1950, 350, 950, 400, 950, 450, 950, 400, 950, 450, 
2050, 5150, 450, 1900, 500, 1900, 450, 1950, 500, 1900, 450, 850, 450, 900, 450, 950, 450, 900, 450, 
2050, 5150, 450, 1900, 500, 1900, 400, 1950, 500, 1900, 450, 900, 400, 950, 450, 950, 450, 900, 450};
  
  if (Buttonstate == LOW){
  Serial.println("BUTTON");
  irsend.sendRaw(irSignal, sizeof(irSignal) / sizeof(irSignal[0]), khz); //Note the approach used to automatically calculate the size of the array.
  delay(100); //In this example, the signal will be repeated every 5 seconds, approximately.
  }
  if (Button2state == LOW){
    Serial.println("BUTTON2");
  irsend.sendRaw(irSignalBack, sizeof(irSignalBack) / sizeof(irSignalBack[0]), khz);
  delay(100);
  }
  
  
}
