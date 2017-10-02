#include <Arduino.h>

#define data0 2
#define data1 3
#define data2 4
#define data3 5
#define data4 6
#define data5 7
#define data6 8
#define ds0   A0
#define ds1   A1
#define _wr   A4

void setChar(char digit, char symbol) {
  digitalWrite(ds0, !(digit & 1 << 0));
  digitalWrite(ds1, !(digit & 1 << 1));
  digitalWrite(_wr, LOW);
  digitalWrite(data0, symbol & 1 << 0);
  digitalWrite(data1, symbol & 1 << 1);
  digitalWrite(data2, symbol & 1 << 2);
  digitalWrite(data3, symbol & 1 << 3);
  digitalWrite(data4, symbol & 1 << 4);
  digitalWrite(data5, symbol & 1 << 5);
  digitalWrite(data6, symbol & 1 << 6);
  digitalWrite(_wr, HIGH);
}

void setStr(String x) {
  for (size_t i = 0; i < 4; i++) {
    setChar(i, x[i]);
  }
}

void setup() {
  pinMode(data0, OUTPUT);
  pinMode(data1, OUTPUT);
  pinMode(data2, OUTPUT);
  pinMode(data3, OUTPUT);
  pinMode(data4, OUTPUT);
  pinMode(data5, OUTPUT);
  pinMode(data6, OUTPUT);
  pinMode(ds0,   OUTPUT);
  pinMode(ds1,   OUTPUT);
  pinMode(_wr,   OUTPUT);
  setStr("    ");
}

void loop() {
  for (size_t i = 0; i < 100; i++) {
    for (size_t j = 0; j < 4; j++) {
      setChar(j, random(0, 256));
    }
    delay(25);
  }
  delay(1000);
}
