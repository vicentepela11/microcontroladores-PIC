// LCD module connections
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

int menu = 0    ;

sbit PROXIMO at RA0_bit;
sbit ANTERIOR at RA1_bit;
sbit ENTER at RA2_bit;

sbit LED1 at RA3_bit;   
sbit LED2 at RA6_bit ;
sbit LED3 at RA7_bit  ;

void main() 
{
TRISA = 0B00000111;
CMCON = 7;
Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
Lcd_Out(1,1,"ESCOLHA");
Lcd_Out(2,1,"TAREFA");

RA3_bit = 0;
RA6_bit = 0;
RA7_bit = 0;

while(1)
{
 if(PROXIMO==1)
 {
 menu++;
 }while(PROXIMO == 1);
 
 if(ANTERIOR==1)
 {
 menu--;
 }  while(ANTERIOR == 1);
 
 if((ENTER==1)&&(menu==1))
 {
 LED1 = 1;
 
 }
 if((ENTER==1)&&(menu==2))
 {
 LED1 = 0;
 
 }
  if((ENTER==1)&&(menu==3))
 {
 LED2 = 1;
 
 }
  if((ENTER==1)&&(menu==4))
 {
 LED2 = 0;
 }
 
  if((ENTER==1)&&(menu==5))
 {
 LED3 = 1;
 }
 
 switch(menu)
 {
  case 1: Lcd_Out(1,1,"LED 1 ON");
          Lcd_Out(2,1,"LED 1 OFF");break;
  case 2: Lcd_Out(1,1,"LED 1 OFF");
          Lcd_Out(2,1,"LED 2 ON");break;
  case 3: Lcd_Out(1,1,"LED 2 ON");
          Lcd_Out(2,1,"LED 2 OFF");break;       
  case 4: Lcd_Out(1,1,"LED 2 OFF");
          Lcd_Out(2,1,"LED 3 ON");break;  
  case 5: Lcd_Out(1,1,"LED 3 ON");
          Lcd_Out(2,1,"LED 3 OFF");break;  

}
}
}