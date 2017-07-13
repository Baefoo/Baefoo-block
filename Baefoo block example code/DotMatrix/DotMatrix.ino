#include "MaxMatrix.h"
#include "Mouths.h"
#define NumMatrix 1       // Cuantas matrices vamos a usar

MaxMatrix lc=MaxMatrix(12,10,11, NumMatrix);  // Creamos una instancia de LedControl

void setup()
{
   for (int i=0; i< NumMatrix ; i++)
   {
      lc.init();
      lc.setIntensity(1);    // Poner el brillo a un valor intermedio
   }
   Serial.begin(9600);
   Serial.println("zero:0\none:1\ntwo:2\nthree:3\nfour:4\nfive:5\nsix:6\nseven:7\neight:8\nnine:9\nsmile:10\nhappyOpen:11\nhappyClosed:12\nheart:13\nbigSurprise:14\nsmallSurprise:15\ntongueOut:16\nvamp1:17\nvamp2:18\nlineMouth:19\nconfused:20\ndiagonal:21\nsad:22\nsadOpen:23\nsadClosed:24\nokMouth:25\nxMouth:26\ninterrogation:27\nthunder:28\nculito:29\nangry:30");
}

void loop()
{
   while (Serial.available()) {
     int val = Serial.parseInt();
     if (val >= 0 && val <= 30) {
       lc.writeFull(val);
     }
   }
}
