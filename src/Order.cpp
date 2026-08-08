#include"Order.h"
#include<iostream>
#include<fstream>
using namespace std;

Order::Order(){
    OrderId=0;
    CustomerId=0;
    AssignedDroneId=0;
    PackageWeight=0;
    Destination="";
    status="Pending";
}

bool Order::createOrder(){
    cout<<"enter order Id :";
    cin>>OrderId;
    cout<<"enter customer Id :";
    cin>>CustomerId;
    cout<<"enter package Weight :";
    cin>>PackageWeight;
    if(PackageWeight <=0){
        cout << "Invalid weight!" << endl;
        return false;
    }else{
        cout<<"enter Destination :";
        getline(cin>> ws,Destination);
        return true;
    }
    
}
void Order::assignDrone(int droneId){
    AssignedDroneId = droneId;
}
void Order::updateStatus(string newStatus){
    status = newStatus;
}
void Order ::displayOrder(){
    cout<<"\n---------------------------\n";
    cout<<"Order ID              :"<<OrderId;
    cout<<"\nCustomer ID         :"<<CustomerId;
    cout<<"\nPackage Weight      :"<<PackageWeight;
    cout<<"\nDestinatin          :"<<Destination;
    cout<<"\nAssigned Drone      :"<<AssignedDroneId;
    cout<<"\nStatus              :"<<status;
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
void Order::saveToFile()
{
    ofstream file("orders.txt", ios::app);

    if (!file)
    {
        cout << "Unable to open order file." << endl;
        return;
    }

    file << OrderId << " "
         << CustomerId << " "
         << PackageWeight << " "
         << Destination << " "
         << status << " "
         << AssignedDroneId << endl;

    file.close();

    cout << "Order saved successfully!" << endl;
}
void Order::loadFromFile()
{
    ifstream file("orders.txt");

    if (!file)
    {
        cout << "No order data found." << endl;
        return;
    }

    int id;
    int custId;
    float weight;
    string place;
    string orderStatus;
    int droneId;

    while (file >> id >> custId >> weight >> place >> orderStatus >> droneId)
    {
        cout << "-----------------------------" << endl;

        cout << "Order ID        : " << id << endl;
        cout << "Customer ID     : " << custId << endl;
        cout << "Package Weight  : " << weight << " kg" << endl;
        cout << "Destination     : " << place << endl;
        cout << "Status          : " << orderStatus << endl;

        if (droneId == 0)
        {
            cout << "Assigned Drone  : Not Assigned" << endl;
        }
        else
        {
            cout << "Assigned Drone  : " << droneId << endl;
        }
    }

    file.close();
}