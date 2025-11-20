const int ROWS = 8;
const int COLS = 8;

// FILAS (en orden fila 1 → fila 8)
const int row[ROWS] = {
  6,    // fila 1
  9,    // fila 2
  7,    // fila 3
  A1,   // fila 4
  3,    // fila 5
  2,    // fila 6
  10,   // fila 7
  12    // fila 8
};

// COLUMNAS (en orden columna 1 → columna 8)
const int col[COLS] = {
  5,    // columna 1
  11,   // columna 2
  A0,   // columna 3
  13,   // columna 4
  4,    // columna 5
 A2,   // columna 6
  8,    // columna 7
  A3    // columna 8
};

void setup() {
  // Filas (ánodos)
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], LOW);  // apagadas
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW); // apagadas
  }
}

void loop() {
    for (int r = 0; r < ROWS; r++) {
      digitalWrite(col[r], HIGH);
      for (int c = 0; c < COLS; c++) {

        digitalWrite(row[c], LOW);
        delay(100);
        digitalWrite(row[c], HIGH);
      }
      digitalWrite(col[r], LOW);
    }
}