#ifndef MODULOTESTE_H_INCLUDED
#define MODULOTESTE_H_INCLUDED

#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

#include "TikTokData.h"

class moduloteste
{
    public:

       moduloteste();

       ~moduloteste();


       void acessaRegistro(int i, std::vector<TikTokData> dados);

       void testeImportacao(std::vector<TikTokData> dados);

       void randomImport(std::vector<TikTokData> dados, std::vector<TikTokData> vectorRandom, int n);

};

#endif // MODULOTESTE_H_INCLUDED
