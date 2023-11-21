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

string Itinerary :: list_Itinerary(string source, string destination, string type){
//lists the packages in the system
//accessed by search , booking
    topic = "List Itinerary";
    fstream fin;
    choice = -1;
    fin.open("zitinerary.txt",ios::in);
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
        packageId=row[0];
        title=row[1];
        start=row[2];
        end=row[3];
        days=row[4];
        expense=row[5];
        if(!fin.eof()){
            if(type == "general"  || type == "book"){
                if(source == title || source == start || destination == end){
                    displayItinerary(count);
                    count+=1;
                }
            }
            else if (type == "specific"){
                if(source == start && destination == end){
                displayItinerary(count);
                count += 1;
                }
            }
            else if(type == "all"){
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
                if(type == "general" || type == "specific" || type == "all"){
                    moveCursor(2,23);
                    cout<<"-Enter [ID] to ";
                    moveCursor(2,24);
                    cout<<"view detail";
                }
                if(type == "book"){
                    moveCursor(2,23);
                    cout<<"-Enter [ID] to book";
                }
                moveCursor(60,36);
                cout<<"Enter your choice:";
                cin>>display;
                display = upper(display);
                if(display == "EXIT" || display == "E"){
                    return ("404");
                }
                else if(display == "NEXT" || display == "N"){
                    design();
                    headline(topic);
                    itineraryHead();
                }
                else if(display == "ID" && type != "book"){
                    return("middle");
                }
                else if(display == "ID" && type == "book"){
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
                    choice = -1;
                    return("error");
                    break;
                }
                case 2:{
                    return ("404");
                }
                default:{
                    choice = -1;
                    break;
                }
            }
        }
    }
    choice = -1;
    return (source);
}

string Itinerary :: search_Itinerary(string type){
//searches the desired packages
//tpe specifies "general", "specific" ,"all"
//"general" to search packages that matches 'package title', 'start place', 'destination'
//"specific" to search package that has specific "start place" and "destination"
//"all" to search package without any criteria
    int check;
    fstream fin;
    string ID,source,destination;
    topic = "Packages Details";
SEARCH_TOP_A:
    design();
    headline(topic);
    if(type == "general"  || type == "book"){
        moveCursor(60,20);
        cout<<"Enter Package Title: ";
        source=get_text("space");
        destination = source;
    }
    else if(type == "specific"){
        moveCursor(60,20);
        cout<<"Enter Starting Place: ";
        source=get_text("space");
        moveCursor(60,22);
        cout<<"Enter Destination: ";
        destination=get_text("space");
    }
    else if(type == "all"){
        source = "KATHMANDU";
        source = destination;
    }
SEARCH_TOP_B:
    ID = list_Itinerary(source, destination,type);
    topic = "Package Detail";
    if(ID == "error"){
        goto SEARCH_TOP_A;
    }
    else if(ID == "404"){
        ID = "404";
        return (ID);
    }
    moveCursor(2,18);
    cout<<"-Enter [EXIT] to exit";
    if(ID != "middle"){
        moveCursor(2,20);
        cout<<"-Enter package id to";
        moveCursor(2,21);
        cout<<" view detail";
    }
    moveCursor(60,36);
    cout<<"Enter Package ID: ";
    cin>>ID;
    ID=upper(ID);
    if(ID == "EXIT" || ID == "E"){
        ID = "404";
        return (ID);
    }
    count = -1;
    design();
    headline(topic);
    check = -1;
    fin.open("zitinerary.txt",ios::in);
    vector<string>row;
    string line, word;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        count = 0;
        stringstream s(line);
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
            if(type == "general"  || type == "book"){
                if((ID == packageId) && (source == title || source == start || destination == end)){
                    check = 1;
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
                    exit;
                }
            }
            else if(type == "all"){
                if(ID == packageId){
                    check = 1;
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
                    cout<<": "<<row[5];
                    Y=13;
                    moveCursor(32,Y);
                    for(int i=6;i<count;i++){
                        cout<<row[i];
                        Y+=1;
                        moveCursor(32,Y);
                    }
                    exit;
                }
            }
            else if(type == "specific"){
                if(ID == packageId && source == start && destination == end){
                    check = 1;
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
                    cout<<": "<<row[5];
                    Y=13;
                    moveCursor(32,Y);
                    for(int i=6;i<count;i++){
                        cout<<row[i];
                        Y+=1;
                        moveCursor(32,Y);
                    }
                    exit;
                }
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(check == -1){
        while(choice != 0){
            design();
            headline(topic);
            moveCursor(60,8);
            cout<<"**** Package Not Found!!";
            moveCursor(60,18);
            cout<<"1. Search Menu";
            moveCursor(60,20);
            cout<<"2. List";
            moveCursor(60,22);
            cout<<"3. Exit";
            moveCursor(60,36);
            cout<<"Enter Your Choice: ";
            cin>>choice;
            switch(choice){
                case 1:{
                    goto SEARCH_TOP_A;
                    break;
                }
                case 2:{
                    design();
                    headline(topic);
                    goto SEARCH_TOP_B;
                    break;
                }
                case 3:{
                    ID = "404";
                    choice = -1;
                    return (ID);
                }
                default:{
                    choice = -1;
                    break;
                }
            }
        }
    }
    else{
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
        if(type == "specific" || type == "general"){
            while(choice != 0){
                design();
                headline(topic);
                moveCursor(60,18);
                cout<<"1. New Search";
                moveCursor(60,20);
                cout<<"2. List";
                moveCursor(60,22);
                cout<<"3. Exit";
                moveCursor(60,36);
                cout<<"Enter Your Choice: ";
                cin>>choice;
                switch(choice){
                    case 1:{
                        design();
                        headline(topic);
                        goto SEARCH_TOP_A;
                        choice = -1;
                        break;
                    }
                    case 2:{
                        goto SEARCH_TOP_B;
                        choice = -1;
                        break;
                    }
                    case 3:{
                        choice = -1;
                        return (ID);
                    }
                    default:{
                        choice = -1;
                        break;
                    }
                }
            }
        }
    }
    choice = -1;
    return (ID);
}

string Itinerary :: delete_Itinerary(){
    topic = "Delete Itinerary";
    string type = "general";
    fstream fin,fout;
    vector<string>row;
    string line, word;
    int check=-1;
    string search, ID;
DELETE_TOP:
    design();
    headline(topic);
    moveCursor(60,20);
    cout<<"Enter Package Title: ";
    search=get_text("space");
    ID = list_Itinerary(search,search,type);
    if(search == "404"){
        return (ID);
    }
    topic = "Delete Itinerary";
    headline(topic);
    moveCursor(60,36);
    cout<<"Enter Package ID: ";
    cin>>ID;
    ID=upper(ID);
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
            else if((ID == packageId) && (search == title || search == start || search == end)){
                check = 1;
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

void Itinerary :: edit_Itinerary(){
    system("cls");
    moveCursor(30,2);
    cout<<"Edit Package";
    int check = -1;
    string ID;
    fstream fin,fout;
    fin.open("zitinerary.txt",ios::in);
    fout.open("zitinerary2.txt",ios::out|ios::app);
    vector<string>row;
    string line, word;
    count = 0;
    cout<<endl<<"Enter Package ID: ";
    ID=get_num(5);
    cout<<endl;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        count = 0;
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
            count++;
        }
        if(!fin.eof()){
            if(ID == row[0]){
                check = 1;
                cout<<endl<<"Fill the below details:"
                <<endl<<"*NOTE:Use [space] before every entries*\n"<<endl;
                cout<<endl<<"Package ID: ";
                packageId=get_num(5);
                cout<<endl<<"Package Title: ";
                title=get_text("space");
                cout<<endl<<"Starting Place: ";
                start=get_text("space");
                cout<<endl<<"Destination: ";
                end=get_text("space");
                cout<<endl<<"Days: ";
                days=get_num(2);
                cout<<endl<<"Expense(RS): ";
                expense=get_num(7);
                fout<<packageId<<";"<<title<<";"<<start<<";"<<end<<";"<<days<<";"<<expense<<";";
                day=stoi(days);
                cout<<endl<<"Add Every day Destination:"<<endl;
                for(int i=0;i<day;i++){
                    cout<<endl<<"Destination in Day"<<i+1<<" : ";
                    reach=get_text("space");
                    fout<<"Day "<<i+1<<" : "<<reach<<";";
                }
                fout<<"Important Things: "<<";";
                cout<<endl<<"Important Things: "<<endl;
                cout<<"*Note:Use ';[space]' to seperate sentence\n"<<endl;
                cin.ignore();
                getline(cin,things);
                fout<<things<<"\n";
            }
            else{
                for(int i = 0; i<count;i++){
                    fout<<row[i]<<";";
                }
                fout<<"\n";
            }
        }
        if(fin.eof()){
            break;
        }
    }
    if(check == -1){
        system("cls");
        moveCursor(50,10);
        cout<<"Package not Found!";
        moveCursor(50,15);
        cout<<"Press any key to continue....";
        getch();
    }
    fin.close();
    fout.close();
    remove("zitinerary.txt");
    rename("zitinerary2.txt","zitinerary.txt");
    if(check != -1){
        system("cls");
        moveCursor(50,10);
        cout<<"Package Id: "<<packageId<<" Edited Successfully!";
        moveCursor(50,15);
        cout<<"Press any key to continue....";
        getch();
    }
}

#endif