#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// Pines de los LED
const int ledIzqSup = 18;
const int ledDerSup = 19;
const int ledIzqInf = 13;
const int ledDerInf = 15;

// Configuracion de la pantalla OLED
#define ANCHO_OLED 128
#define ALTO_OLED 64
#define OLED_RESET -1
#define OLED_DIRECCION 0x3C

Adafruit_SSD1306 display(
  ANCHO_OLED,
  ALTO_OLED,
  &Wire,
  OLED_RESET
);

void setup() {
  // Configurar los LED como salidas
  pinMode(ledIzqSup, OUTPUT);
  pinMode(ledDerSup, OUTPUT);
  pinMode(ledIzqInf, OUTPUT);
  pinMode(ledDerInf, OUTPUT);

  // Apagar todos los LED
  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  digitalWrite(ledDerInf, LOW);

  // Iniciar comunicacion I2C: SDA = 21, SCL = 22
  Wire.begin(21, 22);

  // Iniciar pantalla OLED
  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_DIRECCION)) {
    while (true) {
      delay(100);
    }
  }

  display.clearDisplay();
  display.display();

  actualizarOLED();
}

// Dibuja una flecha segun los LED encendidos
void actualizarOLED() {
  bool izqSup = digitalRead(ledIzqSup) == HIGH;
  bool derSup = digitalRead(ledDerSup) == HIGH;
  bool izqInf = digitalRead(ledIzqInf) == HIGH;
  bool derInf = digitalRead(ledDerInf) == HIGH;

  // Detectar exactamente los dos LED de la izquierda
  bool izquierda = izqSup && izqInf && !derSup && !derInf;

  // Detectar exactamente los dos LED de la derecha
  bool derecha = derSup && derInf && !izqSup && !izqInf;

  // Detectar exactamente los dos LED superiores
  bool arriba = izqSup && derSup && !izqInf && !derInf;

  // Detectar exactamente los dos LED inferiores
  bool abajo = izqInf && derInf && !izqSup && !derSup;

  display.clearDisplay();

  // Dibujar flecha hacia la izquierda
  if (izquierda) {
    display.drawLine(25, 32, 103, 32, SSD1306_WHITE);
    display.drawLine(25, 32, 43, 14, SSD1306_WHITE);
    display.drawLine(25, 32, 43, 50, SSD1306_WHITE);
  }

  // Dibujar flecha hacia la derecha
  else if (derecha) {
    display.drawLine(25, 32, 103, 32, SSD1306_WHITE);
    display.drawLine(103, 32, 85, 14, SSD1306_WHITE);
    display.drawLine(103, 32, 85, 50, SSD1306_WHITE);
  }

  // Dibujar flecha hacia arriba
  else if (arriba) {
    display.drawLine(64, 52, 64, 12, SSD1306_WHITE);
    display.drawLine(64, 12, 44, 32, SSD1306_WHITE);
    display.drawLine(64, 12, 84, 32, SSD1306_WHITE);
  }

  // Dibujar flecha hacia abajo
  else if (abajo) {
    display.drawLine(64, 12, 64, 52, SSD1306_WHITE);
    display.drawLine(64, 52, 44, 32, SSD1306_WHITE);
    display.drawLine(64, 52, 84, 32, SSD1306_WHITE);
  }

  // Si no hay un par exacto, la pantalla queda vacia
  display.display();
}

void loop() {

  // ==========================================
  // SECUENCIA 1: LED uno por uno
  // ==========================================

  digitalWrite(ledIzqSup, HIGH);
  actualizarOLED();
  delay(500);
  digitalWrite(ledIzqSup, LOW);
  actualizarOLED();
  delay(300);

  digitalWrite(ledDerSup, HIGH);
  actualizarOLED();
  delay(500);
  digitalWrite(ledDerSup, LOW);
  actualizarOLED();
  delay(300);

  digitalWrite(ledIzqInf, HIGH);
  actualizarOLED();
  delay(500);
  digitalWrite(ledIzqInf, LOW);
  actualizarOLED();
  delay(300);

  digitalWrite(ledDerInf, HIGH);
  actualizarOLED();
  delay(500);
  digitalWrite(ledDerInf, LOW);
  actualizarOLED();
  delay(500);


  // ==========================================
  // SECUENCIA 2: Pares de LED
  // ==========================================

  // Dos LED de la izquierda: flecha izquierda
  digitalWrite(ledIzqSup, HIGH);
  digitalWrite(ledIzqInf, HIGH);
  actualizarOLED();
  delay(800);

  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  actualizarOLED();
  delay(400);

  // Dos LED de la derecha: flecha derecha
  digitalWrite(ledDerSup, HIGH);
  digitalWrite(ledDerInf, HIGH);
  actualizarOLED();
  delay(800);

  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledDerInf, LOW);
  actualizarOLED();
  delay(400);

  // Dos LED superiores: flecha arriba
  digitalWrite(ledIzqSup, HIGH);
  digitalWrite(ledDerSup, HIGH);
  actualizarOLED();
  delay(800);

  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledDerSup, LOW);
  actualizarOLED();
  delay(400);

  // Dos LED inferiores: flecha abajo
  digitalWrite(ledIzqInf, HIGH);
  digitalWrite(ledDerInf, HIGH);
  actualizarOLED();
  delay(800);

  digitalWrite(ledIzqInf, LOW);
  digitalWrite(ledDerInf, LOW);
  actualizarOLED();
  delay(400);


  // ==========================================
  // SECUENCIA 3: Todos los LED a la vez
  // ==========================================

  digitalWrite(ledIzqSup, HIGH);
  digitalWrite(ledDerSup, HIGH);
  digitalWrite(ledIzqInf, HIGH);
  digitalWrite(ledDerInf, HIGH);

  actualizarOLED();
  delay(1000);

  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  digitalWrite(ledDerInf, LOW);

  actualizarOLED();
  delay(1500);
}