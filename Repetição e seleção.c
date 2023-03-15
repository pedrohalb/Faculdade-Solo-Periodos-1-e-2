#include <stdio.h>

int main() {
  int num1 = 123, centena, dezena, unidade, num1Inv, sub, som, maior, menor, numInv2, caso = 0;
  while(num1<=987){
   unidade = num1%10;
   dezena = ((num1%100)-unidade)/10;
   centena = (num1-(num1%100))/100;
   num1Inv = (unidade*100) + (dezena*10) + (centena);
    if((centena!=dezena)&&(centena!=unidade)&&(unidade!=dezena)&&(unidade!=0)&&(dezena!=0)){
     if(num1>num1Inv){
       maior = num1;
       menor = num1Inv;
     }else{
       maior = num1Inv;
       menor = num1;}
     sub = maior - menor;
     unidade = sub%10;
     dezena = ((sub%100)-unidade)/10;
     centena = (sub-(sub%100))/100;
     numInv2 = (unidade*100) + (dezena*10) + (centena);
     som = sub + numInv2;
     caso = caso + 1;
     printf("caso%4i: %d-%d=%3d, %3d+%d=%d\n", caso, maior, menor, sub, sub, numInv2, som);}
    num1 = num1 + 1;
    }
  }
