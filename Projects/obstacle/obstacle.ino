
#include "Servo.h"
Servo mind;
int servo_in = 0;
int ft_scan();

int rightDistance = 0;
int leftDistance  =0;

int trig = 7;
int echo = 6;
float walDistance = 0;


//------------------------
// Define M1 variables 
//------------------------
int in1M1	= 12;
int in2M1	= 8;
int pM1		= 11;

//------------------------
// Define M2 variables 
//------------------------
int in1M2	= 2;
int in2M2	= 4;
int pM2		= 5;



/*int btn = 2;*/
void runMotor(int motor, int direction, int speed);

void ft_runUP(int speed);
void ft_runBACK(int speed);
void ft_RIGHT(int speed);
void ft_LEFT(int speed);
void ft_stop();


void setup()
{
// OUTPUT the M1----------------------------------
	pinMode(in1M1, OUTPUT);
    pinMode(in2M1, OUTPUT);
    pinMode(pM1, OUTPUT);
// OUTPUT the M2---------------------------------- 
	pinMode(in1M2, OUTPUT);
    pinMode(in2M2, OUTPUT);
    pinMode(pM2, OUTPUT);

    Serial.begin(9600);
	pinMode(trig, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(echo , INPUT);
	digitalWrite(9, HIGH);
    mind.attach(3);
    mind.write(servo_in);

}

void loop()
{
	ft_runUP(100);
	walDistance = ft_scan();
	Serial.print("Wal Distance : ");
	Serial.println(walDistance);
	
	while(walDistance < 30) {
		Serial.print("Wal Distance : ");
		Serial.println(walDistance);
		//ft_stop();
	   ft_runBACK(100);
	   delay(200);
	   mind.write(180);
		rightDistance = ft_scan();
		delay(100);

		mind.write(0);
		leftDistance = ft_scan();
		delay(100);
		if(leftDistance < rightDistance){
			walDistance = rightDistance;
			ft_RIGHT(80);
			delay(50);
			ft_stop();
		}else {
			walDistance = leftDistance;
			ft_LEFT(80);
			delay(50);
			ft_stop();
		}
	}
	delay(300);
}

void ft_runUP(int speed){
    //-------------------------
    // Run UP Motor M1 and M2
    //-------------------------

    speed = map(speed, 0,100, 0, 255);
    analogWrite(pM1, speed);
    analogWrite(pM2, speed);
    
	digitalWrite(in1M1, 1);
    digitalWrite(in1M2, 1);
    
	digitalWrite(in2M1, 0);
    digitalWrite(in2M2, 0);

	Serial.print("Run UP | speed = ");
	Serial.println(speed);

}

void ft_runBACK(int speed){
    //-------------------------
    // Run UP Motor M1 and M2
    //-------------------------

    speed = map(speed, 0,100, 0, 255);
    analogWrite(pM1, speed);
    analogWrite(pM2, speed);
    
	digitalWrite(in1M1, 0);
    digitalWrite(in1M2, 0);
    
	digitalWrite(in2M1, 1);
    digitalWrite(in2M2, 1);

	Serial.print("Run UP | speed = ");
	Serial.println(speed);
}

void ft_RIGHT(int speed){
    runMotor(1, -1, speed);
    runMotor(2,  1, speed);
	Serial.print("Run right===> | speed = ");
	Serial.println(speed);
}

void ft_LEFT(int speed){
    runMotor(1,  1, speed);
    runMotor(2, -1, speed);
	Serial.print("<===Run LEFT | speed = ");
	Serial.println(speed);
}

void ft_stop(){
    runMotor(1,  0, 0);
    runMotor(2,  0, 0);
	Serial.println("Stop Stop Stop | speed = 0 ");

}
void runMotor(int motor, int direction, int speed)  {
	int in1, status1, in2, status2, p;
//----------------------------
//   Get Motor
//----------------------------
	if(motor == 1){
        in1 = in1M1;
        in2 = in2M1;
        p   = pM1; 
	}else{
        in1 = in1M2;
        in2 = in2M2;
        p   = pM2;       
    }

    //------------------------
    //status Check 
    //------------------------
    
    if(direction == 1)
    {
        status1 = 1;
        status2 = 0;
    }else if(direction == -1)
    {
        status1 = 0;
        status2 = 1;
    }else{
        status1 = 0;
        status2 = 0;
    }

    speed = map(speed, 0,100, 0, 255);
    analogWrite(p, speed);
    digitalWrite(in1, status1);
    digitalWrite(in2, status2);

}
int ft_scan(){
	int distance;
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(trig, LOW);
	distance = pulseIn(echo,HIGH)/58.0;
	return distance;
}