#include"class.h"
#include"itinerary.h"
#include"book.h"
#include"login.h"
string phone, address;

// string get_texts(){
//     string text;
//     TEXT_TOP:
//         count = 0;
//         text.clear();
//         ch=getch();
//         while(ch != 13 ){
//             if(ch == 8 && count != 0){//backspace
//                 cout<<"\b";
//                 text.pop_back();
//                 count--;
//             }
//             else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122) && count != 25){//alphabets
//                 cout<<ch;
//                 if(ch>=97 && ch<=122){//lower to upper case
//                     ch-=32;
//                     text.push_back(ch);
//                 }
//                 else{
//                     text.push_back(ch);
//                 }
//                 count++;
//             }
//             ch=getch();
//         }
//         if(count <= 0){
//             goto TEXT_TOP;
//         }
//         else{
//             return(text);
//         }
// }
// string get_address(){
//     string display;
//     display = "WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM....";
    
    
// }
// void print_slow(string& display){
//     for(int i =0;i<display.length();i++){
//         cout<<display[i];
//         usleep(88000);
//     }
// }

int main(){
    book l;
    string type="WAITING";
    // cout<<"text: ";
    // get_address();
    // get_texts();
    // string display;
    // display = "WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM....";
    l.checkBooking(type);
    getch();
    return(0);
}