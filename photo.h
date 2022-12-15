#ifndef PHOTO_H
#define PHOTO_H

#include <stdlib.h>
#include "multimedia.h"

class Photo : public Multimedia
{

private:
    unsigned int height;
    unsigned int width;

public:
    Photo():Multimedia(){
        height = 0;
        width = 0;
    }

    Photo(std::string title_, std::string filename_, unsigned int height_, unsigned int width_):Multimedia(title_,filename_){
        height = height_;
        width = width_;
    }

    ~Photo(){};

    int getHeight(){return height;}
    int getWidth(){return width;}

    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getHeight() << 'x' << getWidth() <<
          std::endl;
    }

    void play() override {
        std::string cmd = "imagej " + getFilename() + " &";
        system(cmd.data());
    }


};

#endif // PHOTO_H