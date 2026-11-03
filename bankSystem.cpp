// C++ program to simulate a simple banking system
#include <iostream>
#include <iomanip>
using namespace std;

void showBalance(double balance);
double deposit();
double withdraw(double balance);

int main(){
	double balance = 0;
	int choice = 0;

	do{
		// The menu will be displayed until the user decides to exit.
		cout << "******************\n";
		cout << "Enter your choice:\n";
		cout << "******************\n";
		cout << "1. Show Balance\n";
		cout << "2. Deposit\n";
		cout << "3. Withdraw\n";
		cout << "4. Exit\n";
		cout << "Choice: ";
		cin >> choice;

		// This performs an action based on the user's decision
		switch(choice){
			case 1: showBalance(balance); // displays the current balance
				break;
			case 2: balance += deposit(); // Adds the deposited amount
				showBalance(balance); // Displays the updated amount
				break;
			case 3: balance -= withdraw(balance); // Subtracts the withdrawn amount
				showBalance(balance); // Displays the updated amount
				break;
			case 4: cout << "Thanks for visiting.\n";
				break;
			default: cout << "Invalid choice\n";
		}
	}

	while(choice != 4); // The menu will appear until the user enters 4

	return 0;
}

// This displays the balance with two decimal places
void showBalance(double balance){
	cout << "Your balance is: $" << setprecision(2) << fixed << balance << '\n';
}

double deposit(){
	double amount = 0;

	cout << "Enter the amount to be deposited: ";
	cin >> amount;

	if(amount > 0){
		return amount;
	}
	else{
		cout << "That is not a valid amount:\n";
		return 0;
	}
}

double withdraw(double balance){
	double amount = 0;

	cout << "Enter the amount to be withdrawn: ";
	cin >> amount;

	if(amount > balance){
		cout << "Insufficient funds\n";
		return 0;
	}
	else if(amount < 0){
		cout << "That is not a valid amount\n";
		return 0;
	}

	// returns the withdrawal amount if it is valid
	else{
		return amount;
	}

	return amount;
}
