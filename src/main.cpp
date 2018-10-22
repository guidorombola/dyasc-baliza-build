#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "";
const char* password =  "";
const char* token = "";

void setup() {
    Serial.begin(115200);
    delay(4000);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.println("Connecting to WiFi..");
    }
    Serial.println("Connected to the WiFi network"); 
    pinMode(2, OUTPUT);
}

void loop() {
    if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status

        HTTPClient http;

        //http.begin("http://jsonplaceholder.typicode.com/comments?id=10"); //Specify the URL
        http.begin("https://api.travis-ci.com/repo/guidorombola%2Fdyasc-2018/branch/master");
        http.addHeader("Travis-API-Version", "3", false, false);
        http.addHeader("Authorization", token, false, false);
        
        int httpCode = http.GET();                                        //Make the request

        if (httpCode > 0) { //Check for the returning code
            String payload = http.getString();
            //Serial.println(httpCode);
            //Serial.println(payload);
            int inicioEstadoBuild = payload.indexOf("state");
            String aux = payload.substring(inicioEstadoBuild+9);
            int finEstadoBuild = aux.indexOf(",");
            String estado = aux.substring(0, finEstadoBuild-1);
            Serial.println(estado);
            if(estado == "passed"){
                digitalWrite(2, HIGH);
                delay(3000);
                digitalWrite(2, LOW);
            }
            
        }

        else {
            Serial.println("Error on HTTP request");
        }

        http.end(); //Free the resources
    }

    delay(10000);
}