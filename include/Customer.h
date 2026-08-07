#include<iostream>
using namespace std;

class Customer{
 int CustomerId;
 string CustomerName;
 string mobileNum;
 string address;
 public:
 Customer();
 Customer(int id,string name,string mobile,string addres);
 void addCustomer();
 void displayCustomer();
 void searchCustomer();
 void saveToFile();
 void loadFromFile();
};