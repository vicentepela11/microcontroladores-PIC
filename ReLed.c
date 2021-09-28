int plot;
int x = 0 ;
void main() {
   TRISIO = 0b000011;
   GPIO = 0;
   ANSEL = 1;
   ADCON0 = 1;
   CMCON = 7;
   
   ADC_Init();
   
   while(1){
      plot = ADC_Read(0);
      plot = plot /102.4;
      
      if(GP1_bit == 1){
         for(x=0; x <= plot; x++){
          GP2_bit = 1;
          delay_ms(1000);
         }
      }
      GP2_bit = 0;
   }
}