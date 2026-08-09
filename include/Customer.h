#include <iostream>
#include <vector>
using namespace std;

class Customer{
private:
    int CustomerId;
    string CustomerName;
    string mobileNum;
    string address;
public:
    Customer();
    bool addCustomer();
    void displayCustomer();
    void searchCustomer(int targetId);
    void saveToFile();
    void loadFromFile(vector<Customer>& customers);
    void loadData(int id, string name, string mobile, string addr);
    int getCustomerId();
};