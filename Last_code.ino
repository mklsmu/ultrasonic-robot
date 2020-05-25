#include <NewPing.h>
#define SONARC 10
#define SONARL 11
#define SONARR 6
#define MAX_DISTANCE 200
#define NUM_SONAR 3

const int A1A = 2;
const int A1B = 3;
const int B1A = 8;
const int B1B = 9;

NewPing sonar[NUM_SONAR] = {
NewPing(SONARC, SONARC, MAX_DISTANCE),
NewPing(SONARL, SONARL, MAX_DISTANCE),
NewPing(SONARR, SONARR, MAX_DISTANCE)
};
int distance[NUM_SONAR];

void setup() {
  Serial.begin(115200);
  pinMode(B1A,OUTPUT);
  pinMode(B1B,OUTPUT);
  pinMode(A1A,OUTPUT);
  pinMode(A1B,OUTPUT);
}
void sonarset(){
    delay(50);
  updateSonar();
  Serial.print("SONARC: ");
  Serial.print(distance[0]);
  Serial.print("  SONARL: ");
  Serial.print(distance[1]);
  Serial.print("  SONARR: ");
  Serial.println(distance[2]);
}
void updateSonar() {
  for (int i = 0; i < NUM_SONAR; i++) {
    distance[i] = sonar[i].ping_cm();
    if (distance[i] == 0)
      distance[i] = MAX_DISTANCE;}}
void process(){
if(distance[0] >= 20){forward();}
if(distance[0] <= 35){
  reverse();
  delay(750);
  left();
  delay(750);
}
if(distance[1] <= 35){
  reverse();
  delay(750);
  right();}
  delay(400);
if(distance[2] <= 35){
  reverse();
  delay(750);
  left();}
  delay(400);
  }
void forward(){
 motorA('L');
 motorB('L');}
void reverse(){
 motorA('R');
 motorB('R');}
void motoroff(){
 motorA('O');
 motorB('O');}
void left(){
 motorA('L');
 motorB('R');}
void right(){
 motorA('R');
 motorB('L');}
 void rotate(){
 motorA('L');
 motorB('R');}
void motorA(char d)
{
  if(d =='R'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,HIGH); 
  }else if (d =='L'){
    digitalWrite(A1A,HIGH);
    digitalWrite(A1B,LOW);    
    }else if(d =='O'){
    digitalWrite(A1A,LOW);
    digitalWrite(A1B,LOW);    
  }
}
void motorB(char d)
{
    {
    if(d =='R'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,HIGH); 
    }else if(d =='L'){
      digitalWrite(B1A,HIGH);
      digitalWrite(B1B,LOW);    
    }else if(d =='O'){
      digitalWrite(B1A,LOW);
      digitalWrite(B1B,LOW);     
    }
}}
void loop() {
   sonarset(); 
   forward();
   reverse();
   left();
   right();
   motoroff();
   process();
}
