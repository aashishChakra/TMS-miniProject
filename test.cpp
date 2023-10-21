#include<iostream>
#include<conio.h>
using namespace std;
char ch;
int count;
int error = -1;
string address;
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

string get_address(){
    ADDRESS_TOP:
        count = 0;
        address.clear();
        cout<<endl<<"Address: ";
        ch=getch();
        while(ch != 13 ){
            if(ch == 8 and count != 0){
                cout<<"\b";
                address.pop_back();
                count--;
            }
            else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122) && count != 30){//alphabets
                cout<<ch;
                if(ch>=97 && ch<=122){
                    ch-=32;
                    address.push_back(ch);
                }
                count++;
            }
            else if(ch == 32 && count != 30){//space
                cout<<ch;
                address.push_back(ch);
                count++;
            }
            else if(ch >= 48 && ch <= 57 && count != 30){//numbers
                cout<<ch;
                address.push_back(ch);
                count++;
            }
            else if((ch == 44 || ch == 45) && count != 30){//hyphen and comma
                cout<<ch;
                address.push_back(ch);
                count++;
            }
            ch=getch();
        }
        if(count == 0){
            cout<<endl<<"Re-Enter: ";
            goto ADDRESS_TOP;
        }
        return(address);
}
int main(){
    system("cls");
    string read;
    read = get_address();
    cout<<endl<<"your text:"<<read;
    getch();
    return (0);
}