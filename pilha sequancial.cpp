#include <cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct no_ {
  int chave;
  int valor;
} no;

void inicia_lista(no *lista[]) {
  for (int i = 0; i < 50; i++) {
    lista[i] = NULL;
  }
  cout << "Lista inciada." << endl;
}

void encerra_lista(no *lista[], int *ptam) {
  for (int i = 0; i < *ptam; i++) {
    delete (lista[i]);
  }
  cout << "Lista encerrada." << endl;
}
int insere_pilha(no *pilha[], int *ptopo, int chave, int valor) {
  int insere = -1;
  if (*ptopo < 50) {
    *ptopo = *ptopo + 1;
    pilha[*ptopo] = new (no);
    pilha[*ptopo]->chave = chave;
    pilha[*ptopo]->valor = valor;
    insere = *ptopo;
  }
  return insere;
}
no *remove_pilha(no *pilha[], int *ptopo) {
  no *remove = NULL;
  if (*ptopo != -1) {
    remove = pilha[*ptopo];
    pilha[*ptopo] = NULL;
    *ptopo = *ptopo - 1;
  }
  return remove;
}
void escreve(no *lista[]) {
  for (int i = 0; lista[i] != NULL; i++) {
    cout << i + 1 << " "
         << "Chave: " << lista[i]->chave << "\n"
         << " Valor: " << lista[i]->valor << endl;
  }
}
int main(int argc, char **argv) {

  no *pilha[50];
  no *removido;
  int topo = -1;

  inicia_lista(pilha);
  insere_pilha(pilha, &topo, 1, 10);
  insere_pilha(pilha, &topo, 2, 20);
  insere_pilha(pilha, &topo, 3, 30);

  escreve(pilha);

  remove_pilha(pilha, &topo);
  escreve(pilha);

  encerra_lista(pilha, &topo);

  return 0;
}
