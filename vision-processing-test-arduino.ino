#include <Pixy.h>
#include <SPI.h>

Pixy pixy;

int numBlocks;
int x;
int y;
int width = 0;
int height = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

  pixy.init();
}
int j;

void loop() {
 numBlocks = pixy.getBlocks();
 
 if(numBlocks){
    x = pixy.blocks[0].x;
    y = pixy.blocks[0].y;
    width = pixy.blocks[0].width;
    height = pixy.blocks[0].height;
    
    //Don't char your cookies!
    char cookies[32];
    sprintf(cookies, "%d,%d,%d,%d", x, y, width, height); 
    Serial.println(cookies);
  }
 }
