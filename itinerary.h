#ifndef ITINERARY
#define ITINERARY

#include"class.h"

void Itinerary :: itineraryHead(){
    X = 30;
    moveCursor(X + 2,6);
    cout<<"Package ID";
    moveCursor(X + 17,6);
    cout<<"Package Title";
    moveCursor(X + 37,6);
    cout<<"Starting Place";
    moveCursor(X + 57,6);
    cout<<"Destination";
    moveCursor(X + 72,6);
    cout<<"Days";
    moveCursor(X + 82,6);
    cout<<"Expense(RS)";
}

void Itinerary :: displayItinerary(int a){
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
    topic="Add Itinerary";
    fstream fout;
    login l;
    design();
    headline(topic);
    moveCursor(60,6);
    cout<<"Fill the below details:";
    moveCursor(50,7);
    cout<<"*NOTE:Use [space] before every entries*";
    do{
        packageId=l.generate_code("package");
    }while(checkId(packageId,"package"));
    moveCursor(32,8);
    cout<<"Package Title: ";
    title=get_text();
    moveCursor(32,10);
    cout<<"Starting Place: ";
    start=get_text();
    moveCursor(32,12);
    cout<<"Destination: ";
    end=get_text();
    moveCursor(32,14);
    cout<<"Days: ";
    days=get_num(1);
    moveCursor(32,16);
    cout<<"Expense(RS): ";
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
        reach=get_text();
        fout<<"Day "<<i+1<<" : "<<reach<<";";
    }
    fout<<"Important Things: "<<";";
    cout<<"\n\t\t\t\t*Note:Use '; [space]' to seperate sentence\n\n\t\t\t\t";
    cout<<"\n\n\t\t\t\tImportant Things:";
    cin.ignore();
    getline(cin,things);
    fout<<things<<"\n";
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

void Itinerary :: list_Itinerary(){
    topic = "List Itinerary";
    design();
    headline(topic);
    fstream fin;
    fin.open("zitinerary.txt",ios::in);
    vector<string>row;
    string line, word,temp;
    count = 0;
    itineraryHead();
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
            displayItinerary(count);
            count++;
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(count == -1){
        design();
        moveCursor(60,18);
        cout<<"Package Unavailable!!";
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

void Itinerary :: search_Itinerary(){
    design();
    topic = "Search Packages";
    headline(topic);
    int check = -1;
    string ID;
    fstream fin;
    fin.open("zitinerary.txt",ios::in);
    vector<string>row;
    string line, word;
    count == 0;
    moveCursor(32,6);
    cout<<"Enter Package ID: ";
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
        packageId=row[0];
        title=row[1];
        start=row[2];
        end=row[3];
        days=row[4];
        expense=row[5];
        if(!fin.eof()){
            if(ID == packageId){
                check = 1;
                moveCursor(32,7);
                cout<<"Package ID: "<<packageId;
                moveCursor(32,8);
                cout<<"Package Title: "<<title;
                moveCursor(32,9);
                cout<<"Start: "<<start;
                moveCursor(32,10);
                cout<<"Destination: "<<end;
                moveCursor(32,11);
                cout<<"Number of days: "<<days;
                moveCursor(32,12);
                cout<<"Expense: "<<expense;
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
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(check == -1){
        design();
        moveCursor(60,18);
        cout<<"Package not Found!!";
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
        search_Itinerary();
    }
    else{
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
}

void Itinerary :: delete_Itinerary(){
    system("cls");
    moveCursor(30,2);
    cout<<"Delete Package";
    int check=-1;
    cout<<endl<<"Package Id: ";
    packageId=get_num(5);
    cout<<endl;
    fstream fin,fout;
    vector<string>row;
    string line, word;
    fin.open("zitinerary.txt",ios::in);
    fout.open("zitinerary2.txt",ios::out);
    while(!fin.eof()){
        check=1;
        row.clear();
        getline(fin,line);
        stringstream s(line);
        count = 0;
        while(getline(s,word,';'))
        {
            row.push_back(word);
            count++;
        } 
        if(!fin.eof()){
            if(packageId != row[0]){
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
        moveCursor(30,10);
        cout<<"List Empty";
        moveCursor(30,15);
        cout<<"Press any key to continue....";
        getch();
        delete_Itinerary();
    }
    else{
        system("cls");
        fin.close();
        fout.close();
        remove("zitinerary.txt");
        rename("zitinerary2.txt","zitinerary.txt");
        moveCursor(30,10);
        cout<<"Package Id: "<<packageId<<" Deleted Successfully!";
        moveCursor(30,15);
        cout<<"Press any key to continue....";
        getch();
    }
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
                title=get_text();
                cout<<endl<<"Starting Place: ";
                start=get_text();
                cout<<endl<<"Destination: ";
                end=get_text();
                cout<<endl<<"Days: ";
                days=get_num(2);
                cout<<endl<<"Expense(RS): ";
                expense=get_num(7);
                fout<<packageId<<";"<<title<<";"<<start<<";"<<end<<";"<<days<<";"<<expense<<";";
                day=stoi(days);
                cout<<endl<<"Add Every day Destination:"<<endl;
                for(int i=0;i<day;i++){
                    cout<<endl<<"Destination in Day"<<i+1<<" : ";
                    reach=get_text();
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