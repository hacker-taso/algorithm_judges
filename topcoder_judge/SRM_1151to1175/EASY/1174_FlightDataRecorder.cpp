// start from 08:56PM, Jan 31, 2018
// complete at 09:04PM, Jan 31, 2018
#include<iostream>
#include<cmath>
#include<vector>
#define _USE_MATH_DEFINES
using namespace std;

class FlightDataRecorder {
private:
    double degreeToRad(double deg) {
        return deg*2*M_PI/360;
    }
    public:
    double getDistance(vector <int> heading, vector <int> distance) {
        double x=0, y=0;
        for (int i=0; i<heading.size(); i++) {
            double rad = degreeToRad(heading[i]);
            y+=cos(rad) * distance[i];
            x+=sin(rad) * distance[i];
        }
        return hypot(x, y);
    }
};
