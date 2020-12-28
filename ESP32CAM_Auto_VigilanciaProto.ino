#include "esp_camera.h"
#include <WiFi.h>
#include "camera_pins.h"
#define CAMERA_MODEL_WROVER_KIT // Se reemplaza acorde con el modelo especifico de la camara/kit
#define CAMERA_MODEL_M5STACK_PSRAM
#define CAMERA_MODEL_AI_THINKER

const char* ssid = "";  // Aca reemplazamos acorde con las credenciales de nuestra red WiFi
const char* password = "";

extern int leftmotor1 =  4; // Los cuatro pines (4, 2, 14 y 15) del ESP32-CAM son los que se utilizaran para controlar los motores de DC
extern int leftmotor2 = 2;
extern int rightmotor1 = 14;
extern int rightmotor2 = 15;

void setup() {         // Dentro del loop principal, se inicia el motonitor serial y se configuran los motores DC en un nivel bajo.
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();
  digitalWrite(leftmotor1, LOW);
  digitalWrite(leftmotor2, LOW);
  digitalWrite(rightmotor1, LOW);
  digitalWrite(rightmotor2, LOW)
  
// Se definen los pins de motores DC como salida.

pinMode(leftmotor1, OUTPUT);
pinMode(leftmotor2, OUTPUT);
pinMode(rightmotor1, OUTPUT);
pinMode(rightmotor2, OUTPUT);

WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi Conectado");
