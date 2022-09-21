// C++ code
//
const int buzzer = 9; //buzzer to arduino pin 9

int trig=6; //ultrsonic sensor
int led=12;
int echo=4;

  void setup()
{
 pinMode(5,OUTPUT); // led setup
 pinMode(10,OUTPUT); 
 pinMode(7,OUTPUT); 
 Serial.begin(9600);
    
 pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
    
 pinMode (2,INPUT); Serial.begin(9600);  //set pir sensor as output 

 Serial.begin(9600);
 pinMode(trig,OUTPUT);
 pinMode(echo,INPUT);
 pinMode(led,OUTPUT);   
}

void loop()
{
digitalWrite(5,HIGH);
Serial.println("5 LED_ON");
digitalWrite(10,HIGH);
Serial.println("10 LED_ON"); 
digitalWrite(7,HIGH);
Serial.println("7 LED_ON"); 
delay(2000);
digitalWrite(5,LOW);
Serial.println("5 LED_OFF");
digitalWrite(10,LOW);
Serial.println("10 LED_OFF");
digitalWrite(7,LOW);
Serial.println("7 LED_OFF");
delay(2000); 
  

tone(buzzer, 1000); // Send 1KHz sound signal...
delay(1000);        // ...for 1 sec
noTone(buzzer);     // Stop sound...
delay(1000);        // ...for 1sec
  

int p =digitalRead(2); Serial.print ("Motion: "); Serial.println(p);  

 digitalWrite(trig,LOW);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  float dur=pulseIn(echo,HIGH);
  float dist=(dur*0.0343)/2;
  Serial.print("distance in cm");
  Serial.println(dist);
  if(dist>=100)
  {
    digitalWrite(led,HIGH);
  }
 else
 {
   digitalWrite(led,LOW);
 } 
  
}










