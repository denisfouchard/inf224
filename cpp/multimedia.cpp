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
    s << getFilename()<< '\n'
      << getTitle() <<
      std::endl;
}

void Multimedia::play(){}

void Multimedia::write(std::ostream &f){
    f << filename << '\n' << title << '\n';
}

void Multimedia::read(std::istream &f){
    getline(f, filename);
    getline(f, title);
}


