# Drone Delivery Management System

A modular C++ application that simulates a basic drone delivery workflow. The system manages customers, drones, delivery orders, and delivery tracking, with text-file-based persistence for storing application data.

## Features

### Customer Management
- Add customer records
- View all customers
- Search customers
- Delete customer records

### Drone Management
- Add drones to the inventory
- View available drones
- Search drones
- Delete drone records
- Track drone battery levels and availability status

### Order and Delivery Management
- Create delivery orders
- Manage package and destination details
- Assign suitable drones to orders
- Track order and delivery status
- Maintain delivery history

### Data Persistence
- Store application data in text files
- Load saved customer and drone data
- Maintain order and delivery history between program runs

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

## Concepts and Technologies

- C++
- Object-Oriented Programming
- Classes and Objects
- Encapsulation
- Header and Source File Separation
- File Handling
- Data Persistence
- Modular Program Design
- Menu-Driven Application Architecture

## System Design

The application is organized around four core entities:

- **Customer** — manages customer information such as ID, name, mobile number, and address.
- **Drone** — represents drones in the system, including their ID, name, capacity, battery level, and current status.
- **Order** — manages delivery requests, package details, destination information, and assigned drones.
- **Delivery** — tracks the lifecycle of an order from drone assignment to completion and maintains delivery history.

Each entity is implemented as a separate class with its own header and source files. This separation keeps the application modular and makes individual components easier to understand and maintain.

## How It Works

A typical workflow is:

```text
Customer Registration
        ↓
Drone Management
        ↓
Order Creation
        ↓
Drone Assignment
        ↓
Delivery Status Tracking
        ↓
Delivery History
```

Application data is stored in text files inside the `data/` directory, allowing records to persist between program executions.

## Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/JAY007-think/Drone-Delivery-Management-System.git
cd Drone-Delivery-Management-System
```

### 2. Compile the Project

Using `g++`:

```bash
g++ src/*.cpp -I include -o drone_delivery
```

### 3. Run the Application

**Linux/macOS**

```bash
./drone_delivery
```

**Windows**

```powershell
.\drone_delivery.exe
```

## What I Learned

While building this project, I practiced:

- Designing relationships between multiple classes
- Structuring a multi-file C++ application
- Separating declarations and implementations using header and source files
- Managing application state
- Reading and writing persistent data using file handling
- Designing a menu-driven application workflow
- Breaking a larger problem into smaller, modular components

## Future Improvements

Potential improvements include:

- Stronger input validation and error handling
- Advanced search and filtering
- Improved drone-to-order assignment logic
- Better handling of edge cases
- Database integration for persistent and scalable storage
- Delivery analytics and reporting
- Graphical or web-based interface

## Author

**Jay Soni**

- GitHub: [JAY007-think](https://github.com/JAY007-think)
- LinkedIn: [jayz-tech](https://www.linkedin.com/in/jayz-tech/)

## License

This project is intended for learning and educational purposes.
