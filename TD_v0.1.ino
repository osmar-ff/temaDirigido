#include <VirtualWire.h>
#include <VirtualWire_Config.h>


#include <RFremote.h>


const char *cmd1 = "0110100100100110100100100100110100100100110110110110100100110110110110110100110100110";
const char *cmd2 = "0110100100100110100100100100110100100100110110110110100100110110110110100100110100110";
const char *cmd3 = "0110100100100110100100100100110100100100110110110110100100110110110100110100110100110";
SignalPatternParams params;

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
    if (strncmp((char*)rfrecv.cmd, cmd1, CMD_SIZE) == 0)
    {
      Serial.print("A");
    }
    else
    {
      if (strncmp((char*)rfrecv.cmd, cmd2, CMD_SIZE) == 0)
    {
      Serial.print("B");
    }
    else
    {
      if (strncmp((char*)rfrecv.cmd, cmd3, CMD_SIZE) == 0)
    {
      Serial.print("C");
    }
    else
    {
      Serial.print("ERRO!");
    }
    }
    }
  }
  String t;
  while(Serial.available()){
  t+=(char)Serial.read();
  }
  if(t.length()) { //if string is not empty do the following
    if(t == "a") { //if the string is equal to "on" then turn LED on
      vw_send("0110100100100110100100100100110100100100110110110110100100110110110110110100110100110", 85);
    Serial.write("a");
    }
    else if (t == "b") { 
      vw_send("0110100100100110100100100100110100100100110110110110100100110110110110100100110100110", 85);
      Serial.write("b");
    }
    else if (t=="c"){
       vw_send("0110100100100110100100100100110100100100110110110110100100110110110100110100110100110", 85);
        Serial.write("c"); 
  
  }
  }
}

