#ifndef FILEREADER_H_INCLUDED
#define FILEREADER_H_INCLUDED

#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include <iomanip>

#include "TikTokData.h"

class FileReader {

    public:

        FileReader(); // construtor

        ~FileReader(); // destrutor

        /// fun��o que l� o arquivo .csv e passa as informa��es para um vector
        std::vector<TikTokData> readTikTok(std::string tikTokFile);

        ///cria o arquivo .bin e pega as informa��es do vector e escreve no arquivo .bin
        void writeInFile(std::vector<TikTokData> &data);

    private:

};

#endif // FILEREADER_H_INCLUDED
