/*
Read from and Write to a Hybrid Object

Copy the files from the interface folder 
to your Hybrid Object.

created 2015
by Valentin Heun
*/

#include <HybridObject.h>
HybridObject obj;

int counter =0;

void setup() {
obj.developer(); // allow developer tools
obj.add("LinechartTest", "led"); // add a new I/O Point to the Object
obj.add("LinechartTest", "sensor");
}

void loop() {
	
  // Read from sensor
  float reading = analogRead(A0); 
  Serial.println(reading);
  
  // Write to Object
  obj.write("LinechartTest", "sensor", reading);
  
  // Read from Object
  analogWrite(13, obj.read("LinechartTest", "led") * 255);
 
 delay(100);
}
