/*Program used to calculate
 *monthly balance on savings account
*/
#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

double CalcBalance(double B, double A, double R, double M);

int main()
{
        double initial=0.0, deposit=0.0, rate=0.0, months=0.0, total=0.0;

        cout << "Enter your initial balance: " << endl;
        cin >> initial;

        cout << "Enter your monthly deposit: " << endl;
        cin >> deposit;

        cout << "Enter annual percent rate: " << endl;
        cin >> rate;

        cout << "For how many months?: " << endl;
        cin >> months;

        for (int i=1; i <= months; ++i) {
                total=CalcBalance(initial, deposit, rate, i);
                cout << fixed << setprecision(2) << "Month " << i << ": $" << total << "\n";
        }

        return 0;
}

double CalcBalance(double B, double A, double R, double M)
{
        double balance=0.0;
        balance=B + A * ((R/12) + M);
        return balance;
}

