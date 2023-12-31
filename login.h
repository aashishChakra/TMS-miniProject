#ifndef LOGIN
#define LOGIN

#include"class.h"

string login :: signin(){
    string id,ps;
SIGNIN_TOP:
    design();
    topic = "Login";
    headline(topic);
    userId.clear();
    password.clear();
    moveCursor(2,18);
    cout<<"Enter [404] to exit";
    moveCursor(60,18);
    id=get_userId();
    if(id == "EXIT"){
        return (id);
    }
    moveCursor(60,20);
    ps=get_password();
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
                design();
                headline(topic);
                moveCursor(60,18);
                display = "Login Successfull!!";
                print_slow(display);
                return(userId);
            }
        }
        if(fin.eof()){
            break;
        }
    }
    fin.close();
    design();
    topic = "Login";
    headline(topic);
    moveCursor(60,18);
    cout<<"Invalid attempt!!";
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
    goto SIGNIN_TOP;
}

void login :: signup(){
    fstream fout;
    design();
    topic = "Register";
    headline(topic);
    moveCursor(32,6);
    fname=get_fname();
    moveCursor(32,8);
    lname=get_lname();
    moveCursor(32,10);
    address=get_address();
    moveCursor(32,12);
    phone=get_phone();
    moveCursor(32,14);
    password=get_password();
    power=get_power();
    do{
        userId=generateCode("userId");
    }while(checkCode(userId, "userId"));
    fout.open("zlogin.txt",ios::out | ios:: app);
    fout<<power<<";"<<userId<<";"<<password<<";"<<fname<<";"<<lname<<";"<<address<<";"<<phone<<";\n";
    fout.close();
    design();
    headline(topic);
    moveCursor(60,18);
    cout<<"Please Note Your User Id for Future Login.";
    moveCursor(60,20);
    cout<<"Your User ID is: "<<userId;
    moveCursor(60,36);
    cout<<"Press any key to continue....";
    getch();
}

string login :: get_power(){
//no use
    power = "ADMIN";
    return (power);
}

string login :: get_userId(){
//accessed by signup
//reads from user not generate
    count=0;
    userId.clear();
    cout<<"USER ID: ";
    userId = get_num(6);
    return(userId);
}

string login :: get_fname(){
    count = 0;
    fname.clear();
    cout<<"First Name: ";
    fname = get_text("nonspace");
    return(fname);
}

string login :: get_lname(){
    count = 0;
    lname.clear();
    cout<<"Last Name: ";
    lname = get_text("nonspace");
    return(lname);
}

string login :: get_address(){
//reads alphabets,numbers,comma,space,hypen
    int alphabet = 0, alphabet_position = -1;
    count = 0;
    address.clear();
    cout<<"Address: ";
ADDRESS_TOP:
    ch=getch();
    while(ch != 13 ){
        if(ch == 8 && count != 0){
            cout<<"\b \b";
            address.pop_back();
            count--;
        }
        else if((ch >= 65 && ch<=90) || (ch >= 97 && ch<=122) && count != 30){
            //upper case alphabets or lower case alphabets
            cout<<ch;
            if(ch>=97 && ch<=122){//condition to read lower case letter
                //conversion from lower case to upper case
                ch-=32;
                address.push_back(ch);
            }
            else{//reading upper case letter
                address.push_back(ch);
            }
            count ++;
            alphabet ++;
        }
        else if(ch == 32 && count != 0){//condition to read space
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if(ch >= 48 && ch <= 57 && count>1){//condition to read numbers
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        else if((ch == 44 || ch == 45) && (count>1)){//condition to read comma and hyphen
            cout<<ch;
            address.push_back(ch);
            count++;
        }
        ch=getch();
    }
    if(count == 0 || alphabet == 0){//checks if alphabets exists or not
        goto ADDRESS_TOP;
    }
    else{
        return(address);
    }
}

string login :: get_phone(){
    error = -1;
    count = 0;
    phone.clear();
    cout<<"Phone: ";
    ch=getch();
    while(ch != 13){//runs until "enter" is pressed
        if(ch == 8 ){//presses backspace
            if (count != 0){//checks if the number has been entered or not
                if(count == 1 || count == 2){
                    if(error > -1){//checks if pre enterd data were valid or not
                        error -= 1;
                    }
                }
                cout<<"\b \b";
                phone.pop_back();
                count --;
            }
        }
        else if(count == 0){//checks first digit 
            if(ch != 57){//checks first digit is 9 or not
                error += 1;//error if not 9
            }
            cout<<ch;
            phone.push_back(ch);
            count += 1;
        }
        else if(count == 1){//checks second digit
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
PHONE_TOP:
        ch=getch();
    }
    if(error != -1 || count != 10){//checks errors in enterd phone number
        goto PHONE_TOP;
    }
    return (phone);
}

string login :: get_password(){
    cout<<"Password: ";
PASSWORD_TOP:
    count=0;
    password.clear();
    ch=getch();
    while(ch != 13){
        if(ch == 8 && count != 0){
            cout<<"\b  \b";
            password.pop_back();
            count--;
        }
        else if(count != 20){
            cout<<'*';
            password.push_back(ch);
            count++;
        }
        ch=getch();
    }
    if(count == 0){
        goto PASSWORD_TOP;
    }
    else{
        return(password);
    }
}

string login :: change_password(string passedId){
    string oldPassword, newPassword, confirmPassword;
    login l;
    fstream fin, fout;
    fin.open("zlogin.txt",ios::in);
    fout.open("zlogin2.txt",ios::out | ios::app);
    CHANGE_TOP:
        design();
        topic = "Change Password";
        headline(topic);
        error = -1;
        userId.clear();
        moveCursor(60,18);
        userId=l.get_userId();
        vector<string>row;
        string line, word;
        if(userId != passedId){
            design();
            headline(topic);
            moveCursor(60,18);
            cout<<"Invalid UserId!!";
            moveCursor(60,36);
            cout<<"Press any key to continue....";
            getch();
            goto CHANGE_TOP;
        }
        else{
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
                            oldPassword.clear();
                            moveCursor(60,20);
                            cout<<"Current ";
                            oldPassword = l.get_password();
                            if(oldPassword == password){
                                PASSWORD_TOP:
                                    design();
                                    headline(topic);
                                    moveCursor(60,18);
                                    cout<<"New ";
                                    newPassword = l.get_password();
                                    moveCursor(60,20);
                                    cout<<"Confirm ";
                                    confirmPassword = l.get_password();
                                    if( (newPassword == confirmPassword) && (oldPassword != newPassword)){
                                        fout<<row[0]<<";"<<row[1]<<";"<<newPassword<<";"<<row[3]<<";"<<row[4]<<";"<<row[5]<<";"<<row[6]<<";\n";
                                    }
                                    else if(oldPassword == newPassword){
                                        design();
                                        headline(topic);
                                        moveCursor(60,18);
                                        cout<<"Password Maatched With Old Password!!";
                                        moveCursor(60,36);
                                        cout<<"Press any key to continue....";
                                        getch();
                                        goto PASSWORD_TOP;
                                    }
                                    else{
                                        design();
                                        headline(topic);
                                        moveCursor(60,18);
                                        cout<<"Password Did Not Match!!";
                                        moveCursor(60,36);
                                        cout<<"Press any key to continue....";
                                        getch();
                                        goto PASSWORD_TOP;
                                    }
                            }
                            else{
                                design();
                                headline(topic);
                                moveCursor(60,18);
                                cout<<"Invalid Password!!";
                                moveCursor(60,36);
                                cout<<"Press any key to continue....";
                                getch();
                                design();
                                headline(topic);
                                moveCursor(60,18);
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
        }
        fin.close();
        fout.close();
        remove("zlogin.txt");
        rename("zlogin2.txt","zlogin.txt");
        if(error == -1){
            goto CHANGE_TOP;
        }
        else{
            design();
            headline(topic);
            moveCursor(60,18);
            cout<<"Password Changed Successfully!";
            moveCursor(60,36);
            cout<<"Press any key to continue....";
            getch();
        }
}

#endif