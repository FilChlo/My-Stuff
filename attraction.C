/*This program is used to calculate
 *the gravitational force of two spheres
 *and display a table of the forces
*/

#include <iostream>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

const double gravForce=6.67408e-11;

double ReadDouble(string prompt);
double ReadDouble(string prompt, double minValue);
double calcDistance(double distance, double length1, double length2);
double calcForce(double mass1, double mass2, double totalDist);

int main()
{
        double size1=0.0, radius1=0.0, size2=0.0, radius2=0.0, distance=0.0;

        radius1=ReadDouble("Enter radius of Sphere A in meters: ",0.0);
        size1=ReadDouble("Enter mass of Sphere A in kg: ",0.0);
        radius2=ReadDouble("Enter radius of Sphere B in meters: ",0.0);
        size2=ReadDouble("Enter mass of Sphere B in kg: ",0.0);
        distance=ReadDouble("Enter distance between both spheres: ",0.0);
        cout << "Distance\tForce" << endl;
        for (int loop=0; loop <= distance; loop++) {
                double totalDistance=calcDistance(distance, radius1, radius2);
                double totalForce=calcForce(size1, size2, totalDistance);
                cout  << totalDistance << "\t\t" << totalForce << endl;
                distance -= distance * 0.01;
        }
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

double ReadDouble(string prompt, double minValue)
{
        double returnValue=0.0;
        returnValue=ReadDouble(prompt);
        while (returnValue < minValue) {
                cout << "Error! Value must be bigger than " << minValue << endl;
                returnValue=ReadDouble(prompt);
        }
        return returnValue;
}

double calcDistance(double distance, double length1, double length2)
{
        double returnValue=0.0;
        returnValue=distance + length1 + length2;
        return returnValue;
}

double calcForce(double mass1, double mass2, double totalDist)
{
        double returnValue=0.0;
        returnValue=(mass1 * mass2 / pow(totalDist,2.0)) * gravForce;
        return returnValue;
}
      
