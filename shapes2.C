/*This program is just like shapes1
 *but this time using classes
*/
#include <iostream>
#include <cmath>
#include <climits>
#include <string>

class Cube
{
        private:
                double side;

        public:
                double CubeVolume();
                double CubeSurfaceArea();
                bool SetSide(double x);
                double GetSide();
                Cube();
};

Cube::Cube()
{
        side=0.0;
}

double Cube::CubeVolume()
{
        return side*side*side;
}

double Cube::CubeSurfaceArea()
{
        return 6.0*(side*side);
}

bool Cube::SetSide(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                side=x;
                rv=true;
        }
        return rv;
}

double Cube::GetSide()
{
        return side;
}
/*-----------------------------------*/
class Sphere
{
        private:
                double radius;

        public:
                double SphereVolume();
                double SphereSurfaceArea();
                bool SetRadius(double x);
                double GetRadius();
                Sphere();
};

Sphere::Sphere()
{
        radius=0.0;
}

double Sphere::SphereVolume()
{
        return (4.0 / 3.0) * M_PI * pow(radius,3.0);
}

double Sphere::SphereSurfaceArea()
{
        return 4.0 * M_PI * pow(radius,2.0);
}

bool Sphere::SetRadius(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                radius=x;
                rv=true;
        }
        return rv;
}

double Sphere::GetRadius()
{
        return radius;
}
/*------------------------------------*/
class Prism
{
        private:
                double length, width, height;

        public:
                double PrismVolume();
                double PrismSurfaceArea();
                bool SetLength(double x);
                bool SetWidth(double x);
                bool SetHeight(double x);
                double GetLength();
                double GetWidth();
                double GetHeight();
                Prism();
};

Prism::Prism()
{
        length=0.0;
        width=0.0;
        height=0.0;
}

double Prism::PrismVolume()
{
        return length*width*height;
}

double Prism::PrismSurfaceArea()
{
        return 2.0*length*width +
                2.0*length*height +
                2.0*height*width;
}

bool Prism::SetLength(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                length=x;
                rv=true;
        }
        return rv;
}

bool Prism::SetWidth(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                width=x;
                rv=true;
        }
        return rv;
}

bool Prism::SetHeight(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                height=x;
                rv=true;
        }
        return rv;
}

double Prism::GetLength()
{
        return length;
}

double Prism::GetWidth()
{
        return width;
}

double Prism::GetHeight()
{
        return height;
}
/*----------------------------------------*/
class Cylinder
{
        private:
                double radius, height;

        public:
                double CylVolume();
                double CylSurfaceArea();
                bool SetRadius(double x);
                bool SetHeight(double x);
                double GetRadius();
                double GetHeight();
                Cylinder();
};

Cylinder::Cylinder()
{
        radius=0.0;
        height=0.0;
}

double Cylinder::CylVolume()
{
        return M_PI*pow(radius,2.0)*height;
}

double Cylinder::CylSurfaceArea()
{
        return 2.0*M_PI*radius*height + 2.0*M_PI*pow(radius,2.0);
}

bool Cylinder::SetRadius(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                radius=x;
                rv=true;
        }
        return rv;
}

bool Cylinder::SetHeight(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                height=x;
                rv=true;
        }
        return rv;
}

double Cylinder::GetRadius()
{
        return radius;
}

double Cylinder::GetHeight()
{
        return height;
}
/*-----------------------------------------*/
class Cone
{
        private:
                double radius, height;

        public:
                double ConeVolume();
                double ConeSurfaceArea();
                bool SetRadius(double x);
                bool SetHeight(double x);
                double GetRadius();
                double GetHeight();
                Cone();
};

Cone::Cone()
{
        radius=0.0;
        height=0.0;
}

double Cone::ConeVolume()
{
        return (M_PI / 3.0)*pow(radius,2.0)*height;
}

double Cone::ConeSurfaceArea()
{
        return M_PI*pow(radius,2.0) + M_PI*radius*sqrt(pow(radius,2.0) + pow(height,2.0));
}

bool Cone::SetRadius(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                radius=x;
                rv=true;
        }
        return rv;
}

bool Cone::SetHeight(double x)
{
        bool rv=false;
        if (x >= 0.0) {
                height=x;
                rv=true;
        }
        return rv;
}

double Cone::GetRadius()
{
        return radius;
}

double Cone::GetHeight()
{
        return height;
}
/*------------------------------------------*/
using namespace std;

const int CUBE=1;
const int SPHERE=2;
const int PRISM=3;
const int CYLINDER=4;
const int CONE=5;
const int QUIT=6;

double ReadDouble(string prompt);
double ReadDouble(string promt, double minValue);

double CubeVolume(Cube cu);
double SphereVolume(Sphere sp);
double PrismVolume(Prism pr);
double CylVolume(Cylinder cy);
double ConeVolume(Cone co);

double CubeSurfaceArea(Cube cu);
double SphereSurfaceArea(Sphere sp);
double PrismSurfaceArea(Prism pr);
double CylSurfaceArea(Cylinder cy);
double ConeSurfaceArea(Cone co);

void CubeInput(Cube& cu);
void SphereInput(Sphere& sp);
void PrismInput(Prism& pr);
void CylinderInput(Cylinder& cy);
void ConeInput(Cone& co);

int main()
{
        int menuChoice=0;

        cout << "1) Cube\n2) Sphere\n3) Prism\n4) Cylinder\n5) Cone\n6) Quit\nEnter choice: ";
        cin >> menuChoice;

        while (menuChoice !=QUIT) {
                if (menuChoice==CUBE) {
                        Cube cube;
                        CubeInput(cube);
                        cout << "Volume: " << cube.CubeVolume() << endl;
                        cout << "Surface Area: " << cube.CubeSurfaceArea() << endl;
                }

                if (menuChoice==SPHERE) {
                        Sphere sphere;
                        SphereInput(sphere);
                        cout << "Volume: " << sphere.SphereVolume() << endl;
                        cout << "Surface Area: " << sphere.SphereSurfaceArea() << endl;
                }

                if (menuChoice==PRISM) {
                        Prism prism;
                        PrismInput(prism);
                        cout << "Volume: " << prism.PrismVolume() << endl;
                        cout << "Surface Area: " << prism.PrismSurfaceArea() << endl;
                }

                if (menuChoice==CYLINDER) {
                        Cylinder cylinder;
                        CylinderInput(cylinder);
                        cout << "Volume: " << cylinder.CylVolume() << endl;
                        cout << "Surface Area: " << cylinder.CylSurfaceArea() << endl;
                }

                if (menuChoice==CONE) {
                        Cone cone;
                        ConeInput(cone);
                        cout << "Volume: " << cone.ConeVolume() << endl;
                        cout << "Surface Area: " << cone.ConeSurfaceArea() << endl;
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

void CubeInput(Cube& cu)
{
        while (cu.SetSide( ReadDouble("Side Length: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
        }
}

void SphereInput (Sphere& sp)
{
        while (sp.SetRadius( ReadDouble("Radius Length: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
        }
}

void PrismInput(Prism& pr)
{
        while (pr.SetLength( ReadDouble("Length: ",0.0) )==false )
        {
                cerr << "Error! Length must be >= 0.0\n";
        }

        while (pr.SetWidth( ReadDouble("Width: ",0.0) )==false )
        {
                cerr << "Error! Width must be >= 0.0\n";
        }

        while (pr.SetHeight( ReadDouble("Height: ",0.0) )==false )
        {
                cerr << "Error! Height must be >= 0.0\n";
        }
}

void CylinderInput(Cylinder& cy)
{
        while (cy.SetRadius( ReadDouble("Radius Length: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
        }

        while (cy.SetHeight( ReadDouble("Height: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
        }

}

void ConeInput(Cone& co)
{
        while (co.SetRadius( ReadDouble("Radius Length: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
        }

        while (co.SetHeight( ReadDouble("Height: ",0.0) )==false )
        {
                cerr << "Error! Input must be >= 0.0\n";
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
