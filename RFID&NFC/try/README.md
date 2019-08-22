# [RFID] 첫 성공
### ♠ CARD UID 받아오기 - 제일 먼저 해야 할 일
##### 1. MFRC522 를 아두이노 라이브러리에서 추가하기
##### 2. MFRC522의 예제 DumpInfo 켜기
##### 3. 다음의 영상을 따라하여 UID만 가져오기 
https://www.youtube.com/watch?v=nkD9xFcrnhY


### ♠ 위의 과정이 끝났다면 Source code와 아래의 회로 그림과 사진을 보고 시도하기 
![image](https://user-images.githubusercontent.com/53041002/63530753-1279db00-c542-11e9-9bca-2be37548ebe6.png)
![image](https://user-images.githubusercontent.com/53041002/63521666-dc345f80-c531-11e9-8593-98ca66aec650.png)
![image](https://user-images.githubusercontent.com/53041002/63521686-e7878b00-c531-11e9-87f3-baf5621a29d2.png)


### ★ 그러나 몇 가지 오류가 존재하므로 수정해야 할 필요 있음
##### 1. display의 글씨 중 '10,000' 부분이 2번째 태그부터 위치가 밀리는 현상  
##### 2. speaker가 2번째 태그부터 소리가 갑자기 커지는 현상
##### 3. speaker는 vip 카드를 태그했을 때 vip 대응 음성이 나오나 display는 일반 고객 화면이 나오는 현상 (display만 바뀜)
