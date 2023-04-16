#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified();


#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;
#include <OneWire.h>
#include <DallasTemperature.h>
const char* ssid = "Galaxy A30s7EFB"; //Your Network SSID
const char* password = "tejateja"; //Your Network Password



WiFiClient client;
unsigned long myChannelNumber = 1753242; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "1O6ZXDX0YV5N626Q"; //Your Write API Key
int val;
int PulseSensorPurplePin = 0;    

int Signal;
#define sensorPin A0 // holds the incoming raw data. Signal value can range from 0-1024 
#define ONE_WIRE_BUS 4
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);


float Celsius = 0;
double alpha=0.75;
int period=20;
double refresh=0.0;

void setup()
{
  Serial.begin(9600);
  if(!accel.begin())
  {
    Serial.println("ADXL not detected");
    while(1);
  }

   delay(10);
   WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 

   ThingSpeak.begin(client);
   
}

void loop()
{
  float x1=0;
  float y=0;
  float z=0;
  sensors_event_t event;
  accel.getEvent(&event);
  x1=event.acceleration.x;
  y=event.acceleration.y;
  z=event.acceleration.z;
   Serial.print(" ");
   Serial.print(event.acceleration.x);
   Serial.print(", ");
   Serial.print(" ");
   Serial.print(event.acceleration.y);
    Serial.print(", ");
   Serial.print(" ");
   Serial.print(event.acceleration.z );
    Serial.print(" ");
    Serial.println(" ");

     Signal = analogRead(PulseSensorPurplePin);
     Signal=Signal/10;                                      
     Serial.println("Pluse:");                                           
   Serial.println(Signal);    
   
  
  sensors.requestTemperatures();
  Celsius = sensors.getTempCByIndex(0);
   Serial.println(Celsius);

    
    ThingSpeak.setField(1, x1);//gas
  ThingSpeak.setField(2, y);//button
   ThingSpeak.setField(3,z);
    //ThingSpeak.setField(4,Signal);
    //ThingSpeak.setField(5,Celsius);
 
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
  delay(20000);
  
}
