#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>

#include "Analise.h"
#include "TikTokData.h"
#include "BTree.h"
#include "RedBlackTree.h"

using namespace std;

Analise::Analise()
{
}

vector<TikTokData> Analise::importacao(int N)
{
    int counti = 0, ale;

    vector<TikTokData> registro;
    ifstream fin;

    fin.open("data.bin",ios::binary);

    if(!fin.is_open())
    {
        cout << "ERRO:Nao foi possivel abrir o arquivo." << endl;
    }

    while(counti < N) {
        srand(time(NULL));

        ale = rand() % 3500000;

        TikTokData registroB;

        registroB.setInfo(data.at(ale).getId(), data.at(ale).getReview(), data.at(ale).getUpVotes(), data.at(ale).getAppVersion(), data.at(ale).getPostDate());

        registro.push_back(registroB);

        counti++;
    }

    fin.close();

    return registro;
}

void Analise::insercao(vector<TikTokData> registrosimportados,RedBlackTree VP,BTree AVL) {

    clock_t start,end;

    double time = double(end - start);

    start = clock();

    for(int it = registrosimportados.begin(); it != registrosimportados.end(); it++) {

        VP.insertId(registrosimportados.at(it).getId());
    }

    for(int it = registrosimportados.begin();it != registrosimportados.end(); it++) {

        VP.insert(registrosimportados.at(it));

    }

    end = clock();

    cout << "tempo da arvore VermelhoPreto : " << time << " segundos" << endl;

    start = clock();

    for(int it = registrosimportados.begin();it != registrosimportados.end();it++) {

        AVL.insertId(registrosimportados.at(it).getId());

    }

    for(int it = registrosimportados.begin();it != registrosimportados.end();it++) {

        AVL.insert(registrosimportados.at(it).getId());

    }

    end = clock();

    cout << "tempo da arvore B : " << time << " segundos" << endl;
}

void Analise::busca(int B,RedBlackTree VP,BTree AVL,vector<TikTokData> registrosimportados) {

    int ale;

    clock_t start,end;

    double time = double(end - start);

    srand(time(NULL));

    ale = rand() % registrosimportados.size();

    start = clock();

    for(int i = 0;i < B;i++) {

        VP.callSearch(registrosimportados.at(ale).getId());

    }

    for(int i = 0;i < B;i++) {

        VP.search(registrosimportados.at(ale));

    }

    end = clock();

    cout << "tempo da arvore VermelhoPreto : " << time << " segundos" << endl;

    start = clock();

    for(int i = 0;i < B;i++) {

        AVL.searchId(registrosimportados.at(ale).getId());

    }

    for(int i = 0;i < B;i++) {

        AVL.search(registrosimportados.at(ale));

    }

    end = clock();

    cout << "tempo da arvore B : " << time << " segundos" << endl;
}
