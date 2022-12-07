#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

struct Node{
    int valor;
    Node *esq;
    Node *dir;
    Node *raiz;
};

/*struct Cabecalho{
    Node *raiz;
};*/

void inicia_arvore(Node *raiz){
    Node *arvore = new Node;
    cout << "a lista foi iniciada"<<endl;;
}

no *insere_arvore(Node *arvore, int valor){
    if(arvore->raiz == NULL){
        arvore->raiz->valor=valor;
    }else{
        if(arvore->valor > valor){
            arvore->dir=valor;
        }else{
            if(arvore->valor < valor){
                arvore->esq=valor;
           }else{
            if(arvore->valor==valor){
                cout<<"o valor já existe"<<endl;
            }
          }
        }
    }
}

encerra_arvore(){}
