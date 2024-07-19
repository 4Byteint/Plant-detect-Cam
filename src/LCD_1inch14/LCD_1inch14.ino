#include <SPI.h>
#include "LCD_Driver.h"
#include "GUI_Paint.h"
#include "image.h" // store a image

void setup()
{
  pinMode(DEV_BL_PIN, OUTPUT);
  digitalWrite(DEV_BL_PIN, HIGH);  // 打開背光（如果需要）

  SPI.begin(DEV_SCK_PIN, DEV_MISO_PIN, DEV_MOSI_PIN, DEV_CS_PIN);

  // 初始化顯示屏或其他 SPI 設備
  pinMode(DEV_CS_PIN, OUTPUT);
  pinMode(DEV_DC_PIN, OUTPUT);
  pinMode(DEV_RST_PIN, OUTPUT);
  digitalWrite(DEV_RST_PIN, LOW);
  delay(10);
  digitalWrite(DEV_RST_PIN, HIGH);
  delay(10);

  //Config_Init();
  Serial.println("Config_Init");
  LCD_Init();
  Serial.println("LCD_Init");
  LCD_Clear(WHITE);
  LCD_SetBacklight(100);
  Paint_NewImage(LCD_WIDTH, LCD_HEIGHT, 0, WHITE);
  Paint_Clear(WHITE);
  Paint_SetRotate(0);
  Paint_DrawPoint(2,1, RED, DOT_PIXEL_1X1,  DOT_FILL_RIGHTUP);//240 240
  Paint_DrawPoint(2,6, RED, DOT_PIXEL_2X2,  DOT_FILL_RIGHTUP);
  Paint_DrawPoint(2,11, RED, DOT_PIXEL_3X3, DOT_FILL_RIGHTUP);
  Paint_DrawPoint(2,16, RED, DOT_PIXEL_4X4, DOT_FILL_RIGHTUP);
  Paint_DrawPoint(2,21, RED, DOT_PIXEL_5X5, DOT_FILL_RIGHTUP);
  Paint_DrawLine( 10,  5, 40, 35, MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
  Paint_DrawLine( 10, 35, 40,  5, MAGENTA, DOT_PIXEL_2X2, LINE_STYLE_SOLID);
  Serial.println("Paint_DrawLine");
  Paint_DrawLine( 80,  20, 110, 20, CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Paint_DrawLine( 95,   5,  95, 35, CYAN, DOT_PIXEL_1X1, LINE_STYLE_DOTTED);
  Serial.println("Paint_DrawLine2");
  Paint_DrawRectangle(10, 5, 40, 35, RED, DOT_PIXEL_2X2,DRAW_FILL_EMPTY);
  Paint_DrawRectangle(45, 5, 75, 35, BLUE, DOT_PIXEL_2X2,DRAW_FILL_FULL);
  Serial.println("Paint_DrawLine3");
  Paint_DrawCircle(95, 20, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_EMPTY);
  Paint_DrawCircle(130, 20, 15, GREEN, DOT_PIXEL_1X1, DRAW_FILL_FULL);
  
  
  Paint_DrawFloatNum (50, 40 ,9.87654321,3, &Font20,  WHITE,  BLACK);
  Paint_DrawString_EN(1, 40, "ABC", &Font20, 0x000f, 0xfff0);
  Paint_DrawString_CN(1,60, "微雪电子",  &Font24CN, WHITE, BLUE);
  Paint_DrawString_EN(1, 100, "WaveShare", &Font16, RED, WHITE);

  Paint_DrawImage(gImage_70X70, 160, 60, 70, 70); 

}
void loop()
{
  // GOT the pic and show on LCD
  Paint_DrawImage(gImage_70X70, 160, 60, 70, 70); 

}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
