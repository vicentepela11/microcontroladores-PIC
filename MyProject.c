int x;
void main() {
     TRISA = 0b00000000;
     TRISB = 0b00000001;
     
     RA0_bit = 0;
     RA1_bit = 0;
     RA2_bit = 0;
     RA3_bit = 0;
     RA4_bit = 0;
     RA5_bit = 0;
     RA6_bit = 0;
     RA7_bit = 0;    
       
     ANSELH = 0;
     
     ANSEL = 0;


     while(1){
        if(RB0_bit){   
          RA0_bit =1;
            for(x = 1; x <= 8; x++){
                    PORTA = PORTA<<1;
                    Delay_Ms(100);
              }
              RA7_bit =1;
            for(x = 1; x <= 8; x++){
                    PORTA = PORTA>>1;
                    Delay_Ms(100);
              }
        }
     }
}