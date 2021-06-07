#define LMF 2 //d2
#define LMB 3 //d3

#define RMF 4 //d4
#define RMB 5 //d5

#define SP 18 //speed

#define IR1 5 //d7
#define IR2 6 //d8
#define IR3 7 //9

//#define CE 10
//#define CSN 9

int color, cnt;

void setup() {

  pinMode(IR1, INPUT);
  pinMode(IR2, INPUT);
  pinMode(IR3, INPUT);

  pinMode(LMF, OUTPUT);
  pinMode(LMB, OUTPUT);
  
  pinMode(RMF, OUTPUT);
  pinMode(RMB, OUTPUT);

  pinMode(SP, OUTPUT);
  analogWrite(SP, 255);

  color = 1;
  cnt == 0;

}

void loop() {
  
  if(color == 1){
    if(digitalRead(IR1) && !digitalRead(IR2) && !digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, LOW);
      digitalWrite(LMB, HIGH);  
    }
    else if(!digitalRead(IR1) && digitalRead(IR2) && !digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
    }
    else if(digitalRead(IR1) && digitalRead(IR2) && digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
    }
    else if(digitalRead(IR1) && digitalRead(IR2) && !digitalRead(IR3)){
      if(cnt%2 == 1){
        digitalWrite(RMF, HIGH);
        digitalWrite(RMB, LOW);
        digitalWrite(LMF, HIGH);
        digitalWrite(LMB, LOW);
        cnt++;
      }
      else{
        cnt = 1;
        digitalWrite(RMF, HIGH);
        digitalWrite(RMB, LOW);
        digitalWrite(LMF, LOW);
        digitalWrite(LMB, HIGH);  
      }
    }
    else {
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, LOW);
      digitalWrite(LMB, HIGH);  
    }
  }
  else if(color == 2){
    if(digitalRead(IR1) && !digitalRead(IR2) && !digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, LOW);
      digitalWrite(LMB, HIGH);  
    }
    else if(!digitalRead(IR1) && digitalRead(IR2) && !digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
    }
    else if(digitalRead(IR1) && digitalRead(IR2) && digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
    }
    else if(digitalRead(IR1) && digitalRead(IR2) && !digitalRead(IR3)){
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, HIGH);
      digitalWrite(LMB, LOW);
    }
    else {
      digitalWrite(RMF, HIGH);
      digitalWrite(RMB, LOW);
      digitalWrite(LMF, LOW);
      digitalWrite(LMB, HIGH);  
    }
  }
  
}
