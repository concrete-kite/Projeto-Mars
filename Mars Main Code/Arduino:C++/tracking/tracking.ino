#include <Servo.h>
#include "inofun.h"

#define pinServo 9

String IncomingData;

Servo servox;
Servo servoy;

int servo_xpos = 90;
int servo_ypos = 90;
int notStarted = 1;
int spd;

struct tuple vec;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(50);
  servox.attach(pinServo); 
  // servoy.attach();
  servox.write(servo_xpos);
  //servoy.write(servo_ypos);
  vec.x = 0.0;
  vec.y = 0.0;
  spd = 1;
}

void loop() {

     //double dist = distance(vec);

     if(Serial.available() > 0){
       IncomingData = Serial.readString(); 
       struct data input = parcedata(IncomingData);
       vec = mapValues(input);
       
         if( vec.x >= 10.0){
          vec = unitvector(vec);
          simple_move(vec);
         }
       //iterrations = 0;
       }//else{
//       if(dist >= 10.0){
//         vec = unitvector(vec);
//         simple_move(vec);
//        }
//        iterrations++;
//     }
}
