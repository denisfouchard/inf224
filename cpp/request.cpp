#include "table.h"
#include <map>

void Table::request(std::string command, std::string objectname, ostream &client){

    auto it = commandMap.find(command);
    if (it==commandMap.end()){
        client << "Error : command"<< command << " is unknown." << std::endl;
    } else {
        it->second(objectname, client);
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