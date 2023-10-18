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

static int id;
int count=0,error=-1;

void moveCursor(int x, int y)
{
    cout << "\033[" << y << ";" << x << "H";
}

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