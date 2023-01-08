#ifndef VIDEO_H
#define VIDEO_H

#include <stdlib.h>
#include <iostream>
#include "multimedia.h"

class Video : public Multimedia
{
private:
    unsigned int duration;

public:
    Video():Multimedia(){
        duration = 0;
    }

    Video(std::string title_, std::string filename_, unsigned int duration_):Multimedia(title_,filename_){
        duration = duration_;
    }

    ~Video(){std::cout << "Object destroyed successfully.";};

    int getDuration() {return duration;};

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



#endif // VIDEO_H
