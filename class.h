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

void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

class login{
    protected:
        string userId, password, fname, lname, address, phone, email, power,nationality,packageId;
    public:
        void writeFile();
        void display();
        void signup(bool);
        bool signin();
        string get_userId();
        string get_password();
        string get_fname();
        string get_lname();
        string get_address();
        string get_phone();
        string get_nationality();
        string get_packageId();
        string cpassword();
        string get_power(bool );
        string generate_userId(bool);
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
            cout<<endl<<"Re-Enter: ";
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
            cout<<endl<<"Re_Enter: ";
            goto NUM_TOP;
        }
        else{
            return(num);
        }
}

#endif
 /*
 package id =5
 userid = 6
 days = 2
 cost = 7
 */