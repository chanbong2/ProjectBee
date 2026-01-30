# BNO055 자이로센서 데이터 로거 (CSV 저장)

**BNO055 자이로센서**를 이용해 측정된 값을 실시간으로 확인하고, Python 스크립트를 통해 `.csv` 파일로 저장하는 코드입니다.
수집된 데이터는 **Edge Impulse**와 같은 머신러닝 플랫폼에서 학습 데이터로 바로 활용할 수 있으니 참고 바랍니다.

---

## 준비물 (Requirements)

* **Anaconda**: 가상환경을 구축하여 PC 내 타 라이브러리와의 충돌을 예방합니다. (상관없으면 생략 가능)
* **Visual Studio Code**: 파이썬 코드 실행 편의성을 위해 사용합니다.
    * *필수: Python Extension 설치*
* **ESP32 보드**: 센서 데이터를 수집하고 전달합니다. (카메라 모듈이 없는 일반 보드 권장)
* **BNO055 센서**: 자이로 및 가속도 측정용 센서

---

## 사용 방법 (Step-by-Step)

### 1. 보드 펌웨어 업로드
1. Arduino IDE에서 `Gyro_Logger.ino` 코드를 엽니다.
2. ESP32 보드에 코드를 업로드합니다.
3. **라이브러리 참고**: BNO055 관련 라이브러리 설치 방법은 아래 링크를 참고하세요.
    * (https://github.com/chanbong2/ProjectBee/blob/main/README.md)

### 2. 하드웨어 연결 및 시리얼 확인
1. 업로드가 끝나면 Arduino IDE의 **Serial Monitor**를 열어 값이 정상적으로 측정되는지 확인합니다.
2. 측정이 정상적으로 된다면 **시리얼 모니터를 반드시 종료**합니다. (종료하지 않으면 Python에서 포트에 접근할 수 없습니다.)

### 3. Python 환경 설정 및 실행
1. Visual Studio Code에서 `main.py` 코드를 실행합니다.
2. **코드 수정**: 사용자 환경에 맞게 아래 항목을 설정하세요.
    * `포트명` (예: COM3, /dev/ttyUSB0 등)
    * `저장할 csv 파일 이름`
3. **라이브러리 설치**: 컴파일 에러가 발생한다면 터미널에서 필요한 라이브러리를 설치합니다.
    ```bash
    pip install pyserial pandas
    ```

### 4. 데이터 수집 프로세스

1. `main.py`를 실행합니다.
2. **[스페이스바]**를 눌러 데이터 측정을 시작합니다.
3. 데이터 수집이 충분히 이루어지면 다시 **[스페이스바]**를 눌러 측정을 종료하고 파일을 저장합니다.

---

## 데이터 학습 (Edge Impulse)
수집된 `csv` 데이터를 바탕으로 **Edge Impulse** 사이트에서 동작 인식 모델 등 다양한 AI 학습을 수행할 수 있습니다.

---

## 관련 링크
* **Sensor Library**: [ProjectBee Repository](https://github.com/chanbong2/ProjectBee)
