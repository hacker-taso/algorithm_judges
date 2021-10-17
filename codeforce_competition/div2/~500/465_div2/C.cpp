// Start at 1:48AM Feb 20, 2018
// End at 2:40AM Feb 20, 2018
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	double R, x1, y1, x2, y2;
	cin >> R >> x1 >> y1 >> x2 >> y2;
	if (x1==x2 && y1==y2) {
		cout << fixed << setprecision(10) << (x1+R/2) << " " << y1 << " " << R/2 <<endl;
		return 0;
	}
	if (R<=hypot(x1-x2, y1-y2)) {
		cout << fixed << setprecision(10) << x1 << " "<< y1 << " " << R << endl;
		return 0;
	}
	if (x1 == x2) {
		double dist = y2-y1;
		double R2 = (R+dist)/2;
		double y3 = y2-(R+dist)/2;
		if (y2-y1 < 0) {
			dist = y1-y2;
			R2 = (R+dist)/2;
			y3 = y2+(R+dist)/2;
		}
		cout << fixed << setprecision(10) << x1 << " "<< y3 << " " << R2 << endl;
		return 0;
	}
	double a = (y1-y2)/(x1-x2);
	double b = -(y1-y2)*x1/(x1-x2)+y1;
	double b2 = b-y1;
	double a_f = a*a+1;
	double b_f = -2*x1 +2*a*b2;
	double c_f = x1*x1+b2*b2-R*R;
	double x_s1 = (-b_f + sqrt(b_f*b_f-4*a_f*c_f))/(2*a_f);
	double x_s2 = (-b_f - sqrt(b_f*b_f-4*a_f*c_f))/(2*a_f);
	double y_s1 = a*x_s1+b;
	double y_s2 = a*x_s2+b;
	double x4, y4;
	if (0<(x2-x1)*(x1-x_s1)) {
		x4 = x_s1;
		y4 = y_s1;
	} else if (0<(x2-x1)*(x1-x_s2)) {
		x4 = x_s2;
		y4 = y_s2;
	}
	double x3 = (x2+x4)/2;
	double y3 = (y2+y4)/2;
	double R3 = hypot(x2-x3, y2-y3);
	cout << fixed << setprecision(10) << x3 << " "<< y3 <<" "<< R3 << endl;
}
