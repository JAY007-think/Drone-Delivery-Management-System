# Drone Delivery Management System

A simple C++ console project for managing customers, drones, orders, and deliveries.

## Features
- Add and view customers
- Add and view drones
- Create and assign orders
- Start and complete deliveries
- Save data in text files so it remains available after restarting the program

## How to Run
1. Open the project folder.
2. Go to the src folder.
3. Compile the program:
   g++ main.cpp Drone.cpp Customer.cpp Order.cpp Delivery.cpp -I../include -o main
4. Run the program:
   ./main

## Project Files
- src/ : main program and C++ source files
- include/ : class declarations
- data/ : saved text data files

This project is simple and beginner-friendly for learning OOP and file handling in C++.