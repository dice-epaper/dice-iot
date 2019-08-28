1. wifi 연결 필수
2. setup() 함수 내에 있는 마감 시간 변경하기 (아래 코드 참고)
![image](https://user-images.githubusercontent.com/37296369/63831914-a6b4c980-c9aa-11e9-9b51-4bb787efad2d.png)

3. 작동원리
Node MCU restart 이후에 약 10초 가량 기다린 후에 -> Card(하얀색) Tag 하면
Display는 Time Sale 화면으로 update 된다.
이때, 설정된 마감시간까지 몇 분 남았는지 약 1분 마다 update 된다.

4. 주의사항
* 하지만 for() 문으로 작동중이기 때문에 Timer 가 작동되는 중간에는 다른 card Tagging이 안된다.  
즉, Node MCU restart 스위치를 통해 다시 재시작해야한다.

-------------

4. 추후에 수정해야할 것
* 시간(분)이 1자리 숫자로 남았을 때 화면에서의 위치가 오른쪽으로 이동하도록 
![image](https://user-images.githubusercontent.com/37296369/63831627-fe066a00-c9a9-11e9-9f0d-ad092f64ad29.png)

* 마감시간 20분 전부터 가동되도록
* 마감시간 이후에는 default 화면으로 이동하도록
