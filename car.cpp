//0Carter Taffe 8045619 
// This is the only file to submit.

#include "car.hpp"
#include <cstddef>
#include <cstring>
#include "doors.hpp"
#include "perf.hpp"

using namespace std;

//default constructor
Car::Car() {
    manufacturer = NULL;
    model = NULL;
    zeroToSixtyNs = 0;
    headonDragCoeff = 0;
    horsepower = 0;
    backseatDoors = None;
    seatCount = 0;
}
//constructor overloading 
Car::Car(char const* const manufacturerName, char const* const modelName, PerformanceStats perf, uint8_t numSeats
, DoorKind backseatDoorDesign){
    this->manufacturer = manufacturerName;
    this->model = modelName;
    this->zeroToSixtyNs = perf.zeroToSixtyNs;
    this->headonDragCoeff = perf.headonDragCoeff;
    this->horsepower = perf.horsepower;
    this->seatCount = numSeats;
    this->backseatDoors = backseatDoorDesign;
}

//copy constructor
Car::Car(Car const& o){
    manufacturer = o.getManufacturer();
    model = o.getModel();

    zeroToSixtyNs = o.getStats(zeroToSixtyNs);
    headonDragCoeff = o.getStats(headonDragCoeff);
    horsepower = o.getStats(horsepower);

    seatCount = o.getSeatCount();
    backseatDoors = o.getBackseatDoors();

   }
   
Car::~Car(){
    delete manufacturer;
    delete model;

}

Car& Car::operator=(Car const& o){
    
    if (this == &o){
        return *this;
    }
    this->manufacturer = o.manufacturer;
    this->model = o.model;
    this->zeroToSixtyNs = o.zeroToSixtyNs;
    this->headonDragCoeff = o.headonDragCoeff;
    this->horsepower = o.horsepower;
    this->seatCount = o.seatCount;
    this->backseatDoors = o.backseatDoors;
    return *this;
}




char const* getManufacturer(){
    return manufacturer;
}

char const* getModel(){
    return model;
}

PerformanceStats getStats(){
    return perf;
}

uint8_t getSeatCount(){
    return numSeats;
}

DoorKind getBackseatDoors(){
    return backseatDoors;
}
void manufacturerChange(char const* const newManufacturer){
  
  delete manufacturer;
  this->manufacturer = newManufacturer;
}
    
    

int main(){

Car a;
a.manufacturerChange('ford');



}
