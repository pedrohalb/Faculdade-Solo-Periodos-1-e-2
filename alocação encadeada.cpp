#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct no_ {
  int valor;
  struct no_ *prox;
} no;

no *ptlista;

no *inicia_lista() {
  no *tmp = new no;
  tmp->valor = 0;
  tmp->prox = NULL;
  return tmp;
}

/*void busca(int valor, no **ant, no **pont) {
  *ant = ptlista;
  *pont = NULL;
  no *ptr = 0;
  while (ptr != NULL) {
    if (ptr->valor < valor) {
      *ant = ptr;
      ptr = ptr->prox;
    } else {
      if (ptr->valor == valor) {
        *pont = ptr;
      }
      cout << "o valor n existe" << endl;
      ptr = NULL;
    }
  }
}*/

int insere(int valor) {
  no *fodase = NULL;
  no *ptr = ptlista->prox;
  no *ant = ptlista;
  while (ptr != NULL) {
    if (ptr->valor < valor) {
      ant = ptr;
      ptr = ptr->prox;
    } else {
      if (ptr->valor == valor) {
        cout << "o valor já existe" << endl;
        fodase = ptr;
        ptr = NULL;
      } else {
        cout << "o valor n existe, ent será inserido" << endl;
        ptr = NULL;
      }
      
    }
  }
  if (fodase == NULL) {
    fodase = new no;
    fodase->valor = valor;
    fodase->prox = ant->prox;
    ant->prox = fodase;
    return 0;
  }
  return -1;
}

int remove(int valor) {
  no *ant = ptlista;
  no *fodase = NULL;
  no *ptr = ptlista->prox;
  while (ptr != NULL) {
    if (ptr->valor < valor) {
      ant = ptr;
      ptr = ptr->prox;
    } else {
      if (ptr->valor == valor) {
        cout << "o valor existe" << endl;
        fodase = ptr;
        ptr = NULL;
      } else {
        cout << "o valor n existe" << endl;
        ptr = NULL;
      }
    }
  }
  if (fodase != NULL) {
    ant->prox = fodase->prox;
    free(fodase);
    return 0;
  }
  return -1;
}

void imprime() {
  no *ptr = ptlista->prox;
  while (ptr != NULL) {
    cout << "(valor): "
         << " " << ptr->valor << endl;
    cout << "----------" << endl;
    ptr = ptr->prox;
  }
}
void encerra_lista(no *ptlista) {
  no *ant = ptlista->prox;
  no *pont = ant->prox;
  while (pont != NULL) {
    free(ant);
    ant = pont;
    pont = pont->prox;
  }
  free(ant);
  free(ptlista);
}

int main() {
  int valor;
  ptlista = inicia_lista();
  insere(6);
  insere(4);
  insere(3);
  insere(5);
  insere(2);
  insere(4);

  cout << remove(2) << endl;
  imprime();

  /*cout << remove(2) << endl;*/
  /*cout << "valor a ser removido: " << endl;
  cin >> valor;*/
  /*remove(2);
  imprime();*/
  /* cout << "valor retornado:"
        << " " << insere(4) << endl;
   imprime();*/
  encerra_lista(ptlista);
}
