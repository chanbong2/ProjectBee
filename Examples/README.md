# Examples 파일
- **i2c_detect.ino** : esp32에 I2C 통신으로 연결되어 있는 센서의 I2C 주소 탐색
   - BH1750 - 0x23
   - BNO055 - 0x29
   - BME/BMP280 - 0x76

- **bno055_Test.ino** : bno055로 측정한 선가속도와 x/y/z축에 대한 회전 방향 값 출력(시리얼 모니터 & 시리얼 플로터)
   - 시리얼 모니터/플로터 활성화 방법 : Tools - Serial Monitor, Serial Plotter
   - value 1/2/3 : x/y/z축 회전 각도
   - value 4/5/6 : x/y/z축 직선 가속도
