#pragma once
#include <iostream>
#include <fstream>

enum class Type {
    Warning,
    Error,
    FatalError,
    Unknown
};

class LogMessage{
public:
    Type type()const;
    const std::string &message() const;
    LogMessage(Type type, const std::string& message);
private:
    std::string _str;
    Type _type;
};

class LogHandler{
public:
    void setNext(LogHandler* handler);
    virtual void handleMessage(const LogMessage& message)= 0;
    LogHandler()= default;
    virtual ~LogHandler() = default;
protected:
    LogHandler* nextHandler= nullptr;
};

class Warning: public LogHandler{
public:
    void handleMessage(const LogMessage& message) override;
};

class Error: public LogHandler{
public:
    void handleMessage(const LogMessage& message) override;
    Error(const std::string& filePath);
    ~Error();
private:
    std::ofstream outfs;
};

class FatalError: public LogHandler{
public:
    void handleMessage(const LogMessage& message) override;
};

class Unknown: public LogHandler{
public:
    void handleMessage(const LogMessage& message) override;
};
