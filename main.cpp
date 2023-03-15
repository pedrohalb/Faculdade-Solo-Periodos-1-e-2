/*----------------------------------------------------------------------------------------------*	
	Victor Hugo Tozzo Filho	- 2020.1.08.018
	Pedro Henrique Alves Barbosa - 2022.1.08.043
	Rafael Silva Fortuna- 2022.1.08.026	
--------------------------------------------------------------------------------------------------
    !!!!!!AVISO IMPORTANTE!!!!!!
    Nesta implementação de lista encadiada, 
    o primeiro slot (o primeiro nó da lista), ficará sempre vazio, contendo valores nulos
    ou seja a lista começa a partir do segundo nó
--------------------------------------------------------------------------------------------------*/
# include <iostream>
# include <string>
# include "avl.cpp"
#include "lista.cpp"

using namespace std;

//Inserção sem balanceamento
template <typename T> //paradinha muito bacana que permite int e string
Node<T>* insertBI(Node<T>* node, T value) { // logo os parametros dessa função podem alternar entre placas ou preços com ftoi() ou numeros
    if (node == nullptr) {
        return new Node<T>(value);
    }
    if (value < node->value) {
        node->left = insertBI(node->left, value);
    } else if (value > node->value) {
        node->right = insertBI(node->right, value);
    } else {
        // ja existe
        return node;
    }
    return node;
}

int main(int argc, char**argv){
    

    Cabecalho *cabeca = new Cabecalho;
    Cabecalho *placas = new Cabecalho;
    Cabecalho *pilha  = new Cabecalho;
    Cabecalho *fila   = new Cabecalho;
    pilha->tam = 0;
    fila->tam = 0;

    
    cabeca->inicio = new Veiculo;
    
    Cabecalho *guarda = new Cabecalho;
    guarda->inicio = new Veiculo;

    leArq(cabeca,"BD_veiculos_2.txt");
    
    string line;

    int resp, caso, caso1;
    string modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa;
    float preco;

    Node<string>* rootAVL = nullptr;
    Node<string>* rootBI = nullptr;
    Node<string>* rootAVLFiltro = nullptr;
    Node<string>* rootBIFiltro = nullptr;
    Node<float>* rootAVLPreco = nullptr;

    Veiculo *percorredor;

    do{
        cout << "\n Digite : (1) para buscar(excluir)\n Digite : (2) para adicionar\n Digite : (3) para relatórios da lista principal\n Digite : (4) para empilhar carros (hidraulico add, eletrico rm)\n Digite : (5) para enfileirar carros (automatico add, manual rm)\n Digite : (6) para arvores\n Digite : (7) para sair\n";
        cin >> caso;
        switch (caso){
        case 1:
            cout << "Digite a placa a ser buscada\n";
            cin >> placa;
            busca(cabeca,placa);
            cout << "Deseja excluir?\n Sim ! exclui essa lata velha - digite(1).\n Não, nuca, não exlua, pf! - digite(2)\n";
            cin >> caso1;
            if(caso1 == 1){
                exclui(cabeca,placa);
            }
            break;
        case 2:
            int umoudois;
            cout << "Inserir Manualmente - (1)\n ou \nInserir Veiculo de um arquivo - (2)" << endl;
            cin >> umoudois;
            if (umoudois == 1)
            { 
            cout << "Digite modelo\n";
                     cin >> modelo;
            cout << "Digite marca\n";
                     cin >> marca;
            cout << "Digite versao\n";
                     cin >> versao;
            cout << "Digite ano\n";
                     cin >> ano;
            cout << "Digite kilometragem\n";
                     cin >> kilometragem;
            cout << "Digite motor\n";
                     cin >> motor;
            cout << "Digite consumo\n";
                     cin >> consumo;
            cout << "Digite moua\n";
                     cin >> moua;
            cout << "Digite direcao\n";
                     cin >> direcao;
            cout << "Digite cor\n";
                     cin >> cor;
            cout << "Digite portas\n";
                     cin >> portas;
            cout << "Digite placa\n";
                     cin >> placa;
            cout << "Digite preco (em float, ex: 12345.00)\n";
                     cin >> preco;
            cout << "adicionando......\n";
            insere_fim(cabeca,modelo,marca,versao,ano,kilometragem,motor,consumo,moua,direcao,cor,portas,placa,preco);
                     } else
                     {
                        string arq_name;
                        cout << "Digite o nome do arquivo \nExemplo: arquivo_exemplo.txt" << endl;
                        cin >> arq_name;
                        //função lê arquivo 
                        leArq(guarda, arq_name);
                        cout << "Veiculos a serem incluidos:" << endl;
                        imprime(guarda);
                        //função insere
                        addLista(cabeca,guarda);
                        imprime(cabeca);
                     }
        break;
        case 3:
            int c3;
            cout << "Mostrar os veiculos = digite (1)\nOrdenar os veiculos pelas placas = digite (2)\n";
            cin >> c3;
            if(c3 == 1){
                imprime(cabeca);
                }else {
                ordena_placa(cabeca,placas);
                imprime_placa(placas);}
        break;
        case 4:
        cria_pilha(cabeca,pilha);
        break;
        case 5:
        cria_fila(cabeca,fila);
        break;
        case 6:
            int arv1ou2;
            cout << "  Digite : (1) para Arvore AVL de todos os veiculos \n  Digite : (2) para Arvore BINARIA de todos os veiculos \n  Digite : (3) para Arvore AVL de veiculos Automaticos que custam menos de 75000 \n  Digite : (4) para Arvore Binaria de veiculos flex com direção elétrica \n  Digite : (5) para Arvore AVL de todos preços" << endl;
            cin >> arv1ou2;
            switch (arv1ou2)
            {
                case 1:
                /* Fazendo inserção de todos os nós da arvore AVL */
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        rootAVL = insert(rootAVL, percorredor->placa);  
                        percorredor = percorredor->prox;
                    }
                printTree(rootAVL,0);
                cout << "AVL Geral - pre ordem:" << endl;
                preOrder(rootAVL);
                break;

                case 2:
                /*  Fazendo inserção de todos os nós da arvore BI */
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        rootBI = insertBI(rootBI, percorredor->placa);  
                        percorredor = percorredor->prox;
                    }
                printTree(rootBI,0);
                cout << "Binaria Geral - pre ordem:" << endl;
                preOrder(rootBI);
                break;

                case 3:
                //fazendo as inserções com IF de filtro
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        if (percorredor->moua == "Automático" && percorredor->preco < 75000.00) 
                        {
                            rootAVLFiltro = insert(rootAVLFiltro, percorredor->placa); 
                            percorredor = percorredor->prox;
                        } else {
                        percorredor = percorredor->prox;
                        }
                    }
                cout << "Pre-ordem:" << endl;
                preOrder(rootAVLFiltro);
                cout << "\n------------\n" << endl;
                printTree(rootAVLFiltro,0);
                break;

                case 4:
                //fazendo as inserções com IF de filtro
                percorredor = cabeca->inicio->prox;
                    while (percorredor != NULL)
                    {
                        if (percorredor->direcao == "Elétrica" && percorredor->consumo == "Flex" )
                        {
                            rootBIFiltro = insertBI(rootBIFiltro, percorredor->placa); 
                            percorredor = percorredor->prox;
                        }else
                        {
                           percorredor = percorredor->prox; 
                        }
                    }
                cout << "Pre-ordem:" << endl;
                preOrder(rootBIFiltro);
                cout << "\n------------\n" << endl;
                printTree(rootBIFiltro,0);
                break;

                case 5:
                percorredor = cabeca->inicio->prox;
                 while (percorredor != NULL)
                    {
                            rootAVLPreco = insert(rootAVLPreco, percorredor->preco); 
                            percorredor = percorredor->prox;
                    }
                printTree(rootAVLPreco,0);
                break;
            
            default:
                break;
            }
        break;
        case 7:
            salva(cabeca);
            resp = 1;
        break;
        }
    } while (resp != 1);
    encerra_lista(cabeca); encerra_lista(placas);encerra_lista(pilha); encerra_lista(fila);
    freeTree(rootAVL);freeTree(rootBI);freeTree(rootBIFiltro);freeTree(rootAVLFiltro);
    return 0;
}