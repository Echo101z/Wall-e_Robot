
#include<Servo.h>
Servo se;


//Define Pins
//Motor A
int enableA = 5;
int MotorA1 = 6;
int MotorA2 = 7;
const int trig=4;
const int echo=2;
 int led=12;
 int buzz=13;
//Motor B
int enableB = 8;
int MotorB1 = 9;
int MotorB2 = 10;
long duration;
int distance;
int rightdistance,leftdistance;
int si=0;



/////***************search**********************8

int search(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);

  digitalWrite(trig,HIGH);
  delayMicroseconds(2);

  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  
 Serial.print("Distance:");
 Serial.println(distance);
 return distance;
 
 }
//////////***************

void setup() {
  //configure pin modes
  pinMode (enableA, OUTPUT);
  pinMode (MotorA1, OUTPUT);
  pinMode (MotorA2, OUTPUT);  
  pinMode (trig,OUTPUT);
  pinMode (echo,INPUT);
  pinMode (enableB, OUTPUT);
  pinMode (MotorB1, OUTPUT);
  pinMode (MotorB2, OUTPUT);   // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
  Serial.begin (9600);
  se.attach(11);
  //se.write(0);
  //delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:

if(si==1){
se.write(90);
 delay(1000);
 //se.write(175);
 //delay(500);
 //se.write(5);
 //delay(500);
 distance=search();
Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
   
//left();
 // backward();
//stop1();
if(distance<30)
{
// digitalWrite (enableA, LOW);
 //digitalWrite (enableB, LOW);
 changepath();
}

 else if ((distance >=30 ) && (distance < 90))
{
se.write(90);
delay(1000);
Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
  delay (1000);
  forward();
}

else{
  forward();
}}


else{

if(Serial.available()>0)
 { char data = Serial.read();
 switch(data)
{case 'A':si=si+1; 
Serial.println(si);
if(si==1)
{se.write(90);
 delay(1000);
 //se.write(175);
 //delay(500);
 //se.write(5);
 //delay(500);
 distance=search();
Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
   
//left();
 // backward();
//stop1();
if(distance<30)
{
// digitalWrite (enableA, LOW);
 //digitalWrite (enableB, LOW);
 changepath();
}

 else if ((distance >=30 ) && (distance < 90))
{
se.write(90);
delay(1000);
Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
  delay (1000);
  forward();
}

else{
  forward();
}
} break;


case 'D': si=si+1;
         break;
default: break;}}}}






         




/*if(distance>20)
 {Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
  delay (1000);
 }//do something
*/




/*
else if(distance<20)
{
 Serial.println ("Enabling Motors");
  digitalWrite (enableA, HIGH);
  digitalWrite (enableB, HIGH);
  delay (1000);
  backward();
  }
*/

 
 

 void stop1(){
  
   Serial.println ("Motion stop");
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, LOW);

  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, LOW);
  delay (500);
  
  }
 
 
 
void right(){
//Serial.println ("Enabling Motors");
 // digitalWrite (enableA, HIGH);
 // digitalWrite (enableB, HIGH);
 // stop1();
  Serial.println ("Motion right");
  digitalWrite (MotorA1, HIGH);
  digitalWrite (MotorA2, LOW);

  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
delay (1000);
  
} 
 
 void left()
{
  //stop1();
  Serial.println ("Motion left");
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);

  digitalWrite (MotorB1, HIGH);
  digitalWrite (MotorB2, LOW);
  delay (1000);
}



void backward()
{  
  Serial.println ("Motion backward");
  digitalWrite (MotorA1, LOW);
  digitalWrite (MotorA2, HIGH);

  digitalWrite (MotorB1, LOW);
  digitalWrite (MotorB2, HIGH);
  delay (1000);
}


  
  
  void forward(){ 

// Serial.println ("Enabling Motors");
  //digitalWrite (enableA, HIGH);
  //digitalWrite (enableB, HIGH);
  Serial.println ("Motion Forward");
  digitalWrite (MotorA1, HIGH);
  digitalWrite (MotorA2, LOW);
  //analogWrite (enableA,500);
  //analogWrite (enableB,500);
  digitalWrite (MotorB1,HIGH);
  digitalWrite (MotorB2, LOW);
  delay (700);
  

}







void changepath(){      
  //digitalWrite (enableA, HIGH);
  //digitalWrite (enableB, HIGH);
  //stop1();                 
  backward();              
  led1();
  stop1();
  se.write (5);           // Check Distance to the Right.
  delay (500);              
  rightdistance = search (); 
  delay (500);               
  se.write (175);         
  delay (1000);             
  leftdistance=search();  
  delay (500);
  led2();                             // Delay for 0.5s.
  se.write(90);           // Return to center.
 // delay (500);               // Delay for 0.5s.
  CompareDistance();        // Find the longest distance.
}
void CompareDistance() {                   // Distance Compare loop.
  if (rightdistance >= leftdistance) {       // If Right is less obstructed.
     right();  
     
     // Robot Turn into Right direction.
    }
  else if (leftdistance > rightdistance) {  // If Left is less obstructed.
      left(); 
     // Robot Turn into Left direction.
    }
  //else {                                    // If both are equally obstructed.
    //  turnaround ();                        // Robot Turn Around.
    //}
}

void led2(){
  
  // pinMode(led, OUTPUT);
   digitalWrite(led,LOW);
   delay(200);
   digitalWrite(buzz,LOW);
   
   delay(200);
  
  
  }


void led1(){
   //pinMode(led, OUTPUT);
   digitalWrite(led,HIGH);
   delay(200);
    digitalWrite(buzz,HIGH);
   delay(200);
  }
