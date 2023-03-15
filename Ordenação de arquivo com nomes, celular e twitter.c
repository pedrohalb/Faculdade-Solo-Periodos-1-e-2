#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[30];
  int celular;
  char twitter[20];
} registro; 

void ordena(registro agenda[], int n) {
  // Implementar a rotina de ordenação aqui
  registro aux;
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (strcmp(agenda[j].nome, agenda[j + 1].nome) > 0) { // strcmp vai comparar se o primeiro elemento vem antes ou depois, na ordem alfabética em relação ao próximo;
        strcpy(aux.nome, agenda[j].nome); // Copiar a string do segundo pro primeiro;
        aux.celular = agenda[j].celular;
        strcpy(aux.twitter, agenda[j].twitter);
        // Copiou de j para aux;
        strcpy(agenda[j].nome, agenda[j + 1].nome);
        agenda[j].celular = agenda[j + 1].celular;
        strcpy(agenda[j].twitter, agenda[j + 1].twitter);
        // Copiou de j+1 para j;
        strcpy(agenda[j + 1].nome, aux.nome);
        agenda[j + 1].celular = aux.celular;
        strcpy(agenda[j + 1].twitter, aux.twitter);
        // Copiou de aux para j+1;
      }
    }
  }
}

int main(void) {
  FILE *arq;
  registro agenda[100];
  // Desenvolver o programa aqui
  char caracter;
  int nl = 0;
  // 1. Abrir o arquivo 'agenda.csv'
  arq = fopen("agenda.csv", "rt");
  // 2. Ler as linhas do arquivo e preencher os campos do vetor agenda
    if ((arq = fopen("agenda.csv", "rt")) == NULL) {
    puts("Não é possivel abrir o arquivo porque ele não existe");
    exit(0);
  } else {
  while (!feof(arq)) { // Enquanto n não acabar de ler o arquivo ele vai...
    caracter = fgetc(arq); // caracter recebe caracter por caracter;
    if (caracter == '\n') {
      nl++; // Se caracter for igual a \n nl++, pq eu preciso saber o número de linhas, pra enviar pra func o numero de pessoas q vai ta dentro da agenda;
    }
  }
}
  rewind(arq); // Função para voltar no início do arquivo;
  for (int i = 0; i < nl; i++) {
    fscanf(arq, "%[^;]s", agenda[i].nome); // Nome do ponteiro, tipo de arquivo(ler até o ;), o ^ é um modificador pra mudar o delimitador, aonde vai guardar na agenda(posição i).nome;
    fgetc(arq);                                // Pular o ";";
    fscanf(arq, "%d", &agenda[i].celular);     // Ler o inteiro celular;
    fgetc(arq);                                // Pular ";";
    fscanf(arq, "%[^\n]s", agenda[i].twitter); // Ler até acabar a linha e guardar em agenda[i].twitter;
    fgetc(arq);                                // Vai pular o \n;
  }
  // 3. Chamar a rotina ordena para ordenar os registros por nome
  ordena(agenda, nl);
  fclose(arq);
  // 4. Criar o arquivo 'agenda-ord.csv'
  arq = fopen("agenda-ord.csv", "w"); // Recebeu a func fopen para escrever no agenda-ord, se n existir criar ou sobrescreve-lo(w);
  // 5. Gravar os campos do vetor agenda no arquivo
  for (int i = 0; i < nl; i++) {
    fprintf(arq, "%s;%d;%s\n", agenda[i].nome, agenda[i].celular,
            agenda[i].twitter);
  }
  fclose(arq);
}

/*Luiz Eduardo;1234;@luizedu
José Pedro;2345;@josepedro
Antonio Carlos;3456;@antonio
Daniel Silveira;4567;@danielsil
Eduardo Siva;5678;@eduardos*/
