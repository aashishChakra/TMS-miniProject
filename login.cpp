// #ifndef LOGIN
// #define LOGIN
#include"class.h"

int admin();


int main(){
    bool status;
    book l;
    Itinerary i;
    char ch,ch1;
    int choice=1,option = 1;;
    while(choice != 0){
        system("CLS");
        cout<<"1. List Package"
        <<endl<<"2. Search Package"
        <<endl<<"3. Login"
        <<endl<<"4. Register"
        <<endl<<"5. Exit"
        <<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:{//list itinerary
                system("cls");
                i.list_Itinerary();
                SEARCH:
                cout<<endl<<"\n\t\t\tDo you want to view detail of package(Y/N): ";
                ch=getch();
                cout<<ch;
                if(ch == 'y' || ch == 'Y'){
                    i.search_Itinerary();
                }
                else if(ch == 'n' || ch == 'N'){
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Press any key to continue....";
                    getch();
                    break;
                }
                else{
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Invalid Choice!";
                    getch();
                    goto SEARCH;
                }
                BOOK:
                cout<<"Do you want to book this package(Y/N): ";
                ch1=getch();
                cout<<ch1;
                if(ch1 == 'y' || ch1 == 'Y'){
                    l.insert_booking();
                    break;
                }
                else if(ch1 == 'n' || ch1 == 'N'){
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Press any key to continue....";
                    getch();
                    break;
                }
                else{
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Invalid Choice!";
                    moveCursor(50,15);
                    cout<<"Press any key to continue....";
                    getch();
                    goto BOOK;
                }
                getch();
                break;
            }
            case 2:{//search itinerary
                i.search_Itinerary();
                BOOK2:
                cout<<endl<<"Do you want to book this package(Y/N): ";
                ch=getch();
                cout<<ch;
                if(ch == 'y' || ch == 'Y'){
                    l.insert_booking();
                    break;
                }
                else if(ch == 'n' || ch == 'N'){
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Press any key to continue....";
                    getch();
                    break;
                }
                else{
                    system("cls");
                    moveCursor(50,10);
                    cout<<"Invalid Choice!";
                    moveCursor(50,15);
                    cout<<"Press any key to continue....";
                    getch();
                    goto BOOK2;
                }
                getch();
                break;
            }
            case 3:{//login
                // if(l.signin()){
                    admin();
                // }
                break;
            }
            case 4:{//register
                system("cls");
                l.signup(false);
                getch();
                break;
            }
            case 5:{
                choice = 0;
                break;
            }
            default:{
                system("cls");
                moveCursor(50,15);
                cout<<"Invalid Choice!!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue";
            }
        }
    }
    system("cls");
    moveCursor(50,10);
    cout<<"Thank you for choosing us!!";
    getch();
    return 0;
}
bool login :: signin(){
    bool status=false;
    system("cls");
    string id,ps;
    userId.clear();
    password.clear();
    moveCursor(50,2);
    cout<<"Login";
    cout<<endl;
    id=get_userId();
    ps=get_password();
    fstream fin;
    fin.open("login.txt",ios::in);
    vector<string>row;
    string line, word;
    count = 0;
    while(!fin.eof()){
        row.clear();
        getline(fin,line);
        stringstream s(line);
        while(getline(s,word,';'))
        {
            row.push_back(word);
        }
        if(!fin.eof()){
            userId=row[1];
            password=row[2];
            if( userId == id && password == ps ){
                system("cls");
                status = true;
                moveCursor(50,10);
                cout<<"Login Successfull!";
                moveCursor(50,15);
                cout<<"Press any key to continue...";
                getch();
                return(status);
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    if(status == false){
        system("cls");
        moveCursor(50,10);
        cout<<"Invalid attempt!";
        moveCursor(50,15);
        cout<<"Press any key to continue...";
        getch();
        signin();
    }
}
void login :: signup(bool post){
    fstream fout;
    moveCursor(50,2);
    cout<<"Register"<<endl;
    fname=get_fname();
    lname=get_lname();
    address=get_address();
    phone=get_phone();
    password=get_password();
    power=get_power(post);//true for admin, false for author
    userId=generate_userId(post);
    fout.open("login.txt",ios::out | ios:: app);
    fout<<power<<";"<<userId<<";"<<password<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<"\n";
    fout.close();
    cout<<endl<<endl<<"Please Note Your User Id for Future Login."<<endl<<"Your User ID is: "<<userId<<endl;
}
string login :: get_power(bool post){
    power.clear();
    if(post==true){
        power=  "AUTHOR";
    }
    else if(post == false){
        power = "ADMIN";
    }
    return (power);
}
string login :: get_userId(){
    count=0;
    userId.clear();
    cout<<"USER ID: ";
    ch=getch();
    while(ch!=13){
        if(ch == 8 && count != 0){
            cout<<"\b";
            userId.pop_back();
            count--;
        }
        else{
            cout<<ch;
            userId.push_back(ch);
            count++;
        }
        ch=getch();
    }
    return(userId);
}
string login :: get_fname(){
    count = 0;
    fname.clear();
    cout<<endl<<"First Name: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            fname.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets both upper and lowe case
            cout<<ch;
            if(ch>=97 && ch<=122){//converts and store lower to upper case
                ch-=32;
                fname.push_back(ch);
            }
            else{//upper case
                fname.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 20);
    if(count == 0){
        cout<<"Invalid First Name"<<endl<<"Re-Enter ";
        get_fname();
    }
    return(fname);
}
string login :: get_lname(){
    count = 0;
    lname.clear();
    cout<<endl<<"Last Name: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            lname.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){//lower to upper case
                ch-=32;
                lname.push_back(ch);
            }
            else{
                lname.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 20);
    if(count == 0){
        cout<<"Invalid Last Name"<<endl<<"Re-Enter ";
        get_lname();
    }
    return(lname);
}
string login :: get_address(){
    count = 0;
    address.clear();
    cout<<endl<<"Address: ";
    ch=getch();
    do{
        if(ch == 8 and count != 0){
            cout<<"\b";
            address.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){
                ch-=32;
                address.push_back(ch);
            }
            count++;
        }
        else if(ch == 32){//space
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if(ch >= 48 && ch <= 57){//numbers
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if(ch == 44 || ch == 45){//hyphen and comma
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 30);
    if(count == 0){
        cout<<"Invalid Address"<<endl<<"Re-Enter ";
        get_address();
    }
    return(address);
}
string login :: get_phone(){
    error = -1;
    count = 0;
    phone.clear();
    cout<<endl<<"Phone: ";
    ch=getch();
    while(ch != 13 && count <= 10){//runs until enter is pressed
        if(ch == 8 && count != 0){//presses backspace
            if(count == 1 || count == 2){
                if(error > -1){//checks if pre enterd data were valid or not
                    error -= 1;
                }
            }
            cout<<"\b";
            phone.pop_back();
            count -= 1;
        }
        else if(count == 0){//checks first digit 
            if(ch != 57){//checks first digit is 9 or not
                error += 1;//error if not 9
            }
            cout<<ch;
            phone.push_back(ch);
            count += 1;
        }
        else if(count == 1){//checks second
            if(ch != 55 && ch != 56){
                error += 1;
            }
            cout<<ch;
            phone.push_back(ch);
            count += 1;
        }
        else if(count > 1 && ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            phone.push_back(ch);
            count += 1;
        }
        ch=getch();
    }
    if(error != -1 || count != 10){
        cout<<"Invalid Phone"<<endl<<"Re-Enter ";
        cout<<"error"<<error<<"\tcount"<<count;
        get_phone();
    }
    return (phone);
}
string login :: get_password(){
    count=0;
    password.clear();
    cout<<endl<<"Password: ";
    ch=getch();
    while(count < 25 && ch != 13){
        if(ch == 8 && count != 0){
            cout<<"\b";
            password.pop_back();
            count--;
        }
        else{
            cout<<ch;
            password.push_back(ch);
            count++;
        }
        ch=getch();
    }
    if(count == 0){
        cout<<"Invalid Password"<<"Re-Enter ";
        get_password();
    }
    return(password);
}
string login :: get_nationality(){
    count = 0;
    nationality.clear();
    cout<<endl<<"Nationality: ";
    ch=getch();
    do{
        if(ch == 8 && count != 0){//backspace
            cout<<"\b";
            nationality.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122)){//alphabets both upper and lowe case
            cout<<ch;
            if(ch>=97 && ch<=122){//converts and store lower to upper case
                ch-=32;
                nationality.push_back(ch);
            }
            else{//upper case
                nationality.push_back(ch);
            }
            count++;
        }
        ch=getch();
    }while(ch != 13 && count != 20);
    if(count == 0){
        cout<<"Invalid First Name"<<endl<<"Re-Enter ";
        get_nationality();
    }
    return(nationality);
}
string login :: get_packageId(){
    count=0;
    packageId.clear();
    cout<<endl<<"Package Id: ";
    ch=getch();
    while(ch!=13){
        if(ch == 8 && count != 0){//presses backspace
            cout<<"\b";
            packageId.pop_back();
            count -= 1;
        }
        else if(ch >= 48 && ch <= 57){//reads only number
            cout<<ch;
            packageId.push_back(ch);
            count += 1;
        }
        ch=getch();
    }
    if(count == 0){
        cout<<endl<<"Invalid Package Id"<<endl;
        get_packageId();
    }
    return(packageId);
}
string login :: generate_userId(bool post){
    //here power is already stored from signup
    login l;
    userId.clear();
    if(post){//admin
        srand(time(0));
        id=870000+rand()%10000;
    }
    else if(!post){//author
        srand(time(0));
        id=370000+rand()%10000;
    }
    userId=to_string(id);
    return(userId);
}


int admin(){
    int choice=1;
    book l;
    Itinerary a;
    while(choice != 0){
        system("cls");
        cout<<"1. Add Itinerary"
        <<endl<<"2. Edit Itinerary"
        <<endl<<"3. Delete Itinerary"
        <<endl<<"4. Logout"
        <<endl<<"5. View Booking"
        <<endl<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:{
                system("cls");
                a.add_Itinerary();
                getch();
                break;
            }
            case 2:{
                system("cls");
                a.edit_Itinerary();
                break;
            }
            case 3:{
                system("cls");
                a.delete_Itinerary();
                getch();
                break;
            }
            case 4:{
                system("cls");
                choice = 0;
                moveCursor(50,10);
                cout<<"Press any Key to Continue";
                getch();
                break;
            }
            case 5:{
                system("cls");
                l.check_booking();
                break;
            }
            default:{
                system("cls");
                moveCursor(50,10);
                cout<<"Invalid Choice!";
                moveCursor(50,15);
                cout<<"Press any Key to Continue";
                getch();
                break;
            }
        }
    }
    return 0;
}
