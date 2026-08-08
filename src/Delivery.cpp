#include"Delivery.h"
#include<fstream>
#include<iostream>
using namespace std;

Delivery::Delivery(){
    deliveryId=0;
    orderId=0;
    droneId=0;
    deliveryDate="";
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

int Delivery::getOrderId(){
    return orderId;
}

int Delivery::getDroneId(){
    return droneId;
}
void Delivery::saveHistory()
{
    ofstream file("history.txt", ios::app);

    if (!file)
    {
        cout << "Unable to open history file." << endl;
        return;
    }

    file << deliveryId << " "
         << orderId << " "
         << droneId << " "
         << deliveryDate << " "
         << deliveryStatus << endl;

    file.close();

    cout << "Delivery history saved successfully!" << endl;
}
void Delivery::loadHistory()
{
    ifstream file("history.txt");

    if (!file)
    {
        cout << "No delivery history found." << endl;
        return;
    }

    int id;
    int order;
    int drone;
    string date;
    string status;

    cout << "\n========== Delivery History ==========\n";

    while (file >> id >> order >> drone >> date >> status)
    {
        cout << "-----------------------------" << endl;
        cout << "Delivery ID   : " << id << endl;
        cout << "Order ID      : " << order << endl;
        cout << "Drone ID      : " << drone << endl;
        cout << "Date          : " << date << endl;
        cout << "Status        : " << status << endl;
    }

    file.close();
}