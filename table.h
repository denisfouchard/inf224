#ifndef TABLE_H
#define TABLE_H

#include <string>
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

        virtual Group* createGroup(std::string groupname_);

        virtual void showMedia(std::string title_);
        virtual void showGroup(std::string groupname_);

        virtual void deleteMedia(std::string title_);
        virtual void deleteGroup(std::string groupname_);

        virtual void play(std::string title_);

        ~Table(){};

};


#endif //TABLE_H