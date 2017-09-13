#include <VirtualWire.h>
#include <VirtualWire_Config.h>


#include <RFremote.h>


String cmd1 = "0110100100100110100100100100110100100100110110110110100100110110110110110100110100110";
char cmd1c []= "0110100100100110100100100100110100100100110110110110100100110110110110110100110100110";
String cmd2 = "0110100100100110100100100100110100100100110110110110100100110110110110100100110100110";
char cmd2c[] = "0110100100100110100100100100110100100100110110110110100100110110110110110100110100110";
String cmd3 = "0110100100100110100100100100110100100100110110110110100100110110110100110100110100110";
char cmd3c[] = "0110100100100110100100100100110100100100110110110110100100110110110110110100110100110";
String cmdIn = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
SignalPatternParams params;

int eval1=0;
int eval2=0;
int eval3=0;

char receive;

RFrecv rfrecv;

void setup()
{
  Serial.begin(9600);
  delay(500);
  params.spaceMin = 10000;
  params.spaceMax = 12000;
  params.dotMin = 400;
  params.dotMax = 600;
  params.traceMin = 850;
  params.traceMax = 1050;
  params.skipFirst = 0;
  params.skipLast = 0;
  rfrecv = RFrecv(&params);
 
  
  rfrecv.begin();
  vw_set_tx_pin(4);
  vw_setup(2000);
}

void loop()
{
  if (rfrecv.available())
  {
    cmdIn=String((char*)rfrecv.cmd);
    if (eval1==0){
      if (cmdIn==cmd1){
        Serial.print("A");
      }
    }
    else if (eval1==1){
      cmd1=cmdIn;
      Serial.print("G");
    }

    if (eval2==0){
      if (cmdIn==cmd2){
        Serial.print("B");
      }
    }
    else if (eval2==1){
      cmd2=cmdIn;
      Serial.print("H");
    }
    
    if (eval3==0){
      if (cmdIn==cmd3){
        Serial.print("C");
      }
    }
    else if (eval3==1){
      cmd3=cmdIn;
      Serial.print("I");
    }
    
    
    
  }
  while(Serial.available()){
  receive=Serial.read();
  }
  if(receive>0) { 
    cmd1.toCharArray(cmd1c,cmd1.length());
    cmd2.toCharArray(cmd2c,cmd2.length());
    cmd3.toCharArray(cmd3c,cmd3.length());
    
    if(receive == 'a') { //if the string is equal to "on" then turn LED on
      vw_send((uint8_t *)cmd1c, 85);
       Serial.write("a");
       receive=0;
    }
    else if (receive == 'b') { 
      vw_send((uint8_t *)cmd2c, 85);
      //Serial.write("b");
      receive=0;
    }
    else if (receive == 'c'){
       vw_send((uint8_t *)cmd3c, 85);
       // Serial.write("c");
        receive=0;
    }
    else if (receive == 'g'){
       eval1=1;
       receive=0;
    }
    else if (receive == 'h'){
       eval2=1;
       receive=0;
    }
    else if (receive == 'i'){
       eval3=1;
       receive=0;
    }
    else if (receive == 't'){
       eval1=0;
       receive=0;
    }
    else if (receive == 'u'){
       eval2=0;
       receive=0;
    }
    else if (receive == 'v'){
       eval3=0;
       receive=0;
    }
   
  }
}

