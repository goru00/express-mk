#include<ESP8266WiFi.h>
#include <express.h>

Express express();

void setup() 
{
    Serial.begin(115200);
    Serial.println('ESP8266 WiFi scan example');

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
}

void loop() 
{
    String ssid;
    int32_t rssi;
    uint8_t encryptionType;
    uint8_t * bssid;
    int32_t channel;
    bool hidden;
    int scanResult;

    Serial.println('Сканируем сеть WiFi...');

    scanResult = WiFi.scanNetworks(false, true);

    if (scanResult == 0) {
        Serial.println('Не было найдено ни одной сети');
    } else if (scanResult > 0) {
        Serial.printf(PSTR("Было найдено %d сетей: \n"), scanResult);
        for (int8_t i = 0; i < scanResult; i++) {
            WiFi.getNetworkInfo(i, ssid, encryptionType, rssi, bssid, channel, hidden);
            Serial.printf(PSTR("  %02d: [CH %02d] [%02X:%02X:%02X:%02X:%02X:%02X] %ddBm %c %c %s\n"),
                    i,
                    channel,
                    bssid[0], bssid[1], bssid[2],
                    bssid[3], bssid[4], bssid[5],
                    rssi,
                    (encryptionType == ENC_TYPE_NONE) ? ' ' : '*',
                    hidden ? 'H' : 'V',
                    ssid.c_str());
            delay(0);
        }
    } else {
        Serial.println('Непредвиденная ошибка сканирования');
    }
    delay(5000);
}