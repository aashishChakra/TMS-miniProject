#ifndef LOGIN
#define LOGIN

#include"class.h"

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
    userId = get_num(6);
    return(userId);
}

string login :: get_fname(){
    count = 0;
    fname.clear();
    cout<<endl<<"First Name: ";
    fname = get_text();
    return(fname);
}

string login :: get_lname(){
    count = 0;
    lname.clear();
    cout<<endl<<"Last Name: ";
    lname = get_text();
    return(lname);
}

string login :: get_address(){
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

string login :: get_phone(){
    PHONE_TOP:
        error = -1;
        count = 0;
        phone.clear();
        cout<<endl<<"Phone: ";
        ch=getch();
        while(ch != 13 ){//runs until enter is pressed
            if(ch == 8 && count > 0){//presses backspace
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
            else if(count > 1 && ch >= 48 && ch <= 57 && count != 10){//reads only number
                cout<<ch;
                phone.push_back(ch);
                count += 1;
            }
            ch=getch();
        }
        if(error != -1 || count != 10){
            cout<<endl<<"Re-Enter: ";
            goto PHONE_TOP;
        }
        return (phone);
}

string login :: get_password(){
    PASSWORD_TOP:
        count=0;
        password.clear();
        cout<<endl<<"Password: ";
        ch=getch();
        while(ch != 13){
            if(ch == 8 && count != 0){
                cout<<"\b";
                password.pop_back();
                count--;
            }
            else if(count != 20){
                cout<<ch;
                password.push_back(ch);
                count++;
            }
            ch=getch();
        }
        if(count == 0){
            cout<<endl<<"Re-Enter: ";
            goto PASSWORD_TOP;
        }
        else{
            return(password);
        }
}

string login :: get_nationality(){
    count = 0;
    nationality.clear();
    cout<<endl<<"Nationality: ";
    nationality = get_text();
    return(nationality);
}

string login :: get_packageId(){
    count=0;
    packageId.clear();
    cout<<endl<<"Package Id: ";
    packageId = get_num(5);
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

#endif