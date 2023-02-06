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

Group* Table::createGroup(std::string groupname_, ostream &client){
    Group * g = new Group(groupname_);
    groupMap[groupname_] = g;
    client << "Group : " << groupname_ << "created successfully." << endl;
    return g;
}

void Table::showMedia(std::string title_, ostream &client) const {
    auto it = mediaMap.find(title_);
    if (it==mediaMap.end()){
        client << "Error : "<< title_ << " not found." << endl;
    } else {
        it->second->showObject(client);
    }
}

void Table::showGroup(std::string groupname_, ostream &client) const {
    auto it = groupMap.find(groupname_);
    if (it==groupMap.end()){
        client << "Error : "<< groupname_ << " not found." << endl;
    } else {
        it->second->showGroup(client);
    }
}

void Table::deleteMedia(std::string title_, ostream &client){
    auto it = mediaMap.find(title_);
    if (it==mediaMap.end()){
        client << "Error : "<< title_ << " not found." << endl;
    } else {
        mediaMap.erase(title_);
        std::map<std::string, Group*>::iterator groupIt;
        for (groupIt = groupMap.begin(); groupIt != groupMap.end(); groupIt++)
        {
            Group * g = groupIt->second;
            g->remove(it->second);
        }
        client << title_ << " deleted successfully." << endl;
    }
}

void Table::deleteGroup(std::string groupname_, ostream &client){
    auto it = groupMap.find(groupname_);
    if (it==groupMap.end()){
        client << "Error : "<< groupname_ << " not found." << endl;
    } else {
        groupMap.erase(groupname_);
        client << groupname_ << " deleted successfully." << endl;
    }
}

void Table::play(std::string title_, ostream &client){
    auto it = mediaMap.find(title_);
    if (it==mediaMap.end()){
        client << "Error : "<< title_ << " not found." << endl;
    } else {
        it->second->play();
    }
}