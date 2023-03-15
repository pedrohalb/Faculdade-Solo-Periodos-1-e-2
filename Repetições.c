#include <stdio.h>

int main(void) {
  int maior = 0, menor = 0, aux = 0, i = 0;
  do {
    printf("\n Digite um numero:");
    scanf("%i", &aux);
    if (i == 0) {
      maior = aux;
      menor = aux;
      i++;
    } else if (aux == -1) {
      break;
    } else if (aux > maior) {
      maior = aux;
    } else if (aux < menor) {
      menor = aux;
    }
  } while (1);
  printf("\n Dos 10 valores positivos lidos, o maior foi %i e o menor %i",
         maior, menor);
}
