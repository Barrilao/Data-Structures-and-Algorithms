#include <iostream>
#include <string>

using namespace std;

class BankAccount {

private:
	string owner;
	string IBAN;
	int balance;

public:
	BankAccount() {
	}

	BankAccount(string o, string I, int b) {
		this->owner = o;
		this->IBAN = I;
		this->balance = b;
	}

	void deposit(int n) {
		balance += n;
		displayBalance();
	}

	void withdraw(int n) {
		balance -= n;
		displayBalance();
	}

	void displayBalance() {
		cout << balance << " $" << endl;
	}

	void displayIBAN() {
		cout << IBAN << endl;
	}

	void displayOwner() {
		cout << owner << endl;
	}
};

int main() {
	BankAccount BA("Juan Barri", "1234 1234 1234 1234", 20000);
	cout << "Owner: \n";
	BA.displayOwner();
	cout << "IBAN: \n";
	BA.displayIBAN();
	cout << "Balance: \n";
	BA.displayBalance();
	cout << "Deposit 100$: \n";
	BA.deposit(1000);
	cout << "Withdraw of 5000$ \n";
	BA.withdraw(10000);
	return 0;
}
