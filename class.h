#ifndef CLASS
#define CLASS

#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<vector>
#include<fstream>
#include<sstream>
#include<graphics.h>

using namespace std;

char ch;
int count = 0, error =- 1, choice = 1;
int X,Y;
string topic;

void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

class login{
    protected:
        string userId, password, fname, lname, address, phone, email, power,nationality,packageId;
    public:
        void signup();
        string signin();
        string get_userId();
        string get_password();
        string get_fname();
        string get_lname();
        string get_address();
        string get_phone();
        // string get_nationality();
        // string get_packageId();
        string change_password(string);
        string get_power();
        string generate_code(string);
        friend class Itinerary;
};

class book : public login{
    public:
        void insert_booking();
        void check_booking();
        void bookingHead();
        void displayBooking(int);
};

class Itinerary{
    protected:
        string packageId,title,start,end,days,expense,things,reach;
        int day;
    public:
        void displayItinerary(int);
        void itineraryHead();
        void add_Itinerary();
        void list_Itinerary();
        void search_Itinerary();
        void delete_Itinerary();
        void edit_Itinerary();
};

string get_text(){
    string text;
    TEXT_TOP:
        count = 0;
        text.clear();
        ch=getch();
        while(ch != 13 ){
            if(ch == 8 && count != 0){//backspace
                cout<<"\b";
                text.pop_back();
                count--;
            }
            else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122) && count != 25){//alphabets
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
        }
        if(count <= 0){
            goto TEXT_TOP;
        }
        else{
            return(text);
        }
}

string get_num(int a){//int "a" is length of digit
    string num;
    NUM_TOP:
        count = 0;
        num.clear();
        ch=getch();
        while(ch != 13 ){//runs until enter is pressed or 10 digits
            if(ch == 8 && count > 0){//presses backspace
                cout<<"\b";
                num.pop_back();
                count -= 1;
            }
            else if(ch >= 48 && ch <= 57 && count != a){//reads only number
                cout<<ch;
                num.push_back(ch);
                count ++;
            }
            ch=getch();
        }
        if(count <= 0){
            goto NUM_TOP;
        }
        else{
            return(num);
        }
}

void design(){
    system("cls");
    moveCursor(60,2);
    cout<<"TRAVEL MANAGEMENT SYSTEM";
    //Left margin
    X = 25;
    Y = 1;
    ch = 201;
    moveCursor(X,Y);
    cout<<ch;
    for(int i = 0; i<37; i++){
        if(i == 2){
            ch = 199;
            moveCursor(X,Y);
            cout<<ch;
        }
        else if(i == 35){
            ch = 199;
            moveCursor(X,Y);
            cout<<ch;
        }
        else{
            ch = 186;
            Y += 1;
            moveCursor(X,Y);
            cout<<ch;
        }
    }
    Y += 1;
    moveCursor(X,Y);
    ch = 200;
    cout<<ch;

    //right margin
    X = 126;
    Y = 1;
    ch = 187;
    moveCursor(X,Y);
    cout<<ch;
    for(int i = 0; i<37; i++){
        if(i == 2){
            ch = 182;
            moveCursor(X,Y);
            cout<<ch;
        }
        else if(i == 35){
            ch = 182;
            moveCursor(X,Y);
            cout<<ch;
        }
        else{
            ch = 186;
            Y += 1;
            moveCursor(X,Y);
            cout<<ch;
        }
    }
    Y+=1;
    moveCursor(X,Y);
    ch = 188;
    cout<<ch;
    
    //Top Margin
    X = 25;
    Y = 1;
    ch = 205;
    for(int i = 0; i<100; i++){
        X += 1;
        moveCursor(X,Y);
        cout<<ch;
    }

    //Bottom Margin
    X = 25;
    Y = 37;
    for(int i = 0; i < 100; i++){
        X += 1;
        moveCursor(X,Y);
        cout<<ch;
    }   

    //headder divider
    X = 25;
    Y = 3;
    for(int i = 0; i < 100; i++){
        ch = 196;
        X += 1;
        moveCursor(X,Y);
        cout<<ch;
    } 
    //footer divider
    X = 25;
    Y = 35;
    for(int i = 0; i < 100; i++){
        ch = 196;
        X += 1;
        moveCursor(X,Y);
        cout<<ch;
    } 
}

void headline(string& title){
    ch = 196;
    moveCursor(70,4);
    cout<<title;
    for(int i = 29; i<123; i++){
        moveCursor(i,5);
        cout<<ch;
    }
}

bool checkId(string id, string operation){    
    fstream fin;
    string userId;
    error = -1;
    if(operation == "userId"){
        fin.open("zlogin.txt",ios::in);
    }
    else if(operation == "package"){
        fin.open("zitinerary.txt",ios::in);
    }
    vector<string>row;
    string line, word,temp;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
        }
        if(!fin.eof()){
            if(operation == "userId"){//gets user Id
                userId=row[1];
            }
            else if(operation == "package"){//gets package Id
                userId=row[0];
            }
            if(id == userId){
                error = 1;
                break;
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(error == 1){//id found
        return(true);
    }
    else{//id not found
        return(false);
    }
}

#endif
 /*
 package id =5
 userid = 6
 days = 2
 cost = 7
 */