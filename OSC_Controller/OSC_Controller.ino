#include <WiFi.h>
#include <WiFiUdp.h>
#include <OSCMessage.h>
#include <Wire.h>
#include <Adafruit_MPU6050.h> // MPU6050 라이브러리

// 1. Wi-Fi 설정
const char* ssid = "GRlab"; // Wi-Fi 이름
const char* password = "Indigo1!"; // Wi-Fi 비밀번호

// 2. OSC 통신 설정
IPAddress outIp(192, 168, 0, 15); // OSC 데이터를 수신할 컴퓨터의 IP 주소.
const unsigned int outPort = 8000; // 수신 포트
const unsigned int localPort = 8888; // ESP32 송신 포트

WiFiUDP Udp;
Adafruit_MPU6050 mpu; // MPU 객체 생성

// 3. MPU6050 데이터 전송 함수
void sendMpuDataOSC(float ax, float ay, float az, float gx, float gy, float gz) {
  // 가속도 데이터 전송
  OSCMessage accMessage("/mpu/accel"); // OSC 주소 설정 (Max/MSP, PureData 등에서 수신할 주소)
  accMessage.add(ax).add(ay).add(az);
  Udp.beginPacket(outIp, outPort);
  accMessage.send(Udp);
  Udp.endPacket();
  accMessage.empty(); // 메시지 초기화

  // 자이로 데이터 전송
  OSCMessage gyroMessage("/mpu/gyro");
  gyroMessage.add(gx).add(gy).add(gz);
  Udp.beginPacket(outIp, outPort);
  gyroMessage.send(Udp);
  Udp.endPacket();
  gyroMessage.empty();
}

void setup() {
  Serial.begin(115200);

  // MPU6050 초기화
  if (mpu.begin()) {
    Serial.println("MPU6050 센서를 찾을 수 없습니다! 연결을 확인하세요.");
    while (1) delay(10);
  }
  
  // 가속도 및 자이로 범위 설정
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G); 
  mpu.setGyroRange(MPU6050_RANGE_500_DEG); 
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ); 

  // Wi-Fi 연결
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // UDP 통신 시작
  Udp.begin(localPort);
}

void loop() {
  // MPU6050에서 데이터 읽기
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float accelX = a.acceleration.x;
  float accelY = a.acceleration.y;
  float accelZ = a.acceleration.z;
  
  float gyroX = g.gyro.x;
  float gyroY = g.gyro.y;
  float gyroZ = g.gyro.z;
  
  // Serial 모니터에 출력 (디버깅용)
  Serial.printf("Acc: %.2f, %.2f, %.2f | Gyro: %.2f, %.2f, %.2f\n", 
                accelX, accelY, accelZ, gyroX, gyroY, gyroZ);

  // OSC 메시지 전송
  sendMpuDataOSC(accelX, accelY, accelZ, gyroX, gyroY, gyroZ);

  delay(100); // 전송 주기 조절 (지연 시간을 줄이려면 줄일 수 있습니다)
}