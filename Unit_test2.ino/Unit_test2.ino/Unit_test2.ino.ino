#include<VarSpeedServo.h>

VarSpeedServo myservo1;//VarSpeedServo　を　myservo1　に変える
VarSpeedServo myservo2;
VarSpeedServo myservo3;
VarSpeedServo myservo4;
VarSpeedServo myservo5;
VarSpeedServo myservo6;
VarSpeedServo myservo7;           
VarSpeedServo myservo8;
VarSpeedServo myservo9;//VarSpeedServo　を　myservo1　に変える
VarSpeedServo myservo10;
VarSpeedServo myservo11;
VarSpeedServo myservo12;
VarSpeedServo myservo13;
VarSpeedServo myservo14;
VarSpeedServo myservo15;           
VarSpeedServo myservo16;


const int servoPin1 = 11;
const int servoPin2 = 10;
const int servoPin3 = 9;
const int servoPin4 = 8;
const int servoPin5 = 7;
const int servoPin6 = 6;
const int servoPin7 = 5;
const int servoPin8 = 4;
const int servoPin9 = 23;
const int servoPin10 = 25;
const int servoPin11 = 27;
const int servoPin12 = 29;
const int servoPin13 = 33;
const int servoPin14 = 35;
const int servoPin15 = 37;
const int servoPin16 = 39;

int data = 0;//ラズパイからの信号データを受け取る変数"data"を初期化
int count=1;
int va1=60,va2=90,va3=90,va4=100;//前右足
int va5=80,va6=90,va7=40,va8=90;//前左足
int va9=110,va10=180,va11=10,va12=150;//後右足
int va13=20,va14=180,va15=135,va16=30;//後左足
//角度
int de1=0,de2=0,de3=0,de4=0;
int de5=0,de6=0,de7=0,de8=0;
int de9=0,de10=0,de11=0,de12=0;
int de13=0,de14=0,de15=0,de16=0;

void setup() {
  Serial.begin(9600); //シリアル通信による通信速度を9600とする
 
 //myservo1の出力は、servoPin1に反映させる
 //前
  myservo1.attach(servoPin1);//右の中肩
  myservo2.attach(servoPin2);//右肩
  myservo3.attach(servoPin3);//右ひざ　　　　　　  6  5    1  2
  myservo4.attach(servoPin4);//右くるぶし　　　　　7          3   後ろからの図
  myservo5.attach(servoPin5);//左の中肩            8          4
  myservo6.attach(servoPin6);//左肩
  myservo7.attach(servoPin7);//左ひざ
  myservo8.attach(servoPin8);//左くるぶし
  //後
  myservo9.attach(servoPin9);//右の中肩
  myservo10.attach(servoPin10);//右肩
  myservo11.attach(servoPin11);//右ひざ　　　　　　  14  13    9  10
  myservo12.attach(servoPin12);//右くるぶし　　　　　15           11   後ろからの図
  myservo13.attach(servoPin13);//左の中肩            16           12
  myservo14.attach(servoPin14);//左肩
  myservo15.attach(servoPin15);//左ひざ
  myservo16.attach(servoPin16);//左くるぶし
  //初期位置に設定
  set();
}

void loop() {
  while(Serial.available()> 0){//ラズパイからのdataが確認されたら、、、
    data = Serial.read();//そのデータを格納した"data"の中を読み込む
    Serial.print(data);//読み込んだものを表示する
    
    
    if(data == 'a'){//もし、受け取ったデータが'a'だったなら、、、
      //新しい指示があるたびに、初期位置に戻ってほしいので、ここで初期位置
      set();
      //右足
      myservo9.write(35,60,false);
      delay(10);
      myservo10.write(150,60,false);
      delay(10);
      myservo11.write(180,60,false);
      delay(10);
      myservo12.write(60,60,false);
      delay(10);
      //左足
      myservo13.write(145,60,false);
      delay(10);
      myservo14.write(90,60,false);
      delay(10);
      myservo15.write(0,60,false);
      delay(10);
      myservo16.write(120,60,false);
      delay(10);

    }else if(data == 'b'){ //おて！
        //新しい指示があるたびに、初期位置に戻ってほしいので、ここで初期位置
        set();
        //右手
        myservo1.write(0,40,true);
        delay(100);
        myservo3.write(45,40,true);
        delay(100);
        myservo1.write(30,40,true);
        delay(100);
         myservo3.write(15,40,true);
        delay(100);
       
    }else if(data == 'c'){ //ゴウ！
      set();
      walk();
      
    }else if(data == 'd'){//ポチ！（ストップ）
      set();
    }
  }
}

int set(){
//前
  myservo1.write(90,60,false);//初期位置に設定する（90°,128/225の速さ,スルー）
  myservo2.write(90,60,false);
  myservo3.write(90,60,false);
  myservo4.write(90,60,false);
  myservo5.write(90,60,false);
  myservo6.write(90,60,false);
  myservo7.write(90,60,false); //180を90にした（15番が90でまっすぐだったから）
  myservo8.write(90,60,false);
  //後ろ
  myservo9.write(90,60,false);//初期位置に設定する（90°,60/225の速さ,スルー）
  myservo10.write(180,60,false);
  myservo11.write(90,60,false);
  myservo12.write(90,60,false);
  myservo13.write(90,60,false);
  myservo14.write(180,60,false);
  myservo15.write(90,60,false);
  myservo16.write(90,60,false);
  delay(1000);
}
int walk(){
  //set();
  //いったんやさしく位置に付けるように60/255スピードのfalseで位置につかせる
  myservo1.write(va1,60);//右中肩
  myservo2.write(va2,60);//右肩
  myservo3.write(va3,60);//右肘
  myservo4.write(va4,60);//右足
  myservo5.write(va5,60);//左中肩
  myservo6.write(va6,60);//左肩
  myservo7.write(va7,60);//左肘
  myservo8.write(va8,60);//左足
  myservo9.write(va9,60);//後右中肩
  myservo10.write(va10,60);//後右肩
  myservo11.write(va11,60);//後右肘
  myservo12.write(va12,60);//後右足
  myservo13.write(va13,60);//後左中肩
  myservo14.write(va14,60);//後左肩
  myservo15.write(va15,60);//後左肘
  myservo16.write(va16,60);//後左足
  while(1){
    if(count=1){
      myservo1.write(va1,255,true);//右中肩
      myservo2.write(va2,255,true);//右肩
      myservo3.write(va3,255,true);//右肘
      myservo4.write(va4,255,true);//右足
      myservo5.write(va5,255,true);//左中肩
      myservo6.write(va6,255,true);//左肩
      myservo7.write(va7,255,true);//左肘
      myservo8.write(va8,255,true);//左足
      myservo9.write(va9,255,true);//後右中肩
      myservo10.write(va10,255,true);//後右肩
      myservo11.write(va11,255,true);//後右肘
      myservo12.write(va12,255,true);//後右足
      myservo13.write(va13,255,true);//後左中肩
      myservo14.write(va14,255,true);//後左肩
      myservo15.write(va15,255,true);//後左肘
      myservo16.write(va16,255,true);//後左足
      va1+=de1;
      va2+=de2;
      va3+=de3;
      va4+=de4;
      va5+=de5;
      va6+=de6;
      va7+=de7;
      va8+=de8;
      va9+=de9;
      va10+=de10;
      va11+=de11;
      va12+=de12;
      va13+=de13;
      va14+=de14;
      va15+=de15;
      va16+=de16;
  
       //前右足
       //＜始まり＞
      if(va1==60&&va3==90){//足が少し前へ。第二関節まっすぐ
        de1=1;
        de3=1;//曲げてく
      }
       //＜おわり＞
      if(va1==110&&va3==140){//それぞれ50°角度が変化するようにしている。
        de1=-1;
        de3=-1;//まっすぐに戻していく
      }
       
      //前左足
      //＜始まり＞
      if(va5==130&&va7==90){//第二関節まっすぐ
        de5=-1;
        de7=-1;//曲げていく
      }
      //＜終わり＞
      if(va5==80&&va7==40){//それぞれ50°角度が変化するようにしている。
        de5=1;
        de7=1;//まっすぐに戻す
      }
       //後右足
       //＜始まり＞
       //va9(90を軸)、va11(90を軸)「向きは両方同じ」
       //va9=110で少し後ろ。va11=10でかなり前にある。
      if(va9==110&&va11==10){//少し後ろにあって、第二関節は80°前。形状がくの次ならＯＫ
        de9 = 1;
        de11 = 1;
      }
      
      //＜終わり＞
      //va9=160でかなり後ろ
      if(va9==160&&va11==45){
        de9  = -1;
        de11 = -1;
      }
       //後左足
       //＜始まり＞ 
      if(va13==70&&va15==170){
        de13 = -1;
        de15 = -1;
      }
       //＜終わり＞
      if(va13==20&&va15==135){
        de13 = 1;
        de15 = 1;
      }
       
       
      
      delay(15);
     
    
}
     
}
}
