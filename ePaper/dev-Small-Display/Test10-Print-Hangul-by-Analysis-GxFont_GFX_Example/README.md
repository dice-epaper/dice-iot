# Reference
### 1. Library 예제
예제> GxEPD > GxFont_GFX_Example

### 2. korean font
* u8g2_font_unifont_t_korean1
* u8g2_font_unifont_t_korean2 는 컴파일 에러 뜸...
* 예시
 display.setFont(u8g2_font_unifont_t_korean1) 
<href>https://bigwavek.tistory.com/entry/nodeMCU-oled-%EB%93%9C%EB%9D%BC%EC%9D%B4%EB%B8%8C</href>

* U8g2 지원되는 한글 font 를 찾아보면 되지 않을까 싶다.

### 3. 라이브러리 추가 및 수정
* 스케치 > 검색 > 추가 > U8g2_for_Adafruit_GFX-master
* 수정 > GxEPD 라이브러리
화살표 표시된 주석 풀어주기 > 저장
![image](https://user-images.githubusercontent.com/37296369/63094473-7ed56700-bfa3-11e9-940e-a00883ae7477.png)

### 4. 주의사항
* 아직 필요 소스만 뽑지 않았음. (Test 시 한글 있는 부분 찾아서 원하는 텍스트로 수정하면 됨.)
* 이제 시작임....  
모든 글씨 출력이 되는것이 아님 ㅜㅜ 다른 font도 찾아봐야함
