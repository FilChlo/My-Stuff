#include <iostream>
#include <cmath>

using namespace std;

const double grav_mps=9.8;

int main()
{
        double height_hill=0.0, height_ramp=0.0, velocity=0.0;

        cout << "How tall is the hill in meters?:";
        cin >> height_hill;

        cout << "How tall is the ramp in meters?:";
        cin >> height_ramp;

        velocity = sqrt(2 * grav_mps * (height_hill - height_ramp));

        cout << "Velocity at end of ramp is: " << velocity << " m/s " << endl;
        return 0;
}

