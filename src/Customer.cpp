#include<iostream>
#include"Customer.h"
using namespace std;

Customer::Customer(){
    CustomerId = 0;
    CustomerName = "";
    mobileNum = "";
    address = "";
}

Customer::Customer(int id,string name,string mobile,string addres){
    CustomerId=id;
    CustomerName=name;
    mobileNum=mobile;
    address=addres;
}
void Customer::addCustomer(){
    cout<<"enter customer id :";
    cin>>CustomerId;
    cout<<"enter customer name :";
    getline(cin>> ws,CustomerName);
    cout<<"enter mobile number :";
    cin>>mobileNum;
    cout<<"enter address :";
    cin>>address;
    cout<<"Customer Add Successfully\n";
}
void Customer::displayCustomer(){
    cout<<
    "\n------------------------------------------\n";
    cout<<"Cusstomer ID      :"<<CustomerId<<"\n";
    cout<<"Customer Name     :"<<CustomerName<<"\n";
    cout<<"Mobile Number     :"<<mobileNum<<"\n";
    cout<<"Address           :"<<address<<"\n";
    cout<<
    "------------------------------------------\n";
}
void Customer::searchCustomer(){

}
void Customer::saveToFile(){

}
void Customer::loadFromFile(){

}




