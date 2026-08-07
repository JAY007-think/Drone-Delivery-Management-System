#include <iostream>
#include <vector>
#include "Drone.h"
#include "Customer.h"
#include "Order.h"

using namespace std;

vector<Drone> drones;
vector<Customer> customers;
vector<Order> orders;

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
                while(true){
                    int orderCh;
                    cout << "\n========== Order Management ==========" << endl;
                    cout << "1. Create Order" << endl;
                    cout << "2. View Orders" << endl;
                    cout << "3. Assign Drone" << endl;
                    cout << "4. Back" << endl;
                    cout << "Enter Choice: ";
                    cin >> orderCh;

                    switch(orderCh){
                        case 1: {
                            Order o;
                            if(o.createOrder()){
                                orders.push_back(o);
                                cout << "Order Created Successfully!" << endl;
                            }
                            break;
                        }
                        case 2: {
                            for(int i = 0; i < orders.size(); i++){
                                orders[i].displayOrder();
                            }
                            break;
                        }
                        case 3: {
                            int orderId;
                            cout << "Enter Order ID: ";
                            cin >> orderId;
                            int orderIndex = -1;
                            for(int i = 0; i < orders.size(); i++)
                            {
                                if(orders[i].getOrderId() == orderId)
                                {
                                    orderIndex = i;
                                    break;
                                }
                            }
                            if(orderIndex == -1){
                                cout << "Order not found!" << endl;
                                break;
                            }
                            bool droneFound = false;

                            for(int j = 0; j < drones.size(); j++){
                                if(drones[j].getCapacity() >= orders[orderIndex].getPackageWeight()
                                && drones[j].getBattery() >= 30
                                && drones[j].isAvailable()){
                                    orders[orderIndex].assignDrone(drones[j].getDroneId());
                                    orders[orderIndex].updateStatus("Assigned");
                                    drones[j].setStatus("Delivering");

                                    droneFound = true;
                                    cout << "Drone Assigned Successfully!" << endl;
                                    cout << "Drone ID: " << drones[j].getDroneId() << endl;
                                    break;
                                }
                            }
                            if(droneFound == false){
                                cout << "No suitable drone available!" << endl;
                            }
                        }
                        case 4: {
                            // Back to main menu
                            break;
                        }
                        default: {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                    if(orderCh == 4) break;
                }
                break;
            case 3: {
                cout << "Drone Management" << endl;
                Drone d;
                    if(d.addDrone()==true){
                        drones.push_back(d);
                    }
                    for(int i=0;i<drones.size();i++){
                        drones[i].displayDrone();
                        }
                    break;
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
}