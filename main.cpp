#include"class.h"
#include"itinerary.h"
#include"book.h"
#include"login.h"

int admin(string id){
    choice = 1;
    book l;
    Itinerary a;
    while(choice != 0){
        system("cls");
        cout<<"1. Add Itinerary"
        <<endl<<"2. Edit Itinerary"
        <<endl<<"3. Delete Itinerary"
        <<endl<<"4. View Booking"
        <<endl<<"5. Change Password"
        <<endl<<"6. Logout"
        <<endl<<"Enter your choice: ";
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
                system("cls");
                choice = 0;
                moveCursor(50,15);
                cout<<"Press any Key to Continue...";
                getch();
                break;
            }
            default:{
                system("cls");
                moveCursor(50,10);
                cout<<"Invalid Choice!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue...";
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
        system("cls");
        moveCursor(50,6);
        cout<<"1. List Package";
        moveCursor(50,7);
        cout<<"2. Search Package";
        moveCursor(50,8);
        cout<<"3. Exit";
        moveCursor(50,9);
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{//list
                system("cls");
                i.list_Itinerary();
                SEARCH:
                    cout<<endl<<"\n\t\t\tDo you want to view detail of package(Y/N): ";
                    ch=getch();
                    cout<<ch;
                    if(ch == 'y' || ch == 'Y'){
                        i.search_Itinerary();
                    }
                    else if(ch == 'n' || ch == 'N'){
                        system("cls");
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        system("cls");
                        moveCursor(50,10);
                        cout<<"Invalid Choice!";
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        goto SEARCH;
                    }
                    getch();
                BOOK1:
                    cout<<"Do you want to book this package(Y/N): ";
                    ch1=getch();
                    cout<<ch1;
                    if(ch1 == 'y' || ch1 == 'Y'){
                        l.insert_booking();
                        break;
                    }
                    else if(ch1 == 'n' || ch1 == 'N'){
                        system("cls");
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        system("cls");
                        moveCursor(50,10);
                        cout<<"Invalid Choice!";
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        goto BOOK1;
                    }
                    getch();
            }
            case 2:{//search
                system("cls");
                i.search_Itinerary();
                BOOK2:
                    cout<<endl<<"Do you want to book this package(Y/N): ";
                    ch=getch();
                    cout<<ch;
                    if(ch == 'y' || ch == 'Y'){
                        l.insert_booking();
                        break;
                    }
                    else if(ch == 'n' || ch == 'N'){
                        system("cls");
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        break;
                    }
                    else{
                        system("cls");
                        moveCursor(50,10);
                        cout<<"Invalid Choice!";
                        moveCursor(50,15);
                        cout<<"Press any key to continue....";
                        getch();
                        goto BOOK2;
                    }
            }
            case 3:{//exit
                system("cls");
                choice = 0;
                moveCursor(50,15);
                cout<<"Press any Key to Continue...";
                getch();
                break;
            }
            default:{
                system("cls");
                moveCursor(50,10);
                cout<<"Invalid Choice!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue...";
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
    system("cls");
    moveCursor(50,10);
    cout<<"WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM...";
    moveCursor(50,20);
    cout<<"Press any key to continue....";
    getch();
    while(choice != 0){
        system("CLS");
        moveCursor(50,6);
        cout<<"1. ADMIN";
        moveCursor(50,7);
        cout<<"2. CLIENT";
        moveCursor(50,8);
        cout<<"3. REGISTER";
        moveCursor(50,9);
        cout<<"4. EXIT";
        moveCursor(50,10);
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
                l.signup(false);
                choice = 3;
                break;
            }
            case 4:{
                system("cls");
                choice = 0;
                break;
            }
            default:{
                system("cls");
                moveCursor(50,10);
                cout<<"Invalid Choice!!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue...";
            }
        }
    }
    system("cls");
    moveCursor(50,10);
    cout<<"Thank you for choosing us!!";
    getch();
    return 0;
}