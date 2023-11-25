#ifndef ITINERARY
#define ITINERARY

#include"class.h"

void Itinerary :: itineraryHead(){
//accessed by list only
//to give head for list
    X = 30;
    moveCursor(X + 2,6);
    cout<<"PACKAGE ID";
    moveCursor(X + 17,6);
    cout<<"PACKAGE TITLE";
    moveCursor(X + 37,6);
    cout<<"STARTING PLACE";
    moveCursor(X + 57,6);
    cout<<"DESTINATION";
    moveCursor(X + 72,6);
    cout<<"DAYS";
    moveCursor(X + 82,6);
    cout<<"EXPENSE(RS)";
}

void Itinerary :: displayItinerary(int a){
//accessed by list
//to display list in systymetic manner
    X = 30;
    a += 8;
    moveCursor(X + 2,a);
    cout<<packageId;
    moveCursor(X + 17,a);
    cout<<title;
    moveCursor(X + 37,a);
    cout<<start;
    moveCursor(X + 57,a);
    cout<<end;
    moveCursor(X + 72,a);
    cout<<days;
    moveCursor(X + 82,a);
    cout<<expense;
}

void Itinerary :: add_Itinerary(){
//adds new package to system
    topic="Add Itinerary";
    fstream fout;
    login l;
    design();
    headline(topic);
    moveCursor(60,6);
    cout<<"Fill the below details:";
    moveCursor(50,7);
    // cout<<"*NOTE:Use [space] before every entries*";
    do{
        packageId=generateCode("package");
    }while(checkCode(packageId,"package"));
    moveCursor(32,8);
    cout<<"PACKAGE TITLE";
    moveCursor(47,8);
    cout<<": ";
    title=get_text("space");
    moveCursor(32,10);
    cout<<"STARTING PLACE";
    moveCursor(47,10);
    cout<<": ";
    start=get_text("space");
    moveCursor(32,12);
    cout<<"DESTINATION";
    moveCursor(47,12);
    cout<<": ";
    end=get_text("space");
    moveCursor(32,14);
    cout<<"DAYS";
    moveCursor(47,14);
    cout<<": ";
    days=get_num(2);
    moveCursor(32,16);
    cout<<"EXPENSE(RS)";
    moveCursor(47,16);
    cout<<": ";
    expense=get_num(7);
    fout.open("zitinerary.txt",ios::out | ios::app);//stores normal details
    fout<<packageId<<";"<<title<<";"<<start<<";"<<end<<";"<<days<<";"<<expense<<";";    
// list of location and important things are stored in seperate file for convinence
// package id is store in begining to avoid conflicts
    day=stoi(days);
    moveCursor(32,18);
    cout<<"Add Every day Destination:";
    for(int i=0;i<day;i++){
        
        cout<<"\n \t\t\t\t Destination in Day"<<i+1<<" : ";
        reach=get_text("space");
        fout<<"DAY "<<i+1<<" : "<<reach<<";";
    }
    fout<<";IMPORTANT THINGS: "<<";";
    cout<<"\n\t\t\t\t\t***Note:Use '; ' to seperate sentence***\t\t\t\t";
    cout<<"\n\t\t\t\tIMPORTANT THINGS:";
    cin.ignore();
    getline(cin,things);
    things = upper(things);
    fout<<things<<";";
    fout<<"COST INCLUDES: ;";
    cout<<"\n\t\t\t\t\t***Note:Use '; ' to seperate sentence***\t\t\t\t";
    cout<<"\n\t\t\t\tCOST INCLUDES:";
    cin.ignore();
    getline(cin,things);
    things = upper(things);
    fout<<things<<";\n";
    fout.close();
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    design();
    headline(topic);
    moveCursor(60,18);
    display = "Itinerary Added Successfully";
    print_slow(display);
}

string Itinerary :: delete_Itinerary(){
    topic = "Delete Itinerary";
    fstream fin,fout;
    vector<string>row;
    string line, word;
    int check=-1;
    string search, ID;
DELETE_TOP:
    design();
    headline(topic);
    moveCursor(60,20);
    // cout<<"Enter Package Title: ";
    // search=get_text("space");
    // ID = list_Itinerary(search,search,type);
    ID =searching();
    if(ID == "EXIT"){
        return ("EXIT");
    }
    // design();
    // headline(topic);
    // moveCursor(60,36);
    // cout<<"Enter Package ID: ";
    // cin>>ID;
    // ID=upper(ID);
    fin.open("zitinerary.txt",ios::in);
    fout.open("zitinerary2.txt",ios::out);
    check =- 1;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        count = 0;
        while(getline(s,word,';'))
        {
            row.push_back(word);
            count++;
        }
        packageId=row[0];
        title=row[1];
        start=row[2];
        end=row[3];
        days=row[4];
        expense=row[5];
        if(!fin.eof()){
            if((ID != packageId) && (search != title || search != start || search != end)){
                for(int i = 0; i<count;i++){
                    fout<<row[i]<<";";
                }
                fout<<"\n";
            }
            else if(ID == packageId){
                check += 1;
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    fout.close();
    remove("zitinerary.txt");
    rename("zitinerary2.txt","zitinerary.txt");
    if(check == -1){
        design();
        moveCursor(60,10);
        cout<<"*** Package Not Found!! ***";
        moveCursor(60,20);
        cout<<"Press any key to continue....";
        getch();
        delete_Itinerary();
    }
    else{
        design();
        headline(topic);
        moveCursor(60,20);
        cout<<"Package Id: "<<ID<<" Deleted Successfully!";
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
    choice = -1;
    return (ID);
}

string Itinerary :: searchforBooking(){//accessed by booingForm only
    topic="Book Package";
    fstream fin;
    string search,ID;
    design();
    headline(topic);
    moveCursor(60,20);
    cout<<"Enter Package Title: ";
    search = get_text("space");
TRY:
    fin.open("zitinerary.txt", ios::in);
    vector<string>row;
    string line, word,temp;
    design();
    headline(topic);
    itineraryHead();
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
            title=row[1];
            start=row[2];
            end=row[3];
            days=row[4];
            expense=row[5];
            if(search == row[1] || search == row[2] || search == row[3]){
                displayItinerary(count);
                count += 1;
            }
            if(count == 26){
ERROR_LOOP:
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
                moveCursor(2,20);
                cout<<"-Enter [NEXT] to";
                moveCursor(3,21);
                cout<<"continue to next page";
                moveCursor(2,23);
                cout<<"-Enter [ID] to book";
                moveCursor(60,36);
                cout<<"Enter your choice:";
                display = get_text("nospace");
                if(display == "EXIT" || display == "E"){
                    return ("EXIT");
                }
                else if(display == "NEXT" || display == "N"){
                    design();
                    headline(topic);
                    itineraryHead();
                }
                else if(display == "ID"){
                    break;
                }
                else{
                    goto ERROR_LOOP;
                }
                count = 0;
            }
            if(fin.eof()){
                break;
            }
        }
    }
    fin.close();
    if(count == -1){
        while(choice != 0){
            design();
            headline(topic);
            moveCursor(60,8);
            cout<<"**** Package Not Found!! ***";
            moveCursor(60,18);
            cout<<"1. Try Again";
            moveCursor(60,20);
            cout<<"2. Exit";
            moveCursor(60,36);
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice){
                case 1:{
                    searchforBooking();//calls same functio again
                }
                case 2:{
                    return ("EXIT");
                }
                default:{
                    choice = -1;
                    break;
                }
            }
        }
    }
    else if(count != -1){//to desplay details of package
        count = -1;
        moveCursor(2,18);
        cout<<"-Enter [EXIT] to exit";
        moveCursor(60,36);
        cout<<"Enter Package ID: ";
        cin>>ID;
        ID = upper(ID);
        if(ID == "EXIT" || ID == "E"){
            return ("EXIT");
        }
        ID = detail(ID);
        if(ID == "TRY AGAIN"){
            goto TRY;
        }
        else if(ID == "EXIT"){
            return ("EXIT");
        }
        else{
            moveCursor(60,36);
            cout<<"Press  any key to continue....";
            getch();
            return (ID);
        }  
    }
}

string Itinerary :: detail(string search){
    topic = "Package Detail";
    string ID;
    design();
    headline(topic);
    choice = -1;
    fstream fin;
    fin.open("zitinerary.txt", ios::in);
    vector<string>row;
    string line, word,temp;
    count = -1;
    while(!fin.eof()){
        count = 0;
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
            count ++;
        }
        ID = row[0];
        if(!fin.eof()){
            if(search == row[0]){
                moveCursor(32,6);
                cout<<"PACKAGE ID";
                moveCursor(47,6);
                cout<<": "<<row[0];
                moveCursor(32,7);
                cout<<"PACKAGE TITLE";
                moveCursor(47,7);
                cout<<": "<<row[1];
                moveCursor(32,8);
                cout<<"START";
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
                cout<<": "<<row[5]<<"\t *Per person";
                Y=13;
                moveCursor(32,Y);
                for(int i=6;i<count;i++){
                    cout<<row[i];
                    Y+=1;
                    moveCursor(32,Y);
                }
                count = 1;
                break;
            }
            if(fin.eof()){
                break;
            }
        }
    }
    fin.close();
    if(count == 0){//file not found
        while(choice != 0){
            design();
            headline(topic);
            moveCursor(60,8);
            cout<<"**** Package Not Found!! ***";
            moveCursor(60,18);
            cout<<"1. Try Again";
            moveCursor(60,20);
            cout<<"2. Exit";
            moveCursor(60,36);
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice){
                case 1:{
                    return ("TRY AGAIN");//because current function doesnot read from user
                }
                case 2:{
                    return ("EXIT");
                }
                default:{
                    choice = -1;
                    break;
                }
            }
        }
    }
    else if(count == 1){//file found and displayed
        choice = -1;
        return (ID);
    }
}

string Itinerary :: searching(){
    topic = "Search Package";
    fstream fin;
    string search,ID;
    design();
    headline(topic);
    moveCursor(60,20);
    cout<<"Enter Package Title: ";
    search = get_text("space");
TRY:
    fin.open("zitinerary.txt", ios::in);
    vector<string>row;
    string line, word,temp;
    design();
    headline(topic);
    itineraryHead();
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
            title=row[1];
            start=row[2];
            end=row[3];
            days=row[4];
            expense=row[5];
            if(search == row[1] || search == row[2] || search == row[3]){
                displayItinerary(count);
                count += 1;
            }
            if(count == 26){
ERROR_LOOP:
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
                moveCursor(2,20);
                cout<<"-Enter [NEXT] to";
                moveCursor(3,21);
                cout<<"continue to next page";
                moveCursor(2,23);
                cout<<"-Enter [ID] to book";
                moveCursor(2,24);
                cout<<" view package detail";
                moveCursor(60,36);
                cout<<"Enter your choice:";
                display = get_text("nospace");
                if(display == "EXIT" || display == "E"){
                    return ("EXIT");
                }
                else if(display == "NEXT" || display == "N"){
                    design();
                    headline(topic);
                    itineraryHead();
                }
                else if(display == "ID"){
                    break;
                }
                else{
                    goto ERROR_LOOP;
                }
                count = 0;
            }
            if(fin.eof()){
                break;
            }
        }
    }
    fin.close();
    if(count == -1){
        while(choice != 0){
            design();
            headline(topic);
            moveCursor(60,8);
            cout<<"**** Package Not Found!! ***";
            moveCursor(60,18);
            cout<<"1. Try Again";
            moveCursor(60,20);
            cout<<"2. Exit";
            moveCursor(60,36);
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice){
                case 1:{
                    searching();//calls same functio again
                }
                case 2:{
                    return ("EXIT");
                }
                default:{
                    choice = -1;
                    break;
                }
            }
        }
    }
    else if(count != -1){//to desplay details of package
        count = -1;
        moveCursor(2,18);
        cout<<"-Enter [EXIT] to exit";
        moveCursor(60,36);
        cout<<"Enter Package ID: ";
        cin>>ID;
        ID = upper(ID);
        if(ID == "EXIT" || ID == "E"){
            return ("EXIT");
        }
        ID = detail(ID);
        if(ID == "TRY AGAIN"){
            goto TRY;
        }
        else if(ID == "EXIT"){
            return ("EXIT");
        }
        else{
            moveCursor(60,36);
            cout<<"Press  any key to continue....";
            getch();
            return (ID);
        }  
    }
}

string Itinerary :: list(){
    topic = "List Itinerary";
    fstream fin;
    string search,ID;
    design();
    moveCursor(60,20);
TRY:
    fin.open("zitinerary.txt", ios::in);
    vector<string>row;
    string line, word,temp;
    design();
    headline(topic);
    itineraryHead();
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
            title=row[1];
            start=row[2];
            end=row[3];
            days=row[4];
            expense=row[5];
            
                displayItinerary(count);
                count += 1;
            
            if(count == 26){
ERROR_LOOP:
                moveCursor(2,18);
                cout<<"-Enter [EXIT] to exit";
                moveCursor(2,20);
                cout<<"-Enter [NEXT] to";
                moveCursor(3,21);
                cout<<"continue to next page";
                moveCursor(2,23);
                cout<<"Enter your choice:";
                display = get_text("nospace");
                if(display == "EXIT" || display == "E"){
                    return ("EXIT");
                }
                else if(display == "NEXT" || display == "N"){
                    design();
                    headline(topic);
                    itineraryHead();
                }
                else{
                    goto ERROR_LOOP;
                }
                count = 0;
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
            cout<<"**** File Empty !! ***";
            moveCursor(60,36);
            cout<<"Press any key to continue....";
            getch();
            return ("EXIT");
    }
    else{
        moveCursor(60,36);
        cout<<"Press  any key to continue....";
        getch();
        return (ID);
    }
}

#endif