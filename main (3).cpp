#include <bits/stdc++.h>
using namespace std;

struct accountInfo{
    string accountType;
    string accountLogin;
    string accountPassword;
    string accountName;
    string accountSurname;
    vector <string> employeeTasks;
    int employeeSalary;
    vector <string> completedEmployeeTasks;
    int employeeId;
};
struct marketingCategoryList{
    string marketingPlace;
    long int budget;
    int amountUsers;
};
struct coverageArea{
    string region;
    int amountClients;
};

vector <accountInfo> accounts;
vector <marketingCategoryList> marketingPlaces;
vector <coverageArea> coverageAreaInfo;
long int totalBudget;

accountInfo user;
marketingCategoryList marketingPlace;

coverageArea region;


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
    user = {"2", "Alex", "1234", "Alex", "Shved"};
    accounts.push_back(user);
    user = {"3", "Andrei", "1234", "Andrei", "Gavrilov"};
    accounts.push_back(user);
    user = {"3", "Tamara", "1234", "Tamara", "Alexandrovna", {"do paperwork", "deal with customer complains"}, 15000};
    accounts.push_back(user);
    user = {"3", "Alex", "1234", "Alex", "Shved", {"sell a car", "rent a house", "earn money", "clean up the office"}, 16000};
    accounts.push_back(user);
    user = {"3", "Kolya", "1234", "Kolya", "Zver", {"fix the car", "resell houses"}, 11000};
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
    
    region = {"Bishkek", 15000};
    coverageAreaInfo.push_back(region);
    region = {"Talas", 8000};
    coverageAreaInfo.push_back(region);
    region = {"Osh", 11000};
    coverageAreaInfo.push_back(region);
    region = {"Batken", 4000};
    coverageAreaInfo.push_back(region);
    region = {"Yssyk Kol", 3000};
    coverageAreaInfo.push_back(region);
    region = {"Dzhallalabad", 4500};
    coverageAreaInfo.push_back(region);
    region = {"Naryn", 1000};
    coverageAreaInfo.push_back(region);
    
}




// marketing
void spendBudget(int choice){
    cout << marketingPlaces[choice - 1].marketingPlace << " Budget: " << marketingPlaces[choice - 1].budget << endl;
    long int budgetConsumption;
    cout << "Type the amount of consumption: ";
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
// manager
void showEmployees(){
    for(int i = 0, j = 1; i < accounts.size(); i++){
        if(accounts[i].accountType == "3"){
            accounts[i].employeeId = j;
            cout << j << ". " << accounts[i].accountSurname << " " << accounts[i].accountName << endl;
            j++;
        }
    }
}
void addTasks(){
    cout << "\nChoose the employee you would like to give a task to: \n";
    showEmployees();
        
    int choice;
    cin >> choice;
    cin.ignore();
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].employeeId == choice){
            string employeeTask;
            cout << "Write down a task.\n";
            getline(cin, employeeTask);
            accounts[i].employeeTasks.push_back(employeeTask);
            cout << "You successfully added a task!";
            
        }
    }
}
void showTasks(){
    for(int i = 0, j = 0, k = 1; i < accounts.size(); i++){
        for(int j = 0; j < accounts[i].employeeTasks.size(); j++){
            cout << k << ". " << accounts[i].employeeTasks[j] << endl;
            k++;
        }
    }
}
void showTasksAndEmployees(){
    for(int i = 0, j = 1; i < accounts.size(); i++){
        if(accounts[i].accountType == "3"){
            cout << j << ". " << accounts[i].accountSurname << " " << accounts[i].accountName << endl;
            for(int k = 0, l = 1; k < accounts[i].employeeTasks.size(); k++){
                cout << " - " << l << ". " << accounts[i].employeeTasks[k] << endl;
                l++;
            }
            j++;
        }
    }
}
void showCoverageArea(){
    int totalAmountClients;
    for(int i = 0; i < coverageAreaInfo.size(); i++){
        totalAmountClients = coverageAreaInfo[i].amountClients + totalAmountClients;
    }
    for(int i = 0; i < coverageAreaInfo.size(); i++){
        cout << "\n" << coverageAreaInfo[i].region << ":" << endl;
        cout << " Amount of clients: " << coverageAreaInfo[i].amountClients << endl;
        cout << " Persentage of clients: " << (coverageAreaInfo[i].amountClients * 100) / totalAmountClients << "%\n"; 
    }
}
void managerMenu(){
    cout << "\n 1 - Show the list of employees.\n 2 - Show the to-do list.\n 3 - Show the to-do list for each employee.\n";
    cout << " 4 - Show the list of all coverage areas.\n 5 - Show the total for the real estate.\n 6 - Calculate % for every real estate category.\n 7 - Exit.\n";
        
    string goBack;
    int choice;
    cin >> choice;
    
    switch(choice)
    {
        
      case 1:
        {
            showEmployees();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            managerMenu();
            break;
        }
      case 2:
        {
            tryAgain:
                cout << "\n 0 - Show tasks. \n 1 - Add tasks. \n 2 - Menu. \n";
                string choice;
                cin >> choice;
            if(choice == "0"){
                showTasks();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                managerMenu();
            }else if(choice == "1"){
                addTasks();
                goto tryAgain;
            }else if(choice == "2"){
                managerMenu();
            }else{
                cout << "Invalid Input! Try again!";
                goto tryAgain;
            }
            
            break;
        }
        
      case 3:
        {
            showTasksAndEmployees();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            managerMenu();
            break;
        }
      case 4:
        {
            showCoverageArea();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            managerMenu();
            break;
        }
      case 5:
        
        {
    
            break;
        }
      case 6:
        {
    
            break;
        }
      case 7:
        {
            cout << "The programm is terminated! We will be glad to have you back!";
            break;
        }
      default:
        {
            cout << "Invalid Input! Try again!\n";
            managerMenu();
            break;
        }
    
    }
}
// worker 
string workerPassword, workerLogin;
void workerMenu(){
    for(int i = 0; i < accounts.size(); i++){
        if(workerPassword == accounts[i].accountPassword and workerLogin == accounts[i].accountLogin and accounts[i].accountType == "3"){
            cout << "\nWelcome, dear " << accounts[i].accountName << "!\nPlease, enter the menu item to work with programm. \nIf you finished, enter 5.\n";
            cout << " 1 - Show my tasks. \n 2 - Do my task. \n 3 - Show the completed tasks. \n 4 - Show the salary. \n 5 - Exit.\n";
            string goBack;
            int choice;
            cin >> choice;
            
            switch(choice)
            {
                case 1:
                  {
                    for(int j = 0; j < accounts[i].employeeTasks.size(); j++){
                        cout << j + 1 << ". " << accounts[i].employeeTasks[j] << endl;
                    }
                    cout << "\nPress any key to go to Menu: \n";
                    cin >> goBack;
                    workerMenu();
                    break;
                  }
                  
                case 2:
                  {
                    tryAgain:
                        cout << "\nSelect the task you have already completed.\nPress 0 to go to menu.\n";
                        for(int j = 0; j < accounts[i].employeeTasks.size(); j++){
                            cout << j + 1 << ". " << accounts[i].employeeTasks[j] << endl;
                        }
                        int index;
                        cin >> index;
                    if(index == 0){
                        workerMenu();
                    }else if(index > accounts[i].employeeTasks.size()){
                        cout << "Invalid input! Try again!";
                        goto tryAgain;
                    }else{
                        index = index - 1;
                        string completedTask = accounts[i].employeeTasks[index];
                        accounts[i].employeeTasks.erase(accounts[i].employeeTasks.begin() + index);
                        accounts[i].completedEmployeeTasks.push_back(completedTask);
                        cout << "You successfully completed the task!";
                        goto tryAgain;
                    }
                    break;
                  }
                case 3:
                  {
                    for(int j = 0; j < accounts[i].completedEmployeeTasks.size(); j++){
                        cout << j + 1 << ". " << accounts[i].completedEmployeeTasks[j] << endl;
                    }
                    
                    cout << "\nPress any key to go to Menu: \n";
                    cin >> goBack;
                    workerMenu();
                    break;
                  }
                case 4:
                  {
                    cout << "Your salary right now: " << accounts[i].employeeSalary << " soms.";

                    cout << "\nPress any key to go to Menu: \n";
                    cin >> goBack;
                    workerMenu();
                    break;
                  }
                case 5:
                  {
                    cout << "The programm is terminated! We will be glad to have you back!";
                    break;
                  }
                default:
                  {
                    cout << "Invalid Input! Try again!\n";
                    workerMenu();
                    break;
                  }
            }
            break;
        }
    }
}
//

void chooseMenu(string accountType){
    if(accountType == "1"){
        cout << "\nWelcome, dear Marketer!\nPlease, enter the menu number.\nEnter 5 to finish:";
        marketerMenu();
    }else if(accountType == "2"){
        cout << "\nWelcome, dear Manager! \nPlease, enter the menu number. \nEnter 7 to finish:";
        managerMenu();
    }else if(accountType == "3"){
        workerMenu();
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
            workerPassword = accountPassword;
            workerLogin = accountLogin;
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

