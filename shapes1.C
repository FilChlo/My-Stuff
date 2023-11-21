/*This program is used to ask user
 *for a shape to calculate its volume
 *and surface area
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <string>

using namespace std;

const int CUBE=1;
const int SPHERE=2;
const int PRISM=3;
const int CYLINDER=4;
const int CONE=5;
const int QUIT=6;

double ReadDouble(string prompt);
double ReadDouble(string prompt, double minValue);
double CalcCubeV(double length, double width, double height);
double CalcCubeSA(double length, double width, double height);
double CalcSphereV(double radius);
double CalcSphereSA(double radius);
double CalcPrismV(double length, double width, double height);
double CalcPrismSA(double length, double width, double height, double triSide1, double triSide2, double triSide3);
double CalcCylinderV(double radius, double height);
double CalcCylinderSA(double radius, double height);
double CalcConeV(double radius, double height);
double CalcConeSA(double radius, double height);

int main()
{
        int menuChoice=0;

        cout << "1) Cube\n2) Sphere\n3) Prism\n4) Cylinder\n5) Cone\n6) Quit\nEnter choice: ";
        cin >> menuChoice;

        while (menuChoice != QUIT) {
                if (menuChoice==CUBE) {
                        double side1=0.0, side2=0.0, side3=0.0;
                        side1=ReadDouble("Enter length in meters: ",0.0);
                        side2=ReadDouble("Enter width in meters: ",0.0);
                        side3=ReadDouble("Enter height in meters: ",0.0);
                        double volume=CalcCubeV(side1, side2, side3);
                        double surfarea=CalcCubeSA(side1, side2, side3);
                        cout << "Volume: " << volume << "m^3\nSurface Area: " << surfarea << "m^2" << endl;
                }

                if (menuChoice==SPHERE) {
                        double distance=0.0;
                        distance=ReadDouble("Enter radius in meters: ",0.0);
                        double volume=CalcSphereV(distance);
                        double surfarea=CalcSphereSA(distance);
                        cout << "Volume: " << volume << "m^3\nSurface Area: " << surfarea << "m^2" << endl;
                }

                if (menuChoice==PRISM) {
                        double longline=0.0, wideline=0.0, tall=0.0, side1=0.0, side2=0.0, side3=0.0;
                        longline=ReadDouble("Enter length in meters: ",0.0);
                        wideline=ReadDouble("Enter width in meters: ",0.0);
                        tall=ReadDouble("Enter height in meters: ",0.0);
                        side1=ReadDouble("Enter triangle side 1: ",0.0);
                        side2=ReadDouble("Enter triangle side 2: ",0.0);
                        side3=ReadDouble("Enter triangle side 3: ",0.0);
                        double volume=CalcPrismV(longline, wideline, tall);
                        double surfarea=CalcPrismSA(longline, wideline, tall, side1, side2, side3);
                        cout << "Volume: " << volume << "m^3\nSurface Area: " << surfarea << "m^2" << endl;
                }

                if (menuChoice==CYLINDER) {
                        double distance=0.0, tall=0.0;
                        distance=ReadDouble("Enter radius in meters: ",0.0);
                        tall=ReadDouble("Enter height in meters: ",0.0);
                        double volume=CalcCylinderV(distance, tall);
                        double surfarea=CalcCylinderSA(distance, tall);
                        cout << "Volume: " << volume << "m^3\nSurface Area: " << surfarea << "m^2" << endl;
                }

                if (menuChoice==CONE) {
                        double distance=0.0, tall=0.0;
                        distance=ReadDouble("Enter radius in meters: ",0.0);
                        tall=ReadDouble("Enter height in meters: ",0.0);
                        double volume=CalcConeV(distance, tall);
                        double surfarea=CalcConeSA(distance, tall);
                        cout << "Volume: " << volume << "m^3\nSurface Area: " << surfarea << "m^2" << endl;
                }

                if (menuChoice != CUBE && menuChoice != SPHERE && menuChoice != PRISM && menuChoice != CYLINDER && menuChoice != CONE) {
                        cout << "Error! That's not an option\n";
                }
                
		cout << "1) Cube\n2) Sphere\n3) Prism\n4) Cylinder\n5) Cone\n6) Quit\nEnter choice: ";
                cin >> menuChoice;
        }

        cout << "Goodbye\n";

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

double CalcCubeV(double length, double width, double height)
{
        double returnValue=0.0;
        returnValue=length * width * height;
        return returnValue;
}

double CalcCubeSA(double length, double width, double height)
{
        double returnValue=0.0;
        returnValue=(2 * length * width) + (2 * length * height) + (2 * width * height);
        return returnValue;
}

double CalcSphereV(double radius)
{
        double returnValue=0.0;
        returnValue=(4 / 3) * M_PI * pow(radius,3.0);
        return returnValue;
}

double CalcSphereSA(double radius)
{
        double returnValue=0.0;
        returnValue=4 * M_PI * pow(radius,2.0);
        return returnValue;
}

double CalcPrismV(double length, double width, double height)
{
        double returnValue=0.0;
        returnValue=(length * width * height) / 2;
        return returnValue;
}

double CalcPrismSA(double length, double width, double height, double triSide1, double triSide2, double triSide3)
{
        double returnValue=0.0;
        returnValue=width * height + (triSide1 + triSide2 + triSide3) * length;
        return returnValue;
}

double CalcCylinderV(double radius, double height)
{
        double returnValue=0.0;
        returnValue=M_PI * pow(radius,2.0) * height;
        return returnValue;
}

double CalcCylinderSA(double radius, double height)
{
        double returnValue=0.0;
        returnValue=2 * M_PI * radius * height + 2 * M_PI * pow(radius,2.0);
        return returnValue;
}

double CalcConeV(double radius, double height)
{
        double returnValue=0.0;
        returnValue=(M_PI / 3.0) * pow(radius,2.0) * height;
        return returnValue;
}

double CalcConeSA(double radius, double height)
{
        double returnValue=0.0;
        returnValue=M_PI * pow(radius,2.0) + M_PI * radius * sqrt(pow(radius,2.0) + pow(height,2.0));
        return returnValue;
}

