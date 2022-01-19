#ifndef moduloteste_H_INCLUDED
#define moduloteste_H_INCLUDED

#include <vector>

#include "RedBlackTree.h"
#include "BTree.h"
#include "TikTokData.h"


class Analise {

    public:

       Analise();

       void acessaRegistro(int i);

       void testeImportacao();

       vector<TikTokData> importacao(int N,vector<TikTokData> data);

       void insercao(vector<TikTokData> registrosimportados,RedBlackTree VP,BTree AVL);

       void busca(int B, RedBlackTree VP, BTree AVL, vector<TikTokData> registrosimportados);

};

#endif
