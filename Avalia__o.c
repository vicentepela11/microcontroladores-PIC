sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

void main() {
 TRISA = 0b00000011;
 RA0_bit = 0;
 RA1_bit = 0;
 RA2_bit = 0;
 RA3_bit = 0;
 CMCON =7;
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 //Lcd_Out(1,1,"Test");
 while(1){
 if(RA0_bit == 1)
 {
   RA2_bit =~ RA2_bit;
  }while(RA0_bit ==1);
  if(RA2_bit == 1)
  {
    Lcd_Out(2,1,"led1 on");
  }
  else
  {
   Lcd_Out(2,1,"led1 of");
  }
  if(RA1_bit == 1)
 {
   RA3_bit =~ RA3_bit;
  }while(RA1_bit ==1);
  if(RA3_bit == 1)
  {
    Lcd_Out(1,1,"led2 on");
  }
  else
  {
   Lcd_Out(1,1,"led2 of");
  }
 }
}