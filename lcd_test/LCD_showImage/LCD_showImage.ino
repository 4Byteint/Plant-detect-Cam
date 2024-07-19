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
  // 在圖片上疊加顯示 "healthy" 
  UWORD Xstart = 10; 
  UWORD Ystart = 10; 
  const char* pString_Healthy = "healthy"; 
  const char* pString_UnHealthy = "Unhealthy, disease:___";
  const char* pString_UnDetect = "None";
  sFONT* Font = &Font16;
  UWORD Color_Background = BLACK;
  UWORD Color_Foreground = WHITE;
  Paint_DrawString_EN(Xstart, Ystart, pString_Healthy, Font, Color_Background, Color_Foreground);
  //Paint_DrawImage(gImage_70X70, 160, 60, 70, 70); 

}
void loop()
{
  // GOT the pic and show on LCD
  //Paint_DrawImage(gImage_70X70, 160, 60, 70, 70); 

}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
