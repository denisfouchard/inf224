#include "table.h"
#include <map>

void Table::request(std::string command, std::string objectname, ostream &client){

    auto it = commandMap.find(command);
    if (it==commandMap.end()){
        client << "Error : command "<< command << " is unknown." << std::endl;
    } else {
        it->second(objectname, client);
    }

}