void User1630148() {
  if (Acesso[0] == 0) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Thiago");
    Serial.print(",");
    Serial.print("1630148");
    Serial.print(",");
    Serial.println("Entrou");
  } if (Acesso[0] == 1) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Thiago");
    Serial.print(",");
    Serial.print("1630148");
    Serial.print(",");
    Serial.println("Saiu");
  }
  if (Acesso[0] == 0) {
    Acesso[0]++;
  } else {
    Acesso[0]--;
  }
}




