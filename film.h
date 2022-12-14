#ifndef FILM_H
#define FILM_H

#include <stdlib.h>
#include "video.h"

class Film : public Video
{
private:
    unsigned int duration;
    unsigned int * chapters;

public:
    Film():Video(){
        chapters  = nullptr;
    }

    Film(std::string title_, std::string filename_, unsigned int duration_, unsigned int * chapters_):Video(title_,filename_, duration_){
        chapters = chapters_;
    }

    ~Film(){};

    int getDuration(){return duration;};

    void setChapeters(unsigned int * chapters_){
        delete chapters;
        int i = 0;
        while (chapters_)
    }

    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getDuration() <<
          std::endl;
    }

    void play() override {
        std::string cmd = "mpv " + getFilename() + " &";
        system(cmd.data());
    }



};

#endif // FILM_H
