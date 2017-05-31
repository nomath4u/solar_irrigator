// This #include statement was automatically added by the Particle IDE.
#include "SHT1x.h"
#include "irrigation.h" //Adafruit.io configuration generated file

// This #include statement was automatically added by the Particle IDE.
#include <Adafruit_MQTT.h>
#include "Adafruit_MQTT/Adafruit_MQTT_SPARK.h" 
#include "Adafruit_MQTT/Adafruit_MQTT.h"
/************************* Adafruit.io Setup *********************************/ 
#define AIO_SERVER      "io.adafruit.com" 
#define AIO_SERVERPORT  1883                   // use 8883 for SSL 
#define DATA_PIN        D1
#define CLK_PIN         D0
/************ Global State (you don't need to change this!) ***   ***************/ 
TCPClient TheClient; 
TCPClient HomeClient;
// Setup the MQTT client class by passing in the WiFi client and MQTT server and login details. 
Adafruit_MQTT_SPARK mqtt(&TheClient,AIO_SERVER,AIO_SERVERPORT,AIO_USERNAME,AIO_KEY); 
Adafruit_MQTT_SPARK home_mqtt(&HomeClient,HOME_SERVER,HOME_SERVERPORT,HOME_USERNAME,HOME_PASSWORD); 
/****************************** Feeds ***************************************/ 
// Setup a feed called 'voltage' for publishing. 
// Notice MQTT paths for AIO follow the form: <username>/feeds/<feedname> 
Adafruit_MQTT_Publish moisture = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Moisture Log"); 
Adafruit_MQTT_Publish temp = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/Irrigation Temp"); 
Adafruit_MQTT_Publish humidity = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/irrigation_hummidity"); 
Adafruit_MQTT_Publish home_temp = Adafruit_MQTT_Publish(&home_mqtt, "home/outside_temp"); 
// Setup a feed called 'onoff' for subscribing to changes. 
//Adafruit_MQTT_Subscribe onoffbutton = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/onoff"); 
/*************************** Sketch Code ************************************/ 

//Sensirion soilSensor = Sensirion(DATA_PIN, CLK_PIN);
SHT1x sht1x(DATA_PIN, CLK_PIN);
void setup()  
{ 
   Serial.begin(115200); 
   delay(10); 
   pinMode(A0,INPUT); 
   Serial.println(F("Adafruit MQTT demo")); 
   // Setup MQTT subscription for onoff feed. 
   //mqtt.subscribe(&onoffbutton); 
} 
void loop() 
{ 
   //int value=analogRead(A0);
   float test1 = 40;
   float test2 = 100;

 if( mqtt.Update() ){ 
       temp.publish((int)sht1x.readTemperatureC());
       humidity.publish((int)sht1x.readHumidity());
       Serial.println(sht1x.readTemperatureC());
 } 
 if( home_mqtt.Update() ){
       home_temp.publish((int)sht1x.readTemperatureC());
 }
   //delay(2000);
   System.sleep(SLEEP_MODE_DEEP, 60); //Value is in seconds. With thins you need to be able to pull wake up pin high to re-program it.
} 
