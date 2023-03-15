#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

typedef struct no {
  int valor;
  no *direita;
  no *esquerda;
} No;

typedef struct {
  no *raiz;
} arvb;

No *inserirDiboas(No *raiz, int valor) {
  if (raiz == NULL) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
  } else {
    if (valor > raiz->valor)
      raiz->direita = inserirDiboas(raiz->direita, valor);
    if (valor < raiz->valor)
      raiz->esquerda = inserirDiboas(raiz->esquerda, valor);
  }
  return raiz;
}

int busca(No *raiz, int valor) {
  if (raiz == NULL) {
    return -1;
  } else {
    if (valor == raiz->valor) {
      return valor;
    } else {
      if (valor < raiz->valor) {
        return busca(raiz->esquerda, valor);
      } else {
        return busca(raiz->direita, valor);
      }
    }
  }
}

No *remove(No *raiz, int valor) {
  if (raiz == NULL) {
    cout << "n existe número que possa ser removido" << endl;
    return NULL;

  } else {
    if (valor == raiz->valor) {
      if (raiz->esquerda == NULL && raiz->direita == NULL) {
        free(raiz);
        return NULL;
      } else {
        if (raiz->esquerda == NULL || raiz->direita == NULL) {
          No *aux;
          if (raiz->esquerda != NULL) {
            aux = raiz->esquerda;
          } else {
            aux = raiz->direita;
          }
          free(raiz);
          return aux;
        } else {
          No *aux = raiz->esquerda;
          while (aux->direita != NULL) {
            aux = aux->direita;
          }
          raiz->valor = aux->valor;
          aux->valor = valor;
          raiz->esquerda = remove(raiz->esquerda, valor);
          return raiz;
        }
      }

    } else {
      if (valor < raiz->valor) {
        raiz->esquerda = remove(raiz->esquerda, valor);
      } else {
        raiz->direita = remove(raiz->direita, valor);
      }
      return raiz;
    }
  }
}

/*void insereEsq(No *no, int valor) {
  if (no->esquerda == NULL) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->esquerda = novo;
  } else {
    if (valor < no->esquerda->valor) {
      insereEsq(no->esquerda, valor);
    } else {
      if (no->direita == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->valor = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
        no->direita = novo;
      } else {
        if (valor > no->direita->valor) {
          if (no->direita == NULL) {
            No *novo = (No *)malloc(sizeof(No));
            novo->valor = valor;
            novo->esquerda = NULL;
            novo->direita = NULL;
            no->direita = novo;
          } else {
            insereEsq(no->direita, valor);
          }
        }
      }
    }
  }
}

void insereDir(No *no, int valor) {
  if (no->direita == NULL) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    no->direita = novo;
  } else {
    if (valor > no->direita->valor) {
      insereDir(no->direita, valor);
    } else {
      insereEsq(no->direita, valor);
    }
  }
}

void inserir(arvb *arv, int valor) {
  if (arv->raiz == NULL) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    arv->raiz = novo;
  } else {
    if (valor < arv->raiz->valor) {
      insereEsq(arv->raiz, valor);
    } else {
      insereDir(arv->raiz, valor);
    }
  }
}*/

void imprimir_em_pre_ordem(No *raiz) {
  if (raiz != NULL) {
    cout << raiz->valor << endl;
    imprimir_em_pre_ordem(raiz->esquerda);
    imprimir_em_pre_ordem(raiz->direita);
  }
}

void imprimir_em_ordem(No *raiz) {
  if (raiz != NULL) {
    imprimir_em_ordem(raiz->esquerda);
    cout << raiz->valor << endl;
    imprimir_em_ordem(raiz->direita);
  }
}

void imprimir_em_pos_ordem(No *raiz) {
  if (raiz != NULL) {
    imprimir_em_pos_ordem(raiz->esquerda);
    imprimir_em_pos_ordem(raiz->direita);
    cout << raiz->valor << endl;
  }
}

int main() {
  int op, valor;
  arvb arv;
  arv.raiz = NULL;
  No *raiz = NULL;
  do {
    cout << "n0-sair/n1-inserir/n2-imprimir em ordem/n3-buscar/n4-remover/n5-imprimir em pre ordem/n6-imprimir em pos ordem" << endl;
    cin >> op;
    switch (op) {
    case 0:
      cout << "saindo..." << endl;
      break;
    case 1:
      cout << "digite um valor: " << endl;
      cin >> valor;
      arv.raiz = inserirDiboas(arv.raiz, valor);
      break;
    case 2:
      imprimir_em_ordem(arv.raiz);
      break;
    case 3:
      cout << "qual valor deseja buscar?" << endl;
      cin >> valor;
      cout << busca(arv.raiz, valor) << endl;
      break;
    case 4:
      cout << "qual valor deseja remover?" << endl;
      cin >> valor;
      raiz = remove(arv.raiz, valor);
      break;
    case 5:
      imprimir_em_pre_ordem(arv.raiz);
      break;
    case 6:
      imprimir_em_pos_ordem(arv.raiz);
      break;
    default:
      cout << "opção inválida" << endl;
    }
  } while (op != 0);
}
