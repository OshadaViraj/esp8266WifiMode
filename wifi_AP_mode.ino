#include <ESP8266WiFi.h>


void setup() {
  Serial.begin(115200);
   //accesspoint();
   wifiscan();
   // 
   

}

void loop() {
  // put your main code here, to run repeatedly:
  
}




void accesspoint(){
  WiFi.mode(WIFI_AP);
  IPAddress Ip(200, 10, 15, 2);
  IPAddress NMask(255, 255, 255, 0);
  WiFi.softAPConfig(Ip, Ip, NMask);
  WiFi.softAP("TEST_AP","12345678");
  WiFi.begin();
}

void connectToWifi(){
  String DHCPIP;
  WiFi.disconnect();
  WiFi.begin("TP-LINK_95496D", "Welcome2");
   
  while (WiFi.status() != WL_CONNECTED) {
       delay(500);
       Serial.print(".");
     }
     Serial.println(WiFi.localIP()); 
     if(WiFi.status() == WL_CONNECTED){
        Serial.println("connected..");
      }

   DHCPIP = WiFi.localIP().toString();
   Serial.println("Ip Assign from network : "+DHCPIP);
  
}





 void wifiscan(){
  int numberOfNetworks = WiFi.scanNetworks();
  delay(2000);
  for(int i =0; i<numberOfNetworks; i++){
        Serial.println("Wifi name : "+ WiFi.SSID(i));
  }
  }
