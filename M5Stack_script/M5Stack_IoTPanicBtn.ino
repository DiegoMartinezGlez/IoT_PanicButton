#include <M5Stack.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PSSWD";

void setup() {
    M5.begin();
    M5.Lcd.clear();
    M5.Lcd.setCursor(0, 0, 2);
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    connectToNetwork();
    M5.Lcd.printf("Setup OK\n\n");
}

void connectToNetwork()
{
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    M5.Lcd.printf("Connecting WiFi ... ");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      M5.Lcd.printf(".");
    }
    M5.Lcd.print("Conectado!!\n\n");
}

void request()
{  
    HTTPClient http;
    http.begin("YOUR_TARGET_SERVICE_URL");
    //http.addHeader("Content-Type", "text/plain");
    M5.Lcd.printf("Alert sent ... ");
    int httpCode = http.GET();
    if (httpCode > 0) { //Check for the returning code
        String payload = http.getString();
        M5.Lcd.print(payload);
    }
    else 
    {
      M5.Lcd.printf("Error on HTTP request");
      M5.Lcd.printf("HttpCode: ");
      M5.Lcd.print(httpCode );
      M5.Lcd.printf("\n");
    }
    http.end();    
}

void loop()
{
    if ((WiFi.status() != WL_CONNECTED)) { 
      M5.Lcd.print("WiFi not connected ... \n");
    }
    if (M5.BtnA.wasPressed())
    {
      request();
    }
    if (M5.BtnB.wasPressed())
    {
      request();
    }
    if (M5.BtnC.wasPressed())
    {
      request();
    }
    M5.update();
}
