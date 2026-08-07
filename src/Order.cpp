#include"Order.h"
#include<iostream>
using namespace std;

Order::Order(){

}

Order::Order(int id,int customerId,float Weight,string destination){
    OrderId=id;
    CustomerId=customerId;
    PackageWeight=Weight;
    Destination=destination;
}
void Order::createOrder(){
    cout<<"enter order Id :";
    cin>>OrderId;
    cout<<"enter customer Id :";
    cin>>CustomerId;
    cout<<"enter package Weight :";
    cin>>PackageWeight;
    cout<<"enter Destination :";
    cin>>Destination;
    
}
void Order::assignDrone(){
    AssignedDroneId=0;
}
void Order :: updateStatus(){
    status="Pending";
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
void Order ::assignDrone(){

}
void Order ::updateStatus(){
    
}