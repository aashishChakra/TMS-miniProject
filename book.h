#ifndef BOOK
#define BOOK

#include"class.h"
//for clients to book packages


int book :: insert_booking(){//service for client to add booking
    Itinerary i;
    string type = "book";
    packageId = i.search_Itinerary("book");
    topic = "Booking Form";
    if(packageId == "404"){
        return (0);
    }
    design();
    headline(topic);
    do{
        bookingId=generateCode("booking");
    }while(checkCode(userId, "userId"));
    moveCursor(32,8);
    fname=get_fname();
    moveCursor(32,10);
    lname=get_lname();
    moveCursor(32,12);
    address=get_address();
    moveCursor(32,14);
    phone=get_phone();
    moveCursor(32,16);
    cout<<"Number of Tickets: ";
    number=get_num(1);
    status = "WAITING";
    moveCursor(32,18);
    fstream fout;
    fout.open("zbooking_detail.txt",ios::out | ios::app);
    fout<<packageId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<number<<";"<<status<<"\n";
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

void book :: check_booking(string type){//service for admin to see list of booking
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
    count = -1;
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
            number=row[5];
            status=row[6];
            if(ID == packageId){
                displayBooking(count);
                count++;
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(count == -1){
        design();
        headline(topic);
        moveCursor(60,18);
        cout<<"Booking Unavailable!!";
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
    else{
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
}

void book :: bookingHead(){//prints the head in booking 
    X = 30;
    moveCursor(X + 2,6);
    cout<<"Package ID";
    moveCursor(X + 15,6);
    cout<<"First Name";
    moveCursor(X + 29,6);
    cout<<"Last Name";
    moveCursor(X + 45,6);
    cout<<"Address";
    moveCursor(X+57,6);
    cout<<"Phone";
    moveCursor(X + 67,6);
    cout<<"Number";
    moveCursor(X + 82,6);
    cout<<"Status";
}

void book :: displayBooking(int a){//displays the booking details
    X = 30;
    a += 8;
    moveCursor(X+2,a);
    cout<<packageId;
    moveCursor(X+15,a);
    cout<<fname;
    moveCursor(X+29,a);
    cout<<lname;
    moveCursor(X+45,a);
    cout<<address;
    moveCursor(X+57,a);
    cout<<phone;
    moveCursor(X+67,a);
    cout<<number;
    moveCursor(X+82,a);
    cout<<status;
}
#endif
