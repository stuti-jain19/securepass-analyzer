#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(1000, '\n');
    cin.get();
}

void showHeader() {
    cout << "\n";
    cout << "  ╔══════════════════════════════════════╗\n";
    cout << "  ║         SECUREPASS ANALYZER          ║\n";
    cout << "  ║    Password Strength & Generator     ║\n";
    cout << "  ╚══════════════════════════════════════╝\n\n";
}

void showMenu() {
    cout << "  ┌──────────────────────────────────┐\n";
    cout << "  │           MAIN MENU              │\n";
    cout << "  │                                  │\n";
    cout << "  │  [1] Check Password Strength     │\n";
    cout << "  │  [2] Generate Random Password    │\n";
    cout << "  │  [3] About Project               │\n";
    cout << "  │  [4] Exit                        │\n";
    cout << "  └──────────────────────────────────┘\n";
    cout << "  >> Enter your choice: ";
}

void checkPasswordStrength() {
    cout << "\n── PASSWORD STRENGTH CHECKER ──\n\n";
    cout << "Enter password to analyze: ";

    cin.ignore();
    string password;
    getline(cin, password);

    bool hasUpper=false, hasLower=false, hasDigit=false, hasSpecial=false;
    string specials="!@#$%^&*()_+-=[]{}|;:,./?";

    for(char c: password){
        if(c>='A'&&c<='Z') hasUpper=true;
        else if(c>='a'&&c<='z') hasLower=true;
        else if(c>='0'&&c<='9') hasDigit=true;
        if(specials.find(c)!=string::npos) hasSpecial=true;
    }

    int score=0;
    if(password.length()>=8) score++;
    if(hasUpper) score++;
    if(hasLower) score++;
    if(hasDigit) score++;
    if(hasSpecial) score++;

    cout<<"\nPassword : "<<password;
    cout<<"\nLength   : "<<password.length()<<" characters\n\n";

    cout<<(password.length()>=8?"[YES] ":"[NO]  ")<<"Length >= 8 characters\n";
    cout<<(hasUpper?"[YES] ":"[NO]  ")<<"Uppercase letters\n";
    cout<<(hasLower?"[YES] ":"[NO]  ")<<"Lowercase letters\n";
    cout<<(hasDigit?"[YES] ":"[NO]  ")<<"Numbers\n";
    cout<<(hasSpecial?"[YES] ":"[NO]  ")<<"Special characters\n";

    cout<<"\nScore : "<<score<<"/5\nStrength : ";

    if(score<=2) cout<<"WEAK";
    else if(score==3) cout<<"MEDIUM";
    else if(score==4) cout<<"STRONG";
    else cout<<"VERY STRONG";

    cout<<"\nPassword Security Score: "<<score*20<<"%\n";

    if(score<5){
        cout<<"\nSuggestions:\n";
        if(password.length()<8) cout<<"- Make it at least 8 characters.\n";
        if(!hasUpper) cout<<"- Add uppercase letters.\n";
        if(!hasLower) cout<<"- Add lowercase letters.\n";
        if(!hasDigit) cout<<"- Add digits.\n";
        if(!hasSpecial) cout<<"- Add special characters.\n";
    } else {
        cout<<"\nGreat job! Your password is excellent.\n";
    }

    waitForEnter();
}

void generatePassword(){
    cout<<"\n── PASSWORD GENERATOR ──\n\n";
    cout<<"Enter desired password length (min 8): ";

    int length;
    cin>>length;

    if(length<8){
        cout<<"Too short. Using length 8.\n";
        length=8;
    }

    string upper="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lower="abcdefghijklmnopqrstuvwxyz";
    string digits="0123456789";
    string special="!@#$%^&*";
    string all=upper+lower+digits+special;

    string password;
    password+=upper[rand()%upper.size()];
    password+=lower[rand()%lower.size()];
    password+=digits[rand()%digits.size()];
    password+=special[rand()%special.size()];

    for(int i=4;i<length;i++)
        password+=all[rand()%all.size()];

    for(int i=password.size()-1;i>0;i--){
        int j=rand()%(i+1);
        swap(password[i],password[j]);
    }

    cout<<"\nGenerated Password : "<<password;
    cout<<"\nLength             : "<<length;
    cout<<"\nStrength           : VERY STRONG\n";

    waitForEnter();
}

void showAbout(){
    cout<<"\nSecurePass Analyzer\n";
    cout<<"Language : C++\n";
    cout<<"Features:\n";
    cout<<"- Password strength checker\n";
    cout<<"- Random password generator\n";
    cout<<"- Suggestions for improvement\n";
    cout<<"- Beginner cybersecurity mini project\n";
    waitForEnter();
}

int main(){
    srand(time(0));

    showHeader();

    while(true){
        showMenu();

        int choice;
        if(!(cin>>choice)){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"\nInvalid input. Please enter a number.\n\n";
            continue;
        }

        switch(choice){
            case 1:
                checkPasswordStrength();
                break;
            case 2:
                generatePassword();
                break;
            case 3:
                showAbout();
                break;
            case 4:
                cout<<"\nThanks for using SecurePass Analyzer!\n";
                return 0;
            default:
                cout<<"\nInvalid choice. Please select 1-4.\n\n";
        }
    }
}
