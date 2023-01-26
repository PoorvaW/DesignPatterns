/*
Creational Design pattern
*/

class Vehicle{
    public:
    virtual void createVehicle()=0;
};

class Bike: public Vehicle{
    public:
    void createVehicle(){
        cout<<"Creating bike";
    }
};

class Car: public Vehicle{
    public:
    void createVehicle(){
        cout<<"Creating car";
    }
};

class VehicleFactory{
    public:
    static Vehicle* getVehicle(string type){
        if(type=="bike")
            return new Bike();
        else if(type=="car")
            return new Car();
        else throw invalid_argument("Received invalid vehicle type");
    }
};

int main(){
    string type;
    cin>>type;
    Vehicle *vehicle = VehicleFactory::getVehicle(type);
    vehicle->createVehicle();
}
