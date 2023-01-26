/*
Creational Design pattern
*/
class Logger{
    static Logger* loggerInstance;
    static mutex mtx;
    Logger(){
        cout<<"New instance of logger created"<<endl;
    }
    Logger(const Logger&);
    Logger operator=(const Logger&);
    
    public:
    static Logger* getLogger(){
        if(loggerInstance==nullptr){
            mtx.lock();
        if(loggerInstance==nullptr)
            loggerInstance = new Logger();
        mtx.unlock();
        }
        return loggerInstance;
    }
    
    void log(string msg){
        cout<<msg<<endl;
    }
};

Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;


void user1Logs(){
    Logger* logger1 = Logger::getLogger();
    logger1->log("User 1 logs");
}

void user2Logs(){
    Logger* logger2 = Logger::getLogger();
    logger2->log("User 2 logs");
}

int main() {
    thread t1(user1Logs);
    thread t2(user2Logs);
    
    t1.join();
    t2.join();
}
