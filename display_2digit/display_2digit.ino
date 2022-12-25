/*  
 
 CA2 B  C  E  D
  |  |  |  |  |
  --A--    --A--
 |    B|  |     |B
F|     | F|     |
  --G--    --G-- 
 |    C|  |     |C
E|     | E|     |
  --D--    --D--
  |  |  |  |  |
  G  DP A  F  CA1

*/

/*
0 -> ABCDEF-
1 -> -BC----
2 -> AB-DE-G
3 -> ABCD--G
4 -> -BC--FG
5 -> A-CD-FG
6 -> A-CDEFG
7 -> ABC----
8 -> ABCDEFG
9 -> ABCD-FG
*/

#define segA 2
#define segB 5
#define segC 6
#define segD 8
#define segE 7
#define segF 4
#define segG 3
#define CA1 9
#define CA2 10

const int segs[7] = {segA, segB, segC, segD, segE, segF, segG};

// 0bGFEDCBA, 0=sviti, 1=nesviti
const byte digits[10] = {0b1000000, 0b1111001, 0b0100100, 0b0110000, 0b0011001, 0b0010010, 0b0000010,
0b1111000, 0b0000000, 0b0010000};


void setup() {
  // put your setup code here, to run once:
  for(int a = 0; a<=6; a++){
    pinMode(segs[a], OUTPUT);
  }
  pinMode(CA1, OUTPUT);
  pinMode(CA2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int digitL = 0; digitL < 10; digitL++){
    for(int digitR = 0; digitR < 10; digitR++){
      unsigned long startTime = millis();      
      for(unsigned long trvani=0; trvani < 1000; trvani = millis() - startTime){
        zobrazLeve(digits[digitL]);
        delay(5);
        zobrazPrave(digits[digitR]);
        delay(5);
      }
    }
  }
}

void zobrazLeve(byte cislice){
  digitalWrite(CA1, LOW);
  digitalWrite(CA2, HIGH);
  zapisCislici(cislice);
}

void zobrazPrave(byte cislice){
  digitalWrite(CA1, HIGH);
  digitalWrite(CA2, LOW);
  zapisCislici(cislice);
}
                     
void zapisCislici(byte cislice){
  for(int i = 0; i < 7; i++){
    int bit = bitRead(cislice, i);
    digitalWrite(segs[i], bit);
  }
}
