#include <iostream>
#include "Drone.h"

using namespace std;

class Customer{
    private:
        int customerId;
        string customerName;
        string mobileNum;
        string address;
    public:
        Customer();
        Customer(int id, string name, string mobileNum, string address);
        void addCustomer();
        void displayCustomer();
        void searchCustomer();
        void saveToFile();
        void loadFromFile();
};

class Order{
    private:
        int orderId;
        int customerId;
        float packageWeight;
        string destination;
        string status;
        int assignedDroneId;
    public:
        Order();
        Order(int orderId, int customerId, float weight);
        void createOrder();
        void displayOrder();
        void assignDrone();
        void updateStatus();
};

class Delivery{
    private:
        int deliveryId;
        int orderId;
        int droneId;
        string deliveryDate;
    public:
        Delivery();
        Delivery(int deliveryId, int orderId, int droneId);
        void startDelivery();
        void completeDelivery();
        void saveHistory();
};

int main(){
    int ch;
    Drone d1;
    Customer c1;
    while(true){
        cout << "========== Drone Delivery Management System ==========\n" << endl;
        cout << "1. Customer Management" << endl;
        cout << "2. Order Management" << endl;
        cout << "3. Drone Management" << endl;
        cout << "4. Delivery Operations" << endl;
        cout << "5. Tracking & Reports" << endl;
        cout << "6. Exit\n" << endl;
        cout << "Enter Choice: ";
        cin >> ch;
        switch (ch)
        {
            case 1:
            cout << "Customer Management" << endl;
            c1.addCustomer();
            c1.displayCustomer();
            break;
            case 2:
            cout << "Order Management" << endl;
            break;
            case 3:
            cout << "Drone Management" << endl;
            d1.addDrone();
            d1.displayDrone();
            break;
        case 4:
            cout << "Delivery Operation" << endl;
            break;
        case 5:
            cout << "tracking & reports" << endl;
            break;
        case 6:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    }
}