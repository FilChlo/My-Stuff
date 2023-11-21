/*This program is used to calculate
 *the roots of a quadratic formula
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

double ReadDouble(string prompt);
double CalcRootOne(double value1, double value2, double value3);
double CalcRootTwo(double value1, double value2, double value3);

int main()
{
        double Avalue=0.0, Bvalue=0.0, Cvalue=0.0, Root1=0.0, Root2=0.0;
        bool done=false;
        char again='y';

        while (again=='y') {
                while (done==false) {
                        try {
                                done=true;
                                Avalue=ReadDouble("Enter value A for quadratic formula: ");
                                Bvalue=ReadDouble("Enter value B for quadratic formula: ");
                                Cvalue=ReadDouble("Enter value C for quadratic formula: ");
                                Root1=CalcRootOne(Avalue, Bvalue, Cvalue);
                                Root2=CalcRootTwo(Avalue, Bvalue, Cvalue);
                                cout << "First root is: " << Root1 << endl;
                                cout << "Second root is: " << Root2 << endl;
                        }

                        catch (int e) {
                                done=false;
                                cerr << "An exception was thrown! Error number " << e << endl;
                        }
                }
                cout << "Would you like to go again? (y/n)" << endl;
                cin >> again;
                if (again=='y') {
                        done=false;
                }
        }
        return 0;
}

double ReadDouble(string prompt)
{
        double returnValue=0.0;
        cout << prompt;
        cin >> returnValue;
        while (cin.fail()==1) {
                cout << "Error! Cannot read input.\n";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout << prompt;
                cin >> returnValue;
        }
        return returnValue;
}

double CalcRootOne(double value1, double value2, double value3)
{
        double returnValue=0.0;
        if ((4*value1*value3) > (pow(value2,2.0))) {
                throw 1;
        }
        returnValue=(-value2 + sqrt(value2*value2 - 4*value1*value3)) / (2*value1);
        return returnValue;
}

double CalcRootTwo(double value1, double value2, double value3)
{
        double returnValue=0.0;
        if ((4*value1*value3) > (pow(value2,2.0))) {
                throw 2;
        }
        returnValue=(-value2 - sqrt(value2*value2 - 4*value1*value3)) / (2*value1);
        return returnValue;
}

