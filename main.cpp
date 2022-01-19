#include "BTree.h"
#include "RedBlackTree.h"
#include "NodeBTree.h"
#include "NodeRedBlackTree.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;

int main()
{
    ifstream arq;
    string linha;
    int i,n,a,id;
    cout << "[1] arvore vermelho-preto" << endl << "[2] arvoreB" << endl << "[3] sair"<< endl;
    cin>>i;
    if(i==1)
    {
        RedBlackTree arvVP;
        arvVP.inserir();
        cout<< "[1]modoDeAnalise"<< endl << "[2]modoDeTeste" << endl;
        cin>>a;
        if(a==1)
        {
            arq.open("saida.txt");
            if(arq.is_open)
            {
                while(getline(arq,linha))
                {
                    cout<<linha<<endl;
                }
                arq.close();
            }
            else
                cout<<"Nao foi possivel abrir o arquivo"<<endl;

        }
        else
        {
            cout<<"digite o id"<<endl;
            cin>>id;
            arvVP.busca(NodeRedBlackTree *raiz,id);
        }

    }
    else if(i==2)
    {
        BTree arvB;
        cout<< "digite a ordem de b" << endl;
        cin>>n;
        arvB.inserir();
        cout<< "[1]modoDeAnalise"<< endl << "[2]modoDeTeste" << endl;
        cin>>a;
        if(a==1)
        {
            arq.open("saida.txt");
            if(arq.is_open)
            {
                while(getline(arq,linha))
                {
                    cout<<linha<<endl;
                }
                arq.close();
            }
            else
                cout<<"Nao foi possivel abrir o arquivo"<<endl;


        }
        else
        {
            cout<<"digite o id"<<endl;
            cin>>id;
            arvB.busca(NodeBTree *raiz,id);

        }

    }
    else if(i==3)
    {
        exit 0;

    }
    else
        cout<< "opção invalida"<<endl;


    return 0;
}
