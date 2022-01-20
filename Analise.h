#ifndef moduloteste_H_INCLUDED
#define moduloteste_H_INCLUDED

#include <vector>

#include "RedBlackTree.h"
#include "BTree.h"
#include "TikTokData.h"


class Analise {
  
private:
    
public:
  
    void acessaRegistro(int i);
  
    Analise();

    vector<TikTokData> importacao(int N);
    void insercao(BTree B,RedBlackTree RB);
    void busca(int C,BTree B,RedBlackTree RB);
  
    void testeImportacao();

    vector<TikTokData> importacao(int N,vector<TikTokData> data);

    void insercao(vector<TikTokData> registrosimportados,RedBlackTree VP,BTree AVL);

    void busca(int B, RedBlackTree VP, BTree AVL, vector<TikTokData> registrosimportados);

};

#endif
