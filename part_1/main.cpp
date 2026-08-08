// Standard and custom header file imports

#include"entity.h"
#include"dummy_database.h"
#include"seed_script.h"
#include<ctime>
#include<cstdlib>



using namespace std;


int main()
{
    srand(time(0));

    // database and schema init
    database db;
    initializer init;
    init.initialize(db);

    // CLI interface

    int userChoice = 10;

    while(userChoice!=0){
        cout<< "Enter your catagory (1: User/Student | 2: Admin | 0: Exit): ";
        cin >> userChoice;
        cout << endl;


        if(userChoice == 1){
            // goes inside student portal
            cout << "Entered student portal" << endl;
            string usernameAndPassword;
            cout << "Enter username and password: (format: username,password): ";
            cin >> usernameAndPassword;
            int commaPos = usernameAndPassword.find(',');
            string studentId = usernameAndPassword.substr(0, commaPos);
            string password = usernameAndPassword.substr(commaPos+1);

            if(db.isValid(studentId, password)){
                student * studentUser = db.getStudent(studentId);
                int studentChoice = 10;
                while(studentChoice!=0){
                    cout << "1: View details | 2: Toggle booking status | 0: Logout" << endl;
                    cin >> studentChoice;
                    if(studentChoice==1) studentUser->display();
                    else if(studentChoice==2) studentUser->toggleBooking();
                    else if(studentChoice!=0) cout << "Invalid Choice" << endl;
                }
            }
            else{
                cout << "Invalid credentials" << endl;
            }

        }

        else if(userChoice == 2){

            // goes inside admin portal
            cout << "Entered admin portal" << endl;
            int adminChoice = 10;
            while(adminChoice!=0){
                cout << "1: View all students | 2: View all rooms | 3: Add room | 4: Refresh allocations | 0: Logout" << endl;
                cin >> adminChoice;
                if(adminChoice==1) db.viewAllStudents();
                else if(adminChoice==2) db.viewAllRooms();
                else if(adminChoice==3){
                    int roomNo, capacity;
                    cout << "Enter room no and capacity: ";
                    cin >> roomNo >> capacity;
                    db.addRoom(roomNo, capacity);
                }
                else if(adminChoice==4) db.refresh();
                else if(adminChoice!=0) cout << "Invalid Choice" << endl;
            }

        }
        
        else if(userChoice==0){
            break;
        }
        else{
            cout<< "Invalid Choice" << endl << endl;
        }
    }

    return 0;
}
