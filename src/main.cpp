#include <iostream>
#include <vector>
#include <fstream>
#include "Drone.h"
#include "Customer.h"
#include "Order.h"
#include "Delivery.h"

using namespace std;

vector<Drone> drones;
vector<Customer> customers;
vector<Order> orders;
vector<Delivery> deliveries;

void saveCustomersToFile(){
    ofstream customerFile("../data/Customer.txt", ios::trunc);
    customerFile.close();

    for(int i = 0; i < customers.size(); i++){
        customers[i].saveToFile();
    }
}

void saveDronesToFile(){
    ofstream droneFile("../data/Drone.txt", ios::trunc);
    droneFile.close();

    for(int i = 0; i < drones.size(); i++){
        drones[i].saveToFile();
    }
}

void saveOrdersToFile(){
    ofstream orderFile("../data/orders.txt", ios::trunc);
    orderFile.close();

    for(int i = 0; i < orders.size(); i++){
        orders[i].saveToFile();
    }
}

int main(){
    Drone tempDrone;
    tempDrone.loadFromFile(drones);

    Customer tempCustomer;
    tempCustomer.loadFromFile(customers);

    Order tempOrder;
    tempOrder.loadFromFile(orders);

    int ch;
    while(true){
        cout << "\n========== Drone Delivery Management System ==========" << endl;
        cout << "1. Customer Management" << endl;
        cout << "2. Order Management" << endl;
        cout << "3. Drone Management" << endl;
        cout << "4. Delivery Operations" << endl;
        cout << "5. Tracking & Reports" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> ch;

        switch (ch){
            case 1: {
                while(true){
                    int customerCh;
                    cout << "\n========== Customer Management ==========" << endl;
                    cout << "1. Add New Customer" << endl;
                    cout << "2. View Customers" << endl;
                    cout << "3. Search Customer" << endl;
                    cout << "4. Delete Customer" << endl;
                    cout << "5. Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> customerCh;

                    switch(customerCh){
                        case 1: {
                            Customer c;
                            if(c.addCustomer()){
                                customers.push_back(c);
                                saveCustomersToFile();
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
                            int searchId;
                            cout << "Enter Customer ID: ";
                            cin >> searchId;
                            bool found = false;
                            for(int i = 0; i < customers.size(); i++){
                                if(customers[i].getCustomerId() == searchId){
                                    customers[i].displayCustomer();
                                    found = true;
                                    break;
                                }
                            }
                            if(!found){
                                cout << "Customer not found!" << endl;
                            }
                            break;
                        }
                        case 4: {
                            int deleteId;
                            cout << "Enter Customer ID to delete: ";
                            cin >> deleteId;
                            int index = -1;
                            for(int i = 0; i < customers.size(); i++){
                                if(customers[i].getCustomerId() == deleteId){
                                    index = i;
                                    break;
                                }
                            }
                            if(index == -1){
                                cout << "Customer not found!" << endl;
                            }
                            else{
                                customers.erase(customers.begin() + index);
                                saveCustomersToFile();
                                cout << "Customer deleted successfully!" << endl;
                            }
                            break;
                        }
                        case 5: {
                            break;
                        }
                        default: {
                            cout << "Invalid choice!" << endl;
                            break;
                        }
                    }
                    if(customerCh == 5){
                        break;
                    }
                }
                break;
            }
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
                                bool customerExists = false;
                                for(int i = 0; i < customers.size(); i++){
                                    if(customers[i].getCustomerId() == o.getCustomerId()){
                                        customerExists = true;
                                        break;
                                    }
                                }
                                if(customerExists){
                                    orders.push_back(o);
                                    saveOrdersToFile();
                                    cout << "Order Created Successfully!" << endl;
                                }
                                else{
                                    cout << "Customer ID does not exist!" << endl;
                                }
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
                            for(int i = 0; i < orders.size(); i++){
                                if(orders[i].getOrderId() == orderId){
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
                                    saveOrdersToFile();
                                    saveDronesToFile();
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
                            break;
                        }
                        default: {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                    if(orderCh == 4){
                        break;
                    }
                }
                break;
            }
            case 3: {
                while(true){
                    int droneCh;
                    cout << "\n========== Drone Management ==========" << endl;
                    cout << "1. Add New Drone" << endl;
                    cout << "2. View Drones" << endl;
                    cout << "3. Search Drone" << endl;
                    cout << "4. Delete Drone" << endl;
                    cout << "5. Update Battery" << endl;
                    cout << "6. Change Drone Status" << endl;
                    cout << "7. Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> droneCh;
                    switch(droneCh){
                        case 1: {
                            Drone d;
                            if(d.addDrone()==true){
                                drones.push_back(d);
                                saveDronesToFile();
                            }
                            break;
                        }
                        case 2: {
                            for(int i = 0; i < drones.size(); i++){
                                drones[i].displayDrone();
                            }
                            break;
                        }
                        case 3: {
                            int searchId;
                            cout << "Enter Drone ID: ";
                            cin >> searchId;
                            bool found = false;
                            for(int i = 0; i < drones.size(); i++){
                                if(drones[i].getDroneId() == searchId){
                                    drones[i].displayDrone();
                                    found = true;
                                    break;
                                }
                            }
                            if(!found){
                                cout << "Drone not found!" << endl;
                            }
                            break;
                        }
                        case 4: {
                            int deleteId;
                            cout << "Enter Drone ID to delete: ";
                            cin >> deleteId;
                            int index = -1;
                            for(int i = 0; i < drones.size(); i++){
                                if(drones[i].getDroneId() == deleteId){
                                    index = i;
                                    break;
                                }
                            }
                            if(index == -1){
                                cout << "Drone not found!" << endl;
                            }
                            else{
                                drones.erase(drones.begin() + index);
                                saveDronesToFile();
                                cout << "Drone deleted successfully!" << endl;
                            }
                            break;
                        }
                        case 5: {
                            int droneId;
                            cout << "Enter Drone ID: ";
                            cin >> droneId;
                            for(int i = 0; i < drones.size(); i++){
                                if(drones[i].getDroneId() == droneId){
                                    drones[i].updateBattery();
                                    saveDronesToFile();
                                    break;
                                }
                            }
                            break;
                        }
                        case 6: {
                            int droneId;
                            cout << "Enter Drone ID: ";
                            cin >> droneId;
                            for(int i = 0; i < drones.size(); i++){
                                if(drones[i].getDroneId() == droneId){
                                    drones[i].changeStatus();
                                    saveDronesToFile();
                                    break;
                                }
                            }
                            break;
                        }
                        case 7: {
                            break;
                        }
                        default: {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                    if(droneCh == 7){
                        break;
                    }
                }
                break;
            }
            case 4: {
                while(true){
                    int deliveryCh;
                    cout << "\n========== Delivery Operations ==========" << endl;
                    cout << "1. Start Delivery" << endl;
                    cout << "2. Complete Delivery" << endl;
                    cout << "3. View Delivery History" << endl;
                    cout << "4. Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> deliveryCh;

                    switch(deliveryCh){
                        case 1: {
                            int orderId;
                            cout << "Enter Order ID: ";
                            cin >> orderId;
                            int orderIndex = -1;
                            for(int i = 0; i < orders.size(); i++){
                                if(orders[i].getOrderId() == orderId){
                                    orderIndex = i;
                                    break;
                                }
                            }
                            if(orderIndex == -1){
                                cout << "Order not found!" << endl;
                                break;
                            }
                            int droneId = orders[orderIndex].getAssignedDroneId();
                            if(droneId == 0){
                                cout << "No drone assigned to this order!" << endl;
                                break;
                            }
                            string deliveryDate;
                            cout << "Enter Delivery Date: ";
                            cin >> deliveryDate;
                            Delivery d;
                            d.startDelivery(orderId, droneId, deliveryDate);
                            deliveries.push_back(d);
                            d.saveHistory();
                            break;
                        }
                        case 2: {
                            int orderId;
                            cout << "Enter Order ID: ";
                            cin >> orderId;
                            int orderIndex = -1;
                            for(int i = 0; i < orders.size(); i++){
                                if(orders[i].getOrderId() == orderId){
                                    orderIndex = i;
                                    break;
                                }
                            }
                            if(orderIndex == -1){
                                cout << "Order not found!" << endl;
                                break;
                            }
                            int droneId = orders[orderIndex].getAssignedDroneId();
                            if(droneId == 0){
                                cout << "No drone assigned to this order!" << endl;
                                break;
                            }
                            int droneIndex = -1;
                            for(int i = 0; i < drones.size(); i++){
                                if(drones[i].getDroneId() == droneId){
                                    droneIndex = i;
                                    break;
                                }
                            }
                            if(droneIndex == -1){
                                cout << "Drone not found!" << endl;
                                break;
                            }
                            Delivery d;
                            d.startDelivery(orderId, droneId, "Today");
                            d.completeDelivery();
                            deliveries.push_back(d);
                            d.saveHistory();
                            orders[orderIndex].updateStatus("Delivered");
                            drones[droneIndex].setStatus("Available");
                            drones[droneIndex].reduceBattery(20);
                            drones[droneIndex].increaseDeliveryCount();
                            saveOrdersToFile();
                            saveDronesToFile();
                            break;
                        }
                        case 3: {
                            Delivery d;
                            d.loadHistory();
                            break;
                        }
                        case 4:
                            break;
                        default:
                            cout << "Invalid Choice!" << endl;
                    }
                    if(deliveryCh == 4){
                        break;
                    }
                }
                break;
            }
            case 5: {
                while(true){
                    int reportCh;
                    cout << "\n========== Tracking & Reports ==========" << endl;
                    cout << "1. Track Order" << endl;
                    cout << "2. View Drone Status" << endl;
                    cout << "3. Delivery Statistics" << endl;
                    cout << "4. Back To Main Menu" << endl;
                    cout << "Enter Choice: ";
                    cin >> reportCh;

                    switch(reportCh){
                        case 1: {
                            int orderId;
                            cout << "Enter Order ID: ";
                            cin >> orderId;
                            for(int i = 0; i < orders.size(); i++){
                                if(orders[i].getOrderId() == orderId){
                                    orders[i].displayOrder();
                                    break;
                                }
                            }
                            break;
                        }
                        case 2: {
                            for(int i = 0; i < drones.size(); i++){
                                drones[i].displayDrone();
                            }
                            break;
                        }
                        case 3: {
                            int totalDrones = drones.size();
                            int totalOrders = orders.size();
                            int totalCustomers = customers.size();
                            int completedDeliveries = 0;
                            for(int i = 0; i < orders.size(); i++){
                                if(orders[i].getAssignedDroneId() != 0 && orders[i].getCustomerId() != 0){
                                    completedDeliveries++;
                                }
                            }
                            cout << "Total Drones       : " << totalDrones << endl;
                            cout << "Total Orders       : " << totalOrders << endl;
                            cout << "Total Customers    : " << totalCustomers << endl;
                            cout << "Completed Deliveries: " << completedDeliveries << endl;
                            break;
                        }
                        case 4: {
                            break;
                        }
                        default: {
                            cout << "Invalid Choice!" << endl;
                            break;
                        }
                    }
                    if(reportCh == 4){
                        break;
                    }
                }
                break;
            }
            case 6: {
                cout << "Thank You!" << endl;
                return 0;
            }
            default: {
                cout << "Invalid Choice" << endl;
                break;
            }
        }
    }
}