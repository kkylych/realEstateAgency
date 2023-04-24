#include <bits/stdc++.h>
using namespace std;

struct accountInfo{
    string accountType;
    string accountLogin;
    string accountPassword;
    string accountName;
    string accountSurname;
};
struct marketingCategoryList{
    string marketingPlace;
    long int budget;
    int amountUsers;
};

vector <accountInfo> accounts;
vector <marketingCategoryList> marketingPlaces;
long int totalBudget;

accountInfo user;
marketingCategoryList marketingPlace;

void dataBase(){
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
    
    marketingPlace = {"Instagram", 100, 10000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Facebook", 100, 1000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Twitter", 100, 2000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Telegram", 100, 1000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Youtube", 100, 100450000};
    marketingPlaces.push_back(marketingPlace);
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

// marketing
void spendBudget(int choice){
    cout << marketingPlaces[choice - 1].marketingPlace << " Budget: " << marketingPlaces[choice - 1].budget << endl;
    long int budgetConsumption;
    cout << "Type the amout of consumption: ";
    cin >> budgetConsumption;
    if(budgetConsumption <= marketingPlaces[choice - 1].budget){
        marketingPlaces[choice - 1].budget = marketingPlaces[choice - 1].budget - budgetConsumption;
        cout << "You successfully spend " << budgetConsumption << " on the company!\n";
    }else if(budgetConsumption < 0){
        cout << "Invalid Input!";
    }else{
        cout << "Your budget consumption exceeds the company budget! Try again!\n";
    }
}
void marketerMenu(){
    cout << "\n1 - Show the category list.\n2 - Show the allocated budget.\n3 - Show the total budget.\n4 - Spend the budget.\n5 - Exit.\n"; 
    
    int choice;
    string goBack;
    cin >> choice;
    
    switch(choice)
    {
      case 1:
        for(int i = 0; i < marketingPlaces.size(); i++){
            cout << i + 1 << ". " << marketingPlaces[i].marketingPlace << endl;
            cout << "Amount of users: " << marketingPlaces[i].amountUsers << endl;
        }
        
        cout << "\nPress any key to go to Menu: \n";
        cin >> goBack;
        marketerMenu();
        break;
        
      case 2:
        for(int i = 0; i < marketingPlaces.size(); i++){
            cout << i + 1 << ". " << marketingPlaces[i].marketingPlace << endl;
            cout << "Budget: " << marketingPlaces[i].budget << endl;
        }
        
        cout << "\nPress any key to go to Menu: \n";
        cin >> goBack;
        marketerMenu();
        break;
        
      case 3:
        totalBudget = 0;
        for(int i = 0; i < marketingPlaces.size(); i++){
            totalBudget = totalBudget + marketingPlaces[i].budget;
        }
        cout << "\nTotal budget right now is " << totalBudget;
        cout << "\nPress any key to go to Menu: \n";
        cin >> goBack;
        marketerMenu();
        break;
    
      case 4:
        tryAgain1:
            cout << "\nChoose the place you would like to spend the budget to promote:\nEnter 0 to go to Menu:\n";
        for(int i = 0; i < marketingPlaces.size(); i++){
            cout << i + 1 << ". " << marketingPlaces[i].marketingPlace << endl;
        }
        
        tryAgain:
            int choice;
            cin >> choice;
        if(choice == 1 or choice == 2 or choice == 3 or choice == 4 or choice == 5){
            spendBudget(choice);
            totalBudget = 0;
            goto tryAgain1;
        }else if(choice == 0){
            marketerMenu();
        }else{
            cout << "Incorrect Input! Try again!\n";
            goto tryAgain;
        }
        break;
      case 5:
        cout << "The programm is terminated! We will be glad to have you back!";
        break;
      default:
        cout << "Invalid Input! Try again!\n";
        marketerMenu();
        break;
    }
}

void chooseMenu(string accountType){
    if(accountType == "1"){
        cout << "\nWelcome, dear Marketer!\nPlease, enter the menu number.\nEnter 5 to finish:";
        marketerMenu();
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
    dataBase();
    startProgramm();
    return 0;
}

