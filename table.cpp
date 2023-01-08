#include "multimedia.h"
#include "table.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"


Table::Table(){
    name = "newtable";
    std::map<std::string, Multimedia*> mediaMap;
    std::map<std::string, Group*> groupMap;
}

Table::Table(std::string name_){
    name = name_;
    std::map<std::string, Multimedia*> mediaMap;
    std::map<std::string, Group*> groupMap;
}

Photo* Table::createPhoto(
    std::string title_, 
    std::string filename_, 
    unsigned int height_, 
    unsigned int width_)
    {
    Photo* p = new Photo(title_, filename_, height_, width_);
    mediaMap[title_] = p;
    return p;
}

Video* Table::createVideo(std::string title_, std::string filename_, unsigned int duration_){
    Video* v = new Video(title_, filename_, duration_);
    mediaMap[title_] = v;
    return v;
}

Film* Table::createFilm(std::string title_,
                        std::string filename_,
                        unsigned int duration_,
                        unsigned int * chapters_,
                        unsigned int chaptersCount_){
    Film* f = new Film(title_, filename_, duration_, chapters_, chaptersCount_);
    return f;
}

Group* Table::createGroup(std::string groupname_){
    Group * g = new Group(groupname_);
    groupMap[groupname_] = g;
    return g;
}

void Table::showMedia(std::string title_){
    try {
        Multimedia * m = mediaMap[title_];
        m->showObject(std::cout);
    }
    catch (invalid_argument& e){
        std::cout << "Error : file not found." << endl;
    }
}

void Table::showGroup(std::string groupname_){
    try {
        Group* g = groupMap[groupname_];
        g->showGroup(std::cout);
    }
    catch (invalid_argument& e){
        std::cout << "Error : group not found." << endl;
    }
}

void Table::deleteMedia(std::string title_){
    try {
        mediaMap.erase(title_);
        std::cout << title_ << " deleted sucessfully." << endl;
    }
    catch (invalid_argument& e){
        std::cout << "Error : file not found." << endl;
    }
}

void Table::deleteGroup(std::string groupname_){
    try {
        groupMap.erase(groupname_);
        std::cout << groupname_ << " deleted sucessfully." << endl;
    }
    catch (invalid_argument& e){
        std::cout << "Error : group not found." << endl;
    }
}

void Table::play(std::string title_){
    try {
        Multimedia * m = mediaMap[title_];
        m->play();
    }
    catch (invalid_argument& e){
        std::cout << "Error : file not found." << endl;
    }
}

// TODO: refaire avec des itérateurs et des find