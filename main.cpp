#include <bits/stdc++.h>
using namespace std;

struct accountInfo{
    string accountType;
    string accountLogin;
    string accountPassword;
    string accountName;
    string accountSurname;
};

vector <accountInfo> accounts;
accountInfo user;

void accountDataBase(){
    user = {"1", "Kylych", "1234", "Kylych", "Parpiev"};
    accounts.push_back(user);
    user = {"1", "Takhmina", "1234", "Takhmina", "Parpieva"};
    accounts.push_back(user);
    user = {"1", "Akzhuurat", "1234", "Akzhuurat", "Parpieva"};
    accounts.push_back(user);
    user = {"2", "Akzhuurat", "1234", "Akzhuurat", "Parpieva"};
    accounts.push_back(user);
    user = {"2", "Marat", "1234", "Marat", "Nikiforov"};
    accounts.push_back(user);
    user = {"3", "Andrei", "1234", "Andrei", "Gavrilov"};
    accounts.push_back(user);
    user = {"4", "Arsen", "1234", "Arsen", "Bekbolotov"};
    accounts.push_back(user);
    user = {"5", "Maksat", "1234", "Maksat", "Tashtanov"};
    accounts.push_back(user);
}

void signUp(){
    string accountType, accountLogin, accountPassword, accountName, accountSurname, checkPassword;

    cout << "Enter the type of account: \n 1 - marketing \n 2 - manager \n 3 - worker \n 4 - director \n 5 - sale-manager\n" << endl;
    cin >> accountType;
    if(accountType == "1" or accountType == "2" or accountType == "3" or accountType == "4" or accountType == "5"){
        cout << "Enter your name: ";
        cin >> accountName;
        cout << "Enter your surname: ";
        cin >> accountSurname;
        cout << "Enter login: ";
        cin >> accountLogin;
        
        tryAgain:
            cout << "Enter password: ";
            cin >> accountPassword;
            cout << "Enter password again: ";
            cin >> checkPassword;
        if(checkPassword == accountPassword){
            user = {accountType, accountLogin, accountPassword, accountName, accountSurname};
        }else{
            cout << "Passwords are different! Try again!" << endl;
            goto tryAgain; 
        }
        accounts.push_back(user);
        cout << "You successfully registered! Please, sign in now!" << endl;
    }else{
        cout << "Please, try again!" << endl;
        signUp();
    }
}

void chooseMenu(string accountType){
    if(accountType == "1"){
        cout << "Marketing Menu";
    }else if(accountType == "2"){
        cout << "Manager Menu";
    }else if(accountType == "3"){
        cout << "Worker Menu";
    }else if(accountType == "4"){
        cout << "Director Menu";
    }else if(accountType == "5"){
        cout << "Sale-manager Menu";
    }
}

void signIn(){
    string accountType, accountLogin, accountPassword;

    cout << "Enter the type of account: \n 1 - marketing \n 2 - manager \n 3 - worker \n 4 - director \n 5 - sale-manager\n" << endl;
    cin >> accountType;
    
    if(accountType == "1" or accountType == "2" or accountType == "3" or accountType == "4" or accountType == "5"){
        bool flag = false;
        tryAgain:
            cout << "Enter login: ";
            cin >> accountLogin;
            cout << "Enter password: ";
            cin >> accountPassword;
        for(int i = 0; i < accounts.size(); i++){
            if(accounts[i].accountType == accountType){
                if(accounts[i].accountPassword == accountPassword and accounts[i].accountLogin == accountLogin){
                    flag = true;
                    cout << "You successfully signed in!\n";
                    chooseMenu(accounts[i].accountType);
                    break;
                }
            }
        }
        if(flag == 0){
            cout << "Login or password is wrong! Try again!\n";
            goto tryAgain;
        }    
    }else{
        cout << "Please, try again!" << endl;
        signIn(); 
    }
}

void startProgramm(){
    string accountChoice;
    cout << "To sign up, enter 0.\nTo sign in enter 1." << endl;
    cin >> accountChoice;
    if(accountChoice == "0"){
        signUp();
        startProgramm();
    }else if(accountChoice == "1"){
        signIn();
    }else{
        cout << "Wrong input! Try again." << endl;
        startProgramm();
    }
}

int main(){
    accountDataBase();
    startProgramm();
    return 0;
}
