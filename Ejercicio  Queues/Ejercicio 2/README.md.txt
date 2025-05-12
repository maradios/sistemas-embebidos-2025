Ejercicio 2: Control de LEDs mediante Comandos en la Cola
Otra aplicación práctica donde:

Una tarea productora genera comandos de control de LEDs (rojo, amarillo, verde o parpadeo).

Una tarea consumidora ejecuta las acciones de acuerdo con los comandos recibidos.

Destacado: Si se genera el comando especial de parpadeo, este se envía al frente de la cola usando xQueueSendToFront, dándole prioridad.