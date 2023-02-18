#include "multimedia.h"


Multimedia::Multimedia()
{
    title = "";
    filename = "";
}

Multimedia::Multimedia(std::string title_, std::string filename_)
{
    title = title_;
    filename = filename_;
}

void Multimedia::showObject(std::ostream & s)
{
    s << classname() << '\n' <<
        getTitle() << '\n' <<
        getFilename() << '\n' << std::endl;
}

void Multimedia::play(){}

void Multimedia::write(std::ostream &f){
    f << filename << '\n' << title << '\n';
}

void Multimedia::read(std::istream &f){
    getline(f, filename);
    getline(f, title);
}


