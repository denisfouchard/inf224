#ifndef PHOTO_H
#define PHOTO_H

#include <stdlib.h>
#include <iostream>
#include "multimedia.h"


class Photo : public Multimedia
{
private:
    unsigned int height{};
    unsigned int width{};

public:
    Photo():Multimedia(){
        height = 0;
        width = 0;
    }

    Photo(std::string title_, std::string filename_, unsigned int height_, unsigned int width_):Multimedia(title_,filename_){
        height = height_;
        width = width_;
    }

    ~Photo(){
        std::cout << getTitle() << " destroyed successfully." << endl;
    }

    int getHeight(){return height;}
    int getWidth(){return width;}

    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getHeight() << 'x' << getWidth() <<
          std::endl;
    }

    void play() override {
        // OS compatibility check
        #if defined(__APPLE__) || defined(__MACH__)
        std::string cmd = "open -a Preview " + getFilename() + " &";
        #elif __linux__
        std::string cmd = "imagej " + getFilename() + " &";
        #endif
        system(cmd.data());
    }

};


#endif // PHOTO_H
