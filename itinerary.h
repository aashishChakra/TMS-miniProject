#ifndef ITINERARY
#define ITINERARY

#include"class.h"

void Itinerary :: itineraryHead(){
            moveCursor(35,0);
            cout<<"Package List";
            moveCursor(1,4);
            cout<<"Package ID";
            moveCursor(15,4);
            cout<<"Package Title";
            moveCursor(35,4);
            cout<<"Starting Place";
            moveCursor(55,4);
            cout<<"Destination";
            moveCursor(70,4);
            cout<<"Days";
            moveCursor(80,4);
            cout<<"Expense(RS)";
}

void Itinerary :: displayItinerary(int a){
            a+=5;
            moveCursor(1,a);
            cout<<packageId;
            moveCursor(15,a);
            cout<<title;
            moveCursor(35,a);
            cout<<start;
            moveCursor(55,a);
            cout<<end;
            moveCursor(70,a);
            cout<<days;
            moveCursor(80,a);
            cout<<expense;
}

void Itinerary :: add_Itinerary(){
    fstream fout;
    system("cls");
    cout<<"Fill the below details:"
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
    fout.open("zitinerary.txt",ios::out | ios::app);//stores normal details
    fout<<packageId<<";"<<title<<";"<<start<<";"<<end<<";"<<days<<";"<<expense<<";";    
// list of location and important things are stored in seperate file for convinence
// package id is store in begining to avoid conflicts
    day=stoi(days);
    cout<<endl<<"Add Every day Destination:"<<endl;
    for(int i=0;i<day;i++){
        cout<<endl<<"Destination in Day"<<i+1<<" : ";
        reach=get_text();
        fout<<"Day "<<i+1<<" : "<<reach<<";";
    }
    fout<<"Important Things: "<<";";
    cout<<endl<<"Important Things: "<<endl;
    cout<<"*Note:Use '; [space]' to seperate sentence\n"<<endl;
    cin.ignore();
    getline(cin,things);
    fout<<things<<"\n";
    fout.close();
}

void Itinerary :: list_Itinerary(){
    system("cls");
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
    if(count == -1){
        system("cls");
        moveCursor(50,10);
        cout<<"Package Unavailable!";
        moveCursor(50,15);
        cout<<"Press any key to continue....";
        getch();
    }
    fin.close();
}

void Itinerary :: search_Itinerary(){
    system("cls");
    moveCursor(30,2);
    cout<<"Search Package";
    cout<<endl;
    int check = -1;
    string ID;
    fstream fin;
    fin.open("zitinerary.txt",ios::in);
    vector<string>row;
    string line, word;
    count == 0;
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
        packageId=row[0];
        title=row[1];
        start=row[2];
        end=row[3];
        days=row[4];
        expense=row[5];
        if(!fin.eof()){
            if(ID == packageId){
                check = 1;
                cout<<endl<<"Package ID: "<<packageId
                <<endl<<"Package Title: "<<title
                <<endl<<"Start: "<<start
                <<endl<<"Destination: "<<end
                <<endl<<"Number of days: "<<days
                <<endl<<"Expense: "<<expense<<endl;
                for(int i=6;i<count;i++){
                    cout<<row[i]<<"\n";
                }
                exit;
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
        search_Itinerary();
    }
    fin.close();
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
    count == 0;
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