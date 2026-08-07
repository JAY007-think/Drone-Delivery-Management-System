#include <iostream>
#include <vector>
#include "Drone.h"
#include "Customer.h"

using namespace std;

vector<Drone> drones;
vector<Customer> customers;
// vector<Order> orders;

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
            case 1: {
                cout << "Customer Management" << endl;
                Customer c;
                c.addCustomer();
                customers.push_back(c);
                for(int i = 0; i < customers.size(); i++){
                    customers[i].displayCustomer();
                }
            } break;
            case 2: {
                cout << "Order Management" << endl;
            } break;
            case 3: {
                cout << "Drone Management" << endl;
                Drone d;
                if(d.addDrone()==true){
                    drones.push_back(d);
                }
                for(int i=0;i<drones.size();i++){
                    drones[i].displayDrone();
                }
            } break;
            case 4: {
                cout << "Delivery Operation" << endl;
            } break;
            case 5: {
                cout << "tracking & reports" << endl;
            } break;
            case 6: {
                cout << "Thank You!" << endl;
                return 0;
            } break;
            default: {
                cout << "Invalid Choice" << endl;
            } break;
        }
    }
}