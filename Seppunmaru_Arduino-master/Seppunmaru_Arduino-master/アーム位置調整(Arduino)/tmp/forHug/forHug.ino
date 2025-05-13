#include <Servo.h>

int PortD0 = LOW;
int PortD1 = LOW;
int PortD2 = LOW;
int PortD3 = LOW;

Servo HUG;
Servo LIFT;

void RX2Arduino(void){

  // RXからの命令読み取り
  delay(1);
  PortD0 = digitalRead(8);
  PortD1 = digitalRead(9);
  PortD2 = digitalRead(10);
  PortD3 = digitalRead(11);

  //待機状態
  if(PortD0 == LOW && PortD1 == LOW && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_WAIT_DOWN");
    HUG.write(150);//open元の値
    LIFT.write(10);//down
  }

  //つかむ動作
  else if(PortD0 == HIGH && PortD1 == LOW && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_CATCH");
    HUG.write(10);//close
    LIFT.write(10);//down
  }

  //あげる動作
  else if(PortD0 == LOW && PortD1 == HIGH && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_WAIT_UP");
     HUG.write(10);//close
     LIFT.write(68);//up
  }

  //下げる動作
  else if(PortD0 == LOW && PortD1 == LOW && PortD2 == HIGH && PortD3 == LOW){
    Serial.println("OPEN_UP");
    HUG.write(130);//open
    HUG.write(150);//元の値
    LIFT.write(68);//up
  }
  
  //スタートポジ
  else if(PortD0 == LOW && PortD1 == LOW && PortD2 == LOW && PortD3 == HIGH){
    Serial.println("HUG_START_POSI");
    HUG.write(170);//open
    LIFT.write(10);//down元の値
  }
  
  delay(500);
}

void setup() {
  
  Serial.begin(19200);

  pinMode(8, INPUT); // サーボ2 命令信号受信用_1桁目
  pinMode(9, INPUT); // サーボ1 命令信号受信用_2桁目
  pinMode(10, INPUT); // サーボ1 命令信号受信用_1桁目
  pinMode(11, INPUT); // サーボ1 命令信号受信用_1桁目
  HUG.attach(3);//ピラミッド　Max缶用
  LIFT.attach(4);
  
}

void loop() {

  Serial.println("start");

  LIFT.write(10);
  HUG.write(170);

  delay(3000);

  while(true){
    
    RX2Arduino();
    
  }
}
