/************************************************************
 * Shelby Joiner
 * SNHU - CS 210 Programming Languages
 *
 * Description:
 * This is the Airgead Banking Investment App. It provides
 * users with two investment growth reports: one with monthly
 * deposits and one without, using compound interest calculations.
 * The app allows users to input different initial investments,
 * monthly deposit amounts, annual interest rates, and years.
 * The code adheres to Airgead Banking’s best practices and industry standards.
 ************************************************************/

#include <iostream>
#include <limits>
#include <iomanip>
#include "Investment.h"

void printInputPrompt() {
    std::cout << "****************************************************\n";
    std::cout << "******************* Data Input *********************\n";
    std::cout << "Initial Investment Amount: $";
}

int main() {
    double initialInvestment;
    double monthlyDeposit;
    double annualInterest;
    int numberOfYears;

    // Show full block and get all inputs
    std::cout << "****************************************************\n";
    std::cout << "******************* Data Input *********************\n";
    std::cout << "Initial Investment Amount: $";
    std::cin >> initialInvestment;

    std::cout << "Monthly Deposit: $";
    std::cin >> monthlyDeposit;

    std::cout << "Annual Interest (%): ";
    std::cin >> annualInterest;

    std::cout << "Number of Years: ";
    std::cin >> numberOfYears;

    std::cout << "Press Enter to continue . . .";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get(); // Waits for Enter

    // Display confirmed input block with two decimal places for dollar amounts
    std::cout << "\n****************************************************\n";
    std::cout << "******************* Data Input *********************\n";
    std::cout << "Initial Investment Amount:  $" << std::fixed << std::setprecision(2) << initialInvestment << "\n";
    std::cout << "Monthly Deposit:            $" << std::fixed << std::setprecision(2) << monthlyDeposit << "\n";
    std::cout << "Annual Interest:            %" << annualInterest << "\n";
    std::cout << "Number of Years:            " << numberOfYears << "\n";
    std::cout << "Press Enter to continue . . .";
    std::cin.get(); // Wait again

    // Create Investment object and print reports
    Investment investment(initialInvestment, monthlyDeposit, annualInterest, numberOfYears);

    std::cout << "\n**************************************************\n";
    std::cout << "Balance and Interest Without Additional Monthly Deposits\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Year           Year End Balance         Year End Earned Interest\n";
    std::cout << "--------------------------------------------------\n";
    investment.printReportWithoutMonthlyDeposits();

    std::cout << "\n**************************************************\n";
    std::cout << "Balance and Interest With Additional Monthly Deposits\n";
    std::cout << "--------------------------------------------------\n";
    std::cout << "Year           Year End Balance         Year End Earned Interest\n";
    std::cout << "--------------------------------------------------\n";
    investment.printReportWithMonthlyDeposits();

    return 0;
}
