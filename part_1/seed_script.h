#pragma once
// Standard and custom header file imports
#include<iostream>
#include"dummy_database.h"
#include"entity.h"


using namespace std;

class initializer{

public:

    void initStudent(database &db){

        for(int i=0; i<10; i++){
            string id = "uid" + to_string(i+1);
            student s(id, id, 1, false, 0);
            s.setPassword(id);
            db.STUDENTS.push_back(s);
        }

    }

    void initRoom(database &db){

        for(int i=0; i<5; i++){
            string roomId = "rid" + to_string(i+1);
            db.ROOMS.push_back(room(roomId, 100+i, 2));
        }

    }

    void initHostel(){

    }

    void initParent(){

    }

    void initialize(database &db){
        initStudent(db);
        initRoom(db);
    }
};
