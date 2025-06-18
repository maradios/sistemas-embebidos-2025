#include <WiFi.h>
#include <PubSubClient.h>

WiFiClient espClient;  // Declarar el WiFiClient antes de usarlo
PubSubClient client(espClient);  // Ahora puedes pasarlo al PubSubClient


void setup() {
 Serial.begin(115200);
 Serial.println("probando...");

  //---------- Conectarse a una red por nombre + contraseña-------------------
 
  WiFi.begin("wifi", "***");
  Serial.println("conectando a wifi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println(".");
    delay(500);
  }

  Serial.println("conectado a wifi");

  //-----2. Configurar el broker MQTT-----
  // Creamos un cliente de MQTT con la conexión a internet via wifi
  // Realizamos la conexión con el servidor
  client.setServer("broker.hivemq.com", 1883);

  //------3. Conectarse a un tópico-------
  client.connect("kudellmaradona12345");  // devuelve un booleano indicando si se conecto correctamente

  Serial.println("conectando al broker");

  while (!client.connected()){
      Serial.println(".");
      delay(500);
  } // devuelve un booleano que nos permite chequear si la conexión fue exitosa

  Serial.println("conectado al broker");

  client.subscribe("huergo/sistemas-embebidos/maradona");  // seguir patron del topico a escuchar

  client.setCallback(callback);

}

void loop() {
  //4. Leer del monitor serial el mensaje a enviar
  
  if (Serial.available()) {
    String msg;
    msg ="kudell:" + Serial.readStringUntil('\n');
    client.publish("huergo/sistemas-embebidos/luzko", msg.c_str());  // convertir el mensaje mediante .c_str()
      Serial.println(msg);
  }
  client.loop();
  
  
}

//6. Recibir mensajes
// Callback (una función con una firma particular) que respondera ante un nuevo mensaje recibido
void callback(char* topic, byte* payload, unsigned int length) {
  // Iteramos el payload
  for (int i = 0; i < length; i++) {
    char letra = (char)payload[i];

    Serial.print(letra);
    
  }

}
