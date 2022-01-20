#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <stdio.h> 
#include <stdlib.h>


#include "Analise.h"
#include "TikTokData.h"

using namespace std;

Analise::Analise()
{

}

vector<TikTokData> Analise::importacao(int N)
{
    int count = 0, ale;
    vector<TikTokData> registro;
    ifstream r;

    r.open("data.bin",ios::binary);

    if(!r.is_open())
    {
        cout << "ERRO:Nao foi possivel abrir o arquivo." << endl;
        return exit(EXIT_FAILURE);
    }


    while(count < N)
    {
        srand(time(NULL));
        ale = rand() % 3500000;
        TikTokData registroB;
        r.read((char*) &registroB,ale*sizeof(TikTokData));

        registro.push_back(registroB);

        count++;
    }
    r.close();

    return registro;
}

oid Analise::insercao(BTree B,RedBlackTree RB,vector<TikTokData> importados)
{
    clock_t start,end;
    double time = double(end - start);

    start = clock();
    for(int it = 0;it != importados.size();it++)
    {
        B.insertId(importados.at(it));
    }
    end = clock();

    cout << "tempo de B : " << time << " segundos" << endl;

    start = clock();
    for(vector<TikTokData>::iterator it = importados.begin();it != importados.end();it++)
    {
        RB.insert(importados.at(it).getId());
    }
    end = clock();

    cout << "tempo de RB : " << time << " segundos" << endl;
}


void Analise::busca(int C,BTree B,RedBlackTree RB,vector<TikTokData> importados)
{
    int ale;
    clock_t start,end;
    double t = double(end - start);

    srand(time(NULL));
    ale = rand() % importados.size();

    start = clock();
    for(int i = 0;i < C;i++)
    {
        B.search(importados.at(ale));
    }
    end = clock();

    cout << "tempo de busca B : " << t << " segundos" << endl;

    start = clock();
    for(int i = 0;i < C;i++)
    {
        RB.search(importados.at(ale));
    }
    end = clock();

    cout << "tempo de busca RB : " << t << " segundos" << endl;
}
