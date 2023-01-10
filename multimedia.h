#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <ostream>

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

    virtual void showObject(std::ostream & s);
    virtual void play();


};

#endif // MULTIMEDIA_H
