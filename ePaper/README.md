# E-Paper 개발 시작

1. raw branch : libarary 파일 > GxEPD.zip > 

    or 다운로드 경로 : <https://github.com/ZinggJM/GxEPD />

---
2. master branch : 개발 기록
* 사용 모델 vs header 파일

(Small) GxGDEW0213Z16  // 2.13" b/w/r  
(Big)   GxGDEW042Z15   // 4.2" b/w/r

	디스플레이 모델 읽는 방법 : 디스플레이 하단(노란 얇은 판 부분)에 WFT0213CZ16 => GxGDEW0213Z16.h 끝 부분 매칭

* Pin Matching  
	디스플레이(2.13inch e paper C) - NodeMCU  
	BUSY - D2  
	RST(RES) - D4   
	DC(D/C) - D3  
	CS - D8  
	CLK(SCK) - D5  
	DIN(SDI) - D7  
	GND -GND  
	3.3V - 3.3V  
