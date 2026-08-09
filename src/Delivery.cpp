#include "Delivery.h"
#include <fstream>
#include <iostream>
using namespace std;

Delivery::Delivery(){
    deliveryId = 0;
    orderId = 0;
    droneId = 0;
    deliveryDate = "";
    deliveryStatus = "Not Started";
}

void Delivery::startDelivery(int order, int drone, string date){
    cout << "Enter Delivery ID: ";
    cin >> deliveryId;
    orderId = order;
    droneId = drone;
    deliveryDate = date;
    deliveryStatus = "In Progress";
    cout << "Delivery Started Successfully" << endl;
}

void Delivery::completeDelivery(){
    deliveryStatus = "Completed";
    cout << "Delivery Completed Successfully" << endl;
}

void Delivery::displayDelivery(){
    cout << "\n-------------------------------\n";
    cout << "Delivery ID        : " << deliveryId << endl;
    cout << "Drone ID           : " << droneId << endl;
    cout << "Order ID           : " << orderId << endl;
    cout << "Delivery Date      : " << deliveryDate << endl;
    cout << "Status             : " << deliveryStatus << "\n";
}

int Delivery::getOrderId(){
    return orderId;
}

int Delivery::getDroneId(){
    return droneId;
}

void Delivery::saveHistory(){
    ofstream file("../data/history.txt", ios::app);

    if (!file){
        cout << "Unable to open history file." << endl;
        return;
    }

    file << deliveryId << " "
         << orderId << " "
         << droneId << " "
         << deliveryDate << " "
         << deliveryStatus << endl;

    file.close();
}

void Delivery::loadHistory(){
    ifstream file("../data/history.txt");

    if (!file){
        cout << "No delivery history found." << endl;
        return;
    }

    int id;
    int order;
    int drone;
    string date;
    string status;

    cout << "\n========== Delivery History ==========\n";

    while (file >> id >> order >> drone >> date >> status){
        cout << "-----------------------------" << endl;
        cout << "Delivery ID   : " << id << endl;
        cout << "Order ID      : " << order << endl;
        cout << "Drone ID      : " << drone << endl;
        cout << "Date          : " << date << endl;
        cout << "Status        : " << status << endl;
    }

    file.close();
}