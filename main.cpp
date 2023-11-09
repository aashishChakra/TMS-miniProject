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
        cout<<"2. Edit Itinerary";
        moveCursor(60,16);
        cout<<"3. Delete Itinerary";
        moveCursor(60,18);
        cout<<"4. View Booking";
        moveCursor(60,20);
        cout<<"5. Change Password";
        moveCursor(60,22);
        cout<<"6. Logout";
        moveCursor(60,24);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                system("cls");
                a.add_Itinerary();
                break;
            }
            case 2:{
                system("cls");
                a.edit_Itinerary();
                break;
            }
            case 3:{
                system("cls");
                a.delete_Itinerary();
                break;
            }
            case 4:{
                system("cls");
                l.check_booking();
                break;
            }
            case 5:{
                system("cls");
                l.change_password(id);
                break;
            }
            case 6:{
                choice = 0;
                design();
                moveCursor(60,18);
                cout<<"Thank You For Joining With Us!!";
                moveCursor(60,36);
                cout<<"Press any Key to continue....";
                getch();
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
    Itinerary i;
    char ch,ch1;
    choice = 1;
    while (choice != 0){
        design();
        moveCursor(60,14);
        cout<<"1. List Package";
        moveCursor(60,16);
        cout<<"2. Search Package";
        moveCursor(60,18);
        cout<<"3. Exit";
        moveCursor(60,20);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{//list
                system("cls");
                i.list_Itinerary();
                SEARCH:
                    design();
                    moveCursor(60,18);
                    cout<<"Do you want to view detail of package(Y/N): ";
                    ch=getch();
                    cout<<ch;
                    if(ch == 'y' || ch == 'Y'){
                        i.search_Itinerary();
                    }
                    else if(ch == 'n' || ch == 'N'){
                        design();
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        design();
                        moveCursor(60,18);
                        cout<<"Invalid Choice!!";
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        goto SEARCH;
                    }
                BOOK1:
                    design();
                    moveCursor(60,18);
                    cout<<"Do you want to book this package(Y/N): ";
                    ch1=getch();
                    cout<<ch1;
                    if(ch1 == 'y' || ch1 == 'Y'){
                        l.insert_booking();
                        break;
                    }
                    else if(ch1 == 'n' || ch1 == 'N'){
                        design();
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        design();
                        moveCursor(60,18);
                        cout<<"Invalid Choice!!";
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        goto BOOK1;
                    }
            }
            case 2:{//search
                system("cls");
                i.search_Itinerary();
                BOOK2:
                    design();
                    moveCursor(50,18);
                    cout<<"Do you want to book this package(Y/N): ";
                    ch=getch();
                    cout<<ch;
                    if(ch == 'y' || ch == 'Y'){
                        l.insert_booking();
                        break;
                    }
                    else if(ch == 'n' || ch == 'N'){
                        design();
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        design();
                        moveCursor(60,18);
                        cout<<"Invalid Choice!!";
                        moveCursor(60,36);
                        cout<<"Press any key to continue....";
                        getch();
                        goto BOOK2;
                    }
            }
            case 3:{//exit
                choice = 0;
                design();
                moveCursor(60,18);
                cout<<"Thank You For Joining With Us!!";
                moveCursor(60,36);
                cout<<"Press any Key to continue....";
                getch();
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
    cout<<"WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM....";
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    while(choice != 0){
        design();
        moveCursor(60,14);
        cout<<"1. ADMIN";
        moveCursor(60,16);
        cout<<"2. CLIENT";
        moveCursor(60,18);
        cout<<"3. REGISTER";
        moveCursor(60,20);
        cout<<"4. EXIT";
        moveCursor(60,22);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                id = l.signin();
                admin(id);
                choice = 1;
                break;
            }
            case 2:{//search itinerary
                client();
                choice = 2;
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
            }
        }
    }
    design();
    moveCursor(60,18);
    cout<<"Thank you for choosing us!!";
    moveCursor(60,36);
    cout<<"Press any Key to continue....";
    getch();
    return 0;
}