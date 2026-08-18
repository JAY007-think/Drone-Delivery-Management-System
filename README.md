# Drone Delivery Management System

A C++ object-oriented project for managing customer records, drone inventory, delivery orders, and delivery tracking. The system simulates a basic drone logistics workflow and stores data in text files for persistence.

## Features

- Add, view, search, and delete customer records
- Add, view, search, and delete drones
- Create and manage delivery orders
- Assign suitable drones to orders
- Update battery and status information for drones
- Track delivery history and status updates
- Store and load data from files
- Console-based modular menu system

## Project Structure

```text
Drone-Delivery-Management-System/
├── README.md
├── include/
│   ├── Customer.h
│   ├── Drone.h
│   ├── Order.h
│   └── Delivery.h
├── src/
│   ├── Customer.cpp
│   ├── Drone.cpp
│   ├── Order.cpp
│   ├── Delivery.cpp
│   └── main.cpp
├── data/
│   ├── Customer.txt
│   ├── Drone.txt
│   ├── orders.txt
│   └── history.txt
└── .gitignore
```

## Concepts Used

- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- File Handling
- Modular Program Design
- Data Persistence
- Menu-Driven Application Design

## System Design

The application models the main entities involved in a drone delivery workflow:

- Customer — stores customer details such as ID, name, mobile number, and address.
- Drone — represents available drones, including ID, name, capacity, battery level, and status.
- Order — manages customer orders, package details, destination, and assigned drone.
- Delivery — tracks the movement of an order from assignment to completion and stores delivery history.

Each entity is implemented as a separate class to keep the code modular, understandable, and easier to maintain.

## How to Run

### 1. Clone the repository

```bash
git clone https://github.com/JAY007-think/Drone-Delivery-Management-System.git
cd Drone-Delivery-Management-System
```

### 2. Compile the project

```bash
g++ src/*.cpp -I include -o drone_delivery
```

### 3. Run the application

Linux/macOS:

```bash
./drone_delivery
```

Windows:

```powershell
drone_delivery.exe
```

## What I Learned

While building this project, I practiced:

- Designing relationships between multiple classes
- Organizing a C++ project using header and source files
- Managing application state in memory and files
- Using file handling for data persistence
- Structuring a console application into modular components
- Implementing a menu-driven workflow for real-world systems

## Future Improvements

- Input validation and stronger error handling
- Search and filtering functionality
- Improved order assignment logic
- Database integration for scalable storage
- Graphical or web-based interface
- Delivery analytics and reports

## Author

**Jay Soni**

[GitHub](https://github.com/JAY007-think) • [LinkedIn](https://www.linkedin.com/in/jayz-tech/)

## License

This project is available for learning and educational purposes.
