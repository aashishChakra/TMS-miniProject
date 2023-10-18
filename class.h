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

void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

static int id;
int count=0,error=-1;
class login{
    protected:
        char ch;
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
        
        void insert_booking();
        void check_booking();
        void bookingHead(){
            system("cls");
            moveCursor(30,2);
            cout<<"Bookings";
            moveCursor(1,4);
            cout<<"Package ID";
            moveCursor(15,4);
            cout<<"First Name";
            moveCursor(27,4);
            cout<<"Last Name";
            moveCursor(40,4);
            cout<<"Address";
            moveCursor(55,4);
            cout<<"Phone";
            moveCursor(70,4);
            cout<<"Nationality";
        }
        void displayBooking(int a){
            a+=5;
            moveCursor(1,a);
            cout<<packageId;
            moveCursor(15,a);
            cout<<fname;
            moveCursor(27,a);
            cout<<lname;
            moveCursor(40,a);
            cout<<address;
            moveCursor(55,a);
            cout<<phone;
            moveCursor(70,a);
            cout<<nationality<<endl;
        }
};

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


#endif