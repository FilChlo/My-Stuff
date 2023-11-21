/* This program is used to display
 * more info on Yikes the Clown's
 * journey from being shot from cannon
*/

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const double grav_fps=32.2;
const long numOfIncrement=20;

int main()
{
        double vel_mph=0.0, vel_fps=0.0, angle=0.0, radian=0.0,
               distance=0.0, totaltime=0.0, maxheight=0.0,
               increment=0.0, seconds=0.0, xcord=0.0, ycord=0.0;

        cout << "Enter velocity in mph:";
        cin >> vel_mph;
        while (vel_mph < 0.0) {
                cout << "Sorry, velocity must be positive\n";
                cout << "Enter velocity again:";
                cin >> vel_mph;
        }
        vel_fps = vel_mph * 1.467;

        cout << "Enter angle in degrees:";
        cin >> angle;
        while (angle < 0 || angle > 90) {
                cout << "Angle must be between 0 and 90 degrees!\n";
                cout << "Enter angle again:";
                cin >> angle;
        }
        radian = angle * (M_PI/180);

        distance = (pow(vel_fps,2.0) / grav_fps) * sin(2 * radian);
        cout << "Distance: " << distance << " feet" << endl;

        totaltime = distance / (vel_fps * cos(radian));
        cout << "Air time: " << totaltime << " seconds" << endl;

        maxheight = (vel_fps * sin(radian)) * totaltime / 2 - grav_fps / 2 * (pow((totaltime / 2),2.0));
        cout << "Max height: " << maxheight << " feet" << endl;

        increment = totaltime / numOfIncrement;

        int loop=0;
        cout << "Seconds\tXcord\tYcord" << endl;
        while (loop <= numOfIncrement) {
                cout << fixed << setprecision(3) << seconds << "\t" << xcord << "\t" << ycord << endl;
                seconds += increment;
                xcord = (vel_fps * cos(radian)) * seconds;
                ycord = (vel_fps * sin(radian)) * seconds - .5 * grav_fps * pow(seconds,2.0);
                loop++;
        }
        return 0;
}

