//
// main.cpp
//
//

#include <iostream>
#include "group.h"
#include "table.h"
#include <memory>

using namespace std;

int main(int argc, const char* argv[])
{

    Table * t = new Table();

    Group *g = t->createGroup("Mes médias");

    SmartPtr v = t->createVideo("Dua Lipa - Levitating", "levitating.mp3", 150);


    g->push_back(v);

    t->showMedia("Dua Lipa - Levitating");

    t->deleteMedia("Dua Lipa - Levitating");

    t->showMedia("mec");

    t->deleteMedia("Non");
    
    return 0;
}
