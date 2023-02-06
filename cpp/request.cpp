#include "table.h"


void Table::request(std::string command, std::string filename, ostream &client){
    if (command == "show"){
            // std::cout << "Show " << filename << std::endl;
            this->showMedia(filename, client);
        }
        else if (command == "play"){
            // std::cout << "Play " << filename << std::endl;
            this->play(filename, client);
        } else {
            client << "Error : command " << command << " is unknown." << std::endl;
        }
}