/*Program is used to simulate
 *random dice rolls*/
#include<iostream>
#include<iomanip>
#include<cstdlib>

using namespace std;

int main()
{
        srand(static_cast<int>(time(0)));

        cout << "This is the result of 12 random die being rolled: " << endl;
        for (int counter=1; counter <= 144; ++counter) {
                int face=0.0;
                face = (1 + rand() % 12);
                cout << face << "\t";
                if (counter % 12 == 0) {
                        cout << "\n";
                }
        }
}

