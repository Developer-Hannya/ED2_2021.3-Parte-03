#ifndef TIKTOKDATA_H_INCLUDED
#define TIKTOKDATA_H_INCLUDED
#include <string>
#include <vector>

class TikTokData {

    public:

        TikTokData();
        ~TikTokData();

        ///as fun��es Set dos dados
        void setId(char id);
        void setReview(std::string review);
        void setUpVotes(int upVotes);
        void setAppVersion(std::string appVersion);
        void setPostDate(std::string postDate);
        void setInfo(std::string id, std::string review, int upVotes, std::string appVersion, std::string postDate);

        ///as fun��es Get dos dados
        char getId();
        std::string getReview();
        int getUpVotes();
        std::string getAppVersion();
        std::string getPostDate();
        void getData();

    private:
        ///os dados do arquivo .csv e o tipo de cada vari�vel
        std::string id;
        std::string review;
        int upVotes;
        std::string appVersion;
        std::string postDate;
};

#endif // TIKTOKDATA_H_INCLUDED
