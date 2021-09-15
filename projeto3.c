sbit LIGA at RA1_bit;
sbit DESLIGA at RA2_bit;
sbit MOTOR at RA0_bit;


void main() {
     int MOTOR = 0;
     TRISA = 0b00000110;
     CMCON = 7;
     MOTOR = 0;
     while(1){
       if(LIGA == 1){
           MOTOR++;
           if(MOTOR>255){
             MOTOR=255;
           }
       }
       
       if(DESLIGA == 1){
         MOTOR--;
         if(MOTOR<0){
           MOTOR = 0;
         }
       }
     Delay_ms(100);
     PWM1_Set_Duty(MOTOR);

     }
}