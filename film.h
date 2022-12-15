#ifndef FILM_H
#define FILM_H

#include <stdlib.h>
#include "video.h"

class Film : public Video
{
private:
    unsigned int * chapters;
    unsigned int n_chapters;

public:
    Film():Video(){
        chapters  = nullptr;
        n_chapters = 0;
    }

    Film(std::string title_, std::string filename_, unsigned int duration_, unsigned int * chapters_, unsigned int n_chapters_ ):Video(title_,filename_, duration_){
        setChapters(chapters_, n_chapters_);
        n_chapters = n_chapters_;
    }

    ~Film(){}

    void setChapters(unsigned int * chapters_, unsigned int n_chapters_){
        delete chapters;
        n_chapters = n_chapters_;
        unsigned int chapters [n_chapters_];
        std::copy(chapters_, chapters_+n_chapters_, chapters);
        delete chapters_;

    }

    unsigned int* getChapters(){
        unsigned int chapters_ [n_chapters];
        std::copy(chapters, chapters + n_chapters, chapters_);
        return chapters_;
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
