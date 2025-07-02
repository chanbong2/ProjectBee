# ProjectBee

Sensor Connection
 - H1 : BH1750
 - H4 : BME/BMP280
 - H7 : GY-BNO055
   
![Image](https://github.com/user-attachments/assets/b689cbd4-93d7-4b97-9bd6-5a30cf3b85d2) ![Image](https://github.com/user-attachments/assets/18c7620a-1be2-4f42-8854-db002fa05f9e)

---

# BNO055
Library : Adafruit BNO055

![image](https://github.com/user-attachments/assets/5f35332d-df84-4389-8ac9-81510a590997)

File - Examples - Adafruit BNO055 - read_all_data

---

# BME/BMP280 
Library : BMX280MI

![image](https://github.com/user-attachments/assets/1bf6618e-57ba-40a8-ac54-76c66ceca1bc)

File - Examples - BMx280MI - BMx280_I2C

---

# BH1750
Library : BH1750

![image](https://github.com/user-attachments/assets/af64f6b7-f7e7-43ce-b189-75dba6d13437)

File - Examples - BH1750 


---
# 첨부 파일 코드
- i2c_detect.ino : esp32에 연결되어 있는 i2c 통신 센서의 i2c 주소 탐색
- bno055_Test.ino : bno055로 측정한 선가속도와 x/y/z축에 대한 회전 방향 값 출력(시리얼 모니터 & 시리얼 플로터)
-  - Tools - Serial Monitor, Serial Plotter
   - value 1, 2, 3 : x/y/z축 회전 각도
   - value 4, 5, 6 : x/y/z축 직선 가속도
