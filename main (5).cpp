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
struct buildEquipment{
    string equipment;
    int amountEquipment;
};
struct clientInfo{
    string clientName;
    string clientSurname;
    string clientStatus;
};
struct apartment{
    string apartmentAddress;
    string apartmentStatus; 
    string apartmentSaleStatus; 
    int apartmentPrice;
    int rentPrice;
    string apartmentOwner;
};

vector <accountInfo> accounts;
vector <marketingCategoryList> marketingPlaces;
vector <coverageArea> coverageAreaInfo;
vector <buildEquipment> buildingEquipment;
vector <clientInfo> clients;
vector <apartment> apartments;

apartment apartmentObject;
long int totalBudget;
long int totalSalaryBudget;
long int realEstateBudget;
long int rentBudget;
accountInfo user;
marketingCategoryList marketingPlace;
coverageArea region;
buildEquipment equipment;
clientInfo client;

bool comp(apartment a, apartment b){
    return a.apartmentPrice > b.apartmentPrice;
}
bool comp1(apartment a, apartment b){
    return a.apartmentPrice < b.apartmentPrice;
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
    user = {"3", "Andrei", "1234", "Andrei", "Gavrilov", {"talk to customers"}, 9000};
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
    
    marketingPlace = {"Instagram", 330000000, 10000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Facebook", 40000000, 1000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Twitter", 200000, 2000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Telegram", 4500000, 1000000};
    marketingPlaces.push_back(marketingPlace);
    marketingPlace = {"Youtube", 200000, 100450000};
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
    
    equipment = {"Excavator", 20};
    buildingEquipment.push_back(equipment);
    equipment = {"Bulldozer", 15};
    buildingEquipment.push_back(equipment);
    equipment = {"Crane", 10};
    buildingEquipment.push_back(equipment);
    equipment = {"Concrete mixer", 5};
    buildingEquipment.push_back(equipment);
    equipment = {"Mobile crane", 10};
    buildingEquipment.push_back(equipment);
    equipment = {"Power generator", 25};
    buildingEquipment.push_back(equipment);
    
    apartmentObject = {"Lenina 1", "FREE", "TOBUY", 2000000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Akhunbaeva 23", "OCCUPIED", "SOLD", 1200000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Moskovskaya 5", "FREE", "TORENT", 3000000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Kirova 53", "OCCUPIED", "RENTED", 2500000, 40000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Gagarina 37", "OCCUPIED", "SOLD", 3200000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Lenina 11", "FREE", "TOBUY", 6400000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Moldybaeva 28", "FREE", "TORENT", 3400000, 10000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Bekbalaeva 45", "OCCUPIED", "LONG-RENTED", 8900000, 10000};
    apartments.push_back(apartmentObject);
    apartmentObject = {"Kulatova 67", "OCCUPIED", "LONG-RENTED", 4500000, 15000};
    apartments.push_back(apartmentObject);
    
    client = {"Lebron", "James", "has bought an apartment at Panfilova 28"};
    clients.push_back(client);
    client = {"Maksim", "Galkin", "has bought an apartment at Moskovskaya 75"};
    clients.push_back(client);
    client = {"Filip", "Kirkorov", "has bought an apartment at Bekbolaeva 20"};
    clients.push_back(client);
    client = {"Alla", "Pugacheva"};
    clients.push_back(client);
    client = {"Bill", "Gates"};
    clients.push_back(client);
    client = {"Selena", "Gomez", "has bought an apartment at Kulatova 5"};
    clients.push_back(client);
    client = {"Justin", "Bieber"};
    clients.push_back(client);
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
void showAllocatedBudget(){
    for(int i = 0; i < marketingPlaces.size(); i++){
        cout << i + 1 << ". " << marketingPlaces[i].marketingPlace << endl;
        cout << "Budget: " << marketingPlaces[i].budget << " soms" << endl;
    }
}
void showMarketingTotalBudget(){
    totalBudget = 0;
    for(int i = 0; i < marketingPlaces.size(); i++){
        totalBudget = totalBudget + marketingPlaces[i].budget;
    }
    cout << "\nTotal budget right now is " << totalBudget << " soms";
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
        showAllocatedBudget();
        cout << "\nPress any key to go to Menu: \n";
        cin >> goBack;
        marketerMenu();
        break;
        
      case 3:
        showMarketingTotalBudget();
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
void showTotalRealEstateBudget(){
    realEstateBudget = 0;
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "FREE" and apartments[i].apartmentSaleStatus == "TOBUY"){
            realEstateBudget = apartments[i].apartmentPrice + realEstateBudget;
        }
    }
    cout << "The total budget for the real estate (apartments): " << realEstateBudget; 
}
void showRentBudget(){
    rentBudget = 0;
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "OCCUPIED" and apartments[i].apartmentSaleStatus == "RENTED"){
            rentBudget = apartments[i].apartmentPrice + rentBudget;
        }
    }
    cout << "The total budget for the rent (apartments): " << rentBudget; 
}
void showLeasingBudget(){
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "OCCUPIED" and apartments[i].apartmentSaleStatus == "LONG-RENTED"){
            cout << "Apartment " << j << ": \n";
            cout << " Address: " << apartments[i].apartmentAddress << endl;
            cout << " Rent price: " << apartments[i].rentPrice << endl;
            j++;
        }
    }
}

void calculatePercentageRealEstate(){
    int amountOfApartments = 0;
    int amountOfRent = 0;
    int amountOfSell = 0;
    int amountOfLongRent;
    for(int i = 0; i < apartments.size(); i++){
        amountOfApartments += 1;
    }
    for(int i = 0; i < apartments.size(); i++){
        if(apartments[i].apartmentSaleStatus == "RENTED" or apartments[i].apartmentSaleStatus == "TORENT"){
            amountOfRent += 1;
        }
    }
    for(int i = 0; i < apartments.size(); i++){
        if(apartments[i].apartmentSaleStatus == "SOLD" or apartments[i].apartmentSaleStatus == "TOBUY"){
            amountOfSell += 1;
        }
    }
    for(int i = 0; i < apartments.size(); i++){
        if(apartments[i].apartmentSaleStatus == "LONG-RENTED"){
            amountOfLongRent += 1;
        }
    }
    cout << "The list of real estate: 100%\n";
    cout << "The persentage of rent: " << (amountOfRent * 100) / amountOfApartments << "%\n";
    cout << "The persentage of sold objects: " << (amountOfSell * 100) / amountOfApartments << "%\n";
    cout << "The persentage of leasing objects: " << (amountOfLongRent * 100) / amountOfApartments << "%\n";
    
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
            tryAgain1:
                cout << " 0 - Real Estate Budget.\n 1 - Rent Budget.\n 2 - Leasing Budget.\n ";
                string choice;
                cin >> choice;
            if(choice == "0"){
                showTotalRealEstateBudget();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                managerMenu();
            }else if(choice == "1"){
                showRentBudget();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                managerMenu();
            }else if(choice == "2"){
                showLeasingBudget();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                managerMenu();
            }else{
                cout << "Invalid Input! Try again!\n";
                goto tryAgain1;
            }
            break;
        }
      case 6:
        {
            calculatePercentageRealEstate();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            managerMenu();
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
// director
void showSalaryBudget(){
    for(int i = 0, j = 1; i < accounts.size(); i++){
        if(accounts[i].accountType == "3"){
            cout << j << ". " << accounts[i].accountName << " " << accounts[i].accountSurname << endl;
            cout << "Salary: " << accounts[i].employeeSalary << endl;
            j++;
        }
    }
}
void showTotalSalaryBudget(){
    totalSalaryBudget = 0;
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].accountType == "3"){
            totalSalaryBudget = accounts[i].employeeSalary + totalSalaryBudget;
        }
    }
    cout << "Total budget for salary now: " << totalSalaryBudget;
}
void increaseSalary(){
    string name;
    int salaryIncrement;
    cout << "\nType the last and the first name of the employee whose salary you would like to increase: \n";
    showEmployees();
    cin.ignore();
    getline(cin, name);
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].accountType == "3" and accounts[i].accountSurname + " " + accounts[i].accountName == name){
            cout << "Worker: " << accounts[i].accountSurname << " " << accounts[i].accountName << endl;
            cout << "The salary now: " << accounts[i].employeeSalary << endl;
            cout << "Type the amount of salary increment: \n";
            cin >> salaryIncrement;
            accounts[i].employeeSalary = accounts[i].employeeSalary + salaryIncrement;
            cout << "Salary increment has been added successfully!\n";
            cout << "The salary now: " << accounts[i].employeeSalary;
            break;
        }
    }
}
void decreaseSalary(){
    string name;
    int salaryIncrement;
    cout << "\nType the last and the first name of the employee whose salary you would like to decrease: \n";
    showEmployees();
    cin.ignore();
    getline(cin, name);
    for(int i = 0; i < accounts.size(); i++){
        if(accounts[i].accountType == "3" and accounts[i].accountSurname + " " + accounts[i].accountName == name){
            cout << "Worker: " << accounts[i].accountSurname << " " << accounts[i].accountName << endl;
            cout << "The salary now: " << accounts[i].employeeSalary << endl;
            cout << "Type the amount of salary decrement: \n";
            cin >> salaryIncrement;
            accounts[i].employeeSalary = accounts[i].employeeSalary - salaryIncrement;
            cout << "Salary decrement has been activated successfully!\n";
            cout << "The salary now: " << accounts[i].employeeSalary;
            break;
        }
    }
}
void showEquipment(){
    for(int i = 0; i < buildingEquipment.size(); i++){
        cout << " " << buildingEquipment[i].equipment << endl;
        cout << "Amount: " << buildingEquipment[i].amountEquipment << endl;
    }
}
void directorMenu(){
    cout << "\n 1 - Show the list of all coverage areas.\n 2 - Show the budget list.\n 3 - Show the allocated budget.\n 4 - Show the total marketing budget.\n";
    cout << " 5 - Show the total salary budget.\n 6 - Increase salary.\n 7 - Decrease salary.\n 8 - Show the equipment list for building objects.\n 9 - Exit.\n";
    
    string goBack;
    int choice;
    cin >> choice;
    
    switch(choice){
        case 1:
        {
            showCoverageArea();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 2:
        {
            tryAgain:
                cout << "\n 0 - Marketing budget.\n 1 - Salary budget.\n";
                string choice;
                cin >> choice;
            if(choice == "0"){
                showAllocatedBudget();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                directorMenu();
            }else if(choice == "1"){
                showSalaryBudget();
                cout << "\nPress any key to go to Menu: \n";
                cin >> goBack;
                directorMenu();
            }else{
                cout << "Invalid input! Try again!";
                goto tryAgain;
            }
            break;
        }
        
        case 3:
        {
            showAllocatedBudget();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;  
        }
        
        case 4:
        {
            showMarketingTotalBudget();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 5:
        {
            showTotalSalaryBudget();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 6:
        {
            increaseSalary();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 7:
        {
            decreaseSalary();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 8:
        {
            showEquipment();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            directorMenu();
            break;
        }
        
        case 9:
        {
            cout << "The programm is terminated! We will be glad to have you back!";
            break;
        }
        
        default:
        {
            cout << "Invalid Input! Try again!\n";
            directorMenu();
            break;
        }
    }
    
}

// sale manager
void showClients(){
    for(int i = 0; i < clients.size(); i++){
        cout << i + 1 << ". " << clients[i].clientName << " " << clients[i].clientSurname << endl;
    }
}
void searchClient(){
    cout << "\nType the first name and the last name of the client: \n";
    string name;
    cin.ignore();
    getline(cin, name);
    for(int i = 0; i < clients.size(); i++){
        if(clients[i].clientName + " " + clients[i].clientSurname == name or clients[i].clientName == name){
            cout << "Client has been found: " << clients[i].clientName << " " << clients[i].clientSurname << endl;
            cout << "Client information: " << clients[i].clientStatus << endl;
        }
    }
    
    
}
void showFreeApartmentsToBuy(){
    cout << "\nFree apartments to buy: \n";
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "FREE" and apartments[i].apartmentSaleStatus == "TOBUY"){
            cout << "Apartment " << j << ": \n";
            cout << " Address: " << apartments[i].apartmentAddress << endl;
            cout << " Price: " << apartments[i].apartmentPrice << endl;
            j++;
        }
    }
}
void showSoldApartments(){
    cout << "\nSold apartments: \n";
    for(int i = 0, j = 0; i < apartments.size(); i++){
        if(apartments[i].apartmentSaleStatus == "SOLD"){
            cout << "Apartment " << j + 1 << ": \n";
            cout << " Address: " << apartments[i].apartmentAddress << endl;
            cout << " Price: " << apartments[i].apartmentPrice << endl;
            j++;
        }
    }
}
void showMostExpensiveApartment(){
    sort(apartments.begin(), apartments.end(), comp);
    for(int i = 0; i < apartments.size(); i++){
        cout << "Apartment " << i + 1 << ": \n";
        cout << " Address: " << apartments[i].apartmentAddress << endl;
        cout << " Price: " << apartments[i].apartmentPrice << endl;
    }
}
void showCheapestApartment(){
    sort(apartments.begin(), apartments.end(), comp1);
    for(int i = 0; i < apartments.size(); i++){
        cout << "Apartment " << i + 1 << ": \n";
        cout << " Address: " << apartments[i].apartmentAddress << endl;
        cout << " Price: " << apartments[i].apartmentPrice << endl;
    }
}
void showFreeApartments(){
    cout << "\nFree apartments: \n";
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "FREE"){
            cout << "Apartment " << j << ": \n";
            cout << " Address: " << apartments[i].apartmentAddress << endl;
            cout << " Price: " << apartments[i].apartmentPrice << endl;
            j++;
        }
    }
}
void sellApartment(){
    string address, ownerName, ownerSurname;
    int price;
    cout << "Enter the address of the apartment: \n";
    cin.ignore();
    getline(cin, address);
    
    cout << "Enter the first name of the new owner: \n";
    cin >> ownerName;
    cout << "Enter the last name of the new owner: \n";
    cin >> ownerSurname;
    
    cout << "Enter the price: \n";
    cin >> price;
    
    apartmentObject = {address, "OCCUPIED", "SOLD", price};
    apartmentObject.apartmentOwner = ownerName;
    client.clientName = ownerName;
    client.clientSurname = ownerSurname;
    string phrase = " has bought an apartment at ";
    client.clientStatus = phrase.append(address);
    clients.push_back(client);
    apartments.push_back(apartmentObject);
    cout << "You have successfully sold an apartment!\n";
    
}
void rentApartment(){
    string address, customer, deadline;
    int price;
    
    cout << "Enter the address of the apartment: \n";
    cin.ignore();
    getline(cin, address);
    
    cout << "Enter the name of the customer: \n";
    cin.ignore();
    getline(cin, customer);
    
    cout << "Enter the date of deadline: \n";
    cin.ignore();
    getline(cin, deadline);
    
    cout << "Enter the price for one month: \n";
    cin >> price;

    apartmentObject = {address, "OCCUPIED", "RENTED"};
    apartmentObject.apartmentOwner = customer;
    apartmentObject.rentPrice = price;
    apartments.push_back(apartmentObject);
    cout << "You have successfully rented an apartment!\n";
}
void showOccupiedApartments(){
    cout << "\nOccupied apartments: \n";
    for(int i = 0, j = 1; i < apartments.size(); i++){
        if(apartments[i].apartmentStatus == "OCCUPIED"){
            cout << "Apartment " << j << ": \n";
            cout << " Address: " << apartments[i].apartmentAddress << endl;
            cout << " Price: " << apartments[i].apartmentPrice << endl;
            j++;
        }
    }
}
void saleManagerMenu(){
    cout << "\n 1 - Show clients.\n 2 - Search a client.\n 3 - Show free apartments to buy.\n 4 - Show sold apartments. \n 5 - Show the most expensive apartment.\n";
    cout << " 6 - Show the cheapest apartment.\n 7 - Sell an apartment.\n 8 - Rent an apartment.\n 9 - Show free apartments.\n 10 - Show occupied apartments.\n 11 - Exit.\n";
    
    string goBack;
    int choice;
    cin >> choice;
    
    switch(choice)
    {
        case 1:
        {
            showClients();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 2:
        {
            searchClient();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 3:
        {
            showFreeApartmentsToBuy();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 4:
        {
            showSoldApartments();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 5:
        {
            showMostExpensiveApartment();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 6:
        {
            showCheapestApartment();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 7:
        {
            sellApartment();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 8:
        {
            rentApartment();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 9:
        {
            showFreeApartments();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 10:
        {
            showOccupiedApartments();
            cout << "\nPress any key to go to Menu: \n";
            cin >> goBack;
            saleManagerMenu();
            break;
        }
        
        case 11:
        {
            cout << "The programm is terminated! We will be glad to have you back!";
            break;
        }
        
        default:
        {
            cout << "Invalid Input! Try again!\n";
            saleManagerMenu();
            break;
        }
    }
    
}

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
        cout << "\nWelcome, dear Director! \nPlease, enter the menu number. \nEnter 9 to finish:";
        directorMenu();
    }else if(accountType == "5"){
        cout << "\nWelcome, dear Sale-manager! \nPlease, enter the menu number. \nEnter 11 to finish:";
        saleManagerMenu();
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


