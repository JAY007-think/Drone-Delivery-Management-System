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
        void addDrone();
        void displayDrone();
        void updateBattery();
        void changeStatus();
        void isAvailable();
        void needsMaintenance();
};
