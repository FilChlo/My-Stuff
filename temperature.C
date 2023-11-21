/*Program is used to convert
 *Celsius to Fahrenheit and
 *vice-versa.
*/
#include<iostream>

using namespace std;

int main()
{
        float celsius, fahrenheit;
        char choice;
        double input;

        cout << "Enter C for Celsius or F for Fahrenheit: " << endl;
        cin >> choice;

        if (choice=='c' || choice=='C') {
                cout << "Enter your temperature in Celsius: " << endl;
                cin >> input;
                fahrenheit=(1.8 * input) + 32.0;
                cout << "Temperature in Fahrenheit is: " << fahrenheit << " degrees" << endl;
        }

        else if (choice=='f' || choice=='F') {
                cout << "Enter your temperature in Fahrenheit: " << endl;
                cin >> input;
                celsius=(input - 32) / 1.8;
                cout << "Temperature in Celsius is: " << celsius << " degrees" << endl;
        }

        else {
                cout << "Error, not a choice" << endl;
        }

        return 0;
}


