#include <stdio.h>
 
int main (void) {
    float soma, t, matriz[40][20];
    int n, p, j, i;
    for (i=0;i<5;i++)
        for (j=0;j<4;j++) {
            matriz[i][j]=0;
          }    
    scanf("%d %d", &i, &j);
    scanf ("%d %d %f", &n, &p, &t);
    while (n!=0) {
        n--;
        p--;
        matriz[p][n] = matriz[p][n] + t;
        scanf ("%d %d %f", &n, &p, &t);
    }
    printf("\nTabela de Vendas (p = produto, v = vendedor)\n");
    printf ("       v1       v2     v3       v4\n");
    printf ("  +---------------------------------+\n");
    for (i=0;i<5;i++) {
        printf ("p%d|", i+1);
        soma = 0;
        for (j=0;j<4;j++) {
            printf ("%8.2f", matriz[i][j]);
            soma = soma + matriz[i][j];
        }
        printf (" | ");
        printf ("%5.2f", soma);
        printf ("\n");
    }
    printf ("  +---------------------------------+\n");
    printf ("    ");
    for (j=0;j<4;j++){
        soma = 0;
        for (i=0;i<5;i++) {
            soma = soma + matriz[i][j];
        }
        printf ("%8.2f", soma);
    }
    printf ("\n");    
    return 0;
