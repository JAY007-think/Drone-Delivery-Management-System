#include<iostream>
#include<fstream>
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
    ofstream file("Customer.txt",ios::app);
    if(!file){
        cout<<"unable to open customer file."<<endl;
        return ;
    }
    file<<CustomerId<<" "
        <<CustomerName<<" "
        <<mobileNum<<" "
        <<address<<endl;
    
        file.close();

        cout<<"Customer saved successfully!"<<endl;
}
void Customer::loadFromFile(){
    ifstream file("Customer.txt");

    if(!file){
        cout<<"No customer data found."<<endl;
        return ;
    }
    int id;
    string name;
    string mobile;
    string address;

    while(file>>id>>name>>mobile>>address){
        cout<<
        "--------------------------------"<<endl;
        cout<<"Customer ID         :"<<id<<endl;
        cout<<"Customer Name       :"<<name<<endl;
        cout<<"Mobile Number       :"<<mobile<<endl;
        cout<<"Address             :"<<address<<endl;
    }
    file.close();
}




