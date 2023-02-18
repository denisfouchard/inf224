#ifndef FILM_H
#define FILM_H

#include "video.h"

using namespace std;

class Film : public Video
{
private:
    unsigned int * chapters;
    unsigned int chaptersCount;

public:
    Film();

    Film(std::string title_,
         std::string filename_,
         unsigned int duration_,
         unsigned int * chapters_,
         unsigned int chaptersCount_);

    ~Film(){
        delete chapters;
        std::cout << getTitle() << " destroyed successfully." << endl;
    }

    const unsigned int * getChapters() const {return chapters;}

    std::string classname() const override {return "film";}

    void setChapters(unsigned int * chapters_, unsigned int chaptersCount_);

    unsigned int getChaptersCount(){return chaptersCount;}

    std::string printChapters();
    void writeChapters(std::ostream &f);
    void readChapters(std::istream &f);

    void showObject(std::ostream &s) override;

    virtual void write(std::ostream &f) override;
    virtual void read(std::istream &f) override;

};

#endif // FILM_H
