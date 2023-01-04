#ifndef GROUP_H
#define GROUP_H

#endif // GROUP_H

#include <list>
#include "multimedia.h"

class Group : public std::list<Multimedia*>{
 private:
    std::string name;

 public:
    Group() : std::list<Multimedia*>(){
       name = "unnamed_group";
    }

    Group(std::string groupname_) : std::list<Multimedia*>(){
        name = groupname_;
    }

    ~Group(){};


    std::string getGroupName(){return name;};

    void showGroup(std::ostream & s){
        for (Multimedia *m : *this){
            m->showObject(s);
        }

    }
}
;
