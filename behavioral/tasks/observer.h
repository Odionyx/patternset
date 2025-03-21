#pragma once
#include <algorithm>
#include <iostream>
#include <vector>
#include <memory>
/*
*/
class Observer{
public:
    virtual void onWarning( const std::string& message)= 0;
    virtual void onError(   const std::string& message)= 0;
    virtual void onFatalError(const std::string& message)= 0;
    virtual ~Observer()= default;
};

class Greeting{
public:
    void addObserver( Observer *observer);
    void removeObserver( Observer* observer);
    void warning(   const std::string& message) const;
    void error(     const std::string& message) const;
    void fatalError(const std::string& message) const;
    ~Greeting()= default;
    Greeting()= default;
private:
    std::vector<Observer*> _observers;
};

class ObserverOnWarning: public Observer{
public:
    void onWarning( const std::string& message) override;
    void onError(   const std::string& message) override{};
    void onFatalError(const std::string& message) override{};
    ~ObserverOnWarning()= default;
    ObserverOnWarning()= default;
};

class ObserverOnError: public Observer{
public:
    void setTheFilePath(const std::string& path);
    void onWarning( const std::string& message) override{};
    void onError(   const std::string& message) override;
    void onFatalError(const std::string& message) override{};
    ~ObserverOnError()= default;
    ObserverOnError()= default;
private:
    std::string _pathway{"log2.txt"};
};

class ObserverOnFatalError: public Observer{
public:
    void setTheFilePath(const std::string& path);
    void onWarning( const std::string& message) override{};
    void onError(   const std::string& message) override{};
    void onFatalError(const std::string& message) override;
    ~ObserverOnFatalError()= default;
    ObserverOnFatalError()= default;
private:
    std::string _pathway{"log3.txt"};
};
