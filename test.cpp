#include"class.h"
#include"itinerary.h"
#include"book.h"
#include"login.h"
string phone, address,bookingId,ID;

string test(){
    fstream fin;
    cin>>bookingId;
    fin.open("zitinerary.txt",ios::in);
    vector<string>row;
    string line, word,temp;
    count = -1;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
            count++;
        }
        if(!fin.eof()){
            if(bookingId == row[0]){
                ID=row[6];
                count = 0;
                design();
                moveCursor(32,10);
                cout<<"Package ID: "<<row[0];
                moveCursor(32,12);
                cout<<"Title: "<<row[1];
                moveCursor(32,14);
                cout<<"Start: "<<row[2];
                moveCursor(32,16);
                cout<<"Destination: "<<row[3];
                moveCursor(32,18);
                cout<<"Number of days: "<<row[4];
                moveCursor(32,20);
                cout<<"expense: "<<row[5];
                Y=13;
                moveCursor(32,Y);
                for(int i=6;i<count;i++){
                    cout<<row[i];
                    Y+=1;
                    moveCursor(32,Y);
                }
                exit;
            }
            if(fin.eof()){
                break;
            }
        }
    }
    fin.close();
    if(count == -1){
        design();
        moveCursor(60,18);
        cout<<"Booking Unavailable!!";
        moveCursor(60,36);
        cout<<"Press any key to continue....";
        getch();
    }
    getch();
}
int main(){
    Itinerary i;
    string type="WAITING";
    // cout<<"text: ";
    // get_address();
    // get_texts();
    // string display;
    // display = "WELCOME TO AARC TRAVEL MANAGEMENT SYSTEM....";
    // i.add_Itinerary();
    // test();
    getch();
    return(0);
}
