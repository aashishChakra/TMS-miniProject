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
    fout<<bookingId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<number<<";"<<packageId<<status<<"\n";
    fout.close();
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    design();
    moveCursor(60,18);
    cout<<"THANK YOU FOR BOOKING WITH US";
    moveCursor(50,24);
    cout<<"NOTE: You will receive a call to confirm booking...";
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
} 

string book :: checkBooking(string type){//service for admin to see list of booking
    topic = "Check Booking";
    string ID;
    fstream fin,fout;
    design();
    headline(topic);
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
            bookingId=row[0];
            fname=row[1];
            lname=row[2];
            address=row[3];
            phone=row[4];
            number=row[5];
            packageId=row[6];
            status=row[7];
            if(status == type){
                moveCursor(2,18);
                cout<<"Enter [EXIT] to exit";
                displayBooking(count);
                count++;
            }
            if(count == 26){
ERROR_LOOP:
                count = 0;
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
                moveCursor(2,20);
                cout<<"-Enter [NEXT] to";
                moveCursor(3,21);
                cout<<"continue to next page";
                moveCursor(2,23);
                cout<<"-Enter [ID] to confirm";
                moveCursor(3,24);
                cout<<"booking";
                moveCursor(60,36);
                cout<<"Enter Booking ID:";
                cin>>display;
                display = upper(display);
                if(display == "EXIT"){
                    ID = "404";
                    return (ID);
                }
                else if(display == "NEXT"){
                    design();
                    headline(topic);
                    bookingHead();
                }
                else if(display == "ID"){
                    break;
                }
                else{
                    goto ERROR_LOOP;
                }
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
        count = -1;
        moveCursor(60,36);
        cout<<"Enter Booking ID: ";
        cin>>ID;
        ID=upper(ID);
        if(ID == "EXIT"){
            ID = "404";
            return (ID);
        }
        else{
            fin.open("zbooking_detail.txt",ios::in);
            fout.open("zbooking_detail2.txt",ios::out);
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
                    if(ID == row[0]){
                        design();
                        headline(topic);
                        moveCursor(30,10);
                        cout<<"Booking ID: "<<row[0];
                        moveCursor(30,12);
                        cout<<"First Name: "<<row[1];
                        moveCursor(30,14);
                        cout<<"Last Name: "<<row[2];
                        moveCursor(30,16);
                        cout<<"Address: "<<row[3];
                        moveCursor(30,18);
                        cout<<"Phone: "<<row[4];
                        moveCursor(30,20);
                        cout<<"Number of Tickets: "<<row[5];
                        moveCursor(30,22);
                        cout<<"Package ID: "<<row[6];
                        moveCursor(30,24);
                        cout<<"Status: "<<row[7];
                        moveCursor(8,18);
                        cout<<"'C' to Confirm.";
                        moveCursor(8,20);
                        cout<<"'H' to Hold.";
                        moveCursor(8,22);
                        cout<<"'D' to Cancle.";
                        moveCursor(60,36);
                        cout<<"Enter your choice: ";
                        ch =getch();
                        ch=toupper(ch);
                        if(ch == 'C'){
                            count = 0;
                            fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"CONFIRMED"<<"\n";
                        }
                        else if(ch == 'H'){
                            fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"WAITING"<<"\n";
                        }
                        else if(ch == 'D'){
                            count = 1;
                            fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"CANCELLED"<<"\n";
                        }
                    }
                    else{
                        fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<row[7]<<"\n";
                    }
                }
                if(fin.eof()){
                    break;
                }
            }
            fin.close();
            fout.close();
            remove("zbooking_detail.txt");
            rename("zbooking_detail2.txt","zbooking_detail.txt");
            design();
            headline(topic);
            moveCursor(60,18);
            if(count == 0){
                cout<<"Booking Confirmed for Booking Id: "<<ID;
            }
            else if(count == -1){
                cout<<"Exiting Booking Operation";
            }
            else if(count == 1){
                cout<<"Booking Deleted for Booking Id: "<<ID;
            }
            moveCursor(60,36);
            cout<<"Press any key to continue....";
        }
    }
}

void book :: bookingHead(){//prints the head in booking 
    X = 30;
    moveCursor(X ,6);
    cout<<"Booking ID";
    moveCursor(X + 13,6);
    cout<<"First Name";
    moveCursor(X + 25,6);
    cout<<"Last Name";
    moveCursor(X + 40,6);
    cout<<"Address";
    moveCursor(X+50,6);
    cout<<"Phone";
    moveCursor(X + 64,6);
    cout<<"Number";
    moveCursor(X + 72,6);
    cout<<"Package ID";
    moveCursor(X + 84,6);
    cout<<"Status";
}

void book :: displayBooking(int a){//displays the booking details
    X = 30;
    a += 8;
    moveCursor(X,a);
    cout<<bookingId;
    moveCursor(X+13,a);
    cout<<fname;
    moveCursor(X+25,a);
    cout<<lname;
    moveCursor(X+40,a);
    cout<<address;
    moveCursor(X+50,a);
    cout<<phone;
    moveCursor(X+64,a);
    cout<<number;
    moveCursor(X+72,a);
    cout<<packageId;
    moveCursor(X+84,a);
    cout<<status;
}

#endif
