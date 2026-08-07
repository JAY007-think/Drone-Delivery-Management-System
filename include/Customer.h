#include<iostream>
using namespace std;

class Customer{
 int CustomerId;
 string CustomerName;
 string mobileNum;
 string address;
 public:
 Customer();
 bool addCustomer();
 void displayCustomer();
 void searchCustomer();
 void saveToFile();
 void loadFromFile();
};