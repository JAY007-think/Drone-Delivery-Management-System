#include<iostream>
using namespace std;

class Delivery{
    int deliveryId;
    int orderId;
    int droneId;
    string deliveryDate;
    string deliveryStatus;
    public:
    Delivery();
    Delivery(int deliveryid, int orderid, int droneid);
    void startDelivery();
    void completeDelivery();
    void displayDelivery();
    void saveHistory();
};