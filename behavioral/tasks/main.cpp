#include "log_command.h"
#include "observer.h"
#include "mess_chain_resp.h"
#include <exception>
/*
*/
/*_-task1-_*/
//void print( LogCommand& l){
//    std::string str{"Hello World!"};
//    l.print(str);
//}
//int main( int argc, char** argv){
//    try {
//        LogCommandConsole logCon;
//        LogCommandFile logFile;
//        print(logCon);
//        print(logFile);
//    } catch( const std::exception& e){
//        std::cerr<< e.what()<< std::endl;
//    }
//    return 0;
//}

/*_-task2-_*/
//int main( int argc, char** argv){
//    try {
//        LogCommandConsole logCon;
//        ObserverOnWarning ow;
//        ObserverOnError oe;
//        ObserverOnFatalError ofe;
//        Greeting greet;
//        greet.addObserver(&ow);
//        greet.addObserver(&oe);
//        greet.addObserver(&ofe);
//        greet.warning("Hello World!");
//        greet.error("Hello, world!");
//        greet.fatalError("Hello, world!!!");
//    } catch( const std::exception& e){
//        std::cerr<< e.what()<< std::endl;
//    }
//    return 0;
//}

/*_-task3-_*/
int main( int argc, char** argv){
    try {
        LogMessage log1( Type::Error, "This is a error\n");
        LogMessage log2( Type::Warning, "This is a warning\n");
        LogMessage log3( Type::Unknown, "This is a unknown message\n");
        LogMessage log4( Type::FatalError,
                         "This is fatal error, programm will be closed\n");
        FatalError fatalErrorHandler;
        Error errorHandler("log.txt");
        Warning warningHandler;
        Unknown unknownHandler;

        fatalErrorHandler.setNext(&errorHandler);
        errorHandler.setNext(&warningHandler);
        warningHandler.setNext(&unknownHandler);

        fatalErrorHandler.handleMessage(log1);
        fatalErrorHandler.handleMessage(log2);
    } catch( const std::exception& e){
        std::cerr<< e.what()<< std::endl;
    } catch( ...){
        std::exception_ptr ex = std::current_exception();
        try{ std::rethrow_exception(ex);}
        catch (std::bad_exception const &){
            std::cerr<< __func__<< "Bad exception"<< std::endl;
        }
    }
    return 0;
}
