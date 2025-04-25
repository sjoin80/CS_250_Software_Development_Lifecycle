/************************************************************
 * Shelby Joiner
 * SNHU - CS 210 Programming Languages
 *
 * Description:
 * This header file declares the Investment class, which
 * stores user investment data and provides methods to
 * generate investment reports with and without monthly
 * deposits. It defines the structure and functionality
 * of the investment model.
 ************************************************************/

#ifndef INVESTMENT_H
#define INVESTMENT_H

class Investment {
public:
    Investment(double t_initialInvestment, double t_monthlyDeposit,
        double t_annualInterest, int t_numberOfYears);

    void printReportWithoutMonthlyDeposits() const;
    void printReportWithMonthlyDeposits() const;

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numberOfYears;
};

#endif
