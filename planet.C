/*Program is used to enter info
 *of planets and calculate gravity
 *of each one*/
#include <iostream>
#include <cmath>
#include <climits>
#include <cctype>
#include <string>

class Planet
{
        private:
                std::string name;
                double mass, radius;

        public:
                double SurfaceArea();
                double CalcDensity();
                double CalcGravity();
                bool SetName(std::string x);
                bool SetMass(double x);
                bool SetRadius(double x);
                std::string GetName();
                double GetMass();
                double GetRadius();
                Planet();
};

Planet::Planet()
{
        name;
        mass=0.0;
        radius=0.0;
}

double Planet::SurfaceArea()
{
        return 4.0 * M_PI * pow(radius,2.0);
}

double Planet::CalcDensity()
{
        return mass / (4.0 / 3.0) * M_PI * pow(radius,3.0);
}

double Planet::CalcGravity()
{
        return 6.673e-11 * mass / pow(radius,2.0);
}

bool Planet::SetName(std::string x)
{
        bool rv=false;
        for (int i=0; i < x.length(); i++) {
                if (isdigit(x[i])==false) {
                        name=x;
                        rv=true;
                }
        }
        return rv;
}

bool Planet::SetMass(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                mass=x;
                rv=true;
        }
        return rv;
}

bool Planet::SetRadius(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                radius=x;
                rv=true;
        }
        return rv;
}

std::string Planet::GetName()
{
        return name;
}

double Planet::GetMass()
{
        return mass;
}

double Planet::GetRadius()
{
        return radius;
}

using namespace std;

double ReadDouble(string prompt);
double ReadDouble(string prompt, double minValue);
string ReadString(string prompt);

double SurfaceArea(Planet pla);
double CalcDensity(Planet pla);
double CalcGravity(Planet pla);

void PlanetInput(Planet& pla);

int main()
{
        Planet planet;
        PlanetInput(planet);
        cout << "Name: " << planet.GetName() << endl;
        cout << "Mass: " << planet.GetMass() << endl;
        cout << "Radius: " << planet.GetRadius() << endl;
        cout << "Surface Area: " << planet.SurfaceArea() << endl;
        cout << "Density: " << planet.CalcDensity() << endl;
        cout << "Gravity: " << planet.CalcGravity() << endl;

}

void PlanetInput(Planet& pla)
{
        while (pla.SetName( ReadString("Enter name of planet: ") )==false)
        {
                cerr << "Error! Input must be a string\n";
        }

        while (pla.SetMass( ReadDouble("Enter planet's mass: ", 0.0) )== false)
        {
                cerr << "Error! Input must be >= 0\n";
        }

        while (pla.SetRadius( ReadDouble("Enter planet's radius: ", 0.0) )==false)
        {
                cerr << "Error! Input must be >= 0\n";
        }
}

string ReadString(string prompt)
{
        string returnValue;
        cout << prompt;
        getline(cin, returnValue);
        return returnValue;
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

