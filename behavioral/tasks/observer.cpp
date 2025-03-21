#include "observer.h"
#include "log_command.h"
/*
*/
void Greeting::addObserver( Observer *observer){
    this->_observers.push_back(observer);
}

void Greeting::removeObserver( Observer *observer){
    auto it = std::remove(_observers.begin(), _observers.end(), observer);
    _observers.erase(it, _observers.end());
}

void Greeting::warning(const std::string &message) const{
    for (auto& observer: this->_observers)
        observer->onWarning(message);
}

void Greeting::error(const std::string &message) const{
    for (auto& observer: this->_observers)
        observer->onError(message);
}

void Greeting::fatalError(const std::string &message) const{
    for (auto& observer: this->_observers)
        observer->onFatalError(message);
}

void ObserverOnWarning::onWarning(const std::string &message){
    LogCommandConsole logCon;
    logCon.print(message);
}

void ObserverOnError::setTheFilePath(const std::string &path){
    this->_pathway= path;
}

void ObserverOnError::onError(const std::string &message){
    LogCommandFile logFile;
    logFile.setTheFilePath(this->_pathway);
    logFile.print(message);
}

void ObserverOnFatalError::setTheFilePath(const std::string &path){
    this->_pathway= path;
}

void ObserverOnFatalError::onFatalError(const std::string &message){
    LogCommandConsole logCon;
    LogCommandFile logFile;
    logFile.setTheFilePath(this->_pathway);
    logCon.print(message);
    logFile.print(message);
}
