/*********************************************************
 * Simple Test of Table for oled Displays 
 * Creates 5 lines and 2 colums. Switches the last text ...  
 * Currently tested with 
 * TTGO Lora32 Oled
 * 
 * Created by SteFam http://www.fambach.net
 * GPL2 V3
 * 
 */

#include "OledTable.h"


/* Init  SSD1306 */
#include "SSD1306.h" 

#define DISPLAY_SDA 4
#define DISPLAY_SCL 15
#define DISPLAY_RST 16
#define SSD_ADDRESS 0x3c
SSD1306  display(SSD_ADDRESS, DISPLAY_SDA, DISPLAY_SCL);
OledTable table(&display,5,2);
 
void setup(){

  // reset display 
  pinMode(DISPLAY_RST, OUTPUT);
  digitalWrite(DISPLAY_RST, LOW);    // set GPIO16 low to reset OLED
  delay(50);
  digitalWrite(DISPLAY_RST, HIGH); // while OLED is running, must set GPIO16 in high、

  // init display
  display.init();
  display.flipScreenVertically();
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10); // set a font

  // init table
  table.init();
  
}
bool sw = false;
void loop(){
  table.clear();
  // songtext of Alanis Morissette I'm a bitch ... 
  table.setText(0,0, String("I'm a bitch"));
  table.setText(0,1, "I'm a lover");
  table.setText(1,0, "I'm a child");
  table.setText(1,1, "I'm a mother");
  table.setText(2,0, "I'm a sinner");
  table.setText(2,1, "I'm a saint");
  table.setText(3,0, "I do not feel ashamed", sw);
  table.refresh();

  sw = !sw;
  delay(2000);

}
