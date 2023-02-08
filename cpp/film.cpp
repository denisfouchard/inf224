#include "film.h"


Film::Film():Video(){
    chapters  = nullptr;
    chaptersCount = 0;
};

Film::Film(std::string title_,
        std::string filename_,
        unsigned int duration_,
        unsigned int * chapters_,
        unsigned int chaptersCount_):Video(title_,filename_, duration_){
    chapters = chapters_;
    chaptersCount = chaptersCount_;
};

void Film::setChapters(unsigned int * chapters_, unsigned int chaptersCount_){
    // Deepcopy
    chaptersCount = chaptersCount_;
    chapters = new unsigned int [chaptersCount_] ();
    for (unsigned int i = 0; i < chaptersCount_; i++){
        chapters[i] = chapters_[i];
    }
    delete chapters_;
};

std::string Film::printChapters(){
    std::string s = "";
    for (unsigned int i = 0; i < chaptersCount; i++){
        s += "Chapter " + std::to_string(i) + " : " + std::to_string(chapters[i]) + '\n';
    }
    return s;
};

void Film::writeChapters(std::ostream &f){
    for (unsigned int i = 0; i < chaptersCount; i++){
        f << chapters[i] << '\n';
    }
}

void::Film::readChapters(std::istream &f){
    int chapters[chaptersCount];
    std::string l;
    for (unsigned int i = 0; i < chaptersCount; i++){
        getline(f, l);
        chapters[i] = stoi(l);
    }
}

void Film::showObject(std::ostream &s){
    s << getFilename()<< '\n'
        << getTitle() << '\n'
        << getDuration() << '\n'
        << printChapters() <<
        std::endl;
};

void Film::write(std::ostream &f){
    Video::write(f);
    f << chaptersCount << '\n';
    writeChapters(f);
    
};

void Film::read(std::istream &f){
    Video::read(f);
    std::string cc, c;
    getline(f, cc);
    chaptersCount = stoi(cc);
    readChapters(f);
};
