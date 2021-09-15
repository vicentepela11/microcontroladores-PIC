
int cont = 1;
void main() {
     TRISA = 0B00000010;
     PORTA.B0 = 0;
     CMCON = 7;
     while(1){
         if(PORTA.B1 == 1)   {
            for(cont; cont <= 10; cont ++){
               PORTA.B0 = 1;
               Delay_ms(500);
               PORTA.B0 = 0;
               Delay_ms(500);
            }
         
         }
     }
     
     

     
}