#include"Delivery.h"
#include<iostream>
using namespace std;

Delivery::Delivery(){
    deliveryId=0;
    orderId=0;
    droneId=0;
    deliveryDate="";
    deliveryStatus="Not Started";
    
}
Delivery::Delivery(int deliveryid, int orderid, int droneid){
    deliveryId=deliveryid;
    orderId=orderid;
    droneId=droneid;
    deliveryStatus="Not Started";
}
void Delivery::startDelivery(){
    cout<<"enter delivery ID :";
    cin>>deliveryId;
    cout<<"enter order ID :";
    cin>>orderId;
    cout<<"enter drone ID :";
    cin>>droneId;
    cout<<"enter delivery date :";
    cin>>deliveryDate;
    cout<<"Delivery Starte Successfully\n";
}
void Delivery::completeDelivery(){
    deliveryStatus="completed";
    cout<<"Delivery Complete Succesfully";
}
void Delivery::displayDelivery(){
    cout<<
    "\n-------------------------------\n";
    cout<<"Delivery ID        :"<<deliveryId;
    cout<<"\nDrone ID           :"<<droneId;
    cout<<"\nOrder ID           :"<<orderId;
    cout<<"\nDelivery Date      :"<<deliveryDate;
    cout<<"\nStatus             :"<<deliveryStatus<<"\n";
}
void Delivery::saveHistory(){

}
