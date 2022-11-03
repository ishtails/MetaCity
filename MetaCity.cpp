#include<iostream>
#include<fstream>
#include<conio.h>
#include<cstdlib>
#include <cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<ctime>
#include<unistd.h>
using namespace std;

class collectibles{
    int worth; string name, type, rarity;

    public:
        collectibles(string a, string b, string c, int d){
            name = a; type = b; rarity = c; worth = d;
            }

        string getName(){return name;}
        string getRarity(){return rarity;}
        int getWorth(){return worth;}

        void displayStats(){
            cout<<"Name: "<<name<<endl;
            cout<<"Type: "<<type<<endl;
            cout<<"Rarity: "<<rarity<<endl;
            cout<<"Worth: "<<worth<<endl<<endl;
        }
};
collectibles null1("NULL", "NULL", "NULL", 0);
collectibles e1("Gold Coin", "Coin", "Epic", 2000);
collectibles r1("Silver Coin", "Coin", "Rare", 1000);
collectibles c1("Bronze Coin", "Coin", "Common", 500);
collectibles e2("Red Card", "Card", "Epic", 2000);
collectibles r2("Blue Card", "Card", "Rare", 1000);
collectibles c2("Yellow Card", "Card", "Common", 500);
collectibles l1("Golden Pikachu", "NFT", "Legendary", 5000);
collectibles l2("Red Dragon", "NFT", "Legendary", 5000);
vector<collectibles> allCollectibles(10000, null1);

class users{
    string username, fullname; int age, credits=2000, level=1; vector<string> avatar = {"Default"}; vector<int> collection;

    public:
        users(string a, string b, int c){username = a; fullname = b; age = c;}

        string getUsername(){return username;}
        void addCredits(int x){credits += x;}
        void spendCredits(int x){credits -= x;}
        int getCredits(){return credits;}
        void levelup(){level++;}
        void addAvatar(string s){avatar.push_back(s);}
        void addCollectible(int x){collection.push_back(x);}
        void displayStats(){
            cout<<"Username: "<<username<<endl;
            cout<<"Full Name: "<<fullname<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Credits: "<<credits<<endl;
            cout<<"Level: "<<level<<endl;
            cout<<"Avatars: ";
            for (int i = 0; i < avatar.size(); i++){cout<<avatar[i]<<", ";}
            cout<<endl<<endl;
        }
        void displayCollectibles(){
            if(collection.size() != 0){
                cout<<"Your Collection: [\n";
            
            for (int i = 0; i < collection.size(); i++){
                cout<<"ItemID: "<<collection[i]<<endl;
                allCollectibles[collection[i]].displayStats();
            }
            cout<<"]"<<endl<<endl;
            }

            else{
                cout<<"You do not have any items in your collection currently. Visit a PlayZone or Explorable to collect Cards, Coins & much more...\n\n";
            }

            cout<<"Press Any Key to Continue...\n";
            getch();
        }
}; 
users null("NULL", "NULL", 0);
users t1("ishtails", "Kartikay Tiwari", 21);
users t2("vichu", "Vyshnav Ajith", 19);
users t3("coccoomber", "Arjun Binu", 18);
vector<users> allUsers = {t1, t2, t3};

class maintainers{
    string userid, fullname, job; int age;

    public:
        maintainers(string a, string b, string c, int d){userid = a; fullname = b; job = c; age = d;}
        string getUserid(){return userid;}
        void displayStats(){
            cout<<"Username: "<<userid<<endl;
            cout<<"Full Name: "<<fullname<<endl;
            cout<<"Age: "<<age<<endl;
            cout<<"Job: "<<job<<endl;
        }
};
maintainers kartik("ishtails", "Kartikay Tiwari", "Developer", 21);
maintainers vysh("vichu", "Vyshnav Ajith", "Security", 19);
maintainers arjun("coccoomber", "Arjun Binu", "Helpdesk", 18);
vector<maintainers> allAdmins = {kartik, vysh, arjun};

class expo{
    public:
    string title, address; int ticketPrice, maxOcc;
    virtual void displayStats() = 0;
};

class playzones:public expo{
    string genre; int tier;

    public:
        playzones(string a, string b, int c, int d, string e, int f){title = a; address = b; ticketPrice = c; maxOcc = d; genre = e; tier = f;}

        void displayStats(){
            cout<<"Title: "<<title<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Ticket Price: "<<ticketPrice<<endl;
            cout<<"Max Occupancy: "<<maxOcc<<endl;
            cout<<"Genre: "<<genre<<endl;
            cout<<"Tier: "<<tier<<endl<<endl;
        }
};
playzones xbox("Xbox", "0.0.0.1", 150, 20, "E-Sports", 1);
playzones nintendo("Nintendo", "0.0.0.2", 150, 25, "Arcade", 1);
playzones ps("PlayStation", "0.0.0.3", 150, 30, "Action", 1);
playzones disney("DisneyLand", "0.0.0.4", 300, 90, "Amusement Park", 2);
playzones aquatica("Aquatica", "0.0.0.5", 300, 80, "Water Park", 2);
playzones casino("Royal City", "0.0.0.6", 500, 100, "Gambling & Casino", 3);
vector<playzones> allPlazones = {xbox, nintendo, ps, disney, aquatica, casino};

class explorables:public expo{
    string classification;
    
    public:
        explorables(string a, string b, int c, int d, string e){title = a; address = b; ticketPrice = c; maxOcc = d; classification = e;}

        void displayStats(){
            cout<<"Title: "<<title<<endl;
            cout<<"Address: "<<address<<endl;
            cout<<"Ticket Price: "<<ticketPrice<<endl;
            cout<<"Max Occupancy: "<<maxOcc<<endl;
            cout<<"Classification: "<<classification<<endl<<endl;
        }
};
explorables wonders("Seven Wonders of the World", "0.0.1.1", 300, 1000, "Monuments");
explorables arch("Magics of Mankind", "0.0.1.2", 350, 800, "Architectural Masterpieces");
explorables museum("The Galleria", "0.0.1.3", 300, 700, "Art & Historical Museum");
explorables mall("MetaMall", "0.0.1.4", 200, 300, "Shopping Mall");
explorables zoo("Wildnest", "0.0.1.5", 300, 500, "Zoo");
vector<explorables> allExplorables = {wonders, arch, museum, mall, zoo};

int checkExistingUser(string);
int userAuth(string, int);
int adminAuth(string, int);
int mainMenu();
int userMenu(int);
int maintainerMenu(int);
int userLogin();
int maintainerLogin();
void registerUser();
void showAllCollectibles();
void collectibleInit();
void usersInit();
void lottery(int);

int main(){
    srand(time(NULL));
    collectibleInit();
    usersInit();
    int exit1 = 0;
    
    do{
        switch (mainMenu()){
            case 1:{
                int userToken = userLogin(); int exit2 = 0;
                if(userToken != -1){
                    do
                    {
                        switch (userMenu(userToken))
                        {
                        case 1:{
                            char temp;
                            cout<<"Current Stats:\n";
                            allUsers[userToken].displayStats();
                            cout<<"Press any key to go back...";
                            getch();
                            }
                            break;
                        
                        case 2:
                            allUsers[userToken].displayCollectibles();
                            break;
                        
                        case 3:{
                                string address;
                                for (int i = 0; i < allPlazones.size(); i++){allPlazones[i].displayStats();}
                                cout<<"\nEnter Adress: ";
                                cin>>address;

                                if(address == "0.0.0.1"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Xbox! You will be charged "<<allPlazones[0].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("xbox.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[0].ticketPrice);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}                         
                                }

                                else if(address == "0.0.0.2"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Nintendo! You will be charged "<<allPlazones[1].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("nintendo.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[1].ticketPrice);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.0.3"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit PlayStation! You will be charged "<<allPlazones[2].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("ps.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[2].ticketPrice);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.0.4"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit DisneyLand! You will be charged "<<allPlazones[3].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("disney.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[3].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.0.5"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Aquatica! You will be charged "<<allPlazones[4].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("aquatica.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[4].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.0.6"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Royal City Casino! You will be charged "<<allPlazones[5].ticketPrice<<" credits...\n";
                                    sleep(1);
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("casino.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allPlazones[5].ticketPrice);

                                        cout<<"\nLet's try your luck on the Reward wheel! Press any key to spin...";
                                        getch();
                                        
                                        cout<<endl;
                                        for (int i = 0; i < 3; i++)
                                        {
                                            cout<<"\nWheel Spinning..."<<endl;
                                            sleep(1);
                                        }
                                        cout<<endl;

                                        int rewardID = rand()%10000;                                  

                                        if(allCollectibles[rewardID].getName() != "NULL"){
                                            if(allCollectibles[rewardID].getRarity() == "Legendary"){
                                                cout<<"WOOOAAAAHHH!!!! YOU'VE WON A LEGENDARY ITEM!!\n";
                                            }

                                            else{cout<<"Congratualations! You've won a "<< allCollectibles[rewardID].getName()<<"!!!\n\n";}
                                            
                                            cout<<"Item Details:\n";
                                            cout<<"ItemID: "<<rewardID<<endl;
                                            allCollectibles[rewardID].displayStats();

                                            allUsers[userToken].addCollectible(rewardID);
                                            allUsers[userToken].addCredits(allCollectibles[rewardID].getWorth());
                                            cout<<allCollectibles[rewardID].getWorth()<<" credits have been added to your balance!\n";
                                        }

                                        else{
                                            cout<<"Oh-no! You didn't win anything... Better luck next time!";
                                        }                                  

                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}
                                }

                                else{
                                    cout<<"Error! No PlayZone found on the address! Press any key to go back...\n";
                                    getch();
                                }
                            }
                            break;
                        
                        case 4:{
                                string address;
                                for (int i = 0; i < allExplorables.size(); i++){allExplorables[i].displayStats();}
                                cout<<"\nEnter Adress: ";
                                cin>>address;

                                if(address == "0.0.1.1"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Seven Wonders of The World! You will be charged "<<allExplorables[0].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("wonders.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allExplorables[0].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}                         
                                }

                                else if(address == "0.0.1.2"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Magics of Mankind! You will be charged "<<allExplorables[1].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("arch.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allExplorables[1].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.1.3"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit The Galleria! You will be charged "<<allExplorables[2].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("museum.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allExplorables[2].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.1.4"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit MetaMall! You will be charged "<<allExplorables[3].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("mall.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allExplorables[3].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }
                                
                                else if(address == "0.0.1.5"){
                                    char confirm;
                                    cout<<"\nYou are trying to visit Wildnest! You will be charged "<<allExplorables[4].ticketPrice<<" credits...\n";
                                    cout<<"Do your wish to continue? (Press 'y' to confirm): ";
                                    cin>>confirm;

                                    if(confirm == 'Y' || confirm == 'y'){
                                        cout<<endl;
                                        cout<<"Loading...\n"; sleep(1);
                                        string str;
                                        ifstream MyReadFile("zoo.txt");
                                        while (getline (MyReadFile, str)) {cout << str <<endl;}
                                        MyReadFile.close();
                                        allUsers[userToken].spendCredits(allExplorables[4].ticketPrice);
                                        lottery(userToken);
                                        cout<<"\nRemaining Credits: "<<allUsers[userToken].getCredits()<<"! Press any key to go back...\n";
                                        getch();
                                    } else{break;}  
                                }

                                else{
                                    cout<<"Error! No Explorable found on the address! Press any key to go back...\n";
                                    getch();
                                }
                            }
                            break;
                        
                        case 5:{
                            time_t result = time(nullptr);                            
                            string str;
                            ofstream MyFile("complaints.txt", fstream::app);
                            cout<<"Tell us about your issue: (Press ENTER to submit): ";
                            cin.ignore();
                            getline(cin, str);
                            str = str + " - by $" + allUsers[userToken].getUsername() + " : " + asctime(localtime(&result)) + "\n";
                            MyFile << str;
                            MyFile.close();
                            cout<<"Complaint logged successfully... (Press any key to go back)";
                            getch();
                            }
                            break;

                        case 6:
                            exit2 = 1;
                            break;

                        default:
                            break;
                        }
                    } while (exit2 == 0);
                }

                else{registerUser();}
                break;
            }
            
            case 2:{
                int adminToken = maintainerLogin(); int exit3 = 0;
                    do
                    {
                        switch (maintainerMenu(adminToken))
                        {
                        case 1:{
                            char temp;
                            cout<<"Current stats:\n";
                            allAdmins[adminToken].displayStats();
                            cout<<"\nPress any key to go back...";
                            getch();
                            }
                            break;
                        
                        case 2:{
                            if(allUsers.empty()){
                                cout<<"No users active! Press any key to go back...\n";
                                getch();
                            } else{
                                for (int i = 0; i < allUsers.size(); i++){
                                    if(allUsers[i].getUsername() == "NULL"){
                                        continue;
                                    }
                                    allUsers[i].displayStats();}
                                cout<<"Press any key to continue...\n";
                                getch();
                            }
                            }
                            
                            break;

                        case 3:{string user;
                            cout<<"Enter username of the user to be suspended: ";
                            cin>>user;

                            int i = 0;
                            for (i = 0; i < allUsers.size(); i++)
                            {
                                if(allUsers[i].getUsername() == user){
                                    allUsers[i] = null;
                                    break;
                                }
                            }

                            if(i == allUsers.size() + 1){cout<<"No such user exists!\n";}
                            else{cout<<"User banned!\n";}
                            cout<<"\nPress any key to go back...\n";
                            getch();                                                    
                        }
                            break;
                        
                        case 4:{
                            ifstream ifile;
                            ifile.open("complaints.txt");
                            if(ifile){
                                string str;
                                cout<<"************ User Complaints ************\n";
                                cout<<"----------------------------------------- \n";
                                ifstream MyReadFile("complaints.txt");
                                while (getline (MyReadFile, str)) {cout << str <<endl;}
                                MyReadFile.close();
                                cout<<"\nPress any key to go back...\n";
                                getch();
                            } else{
                                cout<<"Complaint register empty!\n";
                            }
                            }
                            break;

                        case 5:
                            exit3 = 1;
                            break;

                        default:
                            cout<<"\n############################## ERROR! ENTER A VALID OPTION... ################################\n";
                            break;
                        }
                    } while (exit3 == 0);
                
                break;
            }

            case 3:{
                registerUser();
                break;
            }

            case 4:{
                exit1 = 1;
                break;
            }

            default:
                cout<<"\n############################## ERROR! ENTER A VALID OPTION... ################################\n";
                break;
        }
    } while(exit1 == 0);

    remove("complaints.txt");
}

int mainMenu(){
    int choice = 0;
    cout<<"\n----------------------------------------- MAIN MENU -----------------------------------------\n\n";
    cout<<" Welcome to Metacity! Select an option...\n\n";
    cout<<" 1. Login as a user...\n";
    cout<<" 2. Login as a maintainer...\n";
    cout<<" 3. Register as a new user...\n";
    cout<<" 4. Exit...\n";
    cout<<"\n*********************************************************************************************\n\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    return choice;
}
int userMenu(int token){
    int choice = 0;
    cout<<"\n----------------------------------------- USER MENU -----------------------------------------\n\n";
    cout<<" Welcome "<<allUsers[token].getUsername()<<"! What would you like to do today?\n\n";
    cout<<" 1. Show your stats...\n";
    cout<<" 2. Show your collectibles...\n";
    cout<<" 3. Visit a PlayZone...\n";
    cout<<" 4. List of places to see...\n";
    cout<<" 5. Register a complaint...\n";
    cout<<" 6. Log Out...\n";
    cout<<"\n*********************************************************************************************\n\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    return choice;
}
int maintainerMenu(int token){
    int choice = 0;
    cout<<"\n-------------------------------------- MAINTAINER MENU --------------------------------------\n\n";
    cout<<" Welcome "<<allAdmins[token].getUserid()<<"! What would you like to do today?\n\n";
    cout<<" 1. Show your info...\n";
    cout<<" 2. Show all active users...\n";
    cout<<" 3. Kick out a user...\n";
    cout<<" 4. Show all complaints...\n";
    cout<<" 5. Log Out...\n";
    cout<<"\n*********************************************************************************************\n\n";
    cout<<"Enter your choice: ";
    cin>>choice;
    cout<<endl;
    return choice;
}

int checkExistingUser(string username){
    for (int i = 0; i < allUsers.size(); i++)
    {
        if(username == allUsers[i].getUsername()){
            cout<<"Username already exists! Please enter another username!"<<endl;
            return 1;
        }
    } return 0;
}
int userAuth(string username, int token){
    if(token >= allUsers.size()){
        cout<<"Username & Token does not match. Please recheck and enter again!\n\n";
        return 1;
    }

    if(allUsers[token].getUsername() != username){
        cout<<"Username & Token does not match. Please recheck and enter again!\n\n";
        return 1;
    }
    
    return 0;
}
int adminAuth(string userid, int token){
    if(token >= allAdmins.size()){
        cout<<"UserID & Token does not match. Please recheck and enter again!\n\n";
        return 1;
    }

    if(allAdmins[token].getUserid() != userid){
        cout<<"UserID & Token does not match. Please recheck and enter again!\n\n";
        return 1;
    }
    
    return 0;
}
void collectibleInit(){
    for (int i = 0; i < 10000; i++){
        int randNum = rand()%10000;

        if(allCollectibles[i].getName() == "NULL"){
            if(randNum>0 && randNum<2000){allCollectibles[i] = c1;}
            else if(randNum>2000 && randNum<4000){allCollectibles[i] = c2;}
            else if(randNum>4000 && randNum<6000){continue;}
            else if(randNum>6000 && randNum<7500){allCollectibles[i] = r2;}
            else if(randNum>7500 && randNum<9000){allCollectibles[i] = r1;}
            else if(randNum>9000 && randNum<9400){allCollectibles[i] = e1;}
            else if(randNum>9400 && randNum<9800){allCollectibles[randNum] = e2;}
            else if(randNum>9800 && randNum<9900){allCollectibles[randNum] = l2;}
            else{allCollectibles[randNum] = l1;}
        }      
    }
}
void usersInit(){
    allUsers[0].addCredits(8000); allUsers[1].addCredits(8000); allUsers[2].addCredits(8000);
    allUsers[0].levelup(); allUsers[1].levelup(); allUsers[2].levelup();
    allUsers[0].levelup(); allUsers[1].levelup(); allUsers[2].levelup();
    allUsers[0].addAvatar("Rockstar"); allUsers[0].addAvatar("Dark Knight");
    allUsers[1].addAvatar("Mickey Mouse"); allUsers[1].addAvatar("Invisible Man");
    allUsers[2].addAvatar("Doraemon"); allUsers[2].addAvatar("Pablo Escobar");
}
void lottery(int token){
    srand(time(0));
    int chanceToWin = rand()%5 + 1;
    if(chanceToWin == 1 || chanceToWin == 4){
        int rewardID = rand()%10000;        
        if(allCollectibles[rewardID].getName() != "NULL" && allCollectibles[rewardID].getRarity() != "Legendary"){
            cout<<"Congratualations! You've found a "<< allCollectibles[rewardID].getName()<<"!!!\n\n";
            cout<<"Item Details:\n";
            cout<<"ItemID: "<<rewardID<<endl;
            allCollectibles[rewardID].displayStats();
            allUsers[token].addCollectible(rewardID);
            allUsers[token].addCredits(allCollectibles[rewardID].getWorth());
            cout<<allCollectibles[rewardID].getWorth()<<" credits have been added to your balance!\n";
        }
    }
}

int userLogin(){
    cout<<"\n----------------------------------------- USER LOGIN ----------------------------------------\n";
    string username; int token;

    if(allUsers.empty() == true){
        cout<<"No users registered yet! Redirecting to Registration page...\n";
        return -1;
    }

    do{
        cout<<"Enter your username: ";
        cin>>username;

        cout<<"Enter your token number: ";
        cin>>token;

    } while(userAuth(username, token));
    
    cout<<"\nLogin Successful!"<<endl;
    return token;
}
int maintainerLogin(){
    cout<<"\n-------------------------------------- MAINTAINER LOGIN -------------------------------------\n";
    string userid; int token;

    do{
        cout<<"Enter your userID: ";
        cin>>userid;

        cout<<"Enter your token: ";
        cin>>token;
    } while (adminAuth(userid, token));

    cout<<"\nLogin Successful!"<<endl;
    return token;
}
void registerUser(){
    cout<<"\n---------------------------------------- REGISTRATION ---------------------------------------\n";
    string username, fullname; int age;
    
    do{
        cout<<"Enter new username: ";
        cin>>username;
    } while (checkExistingUser(username));
    cout<<"Username is available!"<<endl;    
    
    cout<<"Enter Full Name: ";
    cin.ignore();
    getline(cin, fullname);
    cout<<"Enter Age: ";
    cin>>age;
    
    users *ptr = new users(username, fullname, age);
    allUsers.push_back(*ptr);
    cout<<"\nRegistration successful!"<<endl<<endl;
    cout<<"Your token number is: "<<allUsers.size() - 1<<"! ";
    cout<<"Please keep it somewhere safe. You will need it to access your account!"<<endl<<endl;
    cout<<"Press any key to go back to Main Menu...";
    getch();
}