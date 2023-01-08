//
// main.cpp
//
//

#include <iostream>
#include "multimedia.h"
#include "video.h"
#include "photo.h"
#include "film.h"
#include "group.h"
#include "table.h"
#include <memory>

using namespace std;

int main(int argc, const char* argv[])
{

    Multimedia * m = new Multimedia("Dua Lipa - Levitating", "levitating.mp3");

    Video* v = new Video("Dua Lipa - Levitating", "levitating.mp3", 100);

    Photo* p = new Photo("Dua Lipa portrait", "/cal/exterieurs/dfouchard-21/Desktop/dualipa.png", 1000, 1000);

    Group *g = new Group("Mes médias");

    SmartPtr media(v);

    Table * t = new Table();

    t->createVideo("Dua Lipa - Levitating", "levitating.mp3", 150);

    t->showMedia("Dua Lipa - Levitating");

    t->deleteMedia("Dua Lipa - Levitating");

    t->showMedia("mec");

    t->deleteMedia("Non");
    
    return 0;
}
