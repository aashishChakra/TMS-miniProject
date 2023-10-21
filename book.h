#ifndef BOOK
#define BOOK

#include"class.h"
//for clients to book packages

void book :: displayBooking(int a){//displays the booking details
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

void book :: insert_booking(){//service for client to add booking
    system("cls");
    moveCursor(50,2);
    cout<<"Fill the following form."<<endl;
    packageId=get_packageId();
    cout<<endl;
    fname=get_fname();
    cout<<endl;
    lname=get_lname();
    cout<<endl;
    address=get_address();
    cout<<endl;
    phone=get_phone();
    cout<<endl;
    nationality=get_nationality();
    cout<<endl;
    fstream fout;
    fout.open("zbooking_detail.txt",ios::out | ios::app);
    fout<<packageId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<nationality<<"\n";
    fout.close();
    cout<<"Press any key to continue...";
    getch();
    system("cls");
    moveCursor(50,10);
    cout<<"THANK YOU FOR BOOKING WITH US";
    moveCursor(50,12);
    cout<<"NOTE: You will receive a call to confirm booking.";
    getch();
} 

void book :: check_booking(){//service for admin to see list of booking
    system("cls");
    string ID;
    fstream fin;
    ID=get_packageId();
    fin.open("zbooking_detail.txt",ios::in);
    vector<string>row;
    string line, word,temp;
    bookingHead();
    count = 0;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
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
        if(!fin.eof()){
            if(ID == packageId){
                displayBooking(count);
                count++;
            }
        }
        if(fin.eof()){
            break;
        }
    }
    if(count == -1){
        moveCursor(50,2);
        cout<<"Bookings";
        moveCursor(50,10);
        cout<<"Booking Unavailable!";
        moveCursor(50,15);
        cout<<"Press any key to continue...";
        getch();
    }
    fin.close();
    getch();
}

void book :: bookingHead(){//prints the head in booking 
    system("cls");
    moveCursor(50,2);
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

#endif