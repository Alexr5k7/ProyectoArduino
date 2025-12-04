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
| **Sprint 1** | Montaje básico del juego completo, con sistema de turnos y de victoria | ✔️ Completado |
| **Sprint 2** | Comprobación del loop final del juego y correcto funcionamiento general | ✔️ Completado |

---

## 📘 Bitácora de trabajo

### 🗓️ 11/11/25 – Inicio del proyecto  
- Definimos la idea principal: *Cuatro en Raya con matriz 8x8 y joystick*.  
- Revisión de materiales y planificación inicial.

### 🗓️ 20/11/25 – Set up y montaje 
- Código inicial de "Set up" completado
- Adaptación de los cables para un fácil montaje

### 🗓️ 25/11/25 – Movimiento del joystick completo  
- Código de movimiento del joystick completado
- Comprobación del movimiento entre columnas.

### 🗓️ 02/12/25 – Sistema de fichas y turnos  
- Código de turnos y movimiento de las fichas
- Comprobación de finalización de partidas
- Cronómetro hecho mediante sonido de un buzzer

---

## 🔌 Boceto del circuito (Tinkercad / Fritzing)

### 🔧 Esquema del montaje  

![Matrix8x8 Arduino](https://github.com/user-attachments/assets/1240046c-6ab7-4172-9f83-809f5fe94416)


Montaje final Tinkercad:
![Montaje_ProyectoFinal_XavierPastor_AlejandroMartínez](https://github.com/user-attachments/assets/d3199be1-5234-4ae7-8014-de5b76ecdd6e)



---

## 🧩 Lista de sensores y componentes

### 🟢 Sensores y actuadores
| Componente | Modelo | Función |
|-----------|---------|----------|
| Matriz LED 8x8 | 1588BS | Representación del tablero |
| Joystick analógico XY | Estándar | Movimiento y selección |
| Buzzer | Estándar | Cronómetro e indicaciones |

### 🔵 Otros componentes
- Arduino UNO / compatible  
- Protoboard  
- Cables macho-macho  

---

## 📈 Esquema de conexiones

Un ejemplo del primer montaje:
![image-1763633699471](https://github.com/user-attachments/assets/464fcb99-9c37-4dcc-9fd4-62c7b5dfb689)

El montaje final, con buzzer incluido:
![1000044581](https://github.com/user-attachments/assets/3b4ed390-20cf-44b6-87b6-7989ac7a534a)


---

## 📌 Estado actual y tareas pendientes

### ✔️ Completado
- Montaje del circuito  
- Pruebas iniciales de matriz  
- Lectura del joystick
- Movimiento de selección  
- Caída de ficha  
- Turnos
- Detección de victoria  
- Parpadeo del jugador 2  
- Limpieza final del código  
- Cronómetro con buzzer

### 🔨 En desarrollo


### 🧠 Pendiente
 

---

## 📷 Otros materiales

Un vídeo de muestra de cómo funciona el código "MovimientoJoystick"
https://github.com/user-attachments/assets/ac8557bc-60c5-4e22-ba05-700c3c7971ef


