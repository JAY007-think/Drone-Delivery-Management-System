#include <iostream>
#include <vector>
#include "Drone.h"
#include "Customer.h"
#include "Order.h"
#include "Delivery.h"

using namespace std;

vector<Drone> drones;
vector<Customer> customers;
vector<Order> orders;

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
                while(true){
                    int customerCh;
                    cout << "\n========== Customer Management ==========" << endl;
                    cout << "1.Add New Customer " << endl;
                    cout << "2.View Customer " << endl;
                    cout << "3.Delete Customer " << endl;
                    cout << "4.Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> customerCh;

                    switch (customerCh){
                    case 1: {
                        Customer c;
                        if(c.addCustomer()){
                            customers.push_back(c);
                        }
                        break;
                    }
                    case 2: {
                        for(int i = 0; i < customers.size(); i++){
                            customers[i].displayCustomer();
                        }
                        break;
                    }
                    case 3: {
                        cout << "deleted customer (abhi delete vala feature add nhi kiya h)" << endl;
                        break;
                    }
                    case 4: {
                        break;
                    }
                    default:{
                        cout << "Invalid choice!" << endl;
                        break;
                        }
                    }
                    if(customerCh == 4){
                        break;
                    }
                }
            } break;
            case 2: {
                while(true){
                    int orderCh;
                    cout << "\n========== Order Management ==========" << endl;
                    cout << "1. Create Order" << endl;
                    cout << "2. View Orders" << endl;
                    cout << "3. Assign Drone" << endl;
                    cout << "4. Back To Main Menu" << endl;
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
                            break;
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
                while(true){
                    int droneCh;
                    cout << "\n========== Drone Management ==========" << endl;
                    cout << "1.Add New Drone " << endl;
                    cout << "2.View Available Drone " << endl;
                    cout << "3.Delete Drone " << endl;
                    cout << "4.Add Drones For Inspection " << endl;
                    cout << "5.Back To Main Menu" << endl;
                    cin >> droneCh;
                    switch (droneCh){
                    case 1: {
                        Drone d;
                        if(d.addDrone()==true){
                            drones.push_back(d);
                        }
                        break;
                    }
                    case 2: {
                        for(int i=0;i<drones.size();i++){
                            drones[i].displayDrone();
                            }
                        break;
                    }
                    case 3: {
                        cout << "deleted drone , abhi delete vala feature add nhi kiya" << endl;
                        break;
                    }
                    case 4: {
                        cout << "add drone for inspection vala feature abhi pending h" << endl;
                        break;
                    }
                    case 5: {
                        break;
                    }
                    default:{
                        cout << "Invalid Choice!" << endl;
                    }
                    break;
                    }
                    if(droneCh == 5) break;
                }
            }break;
            case 4: {
                while(true){
                    int deliveryCh;

                    cout << "\n========== Delivery Operations ==========\n";
                    cout << "1. Start Delivery" << endl;
                    cout << "2. Complete Delivery" << endl;
                    cout << "3. View Delivery History" << endl;
                    cout << "4. Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> deliveryCh;

                    switch(deliveryCh){
                        case 1: {
                            cout << "Start Delivery" << endl;
                            Delivery d;
                            d.startDelivery();
                            break;
                        }
                        case 2: {
                            cout << "Complete Delivery" << endl;
                            Delivery d;
                            d.completeDelivery();
                            break;
                        }
                        case 3:{
                            cout << "Delivery history is stored in delivery_history.txt" << endl;
                            break;
                        }
                        case 4:
                            break;
                        default:
                            cout << "Invalid Choice!" << endl;
                    }
                    if(deliveryCh == 4)
                        break;
                }
                break;
            }
            case 5: {
                cout << "tracking & reports" << endl;
            } break;
            case 6: {
                cout << "Thank You!" << endl;
                return 0;
            } break;
            default: {
                cout << "Invalid Choice" << endl;
            }
             break;
            }
        }
    }
}