const int ledIzqSup = 18; // Izquierdo Superior
const int ledDerSup = 19; // Derecho Superior
const int ledIzqInf = 21; // Izquierdo Inferior
const int ledDerInf = 22; // Derecho Inferior

void setup() {
  // Configuramos todos los pines como salida
  pinMode(ledIzqSup, OUTPUT);
  pinMode(ledDerSup, OUTPUT);
  pinMode(ledIzqInf, OUTPUT);
  pinMode(ledDerInf, OUTPUT);
  
  // Aseguramos que inicien apagados (LOW)
  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  digitalWrite(ledDerInf, LOW);
}

void loop() {
  // --- SECUENCIA 1: Uno por uno (Encender y apagar) ---
  
  // 1. Izquierdo Superior
  digitalWrite(ledIzqSup, HIGH);
  delay(500);
  digitalWrite(ledIzqSup, LOW);
  delay(300);

  // 2. Derecho Superior
  digitalWrite(ledDerSup, HIGH);
  delay(500);
  digitalWrite(ledDerSup, LOW);
  delay(300);

  // 3. Izquierdo Inferior
  digitalWrite(ledIzqInf, HIGH);
  delay(500);
  digitalWrite(ledIzqInf, LOW);
  delay(300);

  // 4. Derecho Inferior
  digitalWrite(ledDerInf, HIGH);
  delay(500);
  digitalWrite(ledDerInf, LOW);
  delay(500);

  // --- SECUENCIA 2: Por pares (Izquierda, luego Derecha) ---

  // Se prenden los dos de la izquierda (Superior e Inferior)
  digitalWrite(ledIzqSup, HIGH);
  digitalWrite(ledIzqInf, HIGH);
  delay(800);
  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  delay(400);

  // Se prenden los dos de la derecha (Superior e Inferior)
  digitalWrite(ledDerSup, HIGH);
  digitalWrite(ledDerInf, HIGH);
  delay(800);
  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledDerInf, LOW);
  delay(400);

  // --- SECUENCIA 3: Todos a la vez ---

  // Se prenden todos
  digitalWrite(ledIzqSup, HIGH);
  digitalWrite(ledDerSup, HIGH);
  digitalWrite(ledIzqInf, HIGH);
  digitalWrite(ledDerInf, HIGH);
  delay(1000);

  // Se apagan todos
  digitalWrite(ledIzqSup, LOW);
  digitalWrite(ledDerSup, LOW);
  digitalWrite(ledIzqInf, LOW);
  digitalWrite(ledDerInf, LOW);
  
  // Pausa antes de repetir toda la secuencia
  delay(1500); 
}