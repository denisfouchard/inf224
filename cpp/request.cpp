#include "table.h"
#include <map>

void Table::request(std::string command, std::string objectname, ostream &client){
    std::map<std::string, std::function<void()>> commandMap;
    commandMap.emplace("SHOWMEDIA", [this, &objectname, &client](){this->showMedia(objectname, client);});
    commandMap.emplace("SHOWGROUP", [this, &objectname, &client](){this->showGroup(objectname, client);});
    commandMap.emplace("CREATEGROUP", [this, &objectname, &client](){this->createGroup(objectname, client);});
    commandMap.emplace("DELETEGROUP", [this, &objectname, &client](){this->deleteGroup(objectname, client);});
    commandMap.emplace("DELETEMEDIA", [this, &objectname, &client](){this->deleteMedia(objectname, client);});
    commandMap.emplace("PLAY", [this, &objectname, &client](){this->play(objectname, client);});

    auto it = commandMap.find(command);
    if (it==commandMap.end()){
        client << "Error : command"<< command << " is unknown." << std::endl;
    } else {
        it->second();
    }

    #ifdef VERSION_IF
    #define
    
    if (command == "show"){
            // std::cout << "Show " << objectname << std::endl;
            this->showMedia(objectname, client);
        }
        else if (command == "play"){
            // std::cout << "Play " << objectname << std::endl;
            this->play(objectname, client);
        } else {
            client << "Error : command " << command << " is unknown." << std::endl;
        }
    #endif
}