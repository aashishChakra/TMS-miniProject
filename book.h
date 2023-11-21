#ifndef BOOK
#define BOOK

#include"class.h"
//for clients to book packages


int book :: insert_booking(){//service for client to add booking
    Itinerary i;
    fstream fin,fout;
    topic = "Booking Form";
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
    }while(checkCode(bookingId, "booking"));
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
    status = "HOLDING";
    fout.open("zbooking_detail.txt",ios::out | ios::app);
    fout<<bookingId<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";"<<number<<";"<<packageId<<";"<<status<<";\n";
    fout.close();
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    design();
    moveCursor(60,17);
    cout<<"THANK YOU FOR BOOKING WITH US";
    moveCursor(60,19);
    cout<<"YOUR BOOKING ID IS: "<<bookingId;
    moveCursor(50,25);
    cout<<"NOTE: You will receive a call to confirm booking...";
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
} 

string book :: checkBooking(string type){//service for admin to see list of booking
//type includes "HOLDING", "CONFIRMED", "COMPLETED", "DELETE"
    if(type == "DELETE"){
        topic = "Delete Booking";
    }
    else{
        topic = "Check Booking";
    }
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
            if(status == type && type != "DELETE"){
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
                displayBooking(count);
                count++;
            }
            if(type == "DELETE"){
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
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
                cout<<"Enter your choice: ";
                cin>>display;
                display = upper(display);
                if(display == "EXIT" || display == "E"){
                    ID = "404";
                    return (ID);
                }
                else if(display == "NEXT" || display == "N"){
                    design();
                    headline(topic);
                    bookingHead();
                }
                else if(display == "ID" || display == "I"){
                    break;
                }
                else{
                    goto ERROR_LOOP;
                }
            }
            if(fin.eof()){
                break;
            }
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
STATUS_ERROR:
    moveCursor(60,36);
    cout<<"Enter Booking ID: ";
    cin>>ID;
    ID=upper(ID);
    if(ID == "EXIT" || ID == "E"){
        ID = "404";
        return (ID);
    }
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
            if(type != "DELETE"){
                if((ID == row[0]) && (type == row[7])){
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
                    cout<<"'H' to Hold.";
                    moveCursor(8,20);
                    cout<<"'C' to Confirm.";
                    moveCursor(8,22);
                    cout<<"'F' to Complete.";
                    moveCursor(8,24);
                    cout<<"'D' to Delete.";
    INPUT_ERROR:
                    moveCursor(60,36);
                    cout<<"Enter your choice: ";
                    ch =getch();
                    ch=toupper(ch);
                    if(ch == 'C'){
                        count = 1;
                        type = "CONFIRMED";
                        fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"CONFIRMED"<<";\n";
                    }
                    else if(ch == 'H'){
                        count = 1;
                        type = "HOLDING";
                        fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"HOLDING"<<";\n";
                    }
                    else if(ch == 'F'){
                        count = 1;
                        type = "COMPLETED";
                        fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<"COMPLETED"<<";\n";
                    }
                    else if(ch == 'D'){
                        count = 1;
                        type = "DELETE";
                    }
                    else{
                        goto INPUT_ERROR;
                    }
                }
                else{
                    fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<row[7]<<";\n";
                }
            }
            else if(type == "DELETE"){
                if(ID != row[0]){
                    fout<<row[0]<<";"<<row[1]<<";"<<row[2]<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";"<<row[7]<<";\n";
                }
                else if(ID == row[0]){
                    count = 1;
                }
                type = "DELETE";
            }
            if(fin.eof()){
                break;
            }
        }
    }
    fin.close();
    fout.close();
    if(count == -1){
        goto STATUS_ERROR;
    }
    else if(count == 1){
        design();
        headline(topic);
        moveCursor(60,18);
        cout<<"Booking "<<type<< " for Booking Id: "<<ID;
    }
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    remove("zbooking_detail.txt");
    rename("zbooking_detail2.txt","zbooking_detail.txt");
    return(type);
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

void book :: reviewBooking(){
    topic="Review Booking";
    string ID;
    fstream fin,ifin;
    design();
    headline(topic);
    moveCursor(60,20);
    cout<<"Enter Booking ID: ";
    cin>>bookingId;
    bookingId=upper(bookingId);
    fin.open("zbooking_detail.txt",ios::in);
    vector<string>row;
    string line, word,temp;
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
            if(bookingId == row[0]){
                ID=row[6];
                count = 0;
                design();
                headline(topic);
                moveCursor(32,6);
                cout<<"BOOKING ID";
                moveCursor(45,6);
                cout<<": "<<row[0];
                moveCursor(32,8);
                cout<<"FIRST NAME";
                moveCursor(45,8);
                cout<<": "<<row[1];
                moveCursor(32,10);
                cout<<"LAST NAME";
                moveCursor(45,10);
                cout<<": "<<row[2];
                moveCursor(32,12);
                cout<<"ADDRESS";
                moveCursor(45,12);
                cout<<": "<<row[3];
                moveCursor(32,14);
                cout<<"PHONE";
                moveCursor(45,14);
                cout<<": "<<row[4];
                moveCursor(32,16);
                cout<<"TICKETS";
                moveCursor(45,16);
                cout<<": "<<row[5];
                moveCursor(32,18);
                cout<<"PACKAGE ID";
                moveCursor(45,18);
                cout<<": "<<row[6];
                moveCursor(32,20);
                cout<<"STATUS";
                moveCursor(45,20);
                cout<<": "<<row[7];
            }
            if(fin.eof()){
                break;
            }
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
    else if(count == 0){
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
        design();
        ifin.open("zitinerary.txt",ios::in);
        while(!ifin.eof()){
            row.clear();
            getline(ifin,line);
            count = 0;
            stringstream s(line);
            while(getline(s,word,';'))
            {
                row.push_back(word);
                count++;
            }
            if(!ifin.eof()){
                if(ID == row[0]){
                    design();
                    headline(topic);
                    moveCursor(32,6);
                    cout<<"PACKAGE ID";
                    moveCursor(47,6);
                    cout<<": "<<row[0];
                    moveCursor(32,7);
                    cout<<"PACKAGE TITLE";
                    moveCursor(47,7);
                    cout<<": "<<row[1];
                    moveCursor(32,8);
                    cout<<"STARTING PLACE";
                    moveCursor(47,8);
                    cout<<": "<<row[2];
                    moveCursor(32,9);
                    cout<<"DESTINATION";
                    moveCursor(47,9);
                    cout<<": "<<row[3];
                    moveCursor(32,10);
                    cout<<"NUMBER OF DAYS";
                    moveCursor(47,10);
                    cout<<": "<<row[4];
                    moveCursor(32,11);
                    cout<<"EXPENSE(RS)";
                    moveCursor(47,11);
                    cout<<": "<<row[5];
                    Y=13;
                    moveCursor(32,Y);
                    for(int i=6;i<count;i++){
                        cout<<row[i];
                        Y+=1;
                        moveCursor(32,Y);
                    }
                    break;
                }
                if(ifin.eof()){
                    break;
                }
            }
        }
        ifin.close();
        if(count == -1){
            design();
            moveCursor(60,18);
            cout<<"Package Not Found";
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
}
    
#endif
