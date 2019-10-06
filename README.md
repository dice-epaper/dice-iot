## 1. 작품 소개

E-Paper와 MQTT 통신을 이용한 저전력, 쌍방향 통신 전자가격표시기(ESL) 입니다. 기존의 전자가격표시기(ESL)의 기능에 차별성을 두기 위해 다양한 입력(RFID, 카메라 등)을 통해 등급, 성별, 나이 별 Customizing Promotion 기능을 추가로 제공합니다. 또한 별도의 기기 없이 앱을 이용하여 할인정보를 쉽게 수정, 삭제할 수 있습니다. 이 작품은 4차 산업 혁명 시대의 쇼핑 환경에서 필요성을 느껴 기획하게 되었습니다.

### 1) 가격표시기(Display) 화면 구성 컨셉
![image](https://user-images.githubusercontent.com/37296369/66264483-0bcccc00-e841-11e9-963e-0f54d7c8b888.png)
![image](https://user-images.githubusercontent.com/37296369/66264488-17b88e00-e841-11e9-8833-09510dc36711.png)
### 2) H/W 설계도
- 전체 설계도
![image](https://user-images.githubusercontent.com/37296369/66264501-4fbfd100-e841-11e9-895c-b991ae5b21c7.png)
- PIN Mapping
![image](https://user-images.githubusercontent.com/37296369/66264507-77af3480-e841-11e9-8619-fed2f2404b38.png)

## 2. 작품 구성도	
### 1) S/W 구성도
![image](https://user-images.githubusercontent.com/37296369/66264373-15553480-e83f-11e9-8cd9-9d2380355ffd.png)
### 2) H/W 구성도
![image](https://user-images.githubusercontent.com/37296369/66264378-2dc54f00-e83f-11e9-8ecb-e540b5325045.png)
### 3) 서비스 흐름도
![image](https://user-images.githubusercontent.com/37296369/66264383-4df50e00-e83f-11e9-937d-387e089e5366.png)
### 4) 전체 기능 목록
![image](https://user-images.githubusercontent.com/37296369/66264525-f1dfb900-e841-11e9-8a9e-46399c182b4f.png)
### 5) 개발 환경
![image](https://user-images.githubusercontent.com/37296369/66264450-7fbaa480-e840-11e9-8b7c-768d287e7e12.png)

## 3. 개발 배경 및 필요성	
- ESL로 대체되는 추세 보편화된 '종이'가격표시기와 다르게 '전자'가격표시기(이하 ESL)는 능동적 가격변경과 재사용이 가능합니다. 이에 대형마트에서는 ESL로 대체되고 있는 추세입니다. 
- ESL 보편화 + 고객 맞춤 서비스 중소형 매장에서도 ESL을 사용할 수 있어야 하고, 이제는 소비자에게 단순히 '가격 표시' 기능을 넘는 서비스를 제공해야 할 필요가 있습니다. 따라서 싸고 접근성 높은 서비스를 위해 E-Paper와 IoT, AI 기술을 사용하여 Customizing Promotion을 개발하게 되었습니다.

## 4. 작품 특 장점	
- ESL에 표시될 정보(가격 및 할인율)를 앱으로 수정 
- RFID와 카메라를 이용하여 등급별 또는 연령 및 성별 식별 후 promotion 적용 가능 
- 중소 매장에서도 적용 가능한 저렴하고 쉬운 서비스 4. MQTT 통신과 E-Paper 이용하여 저전력 및 종이 절약 가능 5. 음성서비스 등 고객의 편리를 고려하는 서비스 제공

## 5. 기대효과 및 활동분야	
### 1) 작품의 기대효과 
- ESL 보편화 : 저전력이라는 장점을 이용하여 중소매장에서도 ESL 서비스 제공 가능. 
- Customizing 쇼핑 환경 구축 : RFID 태깅, AI 얼굴인식 등을 통해 고객 맞춤 Promotion 가능 

### 2) 참여 멘티의 교육적 기대효과
- 스마트 매장에 대한 IoT 기술 습득 (AWS 와 HTTP, HTTPS 통신)
