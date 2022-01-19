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
    void insercao(vector<TikTokData> registrosimportados,RedBlackTree VP,BTree AVL);
    void busca(int B,RedBlackTree VP,BTree AVL,vector<TikTokData> registrosimportados);
};

#endif
