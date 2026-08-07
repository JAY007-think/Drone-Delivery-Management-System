#include "Drone.h"
Drone::Drone(){
    drone_name = "";
    drone_id = 0;
    capacity = 0;
    battery = 100;
    status = "Available";
    deliveryCount = 0;
}

bool Drone::addDrone(){
    cout << "Enter Drone ID: ";
    cin >> drone_id;
    cout << "Enter Drone Name: ";
    getline(cin >> ws, drone_name);
    cout << "Enter Drone Capacity: ";
    cin >> capacity;
    if(capacity<=0){
        cout << "Invalid Capacity!" << endl;
    }else{
        battery = 100;
        status = "Available";
        deliveryCount = 0;
        cout << "Drone Added Successfully!" << endl;
        return true;
    }
    return false;
};
void Drone::displayDrone(){
    cout << "------------------------------" << endl;
    cout << "Drone ID       : " <<drone_id<<endl;
    cout << "Drone Name     : " << drone_name << endl;
    cout << "Drone Capacity : " << capacity << endl;
    cout << "Battery        : " << battery << endl;
    cout << "Status         : " << status << endl;
    cout << "Delivery Count : " << deliveryCount << endl;
    cout << "------------------------------" << endl;
}

bool Drone::isAvailable(){
    if(status == "Available"){
        return true;
    }else{
        return false;
    }
}

bool Drone::needsMaintenance(){
    if(deliveryCount>=5){
        return true;
    }else{
        return false;
    }
}

int Drone::getDroneId(){
    return drone_id;
}

float Drone::getCapacity(){
    return capacity;
}

int Drone::getBattery(){
    return battery;
}

string Drone::getStatus(){
    return status;
}

void Drone::reduceBattery(int amount){
    if(battery - amount < 0){
        battery = 0;
    }else{
        battery = battery - amount;
    }
}

void Drone::increaseDeliveryCount(){
    deliveryCount++;
}

void Drone::changeStatus(){
    cout << "1.delivering" << endl;
    cout << "2.Available" << endl;
    cout << "3.charging" << endl;
    cout << "4.Maintainance" << endl;
}

void Drone::updateBattery(){
    int newBattery;
    cout << "Enter new Battery: ";
    cin >> newBattery;
    if(newBattery < 0 || newBattery > 100){
        cout << "Invalid Battery!" << endl;
    }
    else{
        battery = newBattery;
    }
}
void Drone::setStatus(string newStatus){
    status = newStatus;
}