#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

const string accountsFile = "accounts.txt";

struct Account{
    string firstName = "";
    string lastName = "";
    string password = "";
    string email = "";
    bool equals(Account&);
};

bool Account::equals(Account& toCompare){
    return email != toCompare.email;
}

vector<Account> read_accounts_from_file(){
    vector<Account> accounts;
    ifstream input_file(accountsFile);
	if (input_file) {
        Account account;
        while (input_file >> account.firstName >> account.lastName >> account.password >> account.email) {
            accounts.push_back(account);
        }
        input_file.close();
    }
    return accounts;
}

void display_accounts(vector<Account> accounts) {
    int col_width = 10;
    cout << left
		 << setw(col_width * 3) << "Name"
		 << setw(col_width * 4) << "Email" << endl;
    for(Account account : accounts){
        cout << setw(col_width * 3) << account.firstName + ' ' + account.lastName
			 << setw(col_width * 4) << account.email << endl;
    }
	cout << endl;
}

void write_accounts_to_file(const vector<Account>& accounts) {
	ofstream outputFile(accountsFile);
	if (outputFile) {
        for(Account account : accounts){
            outputFile << account.firstName << '\t'
            << account.lastName << '\t'
            << account.password << '\t'
            << account.email << '\n';
        }
		outputFile.close();
	}
}

Account get_account(){
    Account account;
    cout << "First name: ";
    getline(cin, account.firstName);
    cout << "Last name: ";
    getline(cin, account.lastName);
    cout << "Password: ";
    getline(cin, account.password);
    cout << "Email: ";
    getline(cin, account.email);
    return account;
}

int main()
{
	vector<Account> accounts = read_accounts_from_file();

    cout << "Create Account List\n\n";
	display_accounts(accounts);

	char another = 'y';
	while (tolower(another) == 'y') {
        Account account = get_account();
        bool validAccount = false;
        for(Account toCompare : accounts){
            validAccount = account.equals(toCompare);
            if(!validAccount){
                cout << "Sorry, this account already exists.\n\n";
                break;
            }
        }

        if(validAccount){
            accounts.push_back(account);
            write_accounts_to_file(accounts);
            cout << endl << account.email << " was added for " 
                << account.firstName + ' ' + account.lastName << endl << endl;
        }

        

		cout << "Enter another account? (y/n): ";
		cin >> another;
		cin.ignore();
		cout << endl;
	}

	display_accounts(accounts);
}
