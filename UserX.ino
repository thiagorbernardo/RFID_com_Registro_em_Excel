void UserX() {
  if (Acesso[3] == 0) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Banca");
    Serial.print(",");
    Serial.print("000000");
    Serial.print(",");
    Serial.println("Entrou");
  } if (Acesso[3] == 1) {
    Serial.print("DATA, DATE, TIME,");
    Serial.print("Banca");
    Serial.print(",");
    Serial.print("000000");
    Serial.print(",");
    Serial.println("Saiu");
  }
  if (Acesso[3] == 0) {
    Acesso[3]++;
  } else {
    Acesso[3]--;
  }
}
