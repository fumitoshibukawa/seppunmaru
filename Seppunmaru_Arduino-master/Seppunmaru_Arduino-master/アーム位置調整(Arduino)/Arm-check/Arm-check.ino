// *********************************
// *** 前方サーボモータ用        ***
// *** 立ってる缶，ペットボトル  ***
// *********************************
#include <Servo.h>

Servo servo1;
Servo servo2;

void setup() {
  
  Serial.begin(19200);

  servo1.attach(8);   // 平行リンク用
  servo2.attach(11);  // UVG引張用

  Serial.println("\n");
  Serial.println("Arm_Low");  //初期状態
  servo1.write(50); //50
  servo2.write(50);  //50

  // *** アーム ***
  Serial.println("1: Arm_Put");     // ペットボトルを置く
  Serial.println("2: Arm_Middle");  // 持ち上げる
  Serial.println("3: Arm_Low");     // 下げる
  Serial.println("4: Arm_Catch");   // つかむ
  
  Serial.println("\n"); 
}

void loop() {

  byte var = Serial.read();
  var -= 0x30;
 
  switch (var) {

    // *** アーム ***
    case 1:
      Serial.println("Arm_Put");  // ペットボトルを置く
      servo1.write(90);   // 80  台までの高さ：大きいと上
      servo2.write(125);  // 125 
      break;
    case 2:
      Serial.println("Arm_Middle");  // 持ち上げる
      servo1.write(140);  // 大きいと平行リンク持ち上げ 大
      servo2.write(200);  // 大きいと紐が緩む
      break;
    case 3:
      Serial.println("Arm_Low");  // 下げる
      servo1.write(50);
      servo2.write(50);
      break;
    case 4:
      Serial.println("Arm_Catch");  // つかむ
      servo2.write(10); // 23  つかむ距離：小さいと引き込む． 
       
    default:
      Serial.println("---waiting...---");
      break;
  }

  delay(3000);  // [ms]
}
