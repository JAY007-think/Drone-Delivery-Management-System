#include <iostream>
using namespace std;

class Delivery
{
private:
    int deliveryId;
    int orderId;
    int droneId;
    string deliveryDate;
    string deliveryStatus;

public:
    Delivery();

    void startDelivery();
    void completeDelivery();
    void displayDelivery();
    void saveHistory();

    int getOrderId();
    int getDroneId();
};