#include"class.h"

#include"itinerary.h"
#include"book.h"
#include"login.h"

int admin(){
    int choice=1;
    book l;
    Itinerary a;
    while(choice != 0){
        system("cls");
        cout<<"1. Add Itinerary"
        <<endl<<"2. Edit Itinerary"
        <<endl<<"3. Delete Itinerary"
        <<endl<<"4. Logout"
        <<endl<<"5. View Booking"
        <<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                system("cls");
                a.add_Itinerary();
                getch();
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
                getch();
                break;
            }
            case 4:{
                system("cls");
                choice = 0;
                moveCursor(50,10);
                cout<<"Press any Key to Continue";
                getch();
                break;
            }
            case 5:{
                system("cls");
                l.check_booking();
                break;
            }
            default:{
                system("cls");
                moveCursor(50,10);
                cout<<"Invalid Choice!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue";
                getch();
                break;
            }
        }
    }
    return 0;
}

int main(){
    bool status;
    book l;
    Itinerary i;
    char ch,ch1;
    int choice=1,option = 1;;
    while(choice != 0){
        system("CLS");
        cout<<"1. List Package"
        <<endl<<"2. Search Package"
        <<endl<<"3. Login"
        <<endl<<"4. Register"
        <<endl<<"5. Exit"
        <<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:{//list itinerary
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
                    moveCursor(50,10);
                    cout<<"Press any key to continue....";
                    getch();
                    break;
                }
                else{
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Invalid Choice!";
                    getch();
                    goto SEARCH;
                }
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
                    moveCursor(50,10);
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
                break;
            }
            case 2:{//search itinerary
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
                    moveCursor(50,10);
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
                getch();
                break;
            }
            case 3:{//login
                if(l.signin()){
                    admin();
                }
                break;
            }
            case 4:{//register
                system("cls");
                l.signup(false);
                getch();
                break;
            }
            case 5:{
                choice = 0;
                break;
            }
            default:{
                system("cls");
                moveCursor(50,15);
                cout<<"Invalid Choice!!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue";
            }
        }
    }
    system("cls");
    moveCursor(50,10);
    cout<<"Thank you for choosing us!!";
    getch();
    return 0;
}