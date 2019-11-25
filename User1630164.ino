void User1630164() {
  if (Acesso[2] == 0) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Joao");
    Serial.print(",");
    Serial.print("1630164");
    Serial.print(",");
    Serial.println("Entrou");
  } if (Acesso[2] == 1) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Joao");
    Serial.print(",");
    Serial.print("1630164");
    Serial.print(",");
    Serial.println("Saiu");
  }
  if (Acesso[2] == 0) {
    Acesso[2]++;
  } else {
    Acesso[2]--;
  }
}










