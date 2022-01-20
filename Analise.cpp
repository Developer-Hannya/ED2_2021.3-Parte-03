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
    for(int it = 0;it != registrosimportados.size();it++)
    {
        B.insertId(registrosimportados.at(it));
    }
    end = clock();

    cout << "tempo de B : " << time << " segundos" << endl;

    start = clock();
    for(vector<TikTokData>::iterator it = registrosimportados.begin();it != registrosimportados.end();it++)
    {
        RB.insert(registrosimportados.at(it).getId());
    }
    end = clock();

    cout << "tempo de RB : " << time << " segundos" << endl;
}


void Analise::busca(int C,BTree B,RedBlackTree RB)
{
    int ale;
    clock_t start,end;
    double t = double(end - start);

    srand(time(NULL));
    ale = rand() % registrosimportados.size();

    start = clock();
    for(int i = 0;i < C;i++)
    {
        B.search(registrosimportados.at(ale));
    }
    end = clock();

    cout << "tempo de busca B : " << t << " segundos" << endl;

    start = clock();
    for(int i = 0;i < C;i++)
    {
        RB.search(registrosimportados.at(ale));
    }
    end = clock();

    cout << "tempo de busca RB : " << t << " segundos" << endl;
}
