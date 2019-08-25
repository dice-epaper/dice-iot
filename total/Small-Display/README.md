# [8/25 수행 작업]


### I. Display 출력 함수 수정
#### 1. showBitMapExample() 함수 -> showBitmap()
  * 작대기와 네모 그림 분리 하기
  * 위치, 크기 변수 받기
  
    > 예시  
     showBitmap( "arrow", 70, 55, 120, 40 ); 
     // Image_sale.h 파일에서 "arrow" bitmap을 70,55 위치에 120*40 크기로 배치

#### 2. void showFont(const char name[], const uint8_t *f, const int num1, const int num2)
  * display.setCursor(num1 , num2); 없앴음  
  showFont() 함수에 위치 넣으면 됨
  
    > 예시
      showFont("Text", u8g2_font_unifont_t_korean1, 10, 20);  
      // Text 글씨를 rotation(1) 한 후의 10, 20 위치에 배치
  
#### 3. void showfreeFont(const char name[], const GFXfont* f,const int num1, const int num2, uint16_t fontColor)
  * I-2. 과 이하 동문
  
  ---------------
  
### II. RFID
1. RFID Card (UID) List 2차원 배열로 등록해서 관리
UID의 첫 숫자로만 파악하기 

2. 예시  
    > int memberCards[4][4] = {
    {0xD9, 0xAD, 0xC8, 0x55}, //member1 선미's Card  
    {0xC9, 0xAA, 0x54, 0x47}, //member2 선미's token  
    {0xF9, 0xF2, 0xCB, 0x56}, //member3 민주's Card  
    {0xA9, 0x30, 0x50, 0x47} //member4 민주's token  
  };
 
  ---------------
  
### III. 추가로 수정해야할 작업
  * 한글 font Library 확장 !! > Olikraus/u8g2 git repository 참조
  * u8g2 font > 화면 OVER 하면 자동 줄바꿈 되도록
  (우선은, 제품 등록시 제품명 글자수 제한해서 받기)
  
  > u8g2_font_unifont_t_korean1 알아낸 것
   (12.3inch e-Paper)  
  \- 한글 12~13 글자 printing 가능  
  \- [Display] 한글 1글자 = 숫자/영어 2글자   
  \- [length] 한글 1글자 = 3, 영어 1글자 =1  
  
   
