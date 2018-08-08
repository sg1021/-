#include <Servo.h>
Servo  sv1, sv2, sv3, sv4, sv5, sv6, sv7, sv8, sv9, sv10, sv11, sv12, sv13, sv14, sv15, sv16;
int count=1;
int va1=60,va2=90,va3=90,va4=100;
int va5=80,va6=90,va7=40,va8=90;
int va9=110,va10=180,va11=10,va12=150;
int va13=20,va14=180,va15=135,va16=30;
int de1=0,de2=0,de3=0,de4=0;
int de5=0,de6=0,de7=0,de8=0;
int de9=0,de10=0,de11=0,de12=0;
int de13=0,de14=0,de15=0,de16=0;
void setup()
{
  sv1.attach(11);
  sv2.attach(10);
  sv3.attach(9);
  sv4.attach(8);
  sv5.attach(7);
  sv6.attach(6);
  sv7.attach(5);
  sv8.attach(4);
  sv9.attach(23);
  sv10.attach(25);
  sv11.attach(27);
  sv12.attach(29);
  sv13.attach(33);
  sv14.attach(35);
  sv15.attach(37);
  sv16.attach(39);
  
}

void loop(){

if(count=1){
sv1.write(va1);//右中肩
sv2.write(va2);//右肩
sv3.write(va3);//右肘
sv4.write(va4);//右足
sv5.write(va5);//左中肩
sv6.write(va6);//左肩
sv7.write(va7);//左肘
sv8.write(va8);//左足
sv9.write(va9);//後右中肩
sv10.write(va10);//後右肩
sv11.write(va11);//後右肘
sv12.write(va12);//後右足
sv13.write(va13);//後左中肩
sv14.write(va14);//後左肩
sv15.write(va15);//後左肘
sv16.write(va16);//後左足
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


     if(va1==60&&va3==90){
       de1=1;
       de3=1;
       de4=-1;
     }else if(va1==60&&va3!=90){
       de1=0;
     }else if(va3==90&&va1!=60){
       de3=0;
     }
     
     if(va1==110&&va3==140){
       de1=-1;
       de3=-1;
       de4=1;
     }else if(va1==110&&va3!=140){
       de1=0;
     }else if(va3==140&&va1!=110){
       de3=0;
     }
     
     
     if(va5==130&&va7==90){
      de5=-1;
      de7=-1;
      de8=1; }
      else if(va5==130&&va7!=90){
        de5=0;
      }
      else if(va7==90&&va5!=130){
        de7=0;
      }
     if(va5==80&&va7==40){
       de5=1;
       de7=1;
       de8=-1;
     }else if(va5==80&&va7!=40){
       de5=0;
     }
     else if (va7==40&&va5!=80){
       de7=0;
     }
     
     
     if(va9==110&&va11==10){
       de9 = 1;
       de11 = 1;
       de12 = -1;
        }
     else if(va9==110&&va11!=10){
         de9 = 0;}
     else if(va11==10&&va9!=110){
         de11 = 0;}
     else if(va9==160&&va11==45){
       de9  = -1;
       de11 = -1;
       de12 = 1;
     }
     else if(va9==160&&va11!=45){
         de9 = 0;}
     else if(va11==45&&va9!=160){
        de11 = 0;}
       
     
     
     
     
     if(va13==70&&va15==170){
       de13 = -1;
       de15 = -1;
       de16 = 1;}
     else if(va13==70&&va15!=170){
         de13 = 0;}
     else if(va15==170&&va13!=70){
         de15 = 0;}
     else if(va13==20&&va15==135){
       de13 = 1;
       de15 = 1;
        de16 = -1;}
     else if(va13==20&&va15!=135){
         de13 = 0;}
     else if(va15==135&&va13!=20){
         de15 = 0;}
         
         
    
     delay(15);
     
    
}
     
     
}


