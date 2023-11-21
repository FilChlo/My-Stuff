/*This program is used to create
 *a list of planets and display
 *each planest's contents
*/
#include <iostream>
#include <vector>
#include <climits>
#include <cctype>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

double ReadDouble(string prompt);
double ReadDouble(string prompt, double minValue);
double ReadDouble(string prompt, double minValue, double maxValue);
string ReadString(string prompt);

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
                void Input();
                void Display();
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

bool Planet::SetName(string x)
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

void Planet::Input()
{
        while (SetName( ReadString("Enter name of planet: ") )==false)
        {
                cerr << "Error! Input must be a string\n";
        }

        while (SetMass( ReadDouble("Enter planet's mass: ", 0.0) )== false)
        {
                cerr << "Error! Input must be >= 0\n";
        }

        while (SetRadius( ReadDouble("Enter planet's radius: ", 0.0) )==false)
        {
                cerr << "Error! Input must be >= 0\n";
        }
}

void Planet::Display()
{
        cout << "Name: " << name << endl;
        cout << "Mass: " << mass << endl;
        cout << "Radius: " << radius << endl;
        cout << "Surface Area: " << SurfaceArea() << endl;
        cout << "Density: " << CalcDensity() << endl;
        cout << "Gravity: " << CalcGravity() << endl;
}

void Input(vector<Planet>& l);
bool Insert(vector<Planet>& l, Planet val, int pos);
void Remove(vector<Planet>& l);
bool Delete(vector<Planet>& l, int pos);
void Display(vector<Planet>& l);
void Search(vector<Planet>& l, std::string item);

double ReadDouble(string prompt);
double ReadDouble(string prompt, double minValue);
double ReadDouble(string prompt, double minValue, double maxValue);
string ReadString(string prompt);

void Input(vector<Planet>& l)
{
        bool rv=false;
        while (rv==false) {
                Planet p;
                p.Input();
                int position=ReadDouble("Enter position: ",0);
                rv=Insert(l,p,position);
        }
}

bool Insert(vector<Planet>& l, Planet val, int pos)
{
        bool rv=false;
        if (pos>=0) {
                rv=true;
                Planet end;
                l.push_back(end);
                for (int i=l.size()-1;i>=pos;i--) {
                        l[i]=l[i-1];
                }
                l[pos]=val;
        }
        return rv;
}

void Remove(vector<Planet>& l)
{
        bool rv=false;
        while (rv==false) {
                int position=ReadDouble("Enter position to delete: ",0,l.size()-1);
                rv=Delete(l,position);
        }
}

bool Delete(vector<Planet>& l, int pos)
{
        bool rv=false;
        if (pos>=0 && pos<l.size()) {
                rv=true;
                for (int i=pos;i<l.size()-1;i++) {
                        l[i]=l[i+1];
                }
                l.pop_back();
        }
        return rv;
}

void Display(vector<Planet>& l)
{
        if (l.empty()==1) {
                cout << "List is empty...\n";
        }
        else {
                long len=l.size();
                for (long i=0;i<len;i++) {
                        l[i].Display();
                        cout << "\n";
                }
                cout << endl;
        }
}

void Search(vector<Planet>& l, std::string item)
{
        auto id = find(l.begin(), l.end(), item);
        if (id !=l.end()) {
                int index = id - l.begin();
                l[index].Display();
        }
        else {
                cout << item << " not in vector." << endl;
        }
}

const int ADD=1;
const int DELETE=2;
const int FIND=3;
const int DISPLAY=4;
const int QUIT=5;

int main()
{
        vector<Planet> list;

        int menuChoice=0;
        cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Exit\nEnter choice: ";
        cin >> menuChoice;

        while (menuChoice !=QUIT) {
                if (menuChoice==ADD) {
                        Input(list);
                }

                if (menuChoice==DELETE) {
                        Remove(list);
                }

                if (menuChoice==FIND) {
                        string search;
                        cout << "Name of planet?(case sensitive): " << endl;
                        cin >> search;
                        Search(list, search);
                }

                if (menuChoice==DISPLAY) {
                        Display(list);
                }

                if (menuChoice != ADD && menuChoice != DELETE && menuChoice != FIND && menuChoice != DISPLAY) {
                        cout << "Error! That's not an option\n";
                }

                cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Exit\nEnter choice: ";
                cin >> menuChoice;
        }

        cout << "Goodbye...\n";

        return 0;
}

string ReadString(string prompt)
{
        string returnValue;
        cout << prompt;
        cin >> returnValue;
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

double ReadDouble(string prompt, double minValue, double maxValue)
{
        double returnValue=0.0;
        returnValue=ReadDouble(prompt, minValue);
        while (returnValue > maxValue) {
                cout << "Error! Value must be <= " << maxValue << endl;
                returnValue=ReadDouble(prompt,minValue);
        }
        return returnValue;
}

