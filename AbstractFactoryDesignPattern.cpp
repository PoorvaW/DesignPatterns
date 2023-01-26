/*
Creational Design pattern
*/

class IButton{
    public:
    virtual void press()=0;
};

class MacButton: public IButton{
    public:
    void press(){
        cout<<"Mac button pressed"<<endl;
    }
};

class WinButton: public IButton{
    void press(){
        cout<<"Win button pressed"<<endl;
    }
};

class ITextBox{
    public:
    virtual void show()=0;
};

class MacTextBox: public ITextBox{
    public:
    void show(){
        cout<<"Showing Mac textbox"<<endl;
    }
};

class WinTextBox: public ITextBox{
    void show(){
        cout<<"Showing Win textbox"<<endl;
    }
};

class IFactory{
    public:
    virtual IButton* createButton()=0;
    virtual ITextBox* createTextBox()=0;
};

class WinFactory: public IFactory{
    public:
    IButton* createButton(){
        return new WinButton();
    }
    ITextBox* createTextBox(){
        return new WinTextBox();
    }  
};

class MacFactory: public IFactory{
    public:
    IButton* createButton(){
        return new MacButton();
    }
    ITextBox* createTextBox(){
        return new MacTextBox();
    }  
};

class GUIAbstractFactory{
    public:
    static IFactory* createFactory(string osType){
        if(osType=="windows")
            return new WinFactory();
        else if(osType=="mac")
            return new MacFactory();
        else throw invalid_argument("Received invalid OS Type");
    }
};

int main() {
    string osType;
    cin>>osType;
    IFactory* ifactory = GUIAbstractFactory::createFactory(osType);
    IButton* button = ifactory->createButton();
    ITextBox* textbox = ifactory->createTextBox();
    button->press();
    textbox->show();
    
}
