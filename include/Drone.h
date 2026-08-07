#include<bits/stdc++.h>
using namespace std;

class Drone{
    private:
        string drone_name;
        int drone_id;
        float capacity;
        int battery;
        string status;
        int deliveryCount;
    public:
        Drone();
        Drone(int id, string name, float cap);
        bool addDrone();
        void displayDrone();
        void updateBattery();
        void changeStatus();
        bool isAvailable();
        bool needsMaintenance();
        int getDroneId();
        float getCapacity();
        int getBattery();
        string getStatus();
        void reduceBattery(int amount);
        void increaseDeliveryCount();
};
