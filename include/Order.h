#include<iostream>
using namespace std;

class Order{
    int OrderId;
    int CustomerId;
    int AssignedDroneId;
    float PackageWeight;
    string Destination;
    string status;
    public:
    Order();
    Order(int id,int customerId,float Weight,string destination);
    void createOrder();
    void displayOrder();
    void assignDrone();
    void updateStatus();
};
