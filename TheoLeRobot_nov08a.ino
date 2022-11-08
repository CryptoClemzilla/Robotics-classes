
//def pins motors and h bridge
int pinIN1 = 8;
int pinIN2 = 9;
int pinIN3 = 10;
int pinIN4 = 11;
int pinENA = 7;
int pinENB = 12;

void setup() {

//motors
pinMode (pinIN1, OUTPUT);
pinMode (pinIN2, OUTPUT);
pinMode (pinIN3, OUTPUT);
pinMode (pinIN4, OUTPUT);
pinMode (pinENA, OUTPUT);
pinMode (pinENB, OUTPUT);
Serial.begin(9600);
Serial.println("Car ready");
}



void loop() {

forward(2000, 150);
turnRight(800, 150);
forward(2000, 150);
turnRight(800, 150);
forward(2000,150);
turnRight(800, 150);
forward(2000,150);
}


void stopMotors(){
  //stop motors
digitalWrite (pinIN1, LOW);
digitalWrite (pinIN2, LOW);
digitalWrite (pinIN3, LOW);
digitalWrite (pinIN4, LOW);
}


void backward (int sec, int sp){
Serial.println("Go backward");
//speed
analogWrite(pinENA, sp);
analogWrite(pinENB, sp);
//order to the 1st motor
digitalWrite (pinIN1, 1);
digitalWrite (pinIN2, 0);
//order to the 2nd motor
digitalWrite (pinIN3, 1);
digitalWrite (pinIN4, 0);
delay(sec);
}

void forward (int sec, int sp){ 
Serial.println("Go backward");
//speed
analogWrite(pinENA, sp);
analogWrite(pinENB, sp);
//order to the 1st motor
digitalWrite (pinIN1, 0);
digitalWrite (pinIN2, 1);
//order to the 2nd motor
digitalWrite (pinIN3, 0);
digitalWrite (pinIN4, 1);
delay(sec);
}

void turnRight (int sec, int sp) {
Serial.println("Turn right");
//speed
analogWrite(pinENA, sp);
analogWrite(pinENB, sp);
//order to the 1st motor
digitalWrite (pinIN1, 0);
digitalWrite (pinIN2, 0);
//order to the 2nd motor
digitalWrite (pinIN3, 0);
digitalWrite (pinIN4, 1);
delay(sec);

}

void turnLeft (int sec, int sp) {
Serial.println("Turn left");
//speed
analogWrite(pinENA, sp);
analogWrite(pinENB, sp);
//order to the 1st motor
digitalWrite (pinIN1, 0);
digitalWrite (pinIN2, 1);
//order to the 2nd motor
digitalWrite (pinIN3, 0);
digitalWrite (pinIN4, 0);
delay(sec);
}
