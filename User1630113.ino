void User1630113() {
  if (Acesso[1] == 0) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Alexandre");
    Serial.print(",");
    Serial.print("1630113");
    Serial.print(",");
    Serial.println("Entrou");
  } if (Acesso[1] == 1) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Alexandre");
    Serial.print(",");
    Serial.print("1630113");
    Serial.print(",");
    Serial.println("Saiu");
  }
  if (Acesso[1] == 0) {
    Acesso[1]++;
  } else {
    Acesso[1]--;
  }
}
