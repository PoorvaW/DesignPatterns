/*
complex object - eg. vehicle - built using lot of small small things
configurations - object is configurable.. therefore lot's of constructors-to avoid this
*/

class Desktop{
    string monitor;
    string keyboard;
    string mouse;
    string speaker;
    string ram;
    string processor;
    string motherboard;
    
    public:
    void setMonitor(string monitor){
        this->monitor = monitor;
    }
    void setKeyboard(string keyboard){
        this->keyboard = keyboard;
    }
    void setMouse(string mouse){
        this->mouse = mouse;
    }
    void setSpeaker(string speaker){
        this->speaker = speaker;
    }
    void setRam(string ram){
        this->ram = ram;
    }
    void setProcessor(string processor){
        this->processor = processor;
    }
    void setMotherboard(string motherboard){
        this->motherboard = motherboard;
    }
    
    void showSpecs(){
        cout<<monitor<<" "<<keyboard<<" "<<mouse
            <<" "<<speaker<<" "<<ram<<" "<<processor
            <<" "<<motherboard<<" "<<endl;
    }
};


class DesktopBuilder{
protected:
    Desktop* desktop;
public:
    DesktopBuilder(){
        desktop = new Desktop();
    }
    virtual void buildMonitor()=0;
    virtual void buildKeyboard()=0;
    virtual void buildMouse()=0;
    virtual void buildSpeaker()=0;
    virtual void buildRam()=0;
    virtual void buildProcessor()=0;
    virtual void buildMotherboard()=0;
    virtual Desktop* getDesktop(){
        return desktop;
    }
};


class DellDesktopBuilder:public DesktopBuilder{
    void buildMonitor(){
        desktop->setMonitor("dell monitor");
    }
    void buildKeyboard(){
        desktop->setKeyboard("dell keyboard");
    }
    void buildMouse(){
        desktop->setMouse("dell mouse");
    }
    void buildSpeaker(){
        desktop->setSpeaker("dell speaker");
    }
    void buildRam(){
        desktop->setRam("dell ram");
    }
    void buildProcessor(){
        desktop->setProcessor("dell processor");
    }
    void buildMotherboard(){
        desktop->setMotherboard("dell motherboard");
    }
};

class HpDesktopBuilder:public DesktopBuilder{
    void buildMonitor(){
        desktop->setMonitor("hp monitor");
    }
    void buildKeyboard(){
        desktop->setKeyboard("hp keyboard");
    }
    void buildMouse(){
        desktop->setMouse("hp mouse");
    }
    void buildSpeaker(){
        desktop->setSpeaker("hp speaker");
    }
    void buildRam(){
        desktop->setRam("hp ram");
    }
    void buildProcessor(){
        desktop->setProcessor("hp processor");
    }
    void buildMotherboard(){
        desktop->setMotherboard("hp motherboard");
    }
};


class DesktopDirector{
    DesktopBuilder* desktopBuilder;
public:
    DesktopDirector(DesktopBuilder* desktopBuilder){
        this->desktopBuilder = desktopBuilder;
    }
    
    Desktop* getDesktop(){
        return desktopBuilder->getDesktop();
    }
    
    Desktop* buildDesktop(){
        desktopBuilder->buildMonitor();
        desktopBuilder->buildKeyboard();
        desktopBuilder->buildMouse();
        desktopBuilder->buildSpeaker();
        desktopBuilder->buildRam();
        desktopBuilder->buildProcessor();
        desktopBuilder->buildMotherboard();
        return desktopBuilder->getDesktop();
    }
};


int main() {
    HpDesktopBuilder* hpDesktopBuilder = new HpDesktopBuilder();
    DellDesktopBuilder* dellDesktopBuilder = new DellDesktopBuilder();
    
    DesktopDirector* desktopDirector1 = new DesktopDirector(hpDesktopBuilder);
    DesktopDirector* desktopDirector2 = new DesktopDirector(dellDesktopBuilder);
    
    Desktop* hpDesktop = desktopDirector1->buildDesktop();
    Desktop* dellDesktop = desktopDirector2->buildDesktop();
    
    hpDesktop->showSpecs();
    dellDesktop->showSpecs();
    
}
