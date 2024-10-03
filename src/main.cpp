// Enable debug console
// Set CORE_DEBUG_LEVEL = 3 first
#define ERA_DEBUG
// #define ERA_SERIAL Serial

#define ERA_LOCATION_VN
// #define ERA_LOCATION_SG

// You should get Auth Token in the ERa App or ERa Dashboard
#define ERA_AUTH_TOKEN "e07c3b86-7627-4df0-a88a-bb151c5c8bfd"

#include <Arduino.h>
#include <ERa.hpp>

const char ssid[] = "eoh.io";
const char pass[] = "Eoh@2020";

long previousTime = 0;
const long timeOut = 3500;
int countValue = 0;  // Đổi tên biến từ 'count' thành 'countValue'

/* This function will run every time ERa is connected */
ERA_CONNECTED() {
    ERA_LOG("ERa", "ERa connected!");
}

/* This function will run every time ERa is disconnected */
ERA_DISCONNECTED() {
    ERA_LOG("ERa", "ERa disconnected!");
}

void setup() {
    /* Setup debug console */
    Serial.begin(115200);
    ERa.begin(ssid, pass);
    /* Setup timer called function every second */
    Serial.println("Da upload");
}

void loop() {
    ERa.run();
    // Kiểm tra thời gian để thực hiện các hành động mỗi 2 giây
    if (millis() - previousTime >= timeOut) {
        previousTime = millis();  // Cập nhật lại thời gian

        switch (countValue) {  // Sử dụng biến 'countValue' thay vì 'count'
            case 1:
                ERa.virtualWrite(V7, 70);
                ERa.virtualWrite(V8, 23);
                ERa.virtualWrite(V9, 140);
                break;
            case 2:
                ERa.virtualWrite(V7, 68);
                ERa.virtualWrite(V8, 26);
                ERa.virtualWrite(V9, 148);
                break;
            case 3:
                ERa.virtualWrite(V7, 63);
                ERa.virtualWrite(V8, 28);
                ERa.virtualWrite(V9, 150);
                break;
            case 4:
                ERa.virtualWrite(V7, 63);
                ERa.virtualWrite(V8, 28);
                ERa.virtualWrite(V9, 150);
                break;
            case 5:
                ERa.virtualWrite(V7, 60);
                ERa.virtualWrite(V8, 29);
                ERa.virtualWrite(V9, 155);
                break;
            case 6:
                ERa.virtualWrite(V7, 65);
                ERa.virtualWrite(V8, 23);
                ERa.virtualWrite(V9, 160);
                break;
        }

        Serial.print("Count: ");
        Serial.println(countValue);

        // Tăng giá trị countValue, nếu đạt 6 thì reset về 0
        countValue++;
        if (countValue > 6) {
            countValue = 0;
        }
    }
}