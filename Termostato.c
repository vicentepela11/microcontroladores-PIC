unsigned int TEMPERATURA = 0;
void main() {
     TRISIO = 0b000001;
     GPIO = 0;
     ANSEL = 1;
     ADCON0 =1;
     CMCON =7;
     ADC_Init();
     
     while(1){
        TEMPERATURA = ADC_Read(0);
        TEMPERATURA = TEMPERATURA * 500;
        TEMPERATURA = TEMPERATURA / 1024;

           
        if(TEMPERATURA <15){
           GP5_bit = 1;
           GP4_bit = 0;
           GP2_bit = 0;
           GP1_bit = 0;
         }
         if((TEMPERATURA >= 15)&&(TEMPERATURA < 26)){
           GP5_bit = 0;
           GP1_bit = 1;
           GP2_bit = 0;
           GP4_bit = 0;
         }
        if((TEMPERATURA >= 26) && (TEMPERATURA < 37)){
           GP5_bit = 0;
           GP4_bit = 0;
           GP2_bit = 1;
           GP1_bit = 0;
         }
          if(TEMPERATURA >=47)   {
           GP5_bit = 0;
           GP1_bit = 0;
           GP2_bit = 0;
           GP4_bit = 1;
         }
     }
}