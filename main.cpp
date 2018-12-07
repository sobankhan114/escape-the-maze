
#include<Servo.h>

int duration1;
unsigned int dist1;
int duration2;
unsigned int dist2;
int duration3;
unsigned int dist3;

Servo s1;

int trig1=4;
int echo1=5;

int trig2=6;
int echo2=7;

int trig3=8;
int echo3=9;

void setup() {
Serial.begin(9600);
  
s1.attach(3);
pinMode(trig1,OUTPUT);pinMode(echo1,INPUT);
pinMode(trig2,OUTPUT);pinMode(echo2,INPUT);
pinMode(trig3,OUTPUT);pinMode(echo3,INPUT);

 
}

void loop() {
int pf,pl,pr;
pf=front();
pl=leftdistance();
pr=rightdistance();

Serial.print("Front = ");
    Serial.print(pf);
    Serial.print("\t Left = ");
    Serial.print(pl);
    Serial.print("\t Right = ");
    Serial.print(pr);
    Serial.println(" ");
    
    if(pl>92||pr>92){
      
      checkdoor();}

 s1.write(90); 
 delay(500);
 int d = front();
 
    
 if (d>20)
 { 
    forward();
  }
 if(d<18)
  {
     stopp();
    
  s1.write(30);
  delay(500);
  int r  = front();
  
  
  s1.write(155);
  delay(400);
  int l = front();
  
   if(r>25&&l<25)
    { stopp();
    right();
    delay(30);
    }

    if(l>25&&r<25)
    { stopp();
    left();
    delay(30);
    }
    
    
    if(r>l)
    { stopp();
    right();
    delay(30);
    }
    else if(r<l)
    {stopp();
      left();
      delay(30);
    }
    else{
    backward();
    delay(150);
    stopp();
    }
           
  }

    }
   
void backward()
{
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  }
void forward()
{
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  }
  void stopp()
  {
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    }
 void left()
 {
   digitalWrite(10,LOW);
   digitalWrite(11,HIGH);
   digitalWrite(12,HIGH);
   digitalWrite(13,LOW);
  }   
  void right()
  {
     digitalWrite(10,HIGH);
   digitalWrite(11,LOW);
   digitalWrite(12,LOW);
   digitalWrite(13,HIGH);
    }
int front()
    {
    
digitalWrite(trig1,LOW);
delayMicroseconds(2);
digitalWrite(trig1,HIGH);
delayMicroseconds(10);
digitalWrite(trig1,LOW);
delayMicroseconds(2);

duration1 = pulseIn(echo1, HIGH);
dist1= duration1*0.034/2;


return dist1;
        
      }


      int leftdistance()
    {
      
      digitalWrite(trig2,LOW);
      delayMicroseconds(2);
      digitalWrite(trig2,HIGH);
delayMicroseconds(10);
digitalWrite(trig2,LOW);
delayMicroseconds(2);

duration2 = pulseIn(echo2, HIGH);
dist2= duration2*0.034/2;
return dist2;  
      }
      
      int rightdistance()
                {
     
digitalWrite(trig3,LOW);
delayMicroseconds(2);
digitalWrite(trig3,HIGH);
delayMicroseconds(10);
digitalWrite(trig3,LOW);
delayMicroseconds(2);

duration3 = pulseIn(echo3, HIGH);
dist3= duration3*0.034/2;

return dist3;
      }

      void checkdoor()
      {
 int rd= rightdistance();
 int ld= leftdistance();
   if(rd>93||ld>93){
    
  if(rd > 2*ld)
 { stopp();
   right();
   delay(50);
  }
  
 if(ld > 2*rd)
 {
  stopp(); 
  left();
  delay(50);
  } 
    }
else{
  front();
  }
    
    }
    
  
