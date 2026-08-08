#include<iostream>
using namespace std;

class Order{
    private:
        int OrderId;
        int CustomerId;
        int AssignedDroneId;
        float PackageWeight;
        string Destination;
        string status;
    public:
        Order();
        bool createOrder();
        void displayOrder();
        void assignDrone(int drone_id);
        void updateStatus(string newStatus);
        int getOrderId();
        int getCustomerId();
        float getPackageWeight();
        int getAssignedDroneId();

        void setAssignedDroneId(int id);
        void setStatus(string newStatus);

        void saveToFile();
        void  loadFromFile();
};
