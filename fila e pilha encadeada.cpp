#include <cstdlib>
#include <iostream>

typedef struct no_ {
  int valor;        //'carga útil' do nó
                    // num cenario real, poderia ser: nome, endereco...
  struct no_ *prox; // ponteiro para o próximo nó da lista encadeada
} no;

typedef struct {
  int tam;           // critério de busca da ordenação
  struct no_ *lista; // ponteiro para o próximo nó da lista encadeada
} tLista;

using namespace std;

/**
 * Realiza a alocacao do espaco para que a lista possa comecar
 * a receber nos.
 * @return a lista vazia.
 */
tLista *inicia_lista() {
  tLista *tmp = new (tLista);
  tmp->tam = 0;
  tmp->lista = NULL;

  cout << "-A lista foi iniciada." << endl;
  return tmp;
}

/**
 * Desaloca o espaco previamente alocado para a lista encadeada.
 * @param ptlista ponteiro para a lista.
 * @return NULL para atualizar o ponteiro da lista.
 */
tLista *encerra_lista(tLista *ptlista) {
  no *ant = ptlista->lista;
  no *pont = ptlista->lista;

  while (ant != NULL) {
    pont = ant->prox;
    delete (ant);
    ant = pont;
  }
  delete (ptlista);
  cout << "-A lista foi removida." << endl;

  return NULL;
}

/**
 * Busca pelo valor de chave passado dentro da lista encadeada.
 * @param chave a ser buscada.
 * @param ant ponteiro anterior a posicao encontrada.
 * @return verdareiro se o elemento foi encontrado.
 */
no *busca(tLista *ptlista, int valor) {
  no *ant = ptlista->lista;
  no *pont = NULL;
  no *ptr = ptlista->lista->prox;
  no *retorno = 0;
  while (ptr != NULL) {
    if (ptr->valor < valor) {
      ant = ptr;
      ptr = ptr->prox;
    } else {
      if (ptr->valor == valor) {
        pont = ptr;
        cout << ptr->valor << endl;
        ptr = NULL;

      } else {
        cout << "o valor n existe" << endl;
        ptr = NULL;
      }
    }
  }
  return retorno;
}

/**
 * Realiza a insercao do elemento no início da lista ligada.
 * @param valor a ser inserido.
 */
void insere_inicio(tLista *ptlista, int valor) {https://gist.github.com/xXNOMADXx/ec7d2da2842bf5b439f8a547f325ff92.js
  no *novo = new no;
  novo->valor = valor;
  novo->prox = ptlista->lista;
  ptlista->lista = novo;
  ptlista->tam++;
}

/**
 * Realiza a insercao do elemento no fim da lista ligada.
 * @param valor a ser inserido.
 */
void insere_fim(tLista *ptlista, int valor) {
  no *novo = new no;
  novo->valor = valor;
  if (ptlista->lista == NULL) {
    ptlista->lista = novo;
  } else {
    no *ant = ptlista->lista;
    for (no *ptr = ptlista->lista->prox; ptr != NULL;
         ptr = ptr->prox, ant = ant->prox) {
    }

    ant->prox = novo;
  }
}

/**
 * Realiza a remocao do primeiro elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
void remove_inicio(tLista *ptlista) {
  no *aRemover = NULL;
  no *inicio = ptlista->lista;
  if (ptlista->lista != NULL) {

    ptlista->lista = inicio->prox;
    free(inicio);
    ptlista->tam--;
    cout << "Primeiro elemento da lista removido!\n";
  } else
    cout << "Lista já vazia";
}

/**
 * Realiza a remocao do último elemento da lista encadeada, se houver.
 * @return nulo em caso de lista vazia, senão retorna o nó removido.
 */
no *remove_fim(tLista *ptlista) {
  if (ptlista->lista == NULL) {
    return NULL;
  } else if (ptlista->lista->prox == NULL) {
    remove_inicio(ptlista);
  } else {
    no *ant = ptlista->lista;
    no *ptr = ptlista->lista->prox;
    for (; ptr->prox != NULL; ptr = ptr->prox, ant = ant->prox);
    ant->prox = ptr->prox;
    free(ant);
    ptlista->tam--;
  } // dar delete no ant na main dps de chamar a função
}

/**
 * Imprime a lista encadeada.
 */
void imprime(tLista *ptlista) {
  no *inicio = ptlista->lista;
  while (inicio != NULL) {
    cout << " " << inicio->valor << " ";
    inicio = inicio->prox;
  }
  cout << "\n\n";
}

int main() {
  no *r;
  tLista lista1;
  lista1.tam = 0;
  lista1.lista = NULL;

  insere_inicio(&lista1, 5);

  insere_fim(&lista1, 10);

  insere_fim(&lista1, 13);

  // insere_inicio(&lista1, 30);

  // insere_fim(&lista1, 44);

  // insere_fim(&lista1, 55);

  // insere_fim(&lista1, 66);

  remove_inicio(&lista1);

  imprime(&lista1);

  // busca(&lista1, 44);

  return (EXIT_SUCCESS);
}
