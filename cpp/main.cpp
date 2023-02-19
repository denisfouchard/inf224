#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include <ostream>
#include "tcpserver.h"
#include "group.h"
#include "table.h"

//#define VERSION_TEST


const int PORT = 3331;

int main(int argc, const char* argv[])
{
    
    Table * mediaTable = new Table();
    Group *group = mediaTable->createGroup("New_group", std::cout);
    SmartPtr v = mediaTable->createVideo("StarWars", "starwars.mp4", 150);
    SmartPtr image = mediaTable->createPhoto("cat", "cat.png", 100, 100);
    group->push_back(v);
    group->push_back(image);

    #ifdef VERSION_TEST
    mediaTable->showMedia("Levitating", std::cout);
    //mediaTable->deleteMedia("Levitating", std::cout);
    mediaTable->showMedia("mec", std::cout);
    mediaTable->deleteMedia("Non", std::cout);
    group->remove(image);
    mediaTable->deleteMedia("cat", std::cout);
    // mediaTable->readAll("../mediatable");
    mediaTable->saveAll("../mediatable_test");  

    #else

    auto* server =
        new TCPServer([&mediaTable](std::string const& request, std::string& response) {
  
        // the request sent by the client to the server
        std::cout << "Request: " << request << std::endl;

        // Request parsing
        std::string command;
        std::string filename;
        std::stringstream request_stream(request);
        std::ostringstream response_stream;
        request_stream >> command >> filename;

        mediaTable->request(command, filename, response_stream);

    
        // the response that the server sends back to the client
        response = response_stream.str();
        std::replace(response.begin(), response.end(), '\n', ';');

        // return false would close the connecytion with the client
        return true;


    });


    // lance la boucle infinie du serveur
    std::cout << "Starting Server on port " << PORT << std::endl;

    int status = server->run(PORT);

    // en cas d'erreur
    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }
    
    #endif

    return 0;
}
