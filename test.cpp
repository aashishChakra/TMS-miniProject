#include"class.h"
#include "login.h"
string userId, password;

string signin(){
    login l;
    SIGNIN_TOP:
    system("cls");
    string id,ps;
    userId.clear();
    password.clear();
    moveCursor(50,2);
    cout<<"Login";
    cout<<endl;
    id=l.get_userId();
    ps=l.get_password();
    fstream fin;
    fin.open("zlogin.txt",ios::in);
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
                moveCursor(50,10);
                cout<<"Login Successfull!";
                moveCursor(50,15);
                cout<<"Press any key to continue...";
                getch();
                return(userId);
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    {
        system("cls");
        moveCursor(50,10);
        cout<<"Invalid attempt!";
        moveCursor(50,15);
        cout<<"Press any key to continue...";
        getch();
        goto SIGNIN_TOP;
    }
}
void change_password(string id);
int main(){
    string id = "375203";
    system("cls");
    change_password(id);
    getch();
    return(0);
}

void change_password(string id){
    string old, reset, confirm;
    login l;
    fstream fin, fout;
    fin.open("zlogin.txt",ios::in);
    fout.open("zlogin2.txt",ios::out | ios::app);
    CHANGE_TOP:
        system("cls");
        moveCursor(50,2);
        cout<<"Change Password"<<endl;
        error = -1;
        userId.clear();
        moveCursor(50,9);
        userId=l.get_userId();
        vector<string>row;
        string line, word;
        if(id != userId){
            system("cls");
            moveCursor(50,2);
            cout<<"Change Password"<<endl;
            moveCursor(50,10);
            cout<<"Invalid UserId!";
            moveCursor(50,15);
            cout<<"Press any key to continue...";
            getch();
            goto CHANGE_TOP;
        }
        while(!fin.eof()){
            row.clear();
            getline(fin,line);
            count = 0;
            stringstream s(line);
            while(getline(s,word,';'))
            {
                row.push_back(word);
                count ++;
            }
            if(!fin.eof()){
                if(userId == row[1]){
                    error ++;
                    password = row[2];
                    OLD_TOP:
                        old.clear();
                        moveCursor(50,10);
                        cout<<"Current ";
                        old = l.get_password();
                        if(old == password){
                            PASSWORD_TOP:
                                system("cls");
                                moveCursor(50,2);
                                cout<<"Change Password";
                                moveCursor(50,9);
                                cout<<"New ";
                                reset = l.get_password();
                                moveCursor(50,10);
                                cout<<"Confirm ";
                                confirm = l.get_password();
                                if( (reset == confirm) && (old != reset)){
                                    fout<<row[0]<<";"<<row[1]<<";"<<reset<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<"\n";
                                }
                                else if(old == reset){
                                    system("cls");
                                    moveCursor(50,2);
                                    cout<<"Change Password";
                                    moveCursor(50,10);
                                    cout<<"Old Password Matches New Password!";
                                    moveCursor(50,15);
                                    cout<<"Press any key to continue...";
                                    getch();
                                    goto PASSWORD_TOP;
                                }
                                else{
                                    system("cls");
                                    moveCursor(50,2);
                                    cout<<"Change Password";
                                    moveCursor(50,10);
                                    cout<<"Password Mismatch!";
                                    moveCursor(50,15);
                                    cout<<"Press any key to continue...";
                                    getch();
                                    goto PASSWORD_TOP;
                                }
                        }
                        else{
                            system("cls");
                            moveCursor(50,2);
                            cout<<"Change Password";
                            moveCursor(50,10);
                            cout<<"Invalid Password!";
                            moveCursor(50,15);
                            cout<<"Press any key to continue...";
                            getch();
                            system("cls");
                            moveCursor(50,2);
                            cout<<"Change Password";
                            moveCursor(50,9);
                            cout<<"USER ID: "<<userId;
                            goto OLD_TOP;
                        }
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
        fin.close();
        fout.close();
        remove("zlogin.txt");
        rename("zlogin2.txt","zlogin.txt");
        if(error == -1){
            goto CHANGE_TOP;
        }
        else{
            system("cls");
            moveCursor(50,2);
            cout<<"Change Password"<<endl;
            moveCursor(50,10);
            cout<<"Password Changed Successfully!";
            moveCursor(50,15);
            cout<<"Press any key to continue...";
            getch();
        }
}