Ejercicio 1: Envío de Estructuras entre Tareas
Se implementan dos tareas:

Productor: genera una persona aleatoria (Person) y la envía a la cola.

Consumidor: recibe los datos y los imprime por el monitor serial.

Esto demuestra cómo usar estructuras personalizadas dentro de una cola, manteniendo la separación de responsabilidades entre las tareas.

Temas clave:

Uso de xQueueCreate con sizeof(Person)

Comunicación entre núcleos

portMAX_DELAY para espera indefinida

