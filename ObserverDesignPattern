class ISubscriber{
    public:
    virtual void notify(string msg)=0;
};

class Subscriber: public ISubscriber{
    string subName;
    public:
    Subscriber(string subName){
        this->subName=subName;
    }
    void notify(string msg){
        cout<<subName<<" received message: "<<msg<<endl;
    }
};

class Publisher{
    list<ISubscriber*> subscribers;
    public:
    void subscribe(ISubscriber* isubscriber){
        subscribers.push_back(isubscriber);
    }
    
    void unsubscribe(ISubscriber* isubscriber){
        if(subscribers.size()>0)
            subscribers.remove(isubscriber);
    }
    
    void publish(string msg){
        for(ISubscriber* isubscriber: subscribers)
            isubscriber->notify(msg);
    }
    
};

int main() {
    Publisher* publisher = new Publisher();
    Subscriber* sub1 = new Subscriber("sub1");
    Subscriber* sub2 = new Subscriber("sub2");
    Subscriber* sub3 = new Subscriber("sub3");
    
    publisher->subscribe(sub1);
    publisher->subscribe(sub2);
    publisher->subscribe(sub3);
    
    publisher->publish("New Message 1");
    
    publisher->unsubscribe(sub1);
    
    publisher->publish("New Message 2");
}
