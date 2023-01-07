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
#include <memory>

using namespace std;

int main(int argc, const char* argv[])
{

    Multimedia * m = new Multimedia("Dua Lipa - Levitating", "levitating.mp3");

    Video* v = new Video("Dua Lipa - Levitating", "levitating.mp3", 100);

    Photo* p = new Photo("Dua Lipa portrait", "/cal/exterieurs/dfouchard-21/Desktop/dualipa.png", 1000, 1000);

    Group *g = new Group("Mes médias");

    SmartPtr media(v);

    g->push_back(media);

    g->showGroup(std::cout);

    g->remove(media);

    return 0;
}
