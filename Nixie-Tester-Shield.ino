/* NIXIE TUBE SHIELD FOR ARDUINO V1.1 

Author: My Electronics http://my-electronics.net
Copyright (C) 2018 My Electronics

For more information and to find out where to buy the kit visit http://my-electronics.net

SAFTEY NOTES:
This circuit design includes a switch‐mode voltage converter which generates 170 VDC.
DO NOT USE IF YOU DON’T KNOW HOW TO HANDLE HIGH VOLTAGES. 
You are responsible for the safety during the assembly and operation of this device. 

The source code can be modified for personal and educational purposes. The commercial usage is restricted. 

*/

const int EN = A0;

const int A = 13;
const int B = 12;
const int C = 11;
const int D = 10;

int nixieTable[10][4] = {
  {0, 0, 0, 0}, // 0
  {0, 0, 0, 1}, // 1
  {0, 0, 1, 0}, // 2
  {0, 0, 1, 1}, // 3
  {0, 1, 0, 0}, // 4
  {0, 1, 0, 1}, // 5
  {0, 1, 1, 0}, // 6
  {0, 1, 1, 1}, // 7
  {1, 0, 0, 0}, // 8
  {1, 0, 0, 1}, // 9
};

void nixieWrite(int a, int b, int c, int d, int digit) {
      digitalWrite(d, nixieTable[digit][0]);
      digitalWrite(c, nixieTable[digit][1]);   
      digitalWrite(b, nixieTable[digit][2]);
      digitalWrite(a, nixieTable[digit][3]);
}

void setup() {
  pinMode(EN, OUTPUT);
  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
}

void loop() {
    delay (1000);
    digitalWrite(EN, LOW); // Turn the tube OFF

    for (int i = 0; i < 10; i++) {
      nixieWrite(A, B, C, D, i);
      delay (1000); 
    }

   digitalWrite(EN, HIGH); // Turn the tube ON
}
