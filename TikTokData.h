#ifndef TIKTOKDATA_H_INCLUDED
#define TIKTOKDATA_H_INCLUDED
#include <string>
#include <vector>

class TikTokData {

    public:

        TikTokData();
        ~TikTokData();

        ///as funções Set dos dados
        void setId(char idi[]);
        void setReview(char review[]);
        void setUpVotes(int upVotes);
        void setAppVersion(std::string appVersion);
        void setPostDate(std::string postDate);
        void setInfo(char id[], char review[], int upVotes, std::string appVersion, std::string postDate);

        ///as funções Get dos dados
        char getId();
        char getReview();
        int getUpVotes();
        std::string getAppVersion();
        std::string getPostDate();
        void getData();

    private:
        ///os dados do arquivo .csv e o tipo de cada variável
        char id[86];
        char review[900];
        int upVotes;
        std::string appVersion;
        std::string postDate;
};

#endif // TIKTOKDATA_H_INCLUDED
