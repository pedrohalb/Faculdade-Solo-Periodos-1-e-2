#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int heap[MAX_SIZE];
int heapSize = 0;

// Função para trocar dois valores inteiros
void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Função para retornar o índice do pai de um nó
int parent(int i) { return (i - 1) / 2; }

// Função para retornar o índice do filho esquerdo de um nó
int left(int i) { return 2 * i + 1; }

// Função para retornar o índice do filho direito de um nó
int right(int i) { return 2 * i + 2; }

// Função para manter a propriedade de max-heap após a inserção de um novo nó
void heapifyUp(int i) {
  int p = parent(i);
  while (i > 0 && heap[i] > heap[p]) {
    swap(&heap[i], &heap[p]);
    i = p;
    p = parent(i);
  }
}

// Função para inserir um novo valor na árvore heap
void insert(int key) {
  if (heapSize == MAX_SIZE) {
    printf("A heap está cheia!\n");
    return;
  }
  heapSize++;
  int i = heapSize - 1;
  heap[i] = key;
  heapifyUp(i);
}

// Função para manter a propriedade de max-heap após a remoção de um nó
void heapifyDown(int i) {
  int l = left(i);
  int r = right(i);
  int largest = i;
  if (l < heapSize && heap[l] > heap[i]) {
    largest = l;
  }
  if (r < heapSize && heap[r] > heap[largest]) {
    largest = r;
  }
  if (largest != i) {
    swap(&heap[i], &heap[largest]);
    heapifyDown(largest);
  }
}

// Função para remover o valor máximo (raiz) da árvore heap
void extractMax() {
  if (heapSize <= 0) {
    printf("A heap está vazia!\n");
    return;
  }
  if (heapSize == 1) {
    heapSize--;
    return;
  }
  heap[0] = heap[heapSize - 1];
  heapSize--;
  heapifyDown(0);
}
