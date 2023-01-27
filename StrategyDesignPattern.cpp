class DriveStrategy{
public:
    virtual void drive()=0;
};

class NormalDriveStrategy: public DriveStrategy{
public:
    void drive(){
        cout<<"Normal drive"<<endl;
    }
};

class SpecialDriveStrategy: public DriveStrategy{
public:
    void drive(){
        cout<<"Special drive"<<endl;
    }
};

class Vehicle{
    DriveStrategy* driveStrategy;
public:
    Vehicle(DriveStrategy* driveStrategy){
        this->driveStrategy = driveStrategy;
    }
    
    void drive(){
        driveStrategy->drive();
    }
};

class SportsVehicle: public Vehicle{
public:
    SportsVehicle():Vehicle(new SpecialDriveStrategy()){}
};

class PassengerVehicle: public Vehicle{
public:
    PassengerVehicle():Vehicle(new NormalDriveStrategy()){}
};

class OffroadVehicle: public Vehicle{
public:
    OffroadVehicle():Vehicle(new SpecialDriveStrategy()){}
};

int main() {
    OffroadVehicle *v1 = new OffroadVehicle();
    v1->drive();
    PassengerVehicle *v2 = new PassengerVehicle();
    v2->drive();
    SportsVehicle* v3 = new SportsVehicle();
    v3->drive();
}
