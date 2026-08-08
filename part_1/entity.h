#pragma once
// Standard and custom header file imports
#include<iostream>
#include<vector>
#include<string>
using namespace std;

// global variables
vector<string> roomFacilities = {"AC", "Accessible", "Attached_Bathroom"};

class initializer;
class student{

private:
    string password;

public:
    friend class initializer;
    string studentId = "";
    string name = "";
    int no_of_ppl = 0;
    bool bookingStatus = false;
    int roomNoBooked = 0;

    // memeber functions

    // constructor
    student(string studentId, string name, int no_of_ppl, bool bookingStatus, int roomNoBooked){
        this->studentId = studentId;
        this->name = name;
        this->no_of_ppl = no_of_ppl;
        this->bookingStatus = bookingStatus;
        this->roomNoBooked = roomNoBooked;
    }

    // password checker
    bool isValid(string password){return password==this->password;}
    void setPassword(string password){this->password = password;}

    // toggle booking status
    void toggleBooking(){bookingStatus = !bookingStatus;}

    // show own details
    void display(){
        cout << "Student ID: " << studentId << endl;
        cout << "Name: " << name << endl;
        cout << "No of people: " << no_of_ppl << endl;
        cout << "Booking status: " << (bookingStatus ? "Booked" : "Not booked") << endl;
        cout << "Room no booked: " << roomNoBooked << endl;
    }

};

class room{

public:
    friend class initializer;
    string roomId = "";
    int roomNo = 0;
    int capacity = 0;
    bool isAllotted = false;

    room(){}
    room(string roomId, int roomNo, int capacity){
        this->roomId = roomId;
        this->roomNo = roomNo;
        this->capacity = capacity;
    }

    void display(){
        cout << "Room ID: " << roomId << endl;
        cout << "Room No: " << roomNo << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Allotted: " << (isAllotted ? "Yes" : "No") << endl;
    }

};

// if needed
class hostel{};

// if needed
class parent{};
