

void main() {
   TRISA = 0b00111001;
   TRISB = 0b00000000;
   ANSEL = 0;
   
   RA1_bit = 0;
   
   RB1_bit = 0;
   RB2_bit = 0;
   RB3_bit = 0;
   
   while(1){
      if(RA0_bit){
         delay_ms(15);
         if(RA0_bit){
            RA1_bit = ~RA1_bit;
         }
      }while(RA0_bit);
      
      if(RA3_bit){
         delay_ms(15);
         if(RA3_bit){
            RB1_bit = ~RB1_bit;
         }while(RA3_bit);
      }
      
      if(RA4_bit){
         delay_ms(15);
         if(RA4_bit){
            RB2_bit = ~RB2_bit;
         }
      }while(RA4_bit);
      
      if(RA5_bit){
         delay_ms(15);
         if(RA5_bit){
            RB3_bit = ~RB3_bit;
         }
      }while(RA5_bit);
   }
}
