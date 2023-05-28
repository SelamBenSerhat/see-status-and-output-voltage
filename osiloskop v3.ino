#include <ezButton.h>
int buttonState = 0;

ezButton toggleSwitch(3);

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
   Serial.begin(9600);
toggleSwitch.setDebounceTime(50);
}



void loop() {

//buton kısmı

 toggleSwitch.loop();

  if (toggleSwitch.isPressed()) 

   digitalWrite(7, LOW); //19v 
digitalWrite(8, LOW); //12v

  
if (toggleSwitch.isReleased())

    digitalWrite(7, HIGH); //19v 
digitalWrite(8, HIGH); //12v


 int state = toggleSwitch.getState();
  if (state == HIGH)
    Serial.println("Aku sarj modumdayim");
  else
    Serial.println("Kullanim modumdayim");

  
//serial kısmı
      int analogv;
   float v;
   analogv = analogRead(A3);
   v = analogv/204.6*32,5; 
   delay(500);
   Serial.print("19V degeri:");
   Serial.println(v);

   int analogvalue;
   float voltage;
   analogvalue = analogRead(A2);
   voltage = analogvalue/204.6*4.6; 
   delay(500);
   Serial.print("aku voltaji:");
   Serial.println(voltage);
        
  
        
}
