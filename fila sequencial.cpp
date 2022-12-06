#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct no_ {
  int chave;
  int valor;
} no;

void inicia_lista(no *lista[]) {
  for (int i = 1; i < 51; i++) {
    lista[i] = NULL;
  }
  cout << "Lista inciada." << endl;
}
void encerra_lista(no *lista[]) {
  for (int i = 1; i < 51; i++) {
    delete (lista[i]);
  }
  cout << "Lista encerrada." << endl;
}

int insere_fila(no *fila[], int *f, int *r, int *alocs, int chave, int valor) {
  int insere = -1;
  int prov = *r % 50 + 1;
  if (prov != *f) {
    *r = prov;
    fila[*r] = new (no);
    fila[*r]->chave = chave;
    fila[*r]->valor = valor;
    *alocs = *alocs + 1;
    insere = *r;
  }
  if (*f == 0) {
    *f = 1;
  }
  return insere;
}
no *remove_fila(no *fila[], int *f, int *r, int *alocs) {
  no *remove = NULL;
  if (*f != 0) {
    remove = fila[*f];
    fila[*f] = NULL;
    *alocs = *alocs - 1;
    if (*f == *r) {
      *f = 0;
      *r = 0;
    } else {
      *f = *f % 50 + 1;
    }
  }
  return remove;
}
void escreve(no *fila[], int *f, int *r, int *alocs) {
  int i = 1;

  int j = 0;
  while (j < *alocs) {
    if (fila[i] != NULL) {
      cout << i << " - Chave: " << fila[i]->chave << endl
           << "Valor: " << fila[i]->valor << endl;
      j++;
    }
    i++;
  }
}

int main(int argc, char **argv) {

  no *fila[50];
  int f = 0, r = 0, alocs = 0;
  inicia_lista(fila);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  /*insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);
  insere_fila(fila, &f, &r, &alocs, 1, 10);*/

  // remove_fila(fila, &f, &r, &alocs);
  insere_fila(fila, &f, &r, &alocs, 20, 90);
  remove_fila(fila, &f, &r, &alocs);
  // remove_fila(fila, &f, &r, &alocs);

  escreve(fila, &f, &r, &alocs);

  encerra_lista(fila);
}
