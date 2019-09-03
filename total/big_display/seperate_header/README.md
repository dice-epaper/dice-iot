## 수정한 것
1. Timer 중간 RFID Tagging (가능) + 마감 시간 over 알림
2. HW 및 bit map(이미지 컨텐츠) 별로 header 파일 분리함
3. PIN MAP
![image](https://user-images.githubusercontent.com/37296369/64182513-4db1cd80-cea3-11e9-893b-6dd9e175c592.png)

## 주의사항
0. DFPlayer GND 건드리면 restart 됩니다! ---> 나중에 납땜으로 안정성 up 기대

1. header 파일 분리하면서 함수 사용이 바뀜  
[예시]  
display.update() ---> call_display_update()

2. Wifi 관련 정의는  
<code> SW_Timer</code> 에 있습니다!  

3. 새로운 함수 추가 시
* [적절한 HW] .cpp & .h file 을 찾습니다. 
* <code>oo.cpp</code> 파일에서 함수를 (정의)합니다.  

> ![image](https://user-images.githubusercontent.com/37296369/64183001-1c85cd00-cea4-11e9-9c53-df4e43e81f5b.png)

* 위 파일과 이름이 같은 <code>oo.h</code> 파일에 함수를 (선언)해줍니다.  
[단, return 형태 ex) void 와 받는 인자들을 함께 명시해줍니다.]
> ![image](https://user-images.githubusercontent.com/37296369/64183106-4a6b1180-cea4-11e9-93c1-243fa072a828.png)


## Timer 작동을 위한 안내
1. wifi setting을 꼭! 해줍니다.  
<code> main 함수의 setup() </code> 에서 <code> call_WIFI_setup("ssid", "password");</code>  
현재 환경에 맞는 ssid, password로 change

2. 시리얼 모니터로 확인하기
9600 보드 레이트 맞추고 현재 작동되는 함수를 확인합니다.  
특히, 초반 wifi setting이 약 4~5초 소요되고 화면이 1번 update 됩니다.
그리고 tagging 인식 가능하므로 안심하고 시리얼 모니터로 확인하며 작업해주세요.

3. 마감시간 setting을 해줍니다.
<code> main 함수의 setup()</code> 에서 <code> set_magamTime(2019,9,3,23,30);</code>  
위는, 마감시간을 ---> 2019년 9월 3일 23시 30분으로 지정
※ 참고로, 마감시간을 지나면 아래와 같은 화면이 뜹니다.
![image](https://user-images.githubusercontent.com/37296369/64184917-2fe66780-cea7-11e9-8e7d-901893d7cbfc.png)

4. (Card) 로 Tag 해줍니다.
