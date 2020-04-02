/*
  DigitalReadSerial

  Reads a digital input on pin 2, prints the result to the Serial Monitor

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/DigitalReadSerial
*/

// digital pin 2 has a pushbutton attached to it. Give it a name:
int s[] = {2,3,4,5,6,7,8,9};
int p[] = {17,16,15};
int s0 = 2;
int s1 = 3;
int s2 = 4;
int s3 = 5;
int s4 = 6;
int s5 = 7;
int s6 = 8;
int s7 = 9;
int a = 17;
int b = 16;
int c = 15;
int x = 14;

int val[16] = {};

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pin an input:
  pinMode(x, INPUT);
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(s4,OUTPUT);
  pinMode(s5,OUTPUT);
  pinMode(s6,OUTPUT);
  pinMode(s7,OUTPUT);
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  for (int i=0; i<16;i++){
    val[i] = -1;
    digitalWrite(s[i],LOW);
  }
  
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pin:
  for (int i=0; i<2;i++){
    digitalWrite(s[i],HIGH);
    // 0
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    val[i*8+0] = digitalRead(x);
    // 1
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,LOW);
    val[i*8+1] = digitalRead(x);
    // 2
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    val[i*8+2] = digitalRead(x);
    // 3
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,LOW);
    val[i*8+3] = digitalRead(x);
    // 4
    digitalWrite(a,LOW);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    val[i*8+4] = digitalRead(x);
    // 5
    digitalWrite(a,HIGH);
    digitalWrite(b,LOW);
    digitalWrite(c,HIGH);
    val[i*8+5] = digitalRead(x);
    // 6
    digitalWrite(a,LOW);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    val[i*8+6] = digitalRead(x);
    // 7
    digitalWrite(a,HIGH);
    digitalWrite(b,HIGH);
    digitalWrite(c,HIGH);
    val[i*8+7] = digitalRead(x);
    
    digitalWrite(s[i],LOW);
  }
  for (int i=0; i<16;i++){
    Serial.print(" ");
    Serial.print(val[i]);
  }
  Serial.println();
  
  delay(500);        // delay in between reads for stability
}
