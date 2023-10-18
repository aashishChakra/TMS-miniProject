#ifndef BOOK
#define BOOK
#include"class.h"

void book :: bookingHead(){
    system("cls");
    moveCursor(30,2);
    cout<<"Bookings";
    moveCursor(1,4);
    cout<<"Package ID";
    moveCursor(15,4);
    cout<<"First Name";
    moveCursor(27,4);
    cout<<"Last Name";
    moveCursor(40,4);
    cout<<"Address";
    moveCursor(55,4);
    cout<<"Phone";
    moveCursor(70,4);
    cout<<"Nationality";
}

void book :: displayBooking(int a){
    a+=5;
    moveCursor(1,a);
    cout<<packageId;
    moveCursor(15,a);
    cout<<fname;
    moveCursor(27,a);
    cout<<lname;
    moveCursor(40,a);
    cout<<address;
    moveCursor(55,a);
    cout<<phone;
    moveCursor(70,a);
    cout<<nationality<<endl;
}
void book :: insert_booking(){
    system("cls");
    cout<<"\t\t\t\tFill the following form."<<endl;
    packageId=get_packageId();
    fname=get_fname();
    lname=get_lname();
    address=get_address();
    phone=get_phone();
    nationality=get_nationality();
    fstream add;
    add.open("booking_detail.txt",ios::out | ios::app);
    add<<packageId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<nationality<<"\n";
    add.close();
    getch();
    system("CLS");
    moveCursor(50,10);
    cout<<"\t\t\tTHANK YOU FOR BOOKING\n";
    moveCursor(50,12);
    cout<<"\t\tNOTE:You will receive a call to confirm booking\n";
    getch();
} 

void book :: check_booking(){
    system("cls");
    moveCursor(30,2);
    cout<<"Booking List";
    string ID;
    fstream check;
    ID=get_packageId();
    check.open("booking_detail.txt",ios::in);
    vector<string>row;
    string line, word,temp;
    bookingHead();
    count = 0;
    while(!check.eof()){
        row.clear();
        getline(check,line);
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
        }
        packageId=row[0];
        fname=row[1];
        lname=row[2];
        address=row[3];
        phone=row[4];
        nationality=row[5];
        if(!check.eof()){
            if(ID == packageId){
                displayBooking(count);
                count++;
            }
        }
        if(check.eof()){
            break;
        }
    }
    if(count == -1){
        cout<<"Booking Unavailable!";
        getch();
    }
    check.close();
    getch();
}
#endif