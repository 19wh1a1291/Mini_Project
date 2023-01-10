#include<LiquidCrystal.h>;
LiquidCrystal lcd(8,9,10,11,12,13);//rs,en,data pins d4 -d7

int PWM = 6;
int MSD = 0;

int a=0;
int b=0;
int c=0;
int d=0;

int ac=0;
int aa=0;
int bb=0;
int cc=0;
int dd=0;
int ee=0;
const int SW1=4; int SW1INC=1;
const int SW2=5; int SW2DEC=1;

const int S1E=A0;
const int S2E=A1;
const int S3E=A2;
const int S4E=A3;

int S11E=0;
int S12E=0;
int S13E=0;
int S14E=0;

int S1Ealert=1;
int S2Ealert=1;
int S3Ealert=1;
int S4Ealert=1;

void setup()
{

lcd.begin(16,2);

analogWrite(PWM, MSD);

pinMode(SW1, INPUT_PULLUP);

pinMode(SW2, INPUT_PULLUP);

pinMode(S1E, INPUT);
pinMode(S2E, INPUT);
pinMode(S3E, INPUT);
pinMode(S4E, INPUT);

lcd.clear();
lcd.setCursor(0,0);
lcd.print(&quot;Vehicle Speed&quot;);
lcd.setCursor(0,1);
lcd.print(&quot;Limit Controller&quot;);
delay (5000);
lcd.clear();

}

void loop()
{

S1Ealert = digitalRead(S1E);if (S1Ealert == LOW){S11E=0;}else{S11E=1;}
S2Ealert = digitalRead(S2E);if (S2Ealert == LOW){S12E=0;}else{S12E=1;}

S3Ealert = digitalRead(S3E);if (S3Ealert == LOW){S13E=0;}else{S13E=1;}
S4Ealert = digitalRead(S4E);if (S4Ealert == LOW){S14E=0;}else{S14E=1;}
if((S11E==1) &amp; (S12E==1) &amp; (S13E==1) &amp; (S14E==1))
{
SW1INC = digitalRead(SW1);
if (SW1INC == LOW)
{
ac=ac+1;delay(500);
if(ac&gt;10){ac=10;delay(500);}
}

SW2DEC = digitalRead(SW2);
if (SW2DEC == LOW)
{
if(ac&gt;0)
{
ac=ac-1;
delay(500);
}
}

if(ac==0){MSD=0; analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
0 mph &quot;);a=0;b=0;c=0;d=0;}
if(ac==1){MSD=100;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
10 mph &quot;);a=0;b=0;c=0;d=0;}
if(ac==2){MSD=120;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
20 mph &quot;);dd=0;a=0;b=0;c=0;d=0;}
if(ac==3){MSD=140;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
30 mph &quot;);a=1;b=0;c=0;d=0;}
if(ac==4){MSD=160;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
40 mph &quot;);cc=0;a=1;b=0;c=0;d=0;}
if(ac==5){MSD=180;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
50 mph &quot;);a=1;b=1;c=0;d=0;}
if(ac==6){MSD=200;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
60 mph &quot;);bb=0;a=1;b=1;c=0;d=0;}
if(ac==7){MSD=225;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
70 mph &quot;);a=1;b=1;c=1;d=0;}
if(ac==8){MSD=235;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
80 mph &quot;);ee=0;aa=0;a=1;b=1;c=1;d=0;}
if(ac==9){MSD=245;analogWrite(PWM, MSD);delay(500); lcd.setCursor(0,0);lcd.print(&quot;Speed:
90 mph &quot;);a=1;b=1;c=1;d=1;}
if(ac==10)
{
ee=ee+1;
if(ee==1){MSD=255;analogWrite(PWM, MSD);
lcd.setCursor(0,0);lcd.print(&quot;Speed: 100 mph &quot;);
lcd.setCursor(0,1);lcd.print(&quot;Max speed &quot;);delay(2000);lcd.clear();}

if(ee==2){MSD=255;analogWrite(PWM, MSD);lcd.setCursor(0,0);lcd.print(&quot;Speed: 100 mph
&quot;);}
if(ee==3){ee=2;a=1;b=1;c=1;d=1;goto st;}
}
}
st:
//////////////////////////////////////////vehicle speed 80mph/////////////////////////////////////////////////////////
if(d==1)
{
if((S11E==0) &amp; (S12E==1) &amp; (S13E==1) &amp; (S14E==1))
{
aa=aa+1;
if(aa==1)
{
lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Over Speeding &quot;);
lcd.setCursor(0,1);lcd.print(&quot; Detected!! &quot;);
delay (5000);lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Capping Speed &quot;);
lcd.setCursor(0,1);lcd.print(&quot; to 80mph &quot;);
delay (5000);lcd.clear();
}
if(aa&gt;=2)

{
lcd.setCursor(0,0);lcd.print(&quot;SpeedLimit:80mph&quot;);
lcd.setCursor(0,1);lcd.print(&quot;Speed: 80 mph &quot;);
MSD=235;analogWrite(PWM, MSD);delay(500);
delay (3000);lcd.clear();ac=8;
}
}
}
//////////////////////////////////////////vehicle speed 60mph/////////////////////////////////////////////////////////
if(c==1)
{
if((S11E==1) &amp; (S12E==0) &amp; (S13E==1) &amp; (S14E==1))
{
bb=bb+1;
if(bb==1)
{
lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Over Speeding &quot;);
lcd.setCursor(0,1);lcd.print(&quot; Detected!! &quot;);
delay (5000);lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Capping Speed &quot;);
lcd.setCursor(0,1);lcd.print(&quot; to 60mph &quot;);
delay (5000);lcd.clear();

}
if(bb&gt;=2)
{
lcd.setCursor(0,0);lcd.print(&quot;SpeedLimit:60mph&quot;);
lcd.setCursor(0,1);lcd.print(&quot;Speed: 60 mph &quot;);
MSD=200;analogWrite(PWM, MSD);delay(500);
delay (3000);lcd.clear();ac=6;
}
}
}
//////////////////////////////////////////vehicle speed 40mph/////////////////////////////////////////////////////////
if(b==1)
{
if((S11E==1) &amp; (S12E==1) &amp; (S13E==0) &amp; (S14E==1))
{
cc=cc+1;
if(cc==1)
{
lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Over Speeding &quot;);
lcd.setCursor(0,1);lcd.print(&quot; Detected!! &quot;);
delay (5000);lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Capping Speed &quot;);

lcd.setCursor(0,1);lcd.print(&quot; to 40mph &quot;);
delay (5000);lcd.clear();
}
if(cc&gt;=2)
{
lcd.setCursor(0,0);lcd.print(&quot;SpeedLimit:40mph&quot;);
lcd.setCursor(0,1);lcd.print(&quot;Speed: 40 mph &quot;);
MSD=160;analogWrite(PWM, MSD);delay(500);
delay (3000);lcd.clear();ac=4;
}
}
}
//////////////////////////////////////////vehicle speed 20mph////////////////////////////////////////////////////////
if(a==1)
{
if((S11E==1) &amp; (S12E==1) &amp; (S13E==1) &amp; (S14E==0))
{
dd=dd+1;
if(dd==1)
{
lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Over Speeding &quot;);
lcd.setCursor(0,1);lcd.print(&quot; Detected!! &quot;);

delay (5000);lcd.clear();
lcd.setCursor(0,0);lcd.print(&quot;Capping Speed &quot;);
lcd.setCursor(0,1);lcd.print(&quot; to 20mph &quot;);
delay (5000);lcd.clear();
}
if(dd&gt;=2)
{
lcd.setCursor(0,0);lcd.print(&quot;SpeedLimit:20mph&quot;);
lcd.setCursor(0,1);lcd.print(&quot;Speed: 20 mph &quot;);
MSD=120;analogWrite(PWM, MSD);delay(500);
delay (3000);lcd.clear();ac=2;
}
}
}
}