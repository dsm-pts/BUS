#include <SPI.h>
#include "printf.h"
#include "RF24.h"

#define F_IN1 2  //앞 모터드라이버 1번 핀
#define F_IN2 3  //앞 모터드라이버 2번 핀
#define F_IN3 4  //앞 모터드라이버 3번 핀
#define F_IN4 5  //앞 모터드라이버 4번 핀

#define L_IN1 6  //뒷 모터드라이버 1번 핀
#define L_IN2 7  //뒷 모터드라이버 2번 핀
#define L_IN3 8  //뒷 모터드라이버 3번 핀
#define L_IN4 9  //뒷 모터드라이버 4번 핀

//int lineTraceSensor //라인 트레이스 센서 핀 번호 ;


RF24 radio(A1, A2);

uint8_t address[][6] = {"1Node", "2Node"};
bool radioNumber = 1;
bool role = false;
float payload = 0.0;


void forward(){
  digitalWrite(F_IN1, HIGH);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, HIGH);
  digitalWrite(F_IN4, LOW);

  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, HIGH);
  digitalWrite(L_IN4, LOW);
}

void back(){
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, HIGH);
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, HIGH);

  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, HIGH);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, HIGH);
}

void left(){
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, HIGH);
  digitalWrite(F_IN4, LOW);

  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, HIGH);
  digitalWrite(L_IN4, LOW);
}

void right(){
  digitalWrite(F_IN1, HIGH);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, LOW);

  digitalWrite(L_IN1, HIGH);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, LOW);
}


void motorStop(){
  digitalWrite(F_IN1, LOW);
  digitalWrite(F_IN2, LOW);
  digitalWrite(F_IN3, LOW);
  digitalWrite(F_IN4, LOW);

  digitalWrite(L_IN1, LOW);
  digitalWrite(L_IN2, LOW);
  digitalWrite(L_IN3, LOW);
  digitalWrite(L_IN4, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  /*while (!Serial){}
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {} // hold in infinite loop
  }
  Serial.println(F("RF24/examples/GettingStarted"));
  Serial.println(F("Which radio is this? Enter '0' or '1'. Defaults to '0'"));
  while (!Serial.available()) {
    // wait for user input
  }
  char input = Serial.parseInt();
  radioNumber = input == 1;
  Serial.print(F("radioNumber = "));
  Serial.println((int)radioNumber);

  Serial.println(F("*** PRESS 'T' to begin transmitting to the other node"));
  radio.setPALevel(RF24_PA_LOW);
  radio.setPayloadSize(sizeof(payload));
  radio.openWritingPipe(address[radioNumber]);
  radio.openReadingPipe(1, address[!radioNumber]);

  if (role) {
    radio.stopListening();  // put radio in TX mode
  } else {
    radio.startListening(); // put radio in RX mode
  }
  */
  pinMode(F_IN1, OUTPUT); // 전 좌 모터 1
  pinMode(F_IN2, OUTPUT); // 전 좌 모터 2
  pinMode(F_IN3, OUTPUT); // 전 우 모터 1
  pinMode(F_IN4, OUTPUT); // 전 우 모터 2

  pinMode(L_IN1, OUTPUT); // 후 좌 모터 1
  pinMode(L_IN2, OUTPUT); // 후 좌 모터 2
  pinMode(L_IN3, OUTPUT); // 후 우 모터 1
}

void loop() {
  // put your main code here, to run repeatedly:
  /*if (role) {
    // This device is a TX node

    unsigned long start_timer = micros();                    // start the timer
    bool report = radio.write(&payload, sizeof(float));      // transmit & save the report
    unsigned long end_timer = micros();                      // end the timer

    if (report) {
      Serial.print(F("Transmission successful! "));          // payload was delivered
      Serial.print(F("Time to transmit = "));
      Serial.print(end_timer - start_timer);                 // print the timer result
      Serial.print(F(" us. Sent: "));
      Serial.println(payload);                               // print payload sent
      payload += 0.01;                                       // increment float payload
    } else {
      Serial.println(F("Transmission failed or timed out")); // payload was not delivered
    }

    // to make this example readable in the serial monitor
    delay(1000);  // slow transmissions down by 1 second

  }

  else {
    // This device is a RX node

    uint8_t pipe;
    if (radio.available(&pipe)) {             // is there a payload? get the pipe number that recieved it
      uint8_t bytes = radio.getPayloadSize(); // get the size of the payload
      radio.read(&payload, bytes);            // fetch payload from FIFO
      Serial.print(F("Received "));
      Serial.print(bytes);                    // print the size of the payload
      Serial.print(F(" bytes on pipe "));
      Serial.print(pipe);                     // print the pipe number
      Serial.print(F(": "));
      Serial.println(payload);                // print the payload's value
    }
  } // role
  */  
  
  forward();
  delay(500);
  back();
  delay(500);
  left();
  delay(500);
  right();
  delay(500);
  motorStop();
  delay(3000);
  
}
