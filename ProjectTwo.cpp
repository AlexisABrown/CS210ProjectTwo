// ProjectTwo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
using namespace std;

double initialInvestment;
double monthlyDeposit;
double interestRate; 
int numberOfYears;
int year;
double yearEndBalance;
double interestEarned;

void printDetails(int year, double yearEndBalance, double interestEarned) {
	std::cout << year << "\t\t$" << std::fixed << setprecision(2) << yearEndBalance <<
		"\t\t\t$" << interestEarned << "\n";
}

double calculateBalanceWithoutMonthlyDeposit(double initialInvestment, double interestRate, int numberOfYears) {
	//Called when user enters a nothing for the monthlyDeposit
	// printDetails should be called after each year
	std::cout << "      Balance and Interest Without Additional Monthly Deposits";
	std::cout << "================================================================="<< endl;
	std::cout << "      Year Year End Balance Year End Earned Interest";
	std::cout << "-----------------------------------------------------------------"<< endl;
	double currentInvestment = initialInvestment; //Declare variable currentInvestment
	for (int i = 0; i < numberOfYears; i++) { //Create a loop that iterates for each year that the user input
		year = i + 1;
		currentInvestment = (currentInvestment) * ((interestRate / 100) / 12); //Assign the value of the calculation to the currentInvestment variable
		double interestAmount = interestRate;
		printDetails(year, currentInvestment, interestAmount); //Calculate(currentInvestment)* ((interestRate / 100) / 12)
		//Create a loop that iterates for each year that the user input
	}
	return currentInvestment;
};


double balanceWithMonthlyDeposit(double initialInvestment, double monthlyDeposit, double interestRate, int numberOfYears) {
	std::cout << "        Balance and Interest With Additional Monthly Deposits";
	std::cout << "================================================================="<< endl;
	std::cout << "        Year Year End Balance Year End Earned Interest";
	std::cout << "-----------------------------------------------------------------"<< endl;
	double currentInvestment = initialInvestment; //Declare variable currentInvestment
	for (int i = 0; i < numberOfYears; i++) { //Create a loop that iterates for each year that the user input
		year = i + 1;
		currentInvestment = (currentInvestment + monthlyDeposit) * ((interestRate / 100) / 12); //Assign the value of the calculation to the currentInvestment variable
		double interestAmount = interestRate;
		printDetails(year, currentInvestment, interestAmount); //Calculate(currentInvestment)* ((interestRate / 100) / 12)
		//Create a loop that iterates for each year that the user input
	}
	return currentInvestment;
}

int main()
{
    std::cout << "********************************" << endl;
	std::cout << "********** Data Input **********" << endl;
	std::cout << "Initial Investment";
	std::cin >> initialInvestment;
	std::cout << "Monthly Deposit";
	std::cin >> monthlyDeposit;
	std::cout << "Interest Rate";
	std::cin >> interestRate;
	std::cout << "Number of Years";
	std::cin >> numberOfYears;
	if (monthlyDeposit == 0.0) {
		calculateBalanceWithoutMonthlyDeposit(initialInvestment, interestRate, numberOfYears);
	}
	if (monthlyDeposit < 0.0) {
		std::cout << "That's a withdrawal. Please enter a deposit amount." << endl;
	}
	if (monthlyDeposit > 0.0) {
		balanceWithMonthlyDeposit(initialInvestment, monthlyDeposit, interestRate, numberOfYears);
	}
    return 0;
}
