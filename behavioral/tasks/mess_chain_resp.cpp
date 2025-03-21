#include "mess_chain_resp.h"

Type LogMessage::type() const{
    return _type;
}

const std::string &LogMessage::message() const{
    return _str;
}

LogMessage::LogMessage(Type type, const std::string &message)
    :_type(type),_str(message){
}

void LogHandler::setNext(LogHandler *handler){
    nextHandler = handler;
}

void Warning::handleMessage(const LogMessage &message){
    if (message.type() == Type::Warning)
        std::cout << "Warning: " << message.message();
    else
        nextHandler->handleMessage(message);
}

void Error::handleMessage(const LogMessage &message){
    if (message.type() == Type::Error)
        outfs << "Error: " << message.message();
    else
        nextHandler->handleMessage(message);
}

Error::Error(const std::string &filePath){
    outfs.open(filePath, std::ios::ate | std::ios::app);
}

Error::~Error(){
    outfs.close();
}

void FatalError::handleMessage(const LogMessage &message){
    if (message.type() == Type::FatalError)
        throw std::runtime_error(message.message());
    else
        nextHandler->handleMessage(message);
}

void Unknown::handleMessage(const LogMessage &message){
    if (message.type() == Type::Unknown)
        throw std::runtime_error(message.message());
    else
        nextHandler->handleMessage(message);
}
