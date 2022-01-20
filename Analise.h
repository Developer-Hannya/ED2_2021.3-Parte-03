#ifndef Analise_H_INCLUDED
#define Analise_H_INCLUDED

#include <iostream>
#include <vector>

#include "TikTokData.h"
#include "BTree.h"
#include "RedBlackTree.h"

class Analise
{
private:
    
public:
    Analise();

    vector<TikTokData> importacao(int N);
    void insercao(BTree B,RedBlackTree RB);
    void busca(int C,BTree B,RedBlackTree RB);
};

#endif
