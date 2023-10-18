#ifndef ITINERARY
#define ITINERARY
#include<iostream>
#include<conio.h>
#include<fstream>
#include<sstream>
using namespace std;
void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}
class Itinerary{
    protected:
        string packageId,title,start,end,days,expense,things,reach;
        int day;
        int count = 0;
    char ch;
    public:
        void displayItinerary(int);
        void itineraryHead();
        void add_Itinerary();
        void list_Itinerary();
        void search_Itinerary();
        void delete_Itinerary();
        void edit_Itinerary();
        string get_text();
        string get_num();
};
string Itinerary :: get_text(){
    string text;
    
    text.clear();
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            text.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){//lower to upper case
                ch-=32;
                text.push_back(ch);
            }
            else{
                text.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 20);
    if(count == 0){
        cout<<"Invalid Last Name"<<endl<<"Re-Enter ";
        get_text();
    }
    return(text);
}
string Itinerary:: get_num(){
    string num;
    num.clear();
        ch=getch();
    while(ch != 13){//runs until enter is pressed
        if(ch == 8){//presses backspace
            cout<<"\b";
            num.pop_back();
            count -= 1;
        }
        else if(ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            num.push_back(ch);
        }
        ch=getch();
    }
    return(num);
}
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
    fstream detail;
    system("cls");
    cout<<"Fill the below details:"
    <<endl<<"*NOTE:Use [space] before every entries*\n"<<endl;
    cout<<endl<<"Package ID: ";
    packageId=get_num();
    cout<<endl<<"Package Title: ";
    title=get_text();
    cout<<endl<<"Starting Place: ";
    start=get_text();
    cout<<endl<<"Destination: ";
    end=get_text();
    cout<<endl<<"Days: ";
    days=get_num();
    cout<<endl<<"Expense(RS): ";
    expense=get_num();
    detail.open("itinerary.txt",ios::out | ios::app);//stores normal details
    detail<<packageId<<";"<<title<<";"<<start<<";"<<end<<";"<<days<<";"<<expense<<";";    
// list of location and important things are stored in seperate file for convinence
// package id is store in begining to avoid conflicts
    day=stoi(days);
    cout<<endl<<"Add Every day Destination:"<<endl;
    for(int i=0;i<day;i++){
        cout<<endl<<"Destination in Day"<<i+1<<" : ";
        reach=get_text();
        detail<<"Day "<<i+1<<" : "<<reach<<";";
    }
    detail<<"Important Things: "<<";";
    cout<<endl<<"Important Things: "<<endl;
    cout<<"*Note:Use ';[space]' to seperate sentence\n"<<endl;
    cin.ignore();
    getline(cin,things);
    detail<<things<<"\n";
    detail.close();
}
void Itinerary :: list_Itinerary(){
    system("cls");
    fstream list;
    list.open("itinerary.txt",ios::in);
    vector<string>row;
    string line, word,temp;
    count = 0;
    itineraryHead();
    while(!list.eof()){
        row.clear();
        getline(list,line);
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
        if(!list.eof()){
            displayItinerary(count);
            count++;
        }
        if(list.eof()){
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
    list.close();
}
void Itinerary :: search_Itinerary(){
    system("cls");
    moveCursor(30,2);
    cout<<"Search Package";
    cout<<endl;
    int check = -1;
    string ID;
    fstream itinerary;
    itinerary.open("itinerary.txt",ios::in);
    vector<string>row;
    string line, word;
    count == 0;
    cout<<endl<<"Enter Package ID: ";
    ID=get_num();
    cout<<endl;
    while(!itinerary.eof()){
        row.clear();
        getline(itinerary,line);
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
        if(!itinerary.eof()){
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
        if(itinerary.eof()){
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
    itinerary.close();
}
void Itinerary :: delete_Itinerary(){
    system("cls");
    moveCursor(30,2);
    cout<<"Delete Package";
    int check=-1;
    cout<<endl<<"Package Id: ";
    packageId=get_num();
    cout<<endl;
    fstream fin,fout;
    vector<string>row;
    string line, word;
    fin.open("itinerary.txt",ios::in);
    fout.open("itinerary2.txt",ios::out);
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
        remove("itinerary.txt");
        rename("itinerary2.txt","itinerary.txt");
        moveCursor(30,10);
        cout<<"Package Id: "<<packageId<<" deleted successfully!";
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
    fin.open("itinerary.txt",ios::in);
    fout.open("itinerary2.txt",ios::out|ios::app);
    vector<string>row;
    string line, word;
    count == 0;
    cout<<endl<<"Enter Package ID: ";
    ID=get_num();
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
                packageId=get_num();
                cout<<endl<<"Package Title: ";
                title=get_text();
                cout<<endl<<"Starting Place: ";
                start=get_text();
                cout<<endl<<"Destination: ";
                end=get_text();
                cout<<endl<<"Days: ";
                days=get_num();
                cout<<endl<<"Expense(RS): ";
                expense=get_num();
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
    remove("itinerary.txt");
    rename("itinerary2.txt","itinerary.txt");
    if(check != -1){
        system("cls");
        moveCursor(50,10);
        cout<<"Package Id: "<<packageId<<" edited successfully!";
        moveCursor(50,15);
        cout<<"Press any key to continue....";
        getch();
    }
}


#endif