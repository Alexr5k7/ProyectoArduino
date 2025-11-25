const int ROWS = 8;
const int COLS = 8;

const int row[ROWS] = {
  2,  // fila 1 
  3,  // fila 2
  4,  // fila 3
  5,  // fila 4
  6,  // fila 5
  7,  // fila 6
  8,  // fila 7
  9   // fila 8
};

const int col[COLS] = {
  10, // columna 1
  11, // columna 2
  12, // columna 3
  13, // columna 4
  A0, // columna 5
  A1, // columna 6
  A2, // columna 7
  A3  // columna 8
};

const int JOY_X = A4;    
const int JOY_SW = A5;   

int cursorCol = 0;       
bool joyNeutral = true;
unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150; // ms

void setup() {
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }

  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);
  }

  pinMode(JOY_X, INPUT);
  pinMode(JOY_SW, INPUT_PULLUP); 
}

void updateJoystick() {
  int x = analogRead(JOY_X);
  unsigned long now = millis();

  bool left  = (x < 400);
  bool right = (x > 600);

  if ((left || right) && (joyNeutral || now - lastMoveTime > MOVE_DELAY)) {
    if (left && cursorCol > 0) {
      cursorCol--;
    } else if (right && cursorCol < COLS - 1) {
      cursorCol++;
    }
    lastMoveTime = now;
    joyNeutral = false;
  }

  if (x >= 450 && x <= 570) {
    joyNeutral = true;
  }
}

void refreshDisplay() {
  static int currentRow = 0;

  digitalWrite(row[currentRow], HIGH);

  currentRow++;
  if (currentRow >= ROWS) currentRow = 0;

  for (int c = 0; c < COLS; c++) {
    bool ledOn = (currentRow == 0 && c == cursorCol);
    digitalWrite(col[c], ledOn ? HIGH : LOW);
  }

  digitalWrite(row[currentRow], LOW);
}

void loop() {
  updateJoystick();   
  refreshDisplay();   
}