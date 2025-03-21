#pragma once
#include <iostream>
/*
*/
class LogCommand{
public:
    virtual void print(const std::string& message) = 0;
    virtual ~LogCommand() = default;
};

class LogCommandConsole: public LogCommand{
public:
    void print(const std::string& message) override;
    ~LogCommandConsole()= default;
    LogCommandConsole()= default;
};

class LogCommandFile: public LogCommand{
public:
    void setTheFilePath(const std::string& path);
    void print(const std::string& message) override;
    ~LogCommandFile()= default;
    LogCommandFile()= default;
private:
    std::string _pathway{"log.txt"};
};
