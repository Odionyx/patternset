#include "log_command.h"
#include <fstream>
/*
*/
void LogCommandConsole::print(const std::string &message) {
    std::cout<< "Log: "<< message<< std::endl;
}

void LogCommandFile::setTheFilePath(const std::string &path){
    this->_pathway= path;
}

void LogCommandFile::print(const std::string &message) {
    std::ofstream out;
    out.open( this->_pathway, std::ios::ate | std::ios::app);
    out<< message<< std::endl;
    out.close();
}
