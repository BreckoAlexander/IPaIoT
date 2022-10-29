//#include <ESP8266WiFi.h>
//#include <ESP8266HTTPClient.h>
#include <WiFiClientSecure.h>
#include <WiFi.h>
#include <HTTPClient.h>


// Define Wifi SSID and PASS
const char* ssid = "TP-Link_0CBB";
const char* pass = "00179539";
WiFiClient wifi;

// variable
int poc=0;


// setup - vykonava sa len raz pri sputeni programu
// pokusi sa pripojit k wifi
void setup()
{
  Serial.begin(9600);
  WiFi.begin(ssid, pass);
  Serial.println("Connecting");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay (1000);
    Serial.print(".");
  }

  Serial.println("Connected");
}

// vykonava sa dookola
void loop()
{

// Váš kód ...
// pomocne premenne
  poc++;
  String hodnota1=String(poc);
  String hodnota2="22";
  String payload="";

  // NACITANIE DAT Z WEBU
  if (WiFi.status() == WL_CONNECTED) // ak je ESP pripojene k wifi
  {
    HTTPClient http; // vytvorenie HTTP clienta
    String server_name = "https://phpipaiot.azurewebsites.net/"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    http.begin(server_name.c_str());
    int httpCode = http.GET(); // http code

    if (httpCode>0) 
      payload= http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(httpCode); // vypisanie http code do Serial monitoru (200 - OK)
      Serial.println(payload); // vypisanie celej html stranky, ktora sa na tejto url nachadza (zobrazene v serial monitore)

    http.end();
  }

  int hodnota3 = (payload[2]); // nacitanie 2. znaku z html (>)
  Serial.println(hodnota3); // vypisanie ASCII (62) hodnoty znaku >, ktory bol nacitany v payloade
  delay(2000); // 2 sekundy 

  // ZAPIS DAT NA WEB
  if (WiFi.status() == WL_CONNECTED) 
  {
    HTTPClient http;
    String server_name = "https://phpipaiot.azurewebsites.net/getParameters.php/?"; // nazov vasho webu a web stranky, ktoru chcete nacitat
    server_name += "a="; // nazov premennej na webe
    server_name += hodnota1; // hodnota premmenej
    server_name += "&b="; // nazov premennej na webe
    server_name += hodnota2; // hodnota premennej
    http.begin(server_name.c_str());
    int httpCode = http.GET(); // http code

    if (httpCode>0) 
    {
      payload= http.getString();
      Serial.print("HTTP Response code: ");
      Serial.println(httpCode); // vypisanie http code do Serial monitoru (200 - OK)
      Serial.println(payload); // vypisanie celej html stranky, ktora sa na tejto url nachadza (zobrazene v serial monitore)

      int hodnota3 = (payload[26]); // nacitanie 2. znaku z html (>)
      Serial.println(hodnota3); // vypisanie ASCII (62) hodnoty znaku >, ktory bol nacitany v payloade
      delay(2000); // 2 sekundy 
    }
    http.end();
  }  
}
