#include <Wire.h>
#include <SPI.h>
#include <Pixy.h>

Pixy pixy;

int x, y, width, height;

void setup() {
  // put your setup code here, to run once:
  Wire.begin(4);
  Wire.onRequest(requestEvent);

  pixy.init();
}
String dataToSend;
int blocks;
void loop() {
  // put your main code here, to run repeatedly:
  blocks = pixy.getBlocks();
  if(blocks){
      x = pixy.blocks[0].x;
      y = pixy.blocks[0].y;
      width = pixy.blocks[0].width;
      height = pixy.blocks[0].height;
  }
  
  delay(20);
}

void requestEvent(){
  char cookies[32];
  sprintf(cookies, "%d,%d,%d,%d", x, y, width, height);
  Wire.write(cookies);
}
