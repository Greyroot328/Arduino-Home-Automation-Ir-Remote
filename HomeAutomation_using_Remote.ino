//  Before running this code make sure to copy the IRremote folder to your Arduino Librabries
//  and also delete any previous library on IR remote
//  Developed By Naman Sinha 
// https://namansinha.in

#include <IRremote.h>

int IRpin = 12;
IRrecv irrecv(IRpin);
decode_results results;
int Relay1=7;               // Initializing the pins for Relay
int Relay2=8;
int Relay3=9;
int Relay4=10;
int val1=0;                 // Inializing the variable for storing the last status of Relay_pins
int val2=0;
int val3=0;
int val4=0;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(Relay1,OUTPUT);
  pinMode(Relay2,OUTPUT);
  pinMode(Relay3,OUTPUT);
  pinMode(Relay4,OUTPUT);
  digitalWrite(Relay1,HIGH);
  digitalWrite(Relay2,HIGH);
  digitalWrite(Relay3,HIGH);
  digitalWrite(Relay4,HIGH);
}  
void loop() 

{   
  if (irrecv.decode(&results)) 
    {
     Serial.println(results.value); // Print the Serial 'results.value'
      delay(10);

     irrecv.resume();   // Receive the next value
    }

    
    if(results.value==33444015)
    {
      val1=digitalRead(Relay1);
      if(val1==0)
      {
        digitalWrite(Relay1,HIGH);
        val1=1;
        delay(100);
      }
      else
      {
      digitalWrite(Relay1,LOW);
      val1=0;
      delay(100);
      }
    }

    
     if(results.value==33478695)
    {
      val1=digitalRead(Relay2);
      if(val2==0)
      {
        digitalWrite(Relay2,HIGH);
        val2=1;
        delay(100);
      }
       else
      {
      digitalWrite(Relay2,LOW);
      val2=0;
      delay(100);
      }
    }

    
     if(results.value==33486855)
    {
      val1=digitalRead(Relay3);
      if(val3==0)
      {
        digitalWrite(Relay3,HIGH);
        val3=1;
        delay(100);
      }
       else
      {
      digitalWrite(Relay3,LOW);
      val3=0;
      delay(100);
      }
    }

    
     if(results.value==33435855)
    {
      val4=digitalRead(Relay4);
      if(val4==0)
      {
        digitalWrite(Relay4,HIGH);
        val4=1;
        delay(100);
      }
       else
      {
      digitalWrite(Relay4,LOW);
      val4=0;
       delay(100);
      }
    }
    
}    
