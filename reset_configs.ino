#include <EEPROM.h> // Biblioteca para acessar a memória flash

#define EEPROM_SIZE 96
#define RESET_PIN 0 // GPIO0 é geralmente o botão de "Flash"

// Função para limpar as configurações WiFi
void clearWiFiSettings() {
  EEPROM.begin(EEPROM_SIZE);
  for (int i = 0; i < EEPROM_SIZE; ++i) {
    EEPROM.write(i, 0);
  }
  EEPROM.end();
}

void setup() {
  pinMode(RESET_PIN, INPUT_PULLUP);
  Serial.begin(115200);

  // Verifica se o botão de "Flash" (GPIO0) está pressionado durante a inicialização
  if (digitalRead(RESET_PIN) == LOW) {
    clearWiFiSettings();
    Serial.println("Configurações WiFi limpas. Reinicie para reconfigurar.");
  }

  // Resto do seu código de configuração
}

void loop() {
  // Seu código principal aqui
}
