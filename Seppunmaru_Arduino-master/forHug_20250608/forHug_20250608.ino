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

  //たわみには気をつけよう
  //待機状態（開いて下へ）
  if(PortD0 == LOW && PortD1 == LOW && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_WAIT_DOWN");
    //HUG.write(150);//open元の値
    HUG.write(160);
    LIFT.write(10);//down
  }

  //つかむ動作（閉まる動作）
  else if(PortD0 == HIGH && PortD1 == LOW && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_CATCH");
    HUG.write(0);//close
    LIFT.write(10);//down
  }

  //あげる動作（閉じて上）
  else if(PortD0 == LOW && PortD1 == HIGH && PortD2 == LOW && PortD3 == LOW){
    Serial.println("HUG_WAIT_UP");
     HUG.write(0);//close
     LIFT.write(70);//up 68
  }

  //はなす動作（上で開く）
  else if(PortD0 == LOW && PortD1 == LOW && PortD2 == HIGH && PortD3 == LOW){
    Serial.println("OPEN_UP");
    HUG.write(160);//open
    //HUG.write(150);//元の値
    LIFT.write(70);//up 68
  }
  
  //スタートポジ（MAXまで開く．競技台に入る）
  else if(PortD0 == LOW && PortD1 == LOW && PortD2 == LOW && PortD3 == HIGH){
    Serial.println("HUG_START_POSI");
    HUG.write(170); //元の値．open
    //→168くらいでもいいかな
    //HUG.write(150); //open
    //LIFT.write(20);//down
    LIFT.write(10);//down元の値
  }

  //ピラミッド前の状態(真上で三角形を作る)
  if(PortD0 == LOW && PortD1 == LOW && PortD2 == HIGH && PortD3 == HIGH){
    Serial.println("HUG_PYRAMID_UP");
    HUG.write(100); //80
    LIFT.write(70);
  }

  //ピラミッド回収時の状態(三角形のまま下す)
  if(PortD0 == LOW && PortD1 == HIGH && PortD2 == HIGH && PortD3 == HIGH){
    Serial.println("HUG_PYRAMID_DOWN");
    HUG.write(100); //80
    LIFT.write(10);
  }

  //ブルドーザー
  if(PortD0 == LOW && PortD1 == HIGH && PortD2 == LOW && PortD3 == HIGH){
    Serial.println("HUG_BULLDOZE");
    HUG.write(120);
    LIFT.write(10);
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
  HUG.write(170); //元の値．新しい保持機構だとこのままでは競技台にぶつかる
  //HUG.write(150);

  delay(3000);

  while(true){
    
    RX2Arduino();
    
  }
}
