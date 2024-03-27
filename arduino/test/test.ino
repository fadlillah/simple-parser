#include "event_io.h"

#include <ESP8266WiFi.h>
#include <String.h>

#ifndef STASSID
#define STASSID "CITIA"
#define STAPSK "Citia2024"
#endif

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "192.168.1.18";
const uint16_t port = 3000;
//


String macAddress;
//client Connection
WiFiClient client;

bool SuccessfullLogin = false;

void setup()
{
  Serial.begin(19200);
  // We start by connecting to a WiFi networ3000
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Explicitly set the ESP8266 to be a WiFi-client, otherwise, it by default,
     would try to act as both a client and an access-point and could cause
     network-issues with your other WiFi-devices on your WiFi-network. */
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  macAddress = WiFi.macAddress();
  macAddress.replace(":","");
  Serial.println("MAC address: ");
  Serial.println(macAddress);
  if(!client.connect(host,port)){
    Serial.println("connection failed");
    delay(5000);
  }
}
void ReLogin()
{
  
  Serial.print("Login to server:");
  Serial.println(host);
  
  if(client.connected()){
    String idMac ="0006333041454134303730443634";    
    SendingHex(idMac);
  }
  // wait for data to be available
  unsigned long timeout = millis();
  while (client.available() == 0) {
    if (millis() - timeout > 2000) {
      Serial.println(">>> Client Timeout !");
      client.stop();
      delay(30000);
      return;
    }
  }
  while(client.available()){
    char ch = static_cast<char>(client.read());
    if(ch==0x01){
      Serial.print("Success login to Server :");
      Serial.println(host);
      SuccessfullLogin =true;
    }
  }
}

void SendingHex(String input) {
  Serial.print("Original String: ");
  byte byteArray[input.length()/2];
   for (int i = 0, j = 0; i < input.length(); i += 2, j++)
    {
      char hexChars[3] = {input[i], input[i + 1], '\0'};
      String dataString = String(hexChars);
      Serial.print(dataString);
      byteArray[j] =(byte) strtol(dataString.c_str(), NULL, 16);
    }
  Serial.println();
  // Print the hexadecimal array
  Serial.print("HEX DATA: ");
  for (int i = 0; i < input.length()/2; i++) {
    if(byteArray[i]<0x10){
      Serial.print(0);
    }
    Serial.print(byteArray[i], HEX);
    Serial.print(" ");
    //client.write(byteArray[i]);
  }
  // Send the byte array over the client
  client.write(byteArray, sizeof(byteArray));
  Serial.println();
}


void loop()
{
  if(!client.connected())
  {
    client.connect(host,port);
    Serial.println("reconnect to Socket server");
    delay(5000);
  }
  else
  {
if(SuccessfullLogin)
  {
    insertEventIO(11, 0xf4f4, 2);
    insertEventIO(12, 0x1212, 2);
    String hexString = toHexString();
    if(client.connected()){
      SendingHex(hexString);
    }
  }
  else{
    ReLogin();
  }
  }
  
  
  delay(5000);
}
