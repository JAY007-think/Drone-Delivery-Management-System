#include"Order.h"
#include<iostream>
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