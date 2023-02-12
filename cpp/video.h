#ifndef VIDEO_H
#define VIDEO_H

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

    std::string classname() const override {return "video";}

    void showObject(std::ostream & s) override {
        s << getFilename()<< '\n'
          << getTitle() << '\n'
          << getDuration() << '\n' <<
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

    virtual void write(std::ostream &f) override {
        Multimedia::write(f);
        f << duration<< '\n';
    }

    virtual void read(std::istream &f) override {
        Multimedia::read(f);
        std::string d;
        getline(f, d);
        duration = stoi(d);

    }

};

#endif // VIDEO_H
