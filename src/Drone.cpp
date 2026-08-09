#include "Drone.h"
#include <fstream>
#include <iostream>

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
    if(capacity <= 0){
        cout << "Invalid Capacity!" << endl;
        return false;
    }
    battery = 100;
    status = "Available";
    deliveryCount = 0;
    cout << "Drone Added Successfully!" << endl;
    return true;
}

void Drone::displayDrone(){
    cout << "------------------------------" << endl;
    cout << "Drone ID       : " << drone_id << endl;
    cout << "Drone Name     : " << drone_name << endl;
    cout << "Drone Capacity : " << capacity << endl;
    cout << "Battery        : " << battery << endl;
    cout << "Status         : " << status << endl;
    cout << "Delivery Count : " << deliveryCount << endl;
    if(needsMaintenance()){
        cout << "Maintenance    : Needed" << endl;
    }
    else{
        cout << "Maintenance    : Not Needed" << endl;
    }
    cout << "------------------------------" << endl;
}

bool Drone::isAvailable(){
    return status == "Available";
}

bool Drone::needsMaintenance(){
    return deliveryCount >= 5 || battery < 30;
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
    }
    else{
        battery = battery - amount;
    }
}

void Drone::increaseDeliveryCount(){
    deliveryCount++;
}

void Drone::changeStatus(){
    int choice;
    cout << "1. Delivering" << endl;
    cout << "2. Available" << endl;
    cout << "3. Charging" << endl;
    cout << "4. Maintenance" << endl;
    cout << "Enter Choice: ";
    cin >> choice;

    if(choice == 1){
        status = "Delivering";
    }
    else if(choice == 2){
        status = "Available";
    }
    else if(choice == 3){
        status = "Charging";
    }
    else if(choice == 4){
        status = "Maintenance";
    }
    else{
        cout << "Invalid choice!" << endl;
    }
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

void Drone::saveToFile(){
    ofstream file("../data/Drone.txt", ios::app);

    if(file.is_open()){
        file << drone_id << endl;
        file << drone_name << endl;
        file << capacity << endl;
        file << battery << endl;
        file << status << endl;
        file << deliveryCount << endl;

        file.close();
    }
    else{
        cout << "File could not be opened!" << endl;
    }
}

void Drone::loadFromFile(vector<Drone>& drones){
    ifstream droneFile("../data/Drone.txt");

    if(!droneFile.is_open()){
        cout << "Drone file not found!" << endl;
        return;
    }

    int id;
    string name;
    float cap;
    int bat;
    string stat;
    int count;

    while(droneFile >> id){
        droneFile.ignore();
        getline(droneFile, name);
        droneFile >> cap;
        droneFile >> bat;
        droneFile.ignore();
        getline(droneFile, stat);
        droneFile >> count;

        Drone d;
        d.loadData(id, name, cap, bat, stat, count);
        drones.push_back(d);
    }

    droneFile.close();
}

void Drone::loadData(int id, string name, float cap, int bat, string stat, int count){
    drone_id = id;
    drone_name = name;
    capacity = cap;
    battery = bat;
    status = stat;
    deliveryCount = count;
}