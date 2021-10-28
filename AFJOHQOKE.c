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
char seg,m,h,dia;
char *text = "00:00:00";
unsigned cnt;
char Flags = 0;
void interrupt()
{
 TMR0=0;
 cnt++;
 INTCON.TMR0IF = 0;
 if(cnt==1000)
 {
   cnt=0;
   seg++;
   if(seg==60)
   {
     seg=0;
     m++;
     if(m==60)
     {
       seg=0;
       m=0;
       h++;
       if(h==24)
       {
        seg=0;
        m=0;
        h=0;
        dia++;
        if(dia==7)
        {
          dia=0;
        }
       }
     }
   }
 }
}


void main() 
{
 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);


TRISA = 0b00001111;
TRISB = 0b00000000;

CMCON = 7;
INTCON.GIE = 1;
INTCON.PEIE = 1;
INTCON.TMR0IE = 1;
OPTION_REG = 0b10000001;
TMR0 = 0;
seg = EEPROM_Read(3);
m = EEPROM_Read(2);
h = EEPROM_Read(1);
dia = EEPROM_Read(0);

while(1){
   text[6] = seg/10 + '0';
   text[7] = seg%10 + '0';
   text[3] = m/10 + '0';
   text[4] = m%10 + '0';
   text[0] = h/10 + '0';
   text[1] = h%10 + '0';
//   text[0] = dia/10 + '0';
//   text[1] = dia%10 + '0';

   lcd_Out(1,7,text);
   
   if(PORTA.F0) Flags.B0 = 1;
   if(PORTA.F1) Flags.B1 = 1;
   if(PORTA.F2) Flags.B2 = 1;
   if(PORTA.F3) Flags.B3 = 1;
   
   if(PORTA.F0 == 0 && Flags.F0){
     Flags.F0 = 0;
     seg++;
     if(seg >=60) seg = 0;
     EEPROM_Write(3, seg);
   }
   if(PORTA.F1 == 0 && Flags.F1){
     Flags.B1 = 0;
     m++;
     if(m >=60) m = 0;
     EEPROM_Write(2, m);
   }
   if(PORTA.F2 ==0 && Flags.F2){
     Flags.F2 = 0;
     h++;
     if(h >=24) h = 0;
     EEPROM_Write(1, h);
   }
   if(PORTA.F3 == 0 && Flags.F3){
     Flags.F3 = 0;
     h++;
     if(dia>=7) dia = 0;
     EEPROM_Write(0, dia);
   }
   switch(dia)
   {
    case 0: Lcd_out(2,10,"dom");break;
    case 1: Lcd_out(2,10,"seg");break;
    case 2: Lcd_out(2,10,"ter");break;
    case 3: Lcd_out(2,10,"qua");break;
    case 4: Lcd_out(2,10,"qui");break;
    case 5: Lcd_out(2,10,"sex");break;
    case 6: Lcd_out(2,10,"sab");break;
   }

}
}


















