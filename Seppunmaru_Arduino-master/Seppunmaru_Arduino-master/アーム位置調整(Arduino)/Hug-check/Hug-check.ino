// *********************************
// *** 後方サーボモータ用        ***
// *** ピラミッド，Max缶，ボール ***
// *********************************
#include <Servo.h>

Servo HUG;
Servo LIFT;

void setup() {
  
  Serial.begin(19200);

  HUG.attach(3);  // ハグ機構用
  LIFT.attach(4);  // 持ち上げ用
  
  Serial.println("HUG_START_POS");  // スタート位置
  HUG.write(170);
  LIFT.write(10);
  
  Serial.println("\n");

  // *** ハグ機構 ***
  Serial.println("1: HUG_WAIT_DOWN");  // 下して待機
  Serial.println("2: HUG_CATCH");      // つかむ
  Serial.println("3: HUG_WAIT_UP");    // 上げる
  Serial.println("4: OPEN_UP");        // 下す
  Serial.println("5: HUG_START_POS");  // スタート位置
  Serial.println("6: LIFT_UP");        // リフトアップ
  
  Serial.println("\n"); 
}


void loop() {

  byte var = Serial.read();
  var -= 0x30;

  switch (var) {

    case 1:
      Serial.println("HUG_WAIT_DOWN");  // 下して待機
      HUG.write(130);
      LIFT.write(10);
      break;
    case 2:
      Serial.println("HUG_CATCH");  // つかむ
      HUG.write(10);
      delay(1000);
      LIFT.write(10);
      break;
    case 3:
      Serial.println("HUG_WAIT_P");  // 上げる
      HUG.write(10);
      LIFT.write(68);
      break;
    case 4:
      Serial.println("OPEN_UP");  // 下す
      LIFT.write(68);
      delay(1000);
      HUG.write(130);
      break;
    case 5:
      Serial.println("HUG_START_POS");  // スタート位置
      HUG.write(170);
      LIFT.write(10);
      break; 
    case 6:
      Serial.println("LIFT_UP");  // リフトアップ
      //HUG.write(170);
      LIFT.write(68);
      break;
    case 7:
      Serial.println("HUG_PYRAMID_UP"); //ピラミッド前の状態(真上で三角形を作る)
      HUG.write(70);
      LIFT.write(90);
      break;
    case 8:
      Serial.println("HUG_PYRAMID_DOWN"); //ピラミッド回収時の状態(三角形のまま下す)
      HUG.write(70);
      LIFT.write(10);
      break;

    
    default:
      Serial.println("---waiting...---");
      break;
  }

  delay(3000);  // [ms]
}
