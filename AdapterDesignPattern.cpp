/*
Bridge between two incompatible interfaces
*/

class Adaptee{
    string name;
public:
    Adaptee(string name){
        this->name=name;
    }
    
    string getName(){
        return name;
    }
    
    void perform(){
        cout<<"Adaptee "<<name<<" Performing action";
    }
};

class Target{
    public:
    virtual void perform(){
        cout<<"Performing target action"<<endl;
    }
};

class Adapter: public Target{
    Adaptee* adaptee;
public:
    Adapter(Adaptee* adaptee){
        this->adaptee = adaptee;
    }
    
    void perform() override{
        adaptee->perform();
    }
};

int main() {
    Adaptee* adaptee = new Adaptee("A1");
    Target* target = new Adapter(adaptee);
    target->perform();
}
