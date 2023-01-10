#include "table.h"

Table::Table(){
    name = "newtable";
    std::map<std::string, SmartPtr> mediaMap;
    std::map<std::string, Group*> groupMap;
}

Table::Table(std::string name_){
    name = name_;
    std::map<std::string, SmartPtr*> mediaMap;
    std::map<std::string, Group*> groupMap;
}

SmartPtr Table::createPhoto(
    std::string title_, 
    std::string filename_, 
    unsigned int height_, 
    unsigned int width_)
{
    Photo* p = new Photo(title_, filename_, height_, width_);
    SmartPtr photo(p);
    mediaMap[title_] = photo;
    return photo;
}

SmartPtr Table::createVideo(std::string title_, std::string filename_, unsigned int duration_){
    Video* v = new Video(title_, filename_, duration_);
    SmartPtr video(v);
    mediaMap[title_] = video;
    return video;
}

SmartPtr Table::createFilm(std::string title_,
                        std::string filename_,
                        unsigned int duration_,
                        unsigned int * chapters_,
                        unsigned int chaptersCount_){
    Film* f = new Film(title_, filename_, duration_, chapters_, chaptersCount_);
    SmartPtr film(f);
    return film;
}

Group* Table::createGroup(std::string groupname_){
    Group * g = new Group(groupname_);
    groupMap[groupname_] = g;
    return g;
}

void Table::showMedia(std::string title_){
    auto it = mediaMap.find(title_);
    if (it==mediaMap.end()){
        std::cout << "Error : "<< title_ << " not found." << endl;
    } else {
        it->second->showObject(std::cout);
    }

}

void Table::showGroup(std::string groupname_){
    auto it = groupMap.find(groupname_);
    if (it==groupMap.end()){
        std::cout << "Error : "<< groupname_ << " not found." << endl;
    } else {
        it->second->showGroup(std::cout);
    }
}

void Table::deleteMedia(std::string title_){
    auto it = mediaMap.find(title_);
    if (it==mediaMap.end()){
        std::cout << "Error : "<< title_ << " not found." << endl;
    } else {
        mediaMap.erase(title_);
        std::map<std::string, Group*>::iterator groupIt;
        for (groupIt = groupMap.begin(); groupIt != groupMap.end(); groupIt++)
        {
            Group * g = groupIt->second;
            g->remove(it->second);
        }
        std::cout << title_ << " deleted successfully." << endl;
    }
}

void Table::deleteGroup(std::string groupname_){
    auto it = groupMap.find(groupname_);
    if (it==groupMap.end()){
        std::cout << "Error : "<< groupname_ << " not found." << endl;
    } else {
        groupMap.erase(groupname_);
        std::cout << groupname_ << " deleted successfully." << endl;
    }
}

void Table::play(std::string title_){
    try {
        SmartPtr m = mediaMap[title_];
        m->play();
    }
    catch (invalid_argument& e){
        std::cout << "Error : file not found." << endl;
    }
}