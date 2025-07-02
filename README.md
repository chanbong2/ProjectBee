# ProjectBee Sensor

센서 연결법
 - H1 : BH1750
 - H4 : BME/BMP280
 - H7 : GY-BNO055
   
<p align="center">
  <img src="https://github.com/user-attachments/assets/b689cbd4-93d7-4b97-9bd6-5a30cf3b85d2" width="45%" />
  <img src="https://github.com/user-attachments/assets/18c7620a-1be2-4f42-8854-db002fa05f9e" width="45%" />
</p>

---

# 1. BNO055
Library : Adafruit BNO055

![image](https://github.com/user-attachments/assets/5f35332d-df84-4389-8ac9-81510a590997)

File - Examples - Adafruit BNO055 - read_all_data

**※ 35번째 줄의 0x28을 0X29로 바꿔줘야 함** 

  **35 : Adafruit_BNO055 bno = Adafruit_BNO055(55, 0x29, &Wire);**

---

# 2. BME/BMP280 
Library : BMX280MI

![image](https://github.com/user-attachments/assets/1bf6618e-57ba-40a8-ac54-76c66ceca1bc)

File - Examples - BMx280MI - BMx280_I2C

---

# 3. BH1750
Library : BH1750

![image](https://github.com/user-attachments/assets/af64f6b7-f7e7-43ce-b189-75dba6d13437)

File - Examples - BH1750 


---
