const int ROWS = 8;
const int COLS = 8;

const int row[ROWS] = {
  2,    // fila 1
  3,    // fila 2
  4,    // fila 3
  5,    // fila 4
  6,    // fila 5
  7,    // fila 6
  8,    // fila 7
  9     // fila 8
};

const int col[COLS] = {
  10,   // columna 1
  11,   // columna 2
  12,   // columna 3
  13,   // columna 4
  A0,   // columna 5
  A1,   // columna 6
  A2,   // columna 7
  A3    // columna 8
};

void setup() {
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], LOW);  

    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);  
  }
}

void loop() {
  for (int r = 0; r < ROWS; r++) {

    digitalWrite(col[r], HIGH);   

    for (int c = 0; c < COLS; c++) {

      digitalWrite(row[c], LOW);  
      delay(400);                 
      digitalWrite(row[c], HIGH); 
    }

    digitalWrite(col[r], LOW);    
  }
}