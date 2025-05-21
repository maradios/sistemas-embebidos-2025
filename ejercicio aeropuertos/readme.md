🛫 ¿Qué simula este programa?
El programa representa un aeropuerto con dos pistas de aterrizaje (pista 1 y pista 2) y cinco aviones que constantemente solicitan permiso para aterrizar. Todo está gestionado por una torre de control.

🛬 ¿Cómo funciona el sistema?
1. Los aviones
Hay 5 aviones (Avión 1 al Avión 5).

Cada uno, de manera independiente y en momentos aleatorios, pide permiso para aterrizar.

Cuando un avión quiere aterrizar, envía una solicitud a la torre de control.

2. La torre de control
La torre de control está siempre escuchando solicitudes de aterrizaje.

Cuando recibe una solicitud, revisa si alguna de las dos pistas está libre.

Si una pista está libre, le da permiso al avión para aterrizar en ella.

Una vez que el avión aterriza (simulado con una pausa de unos segundos), la pista se libera para el próximo avión.

3. Pistas de aterrizaje
Solo puede aterrizar un avión a la vez por pista.

Si ambas pistas están ocupadas, el avión que pidió permiso espera en la cola hasta que haya una pista disponible.

🧠 ¿Qué conceptos se aplican?
Colas: Para organizar las solicitudes de los aviones.

Semáforos/mutex: Para asegurar que solo un avión use una pista a la vez.

Tareas concurrentes: Cada avión y la torre de control funcionan como tareas independientes que trabajan en paralelo.

🎯 Objetivo principal
Simular una gestión ordenada y segura del aterrizaje de aviones, asegurando que:

No haya colisiones (dos aviones en la misma pista).

Se atienda a todos los aviones conforme llegan.
