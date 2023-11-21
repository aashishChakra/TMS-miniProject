#include"class.h"
#include"itinerary.h"
#include"book.h"
#include"login.h"

int admin(string id){
    choice = 1;
    book l;
    Itinerary a;
    while(choice != 0){
        design();
        moveCursor(60,12);
        cout<<"1. Add Itinerary";
        moveCursor(60,14);
        cout<<"2. List Itinerary";
        moveCursor(60,16);
        cout<<"3. Delete Itinerary";
        moveCursor(60,18);
        cout<<"4. Bookings Operation";
        moveCursor(60,20);
        cout<<"5. Change Password";
        moveCursor(60,22);
        cout<<"6. Logout";
        moveCursor(60,36);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                a.add_Itinerary();
                break;
            }
            case 2:{
                a.search_Itinerary("all");
                break;
            }
            case 3:{
                a.delete_Itinerary();
                break;
            }
            case 4:{
                choice = -1;
                topic = "Booking Operation";
                while(choice != 0){
                    design();
                    headline(topic);
                    moveCursor(60,16);
                    cout<<"1. Booking Requests";
                    moveCursor(60,18);
                    cout<<"2. Confirmed Booking";
                    moveCursor(60,20);
                    cout<<"3. Completed Booking";
                    moveCursor(60,22);
                    cout<<"4. Delete Booking";
                    moveCursor(60,24);
                    cout<<"5. Review Booking";
                    moveCursor(60,26);
                    cout<<"6. Exit";
                    moveCursor(60,36);
                    cout<<"Enter Your Choice: ";
                    cin>>choice;
                    switch(choice){
                        case 1:{
                            l.checkBooking("HOLDING");
                            choice = -1;
                            break;
                        }
                        case 2:{
                            l.checkBooking("CONFIRMED");
                            break;
                        }
                        case 3:{
                            l.checkBooking("COMPLETED");
                            break;
                        }
                        case 4:{
                            l.checkBooking("DELETE");
                            break;
                        }
                        case 5:{
                            l.reviewBooking();
                            break;
                        }
                        case 6:{
                            choice = 0;
                            break;
                        }
                        default:{
                            choice = -1;
                            break;
                        }
                    }
                }
                choice = -1;
                break;
            }
            case 5:{
                l.change_password(id);
                break;
            }
            case 6:{
                choice = 0;
                design();
                moveCursor(60,18);
                display = "Thank You For Joining With Us!!";
                print_slow(display);
                break;
            }
            default:{
                design();
                moveCursor(60,18);
                cout<<"Invalid Choice!!";
                moveCursor(60,36);
                cout<<"Press any Key to continue....";
                getch();
                break;
            }
        }
    }
    return (0);
}

int client(){
    book l;
    string option;
    Itinerary i;
    char ch,ch1;
    choice = -1;
    while (choice != 0){
        design();
        moveCursor(60,16);
        cout<<"1. Search Packages";
        moveCursor(60,18);
        cout<<"2. Book Package";
        moveCursor(60,20);
        cout<<"3. Review Booking";
        moveCursor(60,22);
        cout<<"4. Exit ";
        moveCursor(60,36);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{//list  
                topic = "general";
                i.search_Itinerary(topic);
                moveCursor(60,36);
                break;
            }
            case 2:{//book
                l.insert_booking();
                break;
            }
            case 3:{//checks ticket details
                l.reviewBooking();
                break;
            }
            case 4:{//exit
                choice = 0;
                design();
                display = "Thank You For Joining With Us!!";
                moveCursor(60,18);
                print_slow(display);
                break;
            }
            default:{
                design();
                moveCursor(60,18);
                cout<<"Invalid Choice!!";
                moveCursor(60,36);
                cout<<"Press any Key to continue....";
                getch();
                break;
            }
        }
    }
    return (0);
}

int main(){
    login l;
    string id;
    choice=1;
    design();
    moveCursor(50,18);
    display = "WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM....";
    print_slow(display);
    while(choice != 0){
        design();
        moveCursor(60,14);
        cout<<"1. CHECK ITINERARY ";
        moveCursor(60,16);
        cout<<"2. SIGN IN";
        moveCursor(60,18);
        cout<<"3. SIGN UP";
        moveCursor(60,20);
        cout<<"4. EXIT";
        moveCursor(60,36);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{//search itinerary
                client();
                choice = 2;
                break;
            }
            case 2:{//login
                id = l.signin();
                if(id != "404"){
                    admin(id);
                }
                choice = 1;
                break;
            }
            case 3:{//register
                system("cls");
                l.signup();
                choice = 3;
                break;
            }
            case 4:{
                system("cls");
                choice = 0;
                break;
            }
            default:{
                design();
                moveCursor(60,18);
                cout<<"Invalid Choice!!";
                moveCursor(60,36);
                cout<<"Press any Key to continue....";
                getch();
            }
        }
    }
    design();
    display = "Thank you for joinig with us!!";
    moveCursor(60,18);
    print_slow(display);
    return 0;
}