//Here we are using bluetooth to give command,P for planting and S for pre rinsing of cloths
//As in simulation bluetooth is connected to serial ports so printing on serial ports will give notification on connect bluetooh device 
int trigPin = 9;
int echoPin = 10
void setup() {
pinMode(13, OUTPUT);
pinMode(A5, INPUT);
Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
} 
void loop() {

   digitalWrite(trigPin,LOW);
delayMicroseconds(2);
digitalWrite(trigpin,HIGH);
delayMicroseconds(10);
int duration=pulseIn(echoPin,HIGH);
 float distance=(duration*0.034/2);
 int tds = analogRead(A5);
 int TDS = tds*(5/1023);
 int TDS = TDS * 500
   if (Serial.available() > 0)
  {
    char c = Serial.read();

       if(c == 'P')
      {
         if (TDS > 300)
         { 
          if (distance <0.1)
         
            {
            digitalWrite(7,HIGH);
            digitalWrite(4,HIGH);
            }
           if (distance <0.02)
           { 
             digitalWrite(7,LOW);
          digitalWrite(4,LOW);
           }
          if (TDS < 300)
          { Serial.println("Your water for planting is ready")
          }
       }
       
       if(c == 'C')
      {
         if (TDS > 400)
         { 
          if (distance <0.07)
         
            {
            digitalWrite(7,HIGH);
            digitalWrite(4,HIGH);
            }
           if (distance <0.02)
           { 
             digitalWrite(7,LOW);
          digitalWrite(4,LOW);
           }
           if (TDS <400)
           { Serial.println("Your water for pre-risning is ready")
           }
       }

  delay(1000);
}
