#include <string>
#include <iostream>
#include "TikTokData.h"

TikTokData::TikTokData() {

    for (int i = 0; i < 86; i++) {

        this->id[i] = ' ';

    }

    for (int i = 0; i < 900; i++) {

        this->review[i] = ' ';

    }

    this->upVotes = 0;

    this->appVersion = "";

    this->postDate = "";

}

TikTokData::~TikTokData() {

}

void TikTokData::setId(char idi[]) {

    for(int i = 0; i < 86; i++) {

        this->id[i] = idi[i];

    }

}

void TikTokData::setReview(char reviewX[]) {

    for (int i = 0; i < 900; i++) {

        this->review[i] = reviewX[i];

    }
}

void TikTokData::setUpVotes(int upVotes) {

    this->upVotes = upVotes;

}

void TikTokData::setAppVersion(std::string appVersion) {

    this->appVersion = appVersion;

}

void TikTokData::setPostDate(std::string postDate) {

    this->postDate = postDate;

}

void TikTokData::setInfo(char id[], char review[], int upVotes, std::string appVersion, std::string postDate) {

    setId(id);

    setReview(review);

    setUpVotes(upVotes);

    setAppVersion(appVersion);

    setPostDate(postDate);

}


char TikTokData::getId() {

    return this->id;

}

char TikTokData::getReview() {

    return this->review;

}

int TikTokData::getUpVotes() {

    return this->upVotes;

}

std::string TikTokData::getAppVersion() {

    return this->appVersion;

}

std::string TikTokData::getPostDate() {

    return this->postDate;

}

void TikTokData::getData() {
    std::cout<< getId();

    std::cout<< getReview();

    std::cout<< getUpVotes();

    std::cout<< getAppVersion();

    std::cout<< getPostDate();

    std::cout<< std::endl;

}
