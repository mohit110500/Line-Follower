
#define in1 6//right forward
#define in2 5//right backward
#define in3 8//left forward
#define in4 9//left backward
#define enA 2//right motor speed
#define enB 10//left motor speed

#define ls1 22 //left to middle
#define ls2 24
#define ls3 26
#define ls4 28

#define rs1 36//right to middle
#define rs2 34
#define rs3 32
#define rs4 30

#define trigPin1 44//centre
#define echoPin1 46
#define trigPin2 40//right
#define echoPin2 42
#define trigPin3 13//left
#define echoPin3 12

const int speed1=81;//81
const int speedus=53;//65//51///55
const int DIS=16;

void setup()
{
pinMode (in1, OUTPUT);
pinMode (in2, OUTPUT);
pinMode (in3, OUTPUT);
pinMode (in4, OUTPUT);
pinMode (enA, OUTPUT);
pinMode (enB, OUTPUT);

pinMode (ls1,  INPUT);
pinMode (ls2,  INPUT);
pinMode (ls3,  INPUT);
pinMode (ls4,  INPUT);
pinMode (rs1,  INPUT);
pinMode (rs2,  INPUT);
pinMode (rs3,  INPUT);
pinMode (rs4,  INPUT);

pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
}

void loop() 
{
int LS1,LS2,LS3,LS4,RS4,RS3,RS2,RS1;
  LS1=digitalRead(ls1);
  LS2=digitalRead(ls2);
  LS3=digitalRead(ls3);
  LS4=digitalRead(ls4);
  RS4=digitalRead(rs4);
  RS3=digitalRead(rs3);
  RS2=digitalRead(rs2);
  RS1=digitalRead(rs1);


//CASES FOR FORWARD MOTION
if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==0 && RS1==0)
{
  forward();
}

//CASES FOR RIGHT MOTION

else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==1)
{
  sharpright();
}

//CASES FOR LEFT MOTION

else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
  delay(100);
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
  delay(100);
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}
else if(LS1==1 && LS2==1 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}
else if(LS1==1 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}


//CASE FOR 90 DEGREE TURN
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  uturnrightside();//from right side
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();//from right side
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  uturnrightside();//from right side
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();//from right side
}


//CASE FOR COMPLETE WHITE
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{

//..............................................................
if ( FrontSensor() < DIS && RightSensor () <DIS && LeftSensor ()<DIS) // obstacle infront of all 3 sides
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(200);
}
else if (FrontSensor() <DIS && RightSensor () <DIS && LeftSensor ()>DIS) // obstacle on right and front sides
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(350);
}
else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor ()<DIS) // obstacle on left and front sides
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(250);
}
else if (FrontSensor() <DIS && RightSensor () >DIS && LeftSensor ()>DIS) // obstacle on front sides
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
}
else if (FrontSensor() >DIS && RightSensor () >DIS && LeftSensor ()<DIS) // obstacle on left sides
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(50);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
}
else if (FrontSensor() >DIS && RightSensor () <DIS && LeftSensor ()>DIS) // obstacle on right sides
{ 
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(50);
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
}
else if(FrontSensor()>DIS && RightSensor()<DIS && LeftSensor ()<DIS)//OBSTACLE ON LEFT AND RIGHT SIDE
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speedus); 
analogWrite(enB, speedus);
delay(315);
}
else if(FrontSensor()>DIS && RightSensor()>DIS && LeftSensor ()>DIS)///NO OBSTACLE
{
  uturnleftside();
}
}

//UPPER CODE REPEAT

//CASES FOR FORWARD MOTION
if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  forward();
}
else if(LS1==0 && LS2==0 &&  LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==0 && RS1==0)
{
  forward();
}

//CASES FOR RIGHT MOTION

else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==1 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==1 && RS1==1)
{
  sharpright();
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==1)
{
  sharpright();
}

//CASES FOR LEFT MOTION

else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
  delay(100);
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
  delay(100);
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}
else if(LS1==1 && LS2==1 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}
else if(LS1==1 && LS2==0 && LS3==0 && LS4==0 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();
}


//CASE FOR 90 DEGREE TURN
else if(LS1==0 && LS2==0 && LS3==0 && LS4==0 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  uturnrightside();//from right side
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==0 && RS3==0 && RS2==0 && RS1==0)
{
  uturnleftside();//from right side
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
  uturnrightside();//from right side
}
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  forward();//from right side
}

/////////////////////////////////////////////////////////////////////////////////////////REPEATED CODE ENDS HERE


//CASE FOR COMPLETE BLACK

else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, (speed1+50)); 
analogWrite(enB, (speed1+50));
}

//CASE FOR V TURN ON RIGHT SIDE
else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==1)
{
//uturnrightside();//from right side
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, (225)); 
analogWrite(enB, (225));
}
else if(LS1==0 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==1 && RS1==1)
{
//uturnrightside();//from right side
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, (225)); 
analogWrite(enB, (225));
}
//CASE FOR V TURN ON LEFT SIDE
else if(LS1==1 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  //uturnleftside();//from left side
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, (225)); 
analogWrite(enB, (225));
}
else if(LS1==1 && LS2==1 && LS3==0 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==0)
{
  //uturnleftside();//from left side
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, (225)); 
analogWrite(enB, (225));
}

//CASE FOR V TURN AT V JOINING
else if(LS1==1 && LS2==1 && LS3==1 && LS4==1 && RS4==1 && RS3==0 && RS2==0 && RS1==1)//left
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, (speed1+50)); 
analogWrite(enB, (speed1+50));
delay(250);
}
else if(LS1==1 && LS2==0 && LS3==0 && LS4==1 && RS4==1 && RS3==1 && RS2==1 && RS1==1)//right
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, (speed1+50)); 
analogWrite(enB, (speed1+50));
delay(250);
}
}

void forward()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void reverse()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void stops()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void sharpright()
{
digitalWrite(in1, LOW);
digitalWrite(in2, LOW);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void uturnrightside()
{
digitalWrite(in1, LOW);
digitalWrite(in2, HIGH);
digitalWrite(in3, HIGH);
digitalWrite(in4, LOW);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void uturnleftside()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, HIGH);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
void sharpleft()
{
digitalWrite(in1, HIGH);
digitalWrite(in2, LOW);
digitalWrite(in3, LOW);
digitalWrite(in4, LOW);
analogWrite(enA, speed1); 
analogWrite(enB, speed1);
}
long FrontSensor ()
{
long dur;
digitalWrite(trigPin1, LOW); 
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin1, LOW);
dur = pulseIn(echoPin1, HIGH);
return (dur/30);// convert the distance to centimeters.
}
long RightSensor () 
{
long dur;
digitalWrite(trigPin2, LOW);
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin2, LOW);
dur = pulseIn(echoPin2, HIGH);
return (dur/62);// convert the distance to centimeters.
}
long LeftSensor ()    
{
long dur;
digitalWrite(trigPin3, LOW); 
delayMicroseconds(5); // delays are required for a succesful sensor operation.
digitalWrite(trigPin3, HIGH);
delayMicroseconds(10); //this delay is required as well!
digitalWrite(trigPin3, LOW);
dur = pulseIn(echoPin3, HIGH);
return (dur/50);// convert the distance to centimeters.
}
