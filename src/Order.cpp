#include "Order.h"
#include <iostream>
#include <fstream>
using namespace std;

Order::Order(){
    OrderId = 0;
    CustomerId = 0;
    AssignedDroneId = 0;
    PackageWeight = 0;
    Destination = "";
    status = "Pending";
}

bool Order::createOrder(){
    cout << "Enter Order ID: ";
    cin >> OrderId;
    cout << "Enter Customer ID: ";
    cin >> CustomerId;
    cout << "Enter Package Weight: ";
    cin >> PackageWeight;
    if(PackageWeight <= 0){
        cout << "Invalid weight!" << endl;
        return false;
    }
    cout << "Enter Destination: ";
    getline(cin >> ws, Destination);
    return true;
}

void Order::assignDrone(int droneId){
    AssignedDroneId = droneId;
}

void Order::updateStatus(string newStatus){
    status = newStatus;
}

void Order::displayOrder(){
    cout << "\n---------------------------\n";
    cout << "Order ID          : " << OrderId << endl;
    cout << "Customer ID       : " << CustomerId << endl;
    cout << "Package Weight    : " << PackageWeight << endl;
    cout << "Destination       : " << Destination << endl;
    cout << "Assigned Drone    : " << AssignedDroneId << endl;
    cout << "Status            : " << status << endl;
}

int Order::getOrderId(){
    return OrderId;
}

int Order::getCustomerId(){
    return CustomerId;
}

float Order::getPackageWeight(){
    return PackageWeight;
}

int Order::getAssignedDroneId(){
    return AssignedDroneId;
}

void Order::setAssignedDroneId(int id){
    AssignedDroneId = id;
}

void Order::setStatus(string newStatus){
    status = newStatus;
}

void Order::saveToFile(){
    ofstream file("../data/orders.txt", ios::app);

    if (!file){
        cout << "Unable to open order file." << endl;
        return;
    }

    file << OrderId << endl;
    file << CustomerId << endl;
    file << PackageWeight << endl;
    file << Destination << endl;
    file << status << endl;
    file << AssignedDroneId << endl;

    file.close();
}

void Order::loadFromFile(vector<Order>& orders){
    ifstream file("../data/orders.txt");

    if (!file){
        cout << "No order data found." << endl;
        return;
    }

    int id;
    int custId;
    float weight;
    string place;
    string orderStatus;
    int droneId;

    while (file >> id){
        file.ignore();
        file >> custId;
        file.ignore();
        file >> weight;
        file.ignore();
        getline(file, place);
        getline(file, orderStatus);
        file >> droneId;

        Order o;
        o.loadData(id, custId, weight, place, orderStatus, droneId);
        orders.push_back(o);
    }

    file.close();
}

void Order::loadData(int id, int customerId, float weight, string destination, string orderStatus, int droneId){
    OrderId = id;
    CustomerId = customerId;
    PackageWeight = weight;
    Destination = destination;
    status = orderStatus;
    AssignedDroneId = droneId;
}