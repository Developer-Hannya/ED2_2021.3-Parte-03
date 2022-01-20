#ifndef moduloteste_H_INCLUDED
#define moduloteste_H_INCLUDED

#include <vector>

#include "RedBlackTree.h"
#include "BTree.h"
#include "TikTokData.h"


class Analise {
  
private:
    
public:
  
    Analise();

    vector<TikTokData> importacao(int N);
    void insercao(BTree B,RedBlackTree RB,vector<TikTokData> importados);
    void busca(int C,BTree B,RedBlackTree RB,vector<TikTokData> importados);
  
};

#endif
