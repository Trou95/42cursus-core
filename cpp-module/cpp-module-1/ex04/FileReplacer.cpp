#include "FileReplacer.h"

FileReplacer::FileReplacer(std::string filepath) {
    size_t index = 0;
    if(size_t i = _filePath.find_last_of('/') != _filePath.npos)
        index = i;
    _fileName = filepath.substr(index,filepath.find('.',index) - index) + ".replace";
    _filePath = filepath;
}

void FileReplacer::replace(const char *s1, const char *s2) {
    std::string str;
    std::fstream file;
    file.exceptions(std::ios::badbit | std::ios::failbit);
    unsigned short int err;

    if((err = open(file)))
        exit(err);
    if((err = read(file,str)))
        exit(err);

    strreplace(str,s1,s2);
    if((err = create(file,str)))
        exit(err);

    std::cout << str << std::endl;
}

unsigned short int FileReplacer::open(std::fstream &file) {
    try{
        file.open(_filePath.c_str());
    }
    catch(std::ios_base::failure& e) {
     std::cout << strerror(errno) << std::endl;
     return errno;
    }
    return 0;
}

unsigned short FileReplacer::read(std::fstream &file, std::string& buffer) {
    try{
        file >> buffer;
    }
    catch(std::ios_base::failure& e){
        std::cout << strerror(errno) << std::endl;
        return errno;
    }
    return 0;
}

unsigned short FileReplacer::create(std::fstream &file, const std::string& buffer) {
    std::string _path;
    size_t index = _filePath.find_last_of('/');
    if(index == _filePath.npos)
        index = 0;
    _path = _filePath.substr(0,index) + _fileName;
    try{
        std::ofstream tmp(_path.c_str());
        tmp << buffer;
        tmp.close();
    }
    catch(std::ios_base::failure& e){
        std::cout << strerror(errno) << std::endl;
        return errno;
    }
    return 0;
}