# 🕹️ Proyecto Arduino – *Cuatro en Raya con Joystick*

## 🎯 Objetivo del proyecto
El objetivo de este proyecto es construir una versión electrónica del **Cuatro en Raya** utilizando una **matriz LED 8x8** y un **joystick analógico**.

- **Jugador 1:** ficha fija (brillo total)  
- **Jugador 2:** ficha parpadeante  
- Gana quien complete una línea de 4 en cualquier dirección.

---

## 👥 Equipo y roles
| Integrante | Rol |
|-----------|------|
| **Xavier Pastor** | Montaje del hardware (Arduino, joystick, matriz 8x8) |
| **Alejandro Martínez** | Programación y desarrollo del juego |

---

## 📅 Plan de sprints
| Sprint | Objetivo | Estado |
|--------|-----------|---------|
| **Sprint 1** | Montaje del circuito + prueba de la matriz LED | ✔️ Completado |
| **Sprint 2** | Lectura del joystick + movimiento entre columnas | 🔄 En progreso |
| **Sprint 3** | Lógica de fichas + turnos | ⏳ Pendiente |
| **Sprint 4** | Detección de victoria + pulido | ⏳ Pendiente |
| **Sprint 5** | Pruebas finales + documentación | ⏳ Pendiente |

---

## 📘 Bitácora de trabajo

> **Formato:** *Fecha – Qué se hizo, problemas encontrados, decisiones tomadas.*

### 🗓️ 11/11/25 – Inicio del proyecto  
- Definimos la idea principal: *Cuatro en Raya con matriz 8x8 y joystick*.  
- Revisión de materiales y planificación inicial.

### 🗓️ 20/11/25 – Verificación de componentes  
- Código inicial de "Set up" completado
- Adaptación de los cables para un fácil montaje

### 🗓️ 25/11/25 – Pruebas de encendido  
- Código de movimiento del joystick completado
- Comprobación del movimiento entre columnas.

---

## 🔌 Boceto del circuito (Tinkercad / Fritzing)

### 🔧 Esquema del montaje  
*(Incluye el cableado de la matriz 8x8, joystick y Arduino.)*

![Matrix8x8 Arduino](https://github.com/user-attachments/assets/1240046c-6ab7-4172-9f83-809f5fe94416)

---

## 🧩 Lista de sensores y componentes

### 🟢 Sensores y actuadores
| Componente | Modelo | Función |
|-----------|---------|----------|
| Matriz LED 8x8 | 1588BS | Representación del tablero |
| Joystick analógico XY | Estándar | Movimiento y selección |

### 🔵 Otros componentes
- Arduino UNO / compatible  
- Protoboard  
- Cables macho-macho  

---

## 📈 Esquema de conexiones

![image-1763633699471](https://github.com/user-attachments/assets/464fcb99-9c37-4dcc-9fd4-62c7b5dfb689)

---

## 📌 Estado actual y tareas pendientes

### ✔️ Completado
- Montaje del circuito  
- Pruebas iniciales de matriz  
- Lectura del joystick  

### 🔨 En desarrollo
- Movimiento de selección  
- Caída de ficha  
- Turnos  

### 🧠 Pendiente
- Detección de victoria  
- Parpadeo del jugador 2  
- Limpieza final del código  
- Pruebas completas  

---

## 📷 Otros materiales

Un vídeo de muestra de cómo funciona el código "MovimientoJoystick"
https://github.com/user-attachments/assets/ac8557bc-60c5-4e22-ba05-700c3c7971ef


