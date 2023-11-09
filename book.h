#ifndef BOOK
#define BOOK

#include"class.h"
//for clients to book packages


void book :: insert_booking(){//service for client to add booking
    design();
    topic = "Booking Form";
    headline(topic);
    moveCursor(32,6);
    cout<<"Package Id: ";
    cin>>packageId/*=get_packageId()*/;
    moveCursor(32,8);
    fname=get_fname();
    moveCursor(32,10);
    lname=get_lname();
    moveCursor(32,12);
    address=get_address();
    moveCursor(32,14);
    phone=get_phone();
    // moveCursor(32,16);
    // nationality=get_nationality();
    moveCursor(32,18);
    fstream fout;
    fout.open("zbooking_detail.txt",ios::out | ios::app);
    fout<<packageId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<nationality<<"\n";
    fout.close();
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    design();
    moveCursor(60,18);
    cout<<"THANK YOU FOR BOOKING WITH US";
    moveCursor(50,24);
    cout<<"NOTE: You will receive a call to confirm booking.";
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
} 

void book :: check_booking(){//service for admin to see list of booking
    topic = "Check Booking";
    design();
    headline(topic);
    string ID;
    fstream fin;
    moveCursor(30,6);
    cout<<"Package Id: ";
    cin>>ID;
    design();
    headline(topic);
    // ID=get_packageId();
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
        if(!fin.eof()){
            packageId=row[0];
            fname=row[1];
            lname=row[2];
            address=row[3];
            phone=row[4];
            nationality=row[5];
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
        design();
        headline(topic);
        moveCursor(60,18);
        cout<<"Booking Unavailable!!";
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
    fin.close();
    getch();
}

void book :: bookingHead(){//prints the head in booking 
    X = 30;
    moveCursor(X + 2,6);
    cout<<"Package ID";
    moveCursor(X + 17,6);
    cout<<"First Name";
    moveCursor(X + 37,6);
    cout<<"Last Name";
    moveCursor(X + 57,6);
    cout<<"Address";
    moveCursor(X + 72,6);
    cout<<"Phone";
    moveCursor(X + 82,6);
    cout<<"Email";
}

void book :: displayBooking(int a){//displays the booking details
    X = 30;
    a += 8;
    moveCursor(X+2,a);
    cout<<packageId;
    moveCursor(X+17,a);
    cout<<fname;
    moveCursor(X+37,a);
    cout<<lname;
    moveCursor(X+57,a);
    cout<<address;
    moveCursor(X+72,a);
    cout<<phone;
    moveCursor(X+82,a);
    cout<<nationality<<endl;
}
#endif
