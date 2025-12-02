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

const int JOY_X  = A4;    
const int JOY_SW = A5;   

// Estado del tablero:
// 0 = vacío
// 1 = ficha jugador 1 (siempre encendida)
// 2 = ficha jugador 2 (parpadea)
int board[ROWS][COLS];

int cursorCol = 0;       
bool joyNeutral = true;
unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150;

int lastButtonState = HIGH;
unsigned long lastButtonTime = 0;
const unsigned long BUTTON_DEBOUNCE = 150;

int currentPlayer = 1;

bool isAnimating = false;
int fallingRow = 0;
int fallingCol = 0;
int fallingPlayer = 1;

bool blinkPhase = false;
unsigned long lastBlinkTime = 0;
const unsigned long BLINK_INTERVAL = 300;

void setup() {
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }

  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);
  }

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = 0;
    }
  }

  pinMode(JOY_X, INPUT);
  pinMode(JOY_SW, INPUT_PULLUP); 
}

void updateBlink() {
  unsigned long now = millis();
  if (now - lastBlinkTime >= BLINK_INTERVAL) {
    lastBlinkTime = now;
    blinkPhase = !blinkPhase;
  }
}

void updateJoystick() {
  if (isAnimating) return;

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

void animateDrop(int colIndex, int destRow) {
  isAnimating = true;
  fallingCol = colIndex;
  fallingPlayer = currentPlayer;

  for (int r = 0; r <= destRow; r++) {
    fallingRow = r;

    for (int k = 0; k < 40; k++) {
      updateBlink();
      refreshDisplay();
      delay(2);
    }
  }

  board[destRow][colIndex] = fallingPlayer;
  isAnimating = false;

  currentPlayer = (currentPlayer == 1) ? 2 : 1;

  cursorCol = 0;
}

void tryDropPiece() {
  if (isAnimating) return;

  int c = cursorCol;

  int destRow = -1;
  for (int r = ROWS - 1; r >= 0; r--) {
    if (board[r][c] == 0) {
      destRow = r;
      break;
    }
  }

  if (destRow == -1) {
    return;
  }

  animateDrop(c, destRow);
}

void updateButton() {
  unsigned long now = millis();
  int state = digitalRead(JOY_SW);

  if (state != lastButtonState && (now - lastButtonTime) > BUTTON_DEBOUNCE) {
    lastButtonTime = now;

    if (state == LOW) {
      tryDropPiece();
    }

    lastButtonState = state;
  }
}

void refreshDisplay() {
  static int currentRowScan = 0;

  digitalWrite(row[currentRowScan], HIGH);

  currentRowScan++;
  if (currentRowScan >= ROWS) currentRowScan = 0;

  for (int c = 0; c < COLS; c++) {
    bool ledOn = false;

    if (board[currentRowScan][c] == 1) {
      ledOn = true;
    } else if (board[currentRowScan][c] == 2) {
      ledOn = blinkPhase;
    }

    if (isAnimating && currentRowScan == fallingRow && c == fallingCol) {
      if (fallingPlayer == 1) {
        ledOn = true;
      } else if (fallingPlayer == 2) {
        ledOn = blinkPhase;
      }
    }

    if (!isAnimating && currentRowScan == 0 && c == cursorCol) {
      ledOn = true;
    }

    digitalWrite(col[c], ledOn ? HIGH : LOW);
  }

  digitalWrite(row[currentRowScan], LOW);
}

void loop() {
  updateBlink();
  updateJoystick();
  updateButton();
  refreshDisplay();
}