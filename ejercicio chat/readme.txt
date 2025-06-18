Este código está hecho para un ESP32 que se conecta a una red WiFi y a un broker MQTT público para enviar y recibir mensajes. Es ideal para practicar cómo funcionan los protocolos de comunicación en IoT.

🔌 ¿Qué hace?
Primero importa dos librerías:

WiFi.h para conectarse a internet.

PubSubClient.h para usar MQTT, que es un sistema para mandar mensajes entre dispositivos de forma liviana.

Después, crea dos objetos:

Uno (espClient) que se encarga de la conexión a internet.

Y otro (client) que se encarga de la conexión con el broker MQTT, usando ese internet.

⚙️ En la función setup()
Esto se corre una sola vez al prender el ESP32:

Se inicia el monitor serial a 115200 baudios, así podés ver mensajes en la compu.

Conexión al WiFi:
Se conecta a una red con nombre "asdf" y clave "123456789". Mientras intenta conectarse, imprime puntos en la consola. Cuando logra conectarse, te avisa.

Conexión al broker MQTT:
El broker es broker.hivemq.com en el puerto 1883, que es público y gratuito.
El ESP32 se conecta con el nombre "kudellmaradona12345" (este nombre debe ser único).
También muestra puntos mientras intenta conectarse al broker.

Suscripción a un tópico:
Una vez conectado, se suscribe al canal:

bash
Copiar
Editar
huergo/sistemas-embebidos/maradona
Esto significa que va a estar "escuchando" todo lo que llegue a ese canal.

Callback:
Se configura la función callback, que es la que se va a ejecutar cada vez que llegue un mensaje al canal anterior.

🔁 En la función loop()
Esto se ejecuta en bucle todo el tiempo:

Si escribís algo en el monitor serial (desde tu compu), el ESP32:

Lee ese texto hasta que toques Enter.

Le agrega el prefijo "kudell:".

Lo envía al canal:

bash
Copiar
Editar
huergo/sistemas-embebidos/luzko
Y también lo imprime en la consola.

Ejecuta client.loop() que es obligatorio para mantener activa la conexión con el broker y seguir recibiendo mensajes.

📥 La función callback()
Cuando alguien (otro ESP32 o incluso una compu) manda un mensaje al canal:

bash
Copiar
Editar
huergo/sistemas-embebidos/maradona
el ESP32 recibe ese mensaje automáticamente.

La función callback se encarga de:

Recorrer el mensaje carácter por carácter.

Imprimirlo por el monitor serial.

