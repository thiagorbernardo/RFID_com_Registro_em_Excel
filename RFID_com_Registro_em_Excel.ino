// Projeto: Elaboração de Controle de Acesso por RFID em Excel em uma Catraca Mecânica.
// Grupo: Alexandre da Silva Mateus; João Lucas Mizuguchi Ferreira; Thiago Ramos Bernardo.
// Programador: Thiago Ramos Bernardo
// Base: FILIPEFLOP / Embarcados
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.
const int RelePin = 5; // pino ao qual o Módulo Relé está conectado

int Acesso[4] = {0, 0, 0, 0}; //Adicionar mais um ",0 " para cada novo usuário cadastrado

void setup() {
  SPI.begin();        // Inicia  SPI bus
  Serial.begin(9600); // Inicia a serial
  pinMode(RelePin, OUTPUT); // seta o pino como saída
  mfrc522.PCD_Init(); // Inicia MFRC522
  //  mensagemnicial();
  Serial.println();
  Serial.println("CLEARDATA");
  Serial.println("LABEL, Data, Hora, Nome, Prontuario, Estado");
  Serial.println("MSG, Starting data run");
}

void loop() {
  RFID();

}

void RFID() {
  // Procura novos cartões
  if ( ! mfrc522.PICC_IsNewCardPresent())

  {
    return;
  }
  // Seleciona um dos cartões
  if ( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  //Mostra UID na serial
  Serial.print("UID da tag :");
  String conteudo = "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
    conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
    conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Mensagem : ");
  conteudo.toUpperCase();
  if (conteudo.substring(1) == "A5 87 0B 88") //UID 1 - Tag / Thiago
  {
    Serial.println("LABEL, Data, Hora, Nome, Prontuario, Estado");
    User1630148();

    mensageminicial();
    ativarRele();
  }
  if (conteudo.substring(1) == "CC 4B D6 35") //UID 2 - Cartão / Alexandre
  {
    Serial.println("LABEL, Data, Hora, Nome, Prontuario, Estado");
    User1630113();

    mensageminicial();
    ativarRele();
  }
  if (conteudo.substring(1) == "F4 D6 59 BA") //UID 3 - Cartão / João
  {
    Serial.println("LABEL, Data, Hora, Nome, Prontuario, Estado");
    User1630164();

    mensageminicial();
    ativarRele();
  }
  if (conteudo.substring(1) == "34 30 79 BA") //UID 4 - Cartão / Jacob
  {
    Serial.println("LABEL, Data, Hora, Nome, Prontuario, Estado");
    UserX();

    mensageminicial();
    ativarRele();
  }

}
void mensageminicial()
{
  Serial.println("Aproxime o seu cartao ou tag do leitor...");
}
//https://medium.com/@islamnegm/quick-start-to-simple-daq-system-using-plx-daq-excel-arduino-d2457773384b
//http://www.scielo.br/pdf/rbef/v38n3/1806-1117-rbef-38-03-e3503.pdf

void ativarRele()
{
    digitalWrite(RelePin, HIGH); //aciona o pino
    delay(1000);
    digitalWrite(RelePin, LOW); //aciona o pino
}
