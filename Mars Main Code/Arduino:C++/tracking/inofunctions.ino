#include "inofun.h"
#include <Servo.h>

double distance(struct tuple v){
  double output = (v.x * v.x) + (v.y * v.y);
  output = sqrt(output);
  return output;
}

struct tuple mapValues(struct data d){
  int x = map(d.x,0, d.width, (d.width/-2),(d.width/2));
  int y = map(d.y,0, d.height, (d.height/2),(d.height/-2));

  struct tuple output;
  output.x = (double) x;
  output.y = (double) y;
  return output;
}

int start(){
  String start_data;
  
  if(Serial.available() > 0){
    start_data = Serial.readString();
    if(start_data == "90,90,90,90,"){
       Serial.println("");
       return 0;
    }
    return 1;
   }

   return 1;
}

struct tuple unitvector(struct tuple v){
    struct tuple unit_v;
    double vector_length;

    double aux  = (v.x * v.x) + (v.y * v.y);
    aux = sqrt(aux);
    
    unit_v.x = v.x / aux;
    unit_v.y = v.y / aux;

    return unit_v;
}

struct data parcedata(String raw_data){// Lembrar de botar um , no final do codigo em python
    struct data output;

    int datasize = raw_data.length();
    datasize--;
    
    int switcher = 0;
    String temp = "";
    for (int i = 0; i < datasize; i++){
        if(raw_data[i] == ','){

           if(switcher == 0){
             output.x = temp.toDouble();
           }else if(switcher == 1){
             output.y = temp.toDouble();
           }else if(switcher == 2){
             output.width = temp.toInt();
           }else if(switcher == 3){
             output.height = temp.toInt();
           }else{
             break;
           }

          switcher++;
          temp = "";
          continue;
        }
        
        temp = temp + raw_data[i];
    }

    Serial.println(output.x);
    Serial.println(output.y);
    Serial.println(output.width);
    Serial.println(output.height);

    return output;
}

void simple_move(struct tuple v){

    if((v.x > 0) && (v.y > 0)){
      if(servo_xpos < 180){
        servo_xpos -= spd;
      }
      //servo_ypos += speed;
    }else if((v.x > 0) && (v.y < 0)){
      if(servo_xpos < 180){
        servo_xpos -= spd;
      }
      //servo_ypos -= speed;
    }else if((v.x < 0) && (v.y > 0)){
      if(servo_xpos > 0){
        servo_xpos += spd;
      }
      //servo_ypos += speed;
    }else{
      if(servo_xpos > 0){
        servo_xpos += spd;
      }
      //servo_ypos -= speed;
    }

    servox.write(servo_xpos);
    //servy.write(servo_ypos);
}