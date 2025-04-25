/************************************************************
 * Shelby Joiner
 * SNHU - CS 210 Programming Languages
 *
 * Description:
 * This source file implements the methods defined in the
 * Investment class. It performs the actual calculations
 * for compound interest and displays formatted year-end
 * investment reports with and without monthly deposits.
 ************************************************************/

#include "Investment.h"
#include <iomanip>
#include <cmath>
#include <iostream>

Investment::Investment(double t_initialInvestment, double t_monthlyDeposit,
    double t_annualInterest, int t_numberOfYears)
    : m_initialInvestment(t_initialInvestment), m_monthlyDeposit(t_monthlyDeposit),
    m_annualInterest(t_annualInterest), m_numberOfYears(t_numberOfYears) {
}

void Investment::printReportWithoutMonthlyDeposits() const {
    double balance = m_initialInvestment;
    double totalInterest = 0.0;

    // Loop for each year
    for (int year = 1; year <= m_numberOfYears; ++year) {
        // Calculate interest for the year
        double interestEarned = balance * (m_annualInterest / 100);
        totalInterest += interestEarned;

        // Update balance
        balance += interestEarned;

        // Print the year, balance, and earned interest with 2 decimal places
        std::cout << std::setw(15) << year
            << std::setw(25) << "$" << std::fixed << std::setprecision(2) << balance
            << std::setw(25) << "$" << std::fixed << std::setprecision(2) << interestEarned << std::endl;
    }
}

void Investment::printReportWithMonthlyDeposits() const {
    double balance = m_initialInvestment;
    double totalInterest = 0.0;

    // Loop for each year
    for (int year = 1; year <= m_numberOfYears; ++year) {
        // Calculate interest for the year
        for (int month = 1; month <= 12; ++month) {
            balance += m_monthlyDeposit;
            double interestEarned = balance * ((m_annualInterest / 100) / 12);
            totalInterest += interestEarned;
            balance += interestEarned;
        }

        // Print the year, balance, and earned interest with 2 decimal places
        std::cout << std::setw(5) << year        // Ensure the year is aligned in a 5-character wide column
            << std::setw(25) << "$" << std::fixed << std::setprecision(2) << balance // Align the balance with dollar sign and precision
            << std::setw(25) << "$" << std::fixed << std::setprecision(2) << totalInterest << std::endl; // Align interest
    }
}