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

    ~Video(){
        std::cout << getTitle() << " destroyed successfully." << endl;
    }

    int getDuration() {return duration;};

    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getDuration() <<
          std::endl;
    }

    void play() override {
        // OS compatibility check
        #if defined(__APPLE__) || defined(__MACH__)
        std::string cmd = "open " + getFilename() + " &";
        #elif __linux__
        std::string cmd = "mpv " + getFilename() + " &";
        #endif    
        system(cmd.data());
    }

};

#endif // VIDEO_H
