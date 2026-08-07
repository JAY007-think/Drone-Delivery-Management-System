#include "Drone.h"
Drone::Drone(){
    drone_name = "";
    drone_id = 0;
    capacity = 0;
    battery = 100;
    status = "Available";
    deliveryCount = 0;
}
Drone::Drone(int id, string name, float cap)
{
    drone_id = id;
    drone_name = name;
    capacity = cap;
    battery = 100;
    status = "Available";
    deliveryCount = 0;
}
void Drone::addDrone(){
    cout << "Enter Drone ID: ";
    cin >> drone_id;
    cout << "Enter Drone Name: ";
    getline(cin >> ws, drone_name);
    cout << "Enter Drone Capacity: ";
    cin >> capacity;
    if(capacity<=0){
        cout << "Invalid Capacity!" << endl;
    }
    battery = 100;
    status = "Available";
    deliveryCount = 0;
    cout << "Drone Added Successfully!" << endl;
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