#include<iostream>
#include"Customer.h"
using namespace std;

Customer::Customer(){
    CustomerId = 0;
    CustomerName = "";
    mobileNum = "";
    address = "";
}

bool Customer::addCustomer(){
    cout<<"enter customer id :";
    cin>>CustomerId;
    cout<<"enter customer name :";
    getline(cin>> ws,CustomerName);
    cout<<"enter mobile number :";
    cin>>mobileNum;
    if(mobileNum.length() != 10){
        cout << "Invalid Mobile Number" << endl;
    }else{
        cout<<"enter address :";
        getline(cin>> ws,address);
        cout<<"Customer Add Successfully\n";
        return true;
    }
    return false;
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




