void setup() {
  Serial.begin(9600);
}

void loop() {
  byte var = Serial.read();
  var = var - 0x30; // �ǉ��̍s

  switch (var) {
    case 1:
      //hoge(var);<-���l�𑗂��ĉ����������鏈��
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