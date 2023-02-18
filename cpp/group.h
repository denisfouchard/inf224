#ifndef GROUP_H
#define GROUP_H



#include <list>
#include <memory>
#include "multimedia.h"

// On crée une définition de type pour éviter d'écrire std::shared_ptr<Multimedia> à chaque fois
using SmartPtr = std::shared_ptr<Multimedia>;

class Group : public std::list<SmartPtr>{
 private:
    std::string name;

 public:
    Group() : std::list<SmartPtr>(){
       name = "unnamed_group";
    }

    Group(std::string groupname_) : std::list<SmartPtr>(){
        name = groupname_;
    }
    ~Group(){};

    std::string getGroupName(){return name;};

    void showGroup(std::ostream & s){
        for (std::list<SmartPtr>::iterator m = this->begin(); m != this->end(); m++){
            m->get()->showObject(s);
        }
    }

    void listGroup(std::ostream & s){
        for (std::list<SmartPtr>::iterator m = this->begin(); m != this->end(); m++){
            s << m->get()->getTitle() << std::endl;
        }
    }
}
;
#endif // GROUP_H