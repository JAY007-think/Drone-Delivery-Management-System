#include <iostream>
#include <fstream>
#include "Customer.h"
using namespace std;

Customer::Customer(){
    CustomerId = 0;
    CustomerName = "";
    mobileNum = "";
    address = "";
}

bool Customer::addCustomer(){
    cout << "Enter Customer ID: ";
    cin >> CustomerId;
    cout << "Enter Customer Name: ";
    getline(cin >> ws, CustomerName);
    cout << "Enter Mobile Number: ";
    cin >> mobileNum;
    if(mobileNum.length() != 10){
        cout << "Invalid Mobile Number" << endl;
        return false;
    }
    cout << "Enter Address: ";
    getline(cin >> ws, address);
    cout << "Customer Added Successfully" << endl;
    return true;
}

void Customer::displayCustomer(){
    cout << "\n------------------------------------------\n";
    cout << "Customer ID      : " << CustomerId << "\n";
    cout << "Customer Name    : " << CustomerName << "\n";
    cout << "Mobile Number    : " << mobileNum << "\n";
    cout << "Address          : " << address << "\n";
    cout << "------------------------------------------\n";
}

void Customer::searchCustomer(int targetId){
    if(CustomerId == targetId){
        displayCustomer();
    }
}

void Customer::saveToFile(){
    ofstream file("../data/Customer.txt", ios::app);

    if(file.is_open()){
        file << CustomerId << endl;
        file << CustomerName << endl;
        file << mobileNum << endl;
        file << address << endl;
        file.close();
    }
    else{
        cout << "File could not be opened!" << endl;
    }
}

void Customer::loadFromFile(vector<Customer>& customers){
    ifstream file("../data/Customer.txt");

    if(!file){
        cout << "No customer data found." << endl;
        return;
    }

    int id;
    string name;
    string mobile;
    string addr;

    while(file >> id){
        file.ignore();
        getline(file, name);
        getline(file, mobile);
        getline(file, addr);

        Customer c;
        c.loadData(id, name, mobile, addr);
        customers.push_back(c);
    }

    file.close();
}

void Customer::loadData(int id, string name, string mobile, string addr){
    CustomerId = id;
    CustomerName = name;
    mobileNum = mobile;
    address = addr;
}

int Customer::getCustomerId(){
    return CustomerId;
}