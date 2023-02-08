#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <ostream>
#include <iostream>
#include <istream>
#include <stdlib.h>

using namespace std;

class Multimedia
{
private:
    std::string title;
    std::string filename;
public:
    Multimedia();
    Multimedia(std::string title_, std::string filename_);

    virtual ~Multimedia(){};

    void setTitle(std::string title_){title = title_;};
    void setFilename(std::string filename_){filename = filename_;};

    std::string getTitle(){return title;};
    std::string getFilename(){return filename;};
    virtual std::string classname() const = 0;

    virtual void showObject(std::ostream & s);
    virtual void play();

    virtual void write(std::ostream &f);
    virtual void read(std::istream &f);
};

#endif // MULTIMEDIA_H