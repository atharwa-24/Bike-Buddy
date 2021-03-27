#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>
#define RXPin D7
#define TXPin D6
#define pizo D2
#define FIREBASE_HOST "PRIVATE"
#define FIREBASE_AUTH "PRIVATE"
#define WIFI_SSID "Adronzer"
#define WIFI_PASSWORD "PRIVATE"

static const uint32_t GPSBaud = 9600;
const int xPin = A0;
SoftwareSerial ss(RXPin, TXPin);
TinyGPSPlus gps;
WiFiClient  client;
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 pinMode(pizo,INPUT);
 ss.begin(GPSBaud);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  //accelerometer
 
 int x = analogRead(xPin);
  delay(1000);
  Serial.print("Acceleration : ");
  Serial.println(x);
  Firebase.setInt("User/Acceleration/",x-480);
int value = digitalRead(pizo);
if(value == LOW){
  Serial.println("UAlert!!!");
  Firebase.setString("User/Accident","Safe");
  } 
else if(value==HIGH){
  Serial.println("Alert!!!");
  Firebase.setString("User/Accident","Danger");
  }  
  else{}


 while (ss.available() > 0)
  if (gps.encode(ss.read()))
    displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
  Serial.println(F("No GPS detected: check wiring."));
  while (true);
  }


  }
void displayInfo()
  {
  // Serial.print(F("Location: "));
  if (gps.location.isValid())
  {

    double latitude = (gps.location.lat());
    double longitude = (gps.location.lng());

    String latbuf;
    latbuf += (String(latitude, 6));
    Serial.println(latbuf);
    Firebase.setString("User/Latitude",latbuf);

    String lonbuf;
    lonbuf += (String(longitude, 6));
    Serial.println(lonbuf);
    Firebase.setString("User/Longitude",lonbuf);
  }
  
}
