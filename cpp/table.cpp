#include "table.h"



Table::Table(std::string name_){
    name = name_;
    // Command mapping
    commandMap.emplace("SHOWMEDIA", [this](std::string objectname, ostream &client){this->showMedia(objectname, client);});
    commandMap.emplace("SHOWGROUP", [this](std::string objectname, ostream &client){this->showGroup(objectname, client);});
    commandMap.emplace("CREATEGROUP", [this](std::string objectname, ostream &client){this->createGroup(objectname, client);});
    commandMap.emplace("DELETEGROUP", [this](std::string objectname, ostream &client){this->deleteGroup(objectname, client);});
    commandMap.emplace("DELETEMEDIA", [this](std::string objectname, ostream &client){this->deleteMedia(objectname, client);});
    commandMap.emplace("PLAY", [this](std::string objectname, ostream &client){this->play(objectname, client);});
}

Table::Table():Table("newtable"){
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

bool Table::saveAll(const std::string &filename){
    std::ofstream f;
    f.open(filename);
    if (!f) {
        cerr << "Can't open file " << filename << endl; return false;
    }
    for (auto it = mediaMap.begin(); it != mediaMap.end(); it++) {
        f << it->second->classname() << '\n'; 
        it->second->write(f);

    if (f.fail()) {
        cerr << "Write error in " << filename << endl;
        return false; }
    }
    return true;
}