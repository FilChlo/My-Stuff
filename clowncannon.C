#include <iostream>
#include <cmath>

using namespace std;

const double gravity_fps=32.2;

int main()
{
        double vel_mph=0.0, angle=0.0, distance=0.0;

        cout << "Enter velocity in mph:";
        cin >> vel_mph;

        cout << "Enter angle in degrees:";
        cin >> angle;

        double vel_fps = vel_mph * 1.467;

        double radian = angle * (3.14 / 180);

        distance =(vel_fps * vel_fps) / gravity_fps * sin(2 * radian);

        cout << " Distance: " << distance << " feet " <<  endl;
        return 0;
}

