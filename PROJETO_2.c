void main() {
 TRISA = 0B00000000;
 PORTA.B0 = 0;
 for( ; ;){
   PORTA.B0 = 0;
   Delay_ms(500);
   PORTA.B0 = 1;
   Delay_ms(500);
 }
}