# ProyectoArduino

El objetivo de este proyecto es hacer un "Cuatro en raya" funcional con un joystick. Con el joystick cada jugador se podrá mover entre las columnas y pulsar el joystick para lanzar la ficha hacia abajo. El jugador uno tendrá fichas con intensidad total, y el jugador dos tendrá las fichas que parpadean. Usaremos un Panel Matrix 8x8. El primer jugador en hacer una línea de cuatro en cualquier sentido, gana.

El equipo está compuesto por Xavier Pastor y Alejandro Martínez. Xavier se encarga del montaje del arduino, y Alejandro de la programación del código.

El día 20/11/25 se completó el montaje del arduino y se completó el primer código del proyecto, el cuál está adjunto en Github y sirve para encender todas las LED de forma individual, recorriendo cada fila y columna, llamado "SetUpPines". A partir de eso, podemos hacer la lógica del "Cuatro en raya" de forma limpia y más fácil.
Actualmente solo está el "set up" básico del juego, pero una vez teniendo el código que controla de froam correcta todas las LED, se podrá avanzar mucho más rápido.

Este es el montaje básico de la matriz 8x8:
![Matrix8x8 Arduino](https://github.com/user-attachments/assets/1240046c-6ab7-4172-9f83-809f5fe94416)

Vamos a utilizar estos componentes:
· Arduino
· Matrix8x8 LED
· Joystick
Además de estos componentes principales, vamos a usar cables y un protoboard.

Esta es una imagen del montaje básico de la matriz en físico.
![image-1763633699471](https://github.com/user-attachments/assets/464fcb99-9c37-4dcc-9fd4-62c7b5dfb689)
