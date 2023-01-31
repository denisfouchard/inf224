#include "multimedia.h"
#include <iostream>


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
