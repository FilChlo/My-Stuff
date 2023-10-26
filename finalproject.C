/*Program is an upgrade to
 *the planet list program*/

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <climits>
#include <fstream>
#include <cstdlib>
#include <ctime>
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
                double Density();
                double Gravity();
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

double Planet::Density()
{
        return mass / (4.0 / 3.0) * M_PI * pow(radius,3.0);
}

double Planet::Gravity()
{
        return 6.673e-11 * mass / pow(radius,2.0);
}

bool Planet::SetName(string x)
{
        bool rv=false;
        for (int i=0; i<x.length(); i++) {
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
                cerr << "Error! Input must all letters\n";
        }
        while (SetMass( ReadDouble("Enter planet's mass: ", 0.0) )==false)
        {
                cerr << "Error! Input must be greater than 0\n";
        }
        while (SetRadius( ReadDouble("Enter planet's radius: ", 0.0) )==false)
        {
                cerr << "Error! Input must be greater than 0\n";
        }
}

void Planet::Display()
{
        cout << "Name: " << name << endl;
        cout << "Mass: " << mass << endl;
        cout << "Radius: " << radius << endl;
        cout << "Surface Area: " << SurfaceArea() << endl;
        cout << "Density: " << Density() << endl;
        cout << "Gravity: " << Gravity() << endl;
}

void Input(vector<Planet>& l);
bool Insert(vector<Planet>& l, Planet val, int pos);
void Remove(vector<Planet>& l);
bool Delete(vector<Planet>& l, int pos);
void Display(vector<Planet>& l);
void Search(vector<Planet>& l, std::string item);
void BubbleSort(vector<Planet>& l, long len);
bool DoesFileExist(string filename);

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
                rv=Insert(l, p, position);
        }
}

bool Insert(vector<Planet>& l, Planet val, int pos)
{
        bool rv=false;
        if (pos>=0 && pos<=l.size()) {
                rv=true;
                Planet end;
                l.push_back(end);
                for (int i=l.size()-1; i>=pos; i--) {
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
                int position=ReadDouble("Enter position to delete: ", 0, l.size()-1);
                rv=Delete(l, position);
        }
}

bool Delete(vector<Planet>& l, int pos)
{
        bool rv=false;
        if (pos>=0 && pos<=l.size()) {
                rv=true;
                for (int i=pos; i<l.size()-1; i++) {
                        l[i]=l[i+1];
                }
                l.pop_back();
        }
        return rv;
}

void Display(vector<Planet>& l)
{
        if (l.empty()==1) {
                cout << "List is empty\n";
        }
        else {
                long len=l.size();
                for (long i=0; i<len; i++) {
                        l[i].Display();
                        cout << "\n";
                }
        }
}

void Search(vector<Planet>& l, string item)
{
        for (int i=0; i<l.size(); i++) {
                if (l[i].GetName() == item) {
                        l[i].Display();
                }
                else {
                        cout << "Element not in list.\n";
                }
        }
}

void BubbleSort(vector<Planet>& l, long len)
{
        int i=0, j=0;
        bool flag;
        for (i=0; i<len; i++) {
                flag=false;
                for (j=0; j<len-1-i; j++) {
                        if (l[j].GetName() > l[j+1].GetName())
                        {
                                swap(l[j], l[j+1]);
                                flag=true;
                        }
                }
                if (!flag)
                {
                        break;
                }
        }
}

bool DoesFileExist(string filename)
{
        bool rv=false;
        ifstream in(filename);
        if (in.is_open()==1) {
                rv=true;
                in.close();
        }
        return rv;
}

const int ADD=1;
const int DELETE=2;
const int FIND=3;
const int DISPLAY=4;
const int SORT=5;
const int QUIT=6;

int main()
{
        fstream outFile;
        string outFilename;
        cout << "Enter output file name: ";
        cin >> outFilename;
        DoesFileExist(outFilename);

        vector<Planet> list;

        if (DoesFileExist(outFilename)==true) {
                try {
                        outFile.open(outFilename, ios::app);
                        if (outFile.is_open()==1) {

                                int menuChoice=0;
                                cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Sort List\n6) Quit\nEnter Choice: ";
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
                                                cout << "Enter name of Planet: " << endl;
                                                cin >> search;
                                                Search(list, search);
                                        }
                                        if (menuChoice==DISPLAY) {
                                                Display(list);
                                        }
                                        if (menuChoice==SORT) {
                                                long len=list.size();
                                                BubbleSort(list, len);
                                        }
                                        if (menuChoice!= ADD && menuChoice!=DELETE && menuChoice!=FIND && menuChoice!=DISPLAY && menuChoice!=SORT) {
                                                cout << "That's not an option\n";
                                        }
                                        cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Sort List\n6) Quit\nEnter Choice: ";
                                        cin >> menuChoice;
                                }
                                for (int i=0; i<list.size(); i++) {
                                        outFile << "Name: " << list[i].GetName() << endl;
                                        outFile << "Mass: " << list[i].GetMass() << endl;
                                        outFile << "Radius: " << list[i].GetRadius() << endl;
                                        outFile << "Surface Area: " << list[i].SurfaceArea() << endl;
                                        outFile << "Density: " << list[i].Density() << endl;
                                        outFile << "Gravity: " << list[i].Gravity() << endl << endl;
                                }
                                cout << "Data has been written.\n";
                                outFile.close();
                                cout << "Goodbye\n";
                        }
                        else {
                                cerr << "Error! File " << outFilename << " can't be opened.\n";
                        }
                }
                catch (const char* msg) {
                        cerr << msg << endl;
                }
        }
        if (DoesFileExist(outFilename)==false) {
                try {
                        outFile.open(outFilename, ios::out);
                        if (outFile.is_open()==1) {
                                int menuChoice=0;
                                cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Sort List\n6) Quit\nEnter Choice: ";
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
                                                cout << "Enter name of Planet: " << endl;
                                                cin >> search;
                                                Search(list, search);
                                        }
                                        if (menuChoice==DISPLAY) {
                                                Display(list);
                                        }
                                        if (menuChoice==SORT) {
                                                double size=list.size();
                                                BubbleSort(list, size);
                                        }
                                        if (menuChoice!= ADD && menuChoice!=DELETE && menuChoice!=FIND && menuChoice!=DISPLAY && menuChoice!=SORT) {
                                                cout << "That's not an option\n";
                                        }
                                        cout << "1) Add Planet\n2) Delete Planet\n3) Find Planet\n4) Display List\n5) Sort List\n6) Quit\nEnter Choice: ";
                                        cin >> menuChoice;
                                }
				for (int i=0; i<list.size(); i++) {
                                        outFile << "Name: " << list[i].GetName() << endl;
                                        outFile << "Mass: " << list[i].GetMass() << endl;
                                        outFile << "Radius: " << list[i].GetRadius() << endl;
                                        outFile << "Surface Area: " << list[i].SurfaceArea() << endl;
                                        outFile << "Density: " << list[i].Density() << endl;
                                        outFile << "Gravity: " << list[i].Gravity() << endl << endl;
                                }
                                cout << "Data has been written.\n";
                                outFile.close();
                                cout << "Goodbye\n";
                        }
                        else {
                                cerr << "Error! File " << outFilename << " can't be opened.\n";
                        }
                }
                catch (const char* msg) {
                        cerr << msg << endl;
                }
        }
        return 0;
}

string ReadString(string prompt)
{
        string rv;
        cout << prompt;
        cin >> rv;
        return rv;
}

double ReadDouble(string prompt)
{
        double rv=0.0;
        cout << prompt;
        cin >> rv;
        while (cin.fail()==1) {
                cout << "Error! Cannot read input.\n";
                cin.clear();
                cin.ignore(INT_MAX,'\n');
                cout << prompt;
                cin >> rv;
        }
        return rv;
}

double ReadDouble(string prompt, double minValue)
{
        double rv=0.0;
        rv=ReadDouble(prompt);
        while (rv < minValue) {
                cout << "Error! Value must be bigger than " << minValue << endl;
                rv=ReadDouble(prompt);
        }
        return rv;
}

double ReadDouble(string prompt, double minValue, double maxValue)
{
        double rv=0.0;
        rv=ReadDouble(prompt, minValue);
        while (rv > maxValue) {
                cout << "Error! Value must be bigger than " << maxValue << endl;
                rv=ReadDouble(prompt, minValue);
        }
        return rv;
}				
