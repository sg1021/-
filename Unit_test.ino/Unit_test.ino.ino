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

//サーボの通信ピン番号を13とする
const int servoPin1 = 29;
const int servoPin2 = 27;
const int servoPin3 = 25;
const int servoPin4 = 23;
const int servoPin5 = 39;
const int servoPin6 = 37;
const int servoPin7 = 35;
const int servoPin8 = 33;
const int servoPin9 = 8;
const int servoPin10 = 9;
const int servoPin11 = 10;
const int servoPin12 = 11;
const int servoPin13 = 4;
const int servoPin14 = 5;
const int servoPin15 = 6;
const int servoPin16 = 7;

int data = 0;//ラズパイからの信号データを受け取る変数"data"を初期化

void setup() {
  Serial.begin(9600); //シリアル通信による通信速度を9600とする
 
 //myservo1の出力は、servoPin1に反映させる
  myservo1.attach(servoPin1);//右くるぶし
  myservo2.attach(servoPin2);//右ひざ
  myservo3.attach(servoPin3);//右肩　　　　　　  7  8    4  3
  myservo4.attach(servoPin4);//右の中肩　　　　　6          2   後ろからの図
  myservo5.attach(servoPin5);//左くるぶし        5          1
  myservo6.attach(servoPin6);//左ひざ
  myservo7.attach(servoPin7);//左肩
  myservo8.attach(servoPin8);//左の中肩
  //前
  myservo9.attach(servoPin9);//右くるぶし
  myservo10.attach(servoPin10);//右ひざ
  myservo11.attach(servoPin11);//右肩　　　　　　  15  16    12 11
  myservo12.attach(servoPin12);//右の中肩　　　　　14           10   後ろからの図
  myservo13.attach(servoPin13);//左くるぶし        13            9
  myservo14.attach(servoPin14);//左ひざ
  myservo15.attach(servoPin15);//左肩
  myservo16.attach(servoPin16);//左の中肩
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
      myservo1.write(60,60,false);//指定した位置（180°）に（128のスピードで）動かす
      delay(10);
      myservo2.write(180,60,false);
      delay(10);
      myservo3.write(150,60,false);
      delay(10);
      myservo4.write(35,60,false);
      delay(10);
      myservo5.write(120,60,false);
      delay(10);
      myservo6.write(0,60,false);
      delay(10);
      myservo7.write(90,60,false);
      delay(10);
      myservo8.write(145,60,false);
      delay(10);
    }else if(data == 'b'){
        //新しい指示があるたびに、初期位置に戻ってほしいので、ここで初期位置
        set();
        myservo12.write(0,40,true);
        delay(100);
        myservo12.write(30,40,true);
        delay(100);
        myservo9.write(120,40,true);
      }
  }
}
 int set(){
  //後ろ
    myservo1.write(90,60,false);//初期位置に設定する（90°,128/225の速さ,スルー）
    myservo2.write(90,60,false);
    myservo3.write(180,60,false);
    myservo4.write(90,60,false);
    myservo5.write(90,60,false);
    myservo6.write(90,60,false);
    myservo7.write(90,60,false); //180を90にした（15番が90でまっすぐだったから）
    myservo8.write(90,60,false);
    //前
    myservo9.write(90,60,false);//初期位置に設定する（90°,60/225の速さ,スルー）
    myservo10.write(90,60,false);
    myservo11.write(90,60,false);
    myservo12.write(90,60,false);
    myservo13.write(90,60,false);
    myservo14.write(90,60,false);
    myservo15.write(90,60,false);
    myservo16.write(90,60,false);
    delay(1000);
  
  
}
