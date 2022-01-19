#include "BTree.h"
#include "RedBlackTree.h"
#include "NodeBTree.h"
#include "NodeRedBlackTree.h"
#include "TikTokData.h"
#include "moduloteste.h"
#include "Analise.h"
#include "FileReader.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>

using namespace std;


void auxInsertBTree(BTree tree) {



}

void auxInsertRedBlackTree(RedBlackTree tree) {



}

int main()
{
    ifstream arq;

    string linha;

    int i, n, a, id;

    FileReader c;

    Analise q;

    cout << "[1] a'rvore vermelho-preto" << endl << "[2] a'rvore B" << endl << "[3] sair"<< endl;

    cin >> i;

    if(i == 1) {

        RedBlackTree arvVP;

        auxInsertRedBlackTree(arvVP);

        cout << "[1]modoDeAnalise"<< endl << "[2]modoDeTeste" << endl;

        cin>>a;

        if(a == 1) {

            arq.open("saida.txt");

            if(arq.is_open()) {

                while(getline(arq,linha)) {

                    cout<<linha<<endl;

                }

                arq.close();

            }

            else {

                cout<<"Nao foi possivel abrir o arquivo"<<endl;

            }

        }

        else {

            cout<<"digite o id"<<endl;

            cin>>id;

            arvVP.insertId(id);

        }

    }

    else if(i == 2) {

        cout<< "digite a ordem de b" << endl;

        cin>>n;

        BTree arvB = BTree(n);

        auxInsertBTree(arvB);

        cout<< "[1]modoDeAnalise"<< endl << "[2]modoDeTeste" << endl;

        cin>>a;

        if(a==1) {

            arq.open("saida.txt");

            if(arq.is_open()) {

                while(getline(arq,linha)) {

                    cout<<linha<<endl;

                }

                arq.close();

            }

            else {

                cout<<"Nao foi possivel abrir o arquivo"<<endl;

            }



        }
        else {

            cout<<"digite o id"<<endl;

            cin>>id;

            arvB.callSearch(id);

        }

    }

    else if(i == 3) {

        exit (0);

    }

    else {

        cout<< "opção invalida"<<endl;

    }

    return 0;

}
