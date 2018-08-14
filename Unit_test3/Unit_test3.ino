#include<VarSpeedServo.h>

VarSpeedServo servo[16];//リストにそれぞれ変数の名前を付けるのではなく、リストの要素として扱う。servo[0].attach
//リストのなかに変数を入れようとすると初期化をする必要があり、面倒。
//「こういった場合は、リストの要素を変数として扱おう」

//1～16(実際は0～15)までの番号を振り分ける
const int PinNums[16]={11,10,9,8,7,6,5,4,23,25,27,29,33,35,37,39};


int data = 0;//ラズパイからの信号データを受け取る変数"data"を初期化
int count=1;
int va[16] = {60,90,90,100,80,90,40,90,110,180,10,150,20,180,135,30};
//角度
int de[16] = { };//リストをすべて0にする

void setup() {
  Serial.begin(9600); //シリアル通信による通信速度を9600とする
 
 //sv1の出力は、servoPin1に反映させる
 //前
 for(int i=0;i<16;i++){
   servo[i].attach(PinNums[i]);
   /*
   6  5    1  2                        [5][4] [0][1]
   7          3   後ろからの図         [6]       [2]
   8          4                        [7]       [3]
   
   14  13    9  10                     [13][12] [8][9]
   15           11   後ろからの図      [14]        [10]
   16           12                     [15]        [11]
   */
 }
  
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
      servo[8].write(35,60,false);
      delay(10);
      servo[9].write(150,60,false);
      delay(10);
     servo[10].write(180,60,false);
      delay(10);
      servo[11].write(60,60,false);
      delay(10);
      //左足
      servo[12].write(145,60,false);
      delay(10);
      servo[13].write(90,60,false);
      delay(10);
      servo[14].write(0,60,false);
      delay(10);
      servo[15].write(120,60,false);
      delay(10);

    }else if(data == 'b'){ //おて！
        //新しい指示があるたびに、初期位置に戻ってほしいので、ここで初期位置
        set();
        //右手
        servo[0].write(0,40,true);
        delay(100);
        servo[2].write(45,40,true);
        delay(100);
        servo[0].write(30,40,true);
        delay(100);
        servo[2].write(15,40,true);
        delay(100);
       
    }else if(data == 'c'){ //ゴウ！
      set();
      walk();
      
    }else if(data == 'd'){//ポチ！（ストップ）
      set();
    }
  }
}
//今回のset()の角度ではこうした。でも、本番機は少し違う。
int set(){
  
  for (int i=0;i<16;i++) {
    if (i==9 || i==13) {
      servo[i].write(180,60,false);
    } else {
      servo[i].write(90,60,false);
    }
  }
  delay(1000);
}
int walk() {
  //set();
  //いったんやさしく位置に付けるように60/255スピードのfalseで位置につかせる
  for (int i=0;i<16;i++){
    servo[i].write(va[i],60);
  }

  while(1){
    if(count=1){
      for (int i=0;i<16;i++) {
        servo[i].write(va[i],255,true);
      }
      
      for(int i=0;i<16;i++){
        va[i]+=de[i];
      }
      
       //前右足
       //＜始まり＞
      if(va[0]==60&&va[2]==90){//足が少し前へ。第二関節まっすぐ
        de[0]=1;
        de[2]=1;//曲げてく
      }else if(va[0]==60){//もしものための補正
        de[0]=0;
      }else if(va[2]==90){
        de[2]=0;
      }
       //＜おわり＞
      if(va[0]==110&&va[2]==140){//それぞれ50°角度が変化するようにしている。
        de[0]=-1;
        de[2]=-1;//まっすぐに戻していく
      }else if(va[0]==110){//もしものための補正
        de[0]=0;
      }else if(va[2]==140){
        de[2]=0;
      }
       
      //前左足
      //＜始まり＞
      if(va[4]==130&&va[6]==90){//第二関節まっすぐ
        de[4]=-1;
        de[6]=-1;//曲げていく
      }else if(va[4]==130){//もしものための補正
        de[4]=0;
      }else if(va[6]==90){
        de[6]=0;
      }
      //＜終わり＞
      if(va[4]==80&&va[6]==40){//それぞれ50°角度が変化するようにしている。
        de[4]=1;
        de[6]=1;//まっすぐに戻す
      }else if(va[4]==80){//もしものための補正
        de[4]=0;
      }else if(va[6]==40){
        de[6]=0;
      }
       //後右足
       //＜始まり＞
       //va9(90を軸)、va11(90を軸)「向きは両方同じ」
       //va9=110で少し後ろ。va11=10でかなり前にある。
      if(va[8]==110&&va[10]==10){//少し後ろにあって、第二関節は80°前。形状がくの次ならＯＫ
        de[8] = 1;
        de[10] = 1;
      }else if(va[8]==110){//もしものための補正
        de[8]=0;
      }else if(va[10]==10){
        de[10]=0;
      }
      
      //＜終わり＞
      //va9=160でかなり後ろ
      if(va[8]==160&&va[10]==45){
        de[8]  = -1;
        de[10] = -1;
      }else if(va[8]==160){//もしものための補正
        de[8]=0;
      }else if(va[10]==45){
        de[10]=0;
      }
       //後左足
       //＜始まり＞ 
      if(va[12]==70&&va[14]==170){
        de[12] = -1;
        de[14] = -1;
      }else if(va[12]==70){//もしものための補正
        de[12]=0;
      }else if(va[14]==170){
        de[14]=0;
      }
       //＜終わり＞
      if(va[12]==20&&va[14]==135){
        de[12] = 1;
        de[14] = 1;
      }else if(va[12]==20){//もしものための補正
        de[12]=0;
      }else if(va[14]==135){
        de[14]=0;
      }      
      delay(15);    
}
}
}
