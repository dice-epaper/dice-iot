# [RFID] 첫 성공
### ♠ CARD UID 받아오기 - 제일 먼저 해야 할 일
##### 1. MFRC522 를 아두이노 라이브러리에서 추가하기
##### 2. MFRC522의 예제 DumpInfo 켜기
##### 3. 다음의 영상을 따라하여 UID만 가져오기 (시리얼 모니터에서 확인할 수 있음) 
https://www.youtube.com/watch?v=nkD9xFcrnhY
#
### ♠ 위의 과정이 끝났다면 Source code와 아래의 회로 그림과 사진을 보고 시도하기 
![image](https://user-images.githubusercontent.com/53041002/63635182-98a93500-c69a-11e9-922d-2cc067400470.png)
![image](https://user-images.githubusercontent.com/53041002/63521666-dc345f80-c531-11e9-8593-98ca66aec650.png)
![image](https://user-images.githubusercontent.com/53041002/63521686-e7878b00-c531-11e9-87f3-baf5621a29d2.png)
#### ※ 주의 - main code
##### #define PICC_0 0xF9 
##### #define PICC_1 0xF2
##### #define PICC_2 0xCB
##### #define PICC_3 0x56
##### main code의 이 부분에서 위에서 가져온 UID로 바꿔줘야 인식 가능 (F9,F2,CB,56 부분을 바꾸면 됨)
#
### ★ 그러나 몇 가지 오류가 존재하므로 수정해야 할 필요 있음
##### 1. display의 글씨 중 '10,000' 부분이 2번째 태그부터 위치가 밀리는 현상  
##### 2. speaker가 2번째 태그부터 소리가 갑자기 커지는 현상
##### 3. speaker는 vip 카드를 태그했을 때 vip 대응 음성이 나오나 display는 일반 고객 화면이 나오는 현상 (display만 바뀜)
##### -> 해결 : main code 수정 (!= -> ==)
##### 4. display가 제대로 나오니 음성이 반대로 나오는 현상
##### -> 해결 : sd card에서 mp3파일 안에 넣지 않고 바로 음악을 넣어야 한다. mp3 파일 안에 넣는 순간 음악 재생 순서가 바뀌는 오류 발생
#
### ☆ 여러 번 시도 후 알게 된 정보
##### 1. RST는 RFID와 Display 다른 pin에 연결해야 한다. -> 그러지 않을 경우 태그 1번만 가능 (2번부터는 반응 없음)
##### 2. Nodemcu의 반대쪽 pin을 사용하려고 했으나 적용 불가능 -> 실제 시도해봤으나 실패했음 -> 다시 해보기라는
##### 3. SD card 안에 0001, 0002와 같은 4자리 숫자로 음악을 넣어야 한다.
##### 4. 음악의 경우 처음부터 mp3여야 한다. 변환하거나 mp3파일이 아닌 경우 재생이 되지 않는다.
##### 5. 성공영상의 경우 Hi-Q 라는 App을 통해 녹음한 음성을 고음질 mp3로 저장해서 시도한 결과이다.
