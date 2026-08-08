#pragma once
// Standard and custom header file imports
#include<iostream>
#include<vector>
#include<cstdlib>
#include"entity.h"


using namespace std;

// for storing databases
class database{

public:

    vector<student> STUDENTS ={};
    vector<room> ROOMS = {};
    vector<hostel> HOSTELS = {};
    vector<parent> PARENTS = {};

    student* getStudent(string studentId){
        for(int i=0; i<(int)STUDENTS.size(); i++){
            if(STUDENTS[i].studentId == studentId) return &STUDENTS[i];
        }
        return nullptr;
    }

    bool isValid(string studentId, string password){
        student* s = getStudent(studentId);
        if(s == nullptr) return false;
        return s->isValid(password);
    }

    void addRoom(int roomNo, int capacity){
        string roomId = "rid" + to_string(ROOMS.size()+1);
        ROOMS.push_back(room(roomId, roomNo, capacity));
    }

    void viewAllStudents(){
        for(int i=0; i<(int)STUDENTS.size(); i++) STUDENTS[i].display();
    }

    void viewAllRooms(){
        for(int i=0; i<(int)ROOMS.size(); i++) ROOMS[i].display();
    }

    void refresh(){
        int allotted = 0;
        for(int i=0; i<(int)STUDENTS.size() && allotted<5; i++){
            if(STUDENTS[i].bookingStatus && STUDENTS[i].roomNoBooked==0){
                vector<int> freeRooms;
                for(int j=0; j<(int)ROOMS.size(); j++){
                    if(!ROOMS[j].isAllotted) freeRooms.push_back(j);
                }
                if(freeRooms.size()==0) break;
                int pick = freeRooms[rand()%freeRooms.size()];
                ROOMS[pick].isAllotted = true;
                STUDENTS[i].roomNoBooked = ROOMS[pick].roomNo;
                allotted++;
            }
        }
    }

};
