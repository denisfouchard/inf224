#ifndef TABLE_H
#define TABLE_H

#include <string>
#include <sstream>
#include <map>
#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"



class Table {
    private:
        std::string name;
        std::map<std::string, SmartPtr> mediaMap;
        std::map<std::string, Group*> groupMap;
    
    public:
        Table();
        Table(std::string name_);

        virtual SmartPtr createPhoto(std::string title_, std::string filename_, unsigned int height_, unsigned int width_);
        virtual SmartPtr createVideo(std::string title_, std::string filename_, unsigned int duration_);
        virtual SmartPtr createFilm(std::string title_,
         std::string filename_,
         unsigned int duration_,
         unsigned int * chapters_,
         unsigned int chaptersCount_);

        virtual Group* createGroup(std::string groupname_, ostream &client);

        virtual void showMedia(std::string title_, ostream &client) const;
        virtual void showGroup(std::string groupname_, ostream &client) const;

        virtual void deleteMedia(std::string title_, ostream &client);
        virtual void deleteGroup(std::string groupname_, ostream &client);

        virtual void play(std::string title_, ostream &client);
        virtual void request(std::string command, std::string filename, ostream &client);

        ~Table(){};

};


#endif //TABLE_H