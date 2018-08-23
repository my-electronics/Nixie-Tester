/* NIXIE TESTER SHIELD FOR ARDUINO V1.1 

Author: My Electronics http://my-electronics.net
Copyright (C) 2018 My Electronics

Check out the My Electronics website http://my-electronics.net to find out where to buy the kit.

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
      digitalWrite(D, nixieTable[i][0]);
      digitalWrite(C, nixieTable[i][1]);   
      digitalWrite(B, nixieTable[i][2]);
      digitalWrite(A, nixieTable[i][3]);
      delay (1000); 
    }

   digitalWrite(EN, HIGH); // Turn the tube ON
}
