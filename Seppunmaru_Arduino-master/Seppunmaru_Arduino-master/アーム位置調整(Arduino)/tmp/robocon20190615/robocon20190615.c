#include <Servo.h>
/*
//int state3 = LOW;
//int state4 = LOW; //
//int state5 = LOW;
//int state6 = LOW; //
//int state7 = LOW; //

double Duration = 0; //受信間隔
double Distance = 0; //取得した距離
int trigPin = 9;
int echoPin = 10;

//Servo servo1;
//Servo servo2;
//Servo HUG;
//Servo LIFT;

void RX2Arduino(void){

  // RXからの命令読み取り
  delay(1);
  state6 = digitalRead(6);
  state7 = digitalRead(7);
  state4 = digitalRead(4);
  
  //サーボ用コマンド
  if(state6 == LOW && state7 == LOW && state4 == LOW){
    //Serial.println("Arm_Put");  //ペットボトルを置く
    servo1.write(76);
    servo2.write(115);
  }
  else if(state6 == LOW && state7 == HIGH && state4 == LOW){
    //Serial.println("Arm_Midle");  //持ち上げる
    servo1.write(120);
    servo2.write(175);
  }
  else if(state6 == HIGH && state7 == LOW && state4 == LOW){
    //Serial.println("Arm_Low");  //下げる
    servo1.write(50);
    servo2.write(50);
  }
  else if(state6 == HIGH && state7 == HIGH && state4 == LOW){
    //Serial.println("Arm_Catch");  //掴む
    //servo1.write(30);
    servo2.write(28);
  }

  //待機状態
  else if(state6 == LOW && state7 == LOW && state4 == HIGH){
    //Serial.println("HUG_WAIT_DOWN");
    HUG.write(130);//open
    LIFT.write(10);//down
  }

  //つかむ動作
  else if(state6 == HIGH && state7 == LOW && state4 == HIGH){
    //Serial.println("HUG_CATCH");
    HUG.write(10);//close
    LIFT.write(10);//down
  }

  //上げる動作
  else if(state6 == LOW && state7 == HIGH && state4 == HIGH){
    //Serial.println("HUG_WAIT_UP");
     HUG.write(10);//close
     LIFT.write(68);//up
  }

  //下げる動作
  else if(state6 == HIGH && state7 == HIGH && state4 == HIGH){
    //Serial.println("OPEN_UP");
    HUG.write(130);//open
    LIFT.write(68);//up
  }
  
  else{
    //Serial.println("Arm_Stay");
    servo1.write(140);
    //servo2.write(10);
  }
  delay(500);
}

void Ultrasonic_sensor(void){
  //超音波センサ設定
  digitalWrite(2, HIGH);
  digitalWrite(12,LOW);
  delay(10);
  digitalWrite(12, HIGH);
  delay(10);
  //digitalWrite(trigPin, LOW);
  //delay(20);
  digitalWrite(trigPin, HIGH);
  delay(20);
  digitalWrite(trigPin, LOW);
  Duration = pulseIn(echoPin, HIGH);
  //Serial.print("Duration = ");
  //Serial.println(Duration);

  //超音波センサ読み取り
  if(Duration > 0){
    Duration = Duration/2;
    Distance = Duration*340*100/1000000;
    //Serial.print("Distance:");
    //Serial.print(Distance);
    //Serial.println(" [cm]");
    if(Distance < 5.0 && Distance >= 0.0){
      digitalWrite(2, LOW);
      delay(20);
    }
    else if(Distance < 15.0 && Distance >= 5.0){
      digitalWrite(5, LOW);
      delay(20);
    }
    else{
      digitalWrite(2, HIGH);
      digitalWrite(5, HIGH);
      delay(20);
      }
    }  
}
*/

void setup() {
  Serial.begin(19200);
/*
  pinMode(2, OUTPUT); //超音波センサ検出信号用
  pinMode(5, OUTPUT); //予備用
//  pinMode(3, INPUT); // サーボ2 命令信号受信用_2桁目
  pinMode(4, INPUT); // サーボ2 命令信号受信用_1桁目
  pinMode(6, INPUT); // サーボ1 命令信号受信用_2桁目
  pinMode(7, INPUT); // サーボ1 命令信号受信用_1桁目
  servo1.attach(8); // 平行リンク用
  servo2.attach(11); // UVG引っ張り用
  HUG.attach(3);//ピラミッド　Max缶用
  LIFT.attach(13);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(12, OUTPUT); // 超音波センサスイッチング用
*/
}

void loop() {

  //Serial.println("start");
/*
  LIFT.write(10);
  HUG.write(170);

  servo1.write(50);
  servo2.write(50);

  delay(3000);

  while(true){
    Ultrasonic_sensor();
  
    RX2Arduino();
  }
*/
}
