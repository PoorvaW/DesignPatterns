class BasePizza{
 public:
    virtual int getPrice()=0;
};

class MargheritaPizza: public BasePizza{
public:
    int getPrice(){
        return 250;
    }
};

class NeapolitanPizza: public BasePizza{
public:
    int getPrice(){
        return 300;
    }
};

class PizzaDecorator: public BasePizza{
protected:
    BasePizza* basePizza;
public:
    PizzaDecorator(BasePizza* basePizza){
        this->basePizza = basePizza;
    }
    virtual int getPrice()=0;
};

class MushroomDecorator: public PizzaDecorator{
public:
    MushroomDecorator(BasePizza* basePizza): PizzaDecorator(basePizza){}
    int getPrice(){
        return basePizza->getPrice()+30;
    }
};

class ChickenDecorator: public PizzaDecorator{
public:
    ChickenDecorator(BasePizza* basePizza): PizzaDecorator(basePizza){}
    int getPrice(){
        return basePizza->getPrice()+70;
    }
};

int main() {
    MargheritaPizza* margherita = new MargheritaPizza();
    MushroomDecorator* mushroomMargherita = new MushroomDecorator(margherita);
    cout<<"Cost of Mushroom Margherita "<<mushroomMargherita->getPrice()<<endl;
    ChickenDecorator* chickenMushroomMargherita = new ChickenDecorator(mushroomMargherita);
    cout<<"Cost of Mushroom Chicken Margherita "<<chickenMushroomMargherita->getPrice()<<endl;
    
    NeapolitanPizza* neapolitanPizza = new NeapolitanPizza();
    ChickenDecorator* chickenNeapolitan = new ChickenDecorator(neapolitanPizza);
    cout<<"Cost of Chicken Neapolitan "<<chickenNeapolitan->getPrice()<<endl;
    
}
