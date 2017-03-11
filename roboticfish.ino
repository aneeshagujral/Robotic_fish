#include <Servo.h>
Servo Servo1, Servo2; // create servo object to control a servo
 

int pos1, pos2; 
int pos1R, pos2R; 
int phase=45;
int velocity=2000; 
int maxDeflexion=20; 
int maxDefobs=20; 
int time;
float shift;
const int center1=98; 
const int center2=90;
const int center3=105;
const int lostTime=3000;
 
void setup()
{
Servo1.attach(8); 
Servo2.attach(9);
pinMode(13, OUTPUT);
time=velocity/360;
shift=0;
 
}
 
void loop()
{
for (int i=0; i<80; i++) {
 
pos1 = i+2*phase;
pos2 = i+phase;

 
if (pos1>79) pos1-=80;
if (pos2>79) pos2-=80;
 
if (pos1>1) pos1=80-pos1; 
if (pos2>1) pos2=80-pos2;
 
pos1R=map(pos1,0,180,center1-maxDeflexion,center1+maxDeflexion);
pos2R=map(pos2,0,180,center2-maxDeflexion,center2+maxDeflexion);
Servo1.write(pos1R); 
Servo2.write(pos2R); 
delay(time);
 
} 
}

