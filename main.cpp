//
// main.cpp
//
//

#include <iostream>
#include "multimedia.h"
#include "video.h"
#include "photo.h"
using namespace std;

int main(int argc, const char* argv[])
{
    Multimedia * m = new Multimedia("Dua Lipa - Levitating", "levitating.mp3");

    Video* v = new Video("Dua Lipa - Levitating", "levitating.mp3", 100);

    Photo* p = new Photo("Dua Lipa portrait", "/cal/exterieurs/dfouchard-21/Desktop/dualipa.png", 1000, 1000);

    Multimedia* mlist [3]  = {m, v, p};

    for (Multimedia* mult:mlist){
        mult->showObject(std::cout);
    };

    return 0;
}
