#ifndef Analise_H_INCLUDED
#define Analise_H_INCLUDED

#include <iostream>
#include <vector>

#include "TikTokData.h"
#include "RedBlackTree.h"
#include "BTree.h"

class Analise
{
private:

public:
    Analise();

    std::vector<TikTokData> importacao(int N);

    void insercao(std::vector<TikTokData> registrosimportados, RedBlackTree VP,BTree AVL);

    void busca(int B,RedBlackTree VP, BTree AVL, std::vector<TikTokData> registrosimportados);
};

#endif
