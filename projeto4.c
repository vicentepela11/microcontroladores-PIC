
void main() { 
   TRISA = 0b00000001;
   ANSEL = 0b0;
   RA1_bit = 0;
   
   while(1){
      if(RA0_bit){
         delay_ms(20);
         if(RA0_bit){
            RA1_bit = ~RA1_bit;
         }
      }while(RA0_bit);
   }
}