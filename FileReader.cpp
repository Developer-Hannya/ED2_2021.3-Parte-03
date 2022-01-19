#include "FileReader.h"

FileReader::FileReader(){

}

FileReader::~FileReader(){

}

std::vector<TikTokData> FileReader::readTikTok(std::string tikTokFile) {

    int i = 1;

    std::ifstream file;

    std::string info;

    std::vector<TikTokData> data;

    file.open(tikTokFile);

    std::getline(file, info);

    if(file.is_open()) {

        while(getline(file, info)) {

            if (info == "") {

                continue;

            }

            else {

                std::istringstream dataFromLine(info);

                std::string id, review, upVotes, appVersion, postDate;

                getline(dataFromLine, id, ',');

                getline(dataFromLine, review, ',');

                getline(dataFromLine, upVotes, ',');

                getline(dataFromLine, appVersion, ',');

                getline(dataFromLine, postDate, ',');

                TikTokData element;

                char ni[id.length()];

                for (int i = 0; i < sizeof(id); i++) {

                    ni[i] = id[i];

                }

                char lm[review.length()];

                for(int j = 0; j < sizeof(review); j++) {

                    lm[j] = review[j];

                }

                element.setInfo(ni, lm, atoi(upVotes.c_str()), appVersion, postDate);

                data.push_back(element);

            }

        }

        file.close();

    }

    else {

        std::cout << "Não foi possível abrir o arquivo :(." << std::endl;

    }

    return data;

}

void FileReader::writeInFile(std::vector<TikTokData> &data) {

    std::ofstream file("saída.txt", std::ios::out| std::ios::binary);

    for(int i = 0; i < data.size(); i++) {

        file << data[i].getId() << ", " << data[i].getReview() << ", " << data[i].getUpVotes() << ", " <<

        data[i].getAppVersion() << ", " << data[i].getPostDate() << std::endl;

    }

    file.close();

}
