#include <WiFi.h>
#include <HTTPClient.h>

String URL = "http://192.168.2.241:8012/dht11_project/testdata.php" ;

const char* ssid = "BELL51";
const char* password = "Tangocharli51";

int tempreture = 50;
int humidity = 40;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  connectWiFi();
  
}

void loop() {
  // put your main code here, to run repeatedly:
 if(WiFi.status() != WL_CONNECTED) { 
    connectWiFi();
  }

  String postData = "tempreture=" + String(tempreture) + "&humidity=" + String(humidity); 

  HTTPClient http; 
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int httpCode = http.POST(postData); 
  String payload = http.getString(); 
  
  Serial.print("URL : "); Serial.println(URL); 
  Serial.print("Data: "); Serial.println(postData); 
  Serial.print("httpCode: "); Serial.println(httpCode); 
  Serial.print("payload : "); Serial.println(payload); 
  Serial.println("--------------------------------------------------");
  delay(3000);
}

void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);
  //This line hides the viewing of ESP as wifi hotspot
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}
