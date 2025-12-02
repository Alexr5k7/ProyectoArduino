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

const int JOY_X  = A4;    // VRx
const int JOY_SW = A5;    // botón (pullup)

// Estado del tablero:
// 0 = vacío
// 1 = ficha jugador 1 (siempre encendida)
// 2 = ficha jugador 2 (parpadea)
int board[ROWS][COLS];

// Cursor en la fila 1 (fila 0)
int cursorCol = 0;       
bool joyNeutral = true;
unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150; // ms

// Botón joystick
int lastButtonState = HIGH;
unsigned long lastButtonTime = 0;
const unsigned long BUTTON_DEBOUNCE = 150; // ms

// Turnos
int currentPlayer = 1;  // 1 o 2

// Animación de caída
bool isAnimating = false;
int fallingRow = 0;
int fallingCol = 0;
int fallingPlayer = 1;

// Parpadeo jugador 2
bool blinkPhase = false;
unsigned long lastBlinkTime = 0;
const unsigned long BLINK_INTERVAL = 300; // ms

void setup() {
  // Filas: salida, apagadas (HIGH)
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }

  // Columnas: salida, apagadas (LOW)
  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);
  }

  // Tablero vacío
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
  if (isAnimating) return; // durante la animación ignoramos joystick

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

  // Cuando vuelve al centro, liberamos de nuevo
  if (x >= 450 && x <= 570) {
    joyNeutral = true;
  }
}

void animateDrop(int colIndex, int destRow) {
  isAnimating = true;
  fallingCol = colIndex;
  fallingPlayer = currentPlayer;

  // Recorremos desde fila 0 hasta destRow
  for (int r = 0; r <= destRow; r++) {
    fallingRow = r;

    // Un montón de refrescos rápidos para que se vea la animación
    for (int k = 0; k < 40; k++) {
      updateBlink();      // el jugador 2 parpadea incluso cayendo
      refreshDisplay();
      delay(2);
    }
  }

  // Fin de la animación: fijamos la ficha en el tablero
  board[destRow][colIndex] = fallingPlayer;
  isAnimating = false;

  // Cambiar de jugador
  currentPlayer = (currentPlayer == 1) ? 2 : 1;

  // Cursor vuelve al principio
  cursorCol = 0;
}

// Deja caer una ficha en la columna actual con animación
void tryDropPiece() {
  if (isAnimating) return; // evitar reentradas

  int c = cursorCol;

  // Buscar desde abajo hacia arriba la primera casilla libre
  int destRow = -1;
  for (int r = ROWS - 1; r >= 0; r--) {
    if (board[r][c] == 0) {
      destRow = r;
      break;
    }
  }

  if (destRow == -1) {
    // Columna llena, no hacemos nada
    return;
  }

  // Animar la caída hasta destRow
  animateDrop(c, destRow);
}

void updateButton() {
  unsigned long now = millis();
  int state = digitalRead(JOY_SW);   // LOW = pulsado (INPUT_PULLUP)

  if (state != lastButtonState && (now - lastButtonTime) > BUTTON_DEBOUNCE) {
    lastButtonTime = now;

    // Flanco de bajada: se acaba de pulsar
    if (state == LOW) {
      tryDropPiece();
    }

    lastButtonState = state;
  }
}

void refreshDisplay() {
  static int currentRowScan = 0;

  // Apagar fila anterior
  digitalWrite(row[currentRowScan], HIGH);

  // Siguiente fila
  currentRowScan++;
  if (currentRowScan >= ROWS) currentRowScan = 0;

  // Configurar columnas para esta fila
  for (int c = 0; c < COLS; c++) {
    bool ledOn = false;

    // Fichas ya colocadas
    if (board[currentRowScan][c] == 1) {
      // Jugador 1: siempre ON
      ledOn = true;
    } else if (board[currentRowScan][c] == 2) {
      // Jugador 2: parpadea
      ledOn = blinkPhase;
    }

    // Ficha cayendo (animación)
    if (isAnimating && currentRowScan == fallingRow && c == fallingCol) {
      if (fallingPlayer == 1) {
        ledOn = true;
      } else if (fallingPlayer == 2) {
        ledOn = blinkPhase;
      }
    }

    // Cursor en la primera fila (fila 0), solo cuando no animamos
    if (!isAnimating && currentRowScan == 0 && c == cursorCol) {
      ledOn = true;
    }

    // HIGH = encendido, LOW = apagado
    digitalWrite(col[c], ledOn ? HIGH : LOW);
  }

  // Activar la fila actual (LOW = ON)
  digitalWrite(row[currentRowScan], LOW);
}

void loop() {
  updateBlink();     // controla el parpadeo del jugador 2
  updateJoystick();  // mover cursor (si no hay animación)
  updateButton();    // soltar ficha con animación
  refreshDisplay();  // dibujar tablero + cursor + animación
}