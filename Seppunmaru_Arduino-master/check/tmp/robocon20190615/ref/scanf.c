void setup() {
  Serial.begin(9600);
}

void loop() {
  byte var = Serial.read();
  var = var - 0x30; // 追加の行

  switch (var) {
    case 1:
      //hoge(var);<-数値を送って何かをさせる処理
      Serial.println('1');
      break;
    case 2:
      //hoge(var);
      Serial.println('2');
      break;
    case 3:
      //hoge(var);
      Serial.println('3');
      break;
  }
}