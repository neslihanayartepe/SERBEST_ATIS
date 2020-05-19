//!!!!!NOT= g=10 m/s^2 olarak alınmıştır!!!!!!
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include <LiquidCrystal.h>
#define trigger A4
#define echo A5
//int sure;                                               //Ses dalgasının gidip gelme süresi değişkeni
//int distance;                                            //Ölçülen uzaklık değeri değişkeni
int t;
int V;
int E;
int m = 1  ; //kg cinsinden yazınız

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

float time = 0, distance = 0;

void setup()
{
  lcd.begin(16, 2); //sütun satır
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);

  //lcd.setCursor(7,1);
  //lcd.print("h");


}

void loop()
{

  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH);
  distance = time * 340 / 20000; //burada cm olarak hesaplanıyor.Daha sonra aşağıda metre olacak.
  float t = sqrt(distance / 500); //süreyi hesaplarken 100 ile de böldüm çünkü distance cm kalmıştı burada metre ile süreyi hesaplamış oldum. ayrıca float ondalığa çevirmeye yarıyor.
  // t = V / 10;
  V = 10 * t;
  // m = m / 1000;// grama çevriliyor.
  E = sq(V) * m / 2 ;
delay(20);
   // lcd.clear(); //burdan itibaren
    lcd.setCursor(0, 0);
    lcd.print("h=");
    lcd.print(distance / 100); //metreye çevirmek için bölü 100
    lcd.print("m");
  
    lcd.print("  t=");
    lcd.print(t);
    lcd.print("sn");
  
    lcd.setCursor(0, 1);
    lcd.print("V=");
    lcd.print(V);
    lcd.print(" m/s");
    lcd.print("  E=");
    lcd.print(E);
    lcd.print("J"); //birim kgm^2/s^2


  Serial.print(distance / 100);
  Serial.print(",");
  Serial.println(V);
  //Serial.print(",");
  //Serial.print(E);
  //Serial.print("j,");
  



}
