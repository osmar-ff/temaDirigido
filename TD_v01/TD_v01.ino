#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */



int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;
#define B1 2
#define B2 3
#define B3 4

int B1count=0;
int B2count=0;
int B3count=0;
long Lastreceive1=0;
long Lastreceive2=0;
long Lastreceive3=0;
long IRcmd1=0;
long IRcmd2=0;
long IRcmd3=0;
void setup()
{
  pinMode(B1,INPUT);
  pinMode(B2,INPUT);
  pinMode(B3,INPUT);
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
 if (irrecv.decode(&results)) {
  
  if ( digitalRead(B1)== HIGH){
    if(B1count == 0 && results.value != 0){
      Lastreceive1=results.value;
      B1count = 1;
    }
     if(Lastreceive1 == results.value && results.value != 0){
          B1count++;
          if(B1count > 1){
            IRcmd1 = results.value;
            Serial.print("x");
            B1count = 0;
            }
          }
  }
if ( digitalRead(B2)== HIGH){
    if(B2count == 0 && results.value != 0){
      Lastreceive2=results.value;
      B2count = 1;
    }
     if(Lastreceive2 == results.value && results.value != 0){
          B2count++;
          if(B2count > 1){
            IRcmd2 = results.value;
            Serial.print("y");
            B2count = 0;
            }
          }
  }
   if ( digitalRead(B3)== HIGH){
    if(B3count == 0 && results.value != 0){
      Lastreceive3=results.value;
      B3count = 1;
    }
     if(Lastreceive3 == results.value && results.value != 0){
          B3count++;
          if(B3count > 1){
            IRcmd3 = results.value;
            Serial.print("z");
            B3count = 0;
            }
          }
  }
    if( digitalRead(B1) == LOW && digitalRead(B2) == LOW && digitalRead(B3) == LOW ){
    if(results.value != 0 && IRcmd1 == results.value){
        Serial.print("a");
      }
     if(results.value != 0 && IRcmd2 == results.value){
        Serial.print("b");
      }
     if(results.value != 0 && IRcmd3 == results.value){
        Serial.print("c");
      }
    }
    irrecv.resume(); // Receive the next value
  }
  delay(100);
  
}
