#ifndef FILM_H
#define FILM_H

#include <stdlib.h>
#include <iostream>
#include "video.h"

using namespace std;

class Film : public Video
{
private:
    unsigned int * chapters;
    unsigned int chaptersCount;

public:
    Film():Video(){
        chapters  = nullptr;
        chaptersCount = 0;
    }

    Film(std::string title_,
         std::string filename_,
         unsigned int duration_,
         unsigned int * chapters_,
         unsigned int chaptersCount_):Video(title_,filename_, duration_){
        chapters = chapters_;
        chaptersCount = chaptersCount_;
    }

    ~Film(){
        delete chapters;
        std::cout << "Object destroyed successfully.";
    };

    const unsigned int * getChapters() const {return chapters;}

    void setChapters(unsigned int * chapters_, unsigned int chaptersCount_){
        // Deepcopy
        chaptersCount = chaptersCount_;
        chapters = new unsigned int [chaptersCount_] ();
        for (unsigned int i = 0; i < chaptersCount_; i++){
            chapters[i] = chapters_[i];
        }
        delete chapters_;

    }

    unsigned int getChaptersCount(){
        return chaptersCount;
    }

    std::string printChapters(){
        std::string s = "";
        for (unsigned int i = 0; i < chaptersCount; i++){
            s += "Chapter " + std::to_string(i) + " : " + std::to_string(chapters[i]) + '\n';
        }
       return s;
    }


    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getDuration() << '\n'
          << printChapters() <<
          std::endl;
    }




};

#endif // FILM_H
