// Retrospection:
// 1. This problem was very difficult.. (So, actually, I refered many part from Jongman book)
// 2. Lesson I learned: sutherland hodgman algorithm to get union of two polygons.(read cutPoly function.)
#include<iostream>
#include<iomanip>
#include<cmath>
#include<vector>
using namespace std;

struct vector2{
	double x,y;
	explicit vector2(double x_=0, double y_=0): x(x_),y(y_){}
	vector2 operator + (const vector2& rhs) const {
		return vector2(x+rhs.x, y+rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x-rhs.x, y-rhs.y);
	}
	vector2 operator * (const double rhs) const {
		return vector2(x*rhs, y*rhs);
	}
	bool operator < (const vector2& rhs) const {
		return x==rhs.x ? y<rhs.y : x<rhs.x;
	}
	double norm() const {
		return hypot(x, y);
	}
	vector2 normalize() const {
		return vector2(x/norm(), y/norm());
	}
	double dot(const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x*rhs.y - rhs.x*y;
	}
	vector2 project(const vector2& rhs) const {
		vector2 rUnit =  rhs.normalize();
		return rUnit * rUnit.dot(*this);
	}
};

int numPoint;
vector<vector2> island;
double x_,y_,x2,y2;
vector<vector2> rectangle;

bool lineIntersection(const vector2& a1, const vector2& a2, const vector2& b1, const vector2& b2, vector2& inter) {
	vector2 dirA = a1-a2;
	vector2 dirB = b1-b2;
	double det = dirA.cross(dirB);
	if (fabs(det) < 10e-11) return false;
	double t = dirB.cross(a2-b2)/det;
	inter = a2+dirA*t;
	return true;
}

double ccw(const vector2& a, const vector2& b, const vector2& c) {
	return (b-a).cross(c-a);
}

vector<vector2> cutPoly(const vector<vector2>& poly, const vector2 point1, const vector2 point2) {
	vector<vector2> result;
	vector2 intersection;
	for (int i=0; i<poly.size(); i++) {
		if (0<=ccw(point1, point2, poly[i])) {
			result.push_back(poly[i]);
		}
		if (ccw(point1, point2, poly[i])*ccw(point1, point2, poly[(i+1)%poly.size()]) < 0) {
			lineIntersection(point1, point2, poly[i], poly[(i+1)%poly.size()], intersection);
			result.push_back(intersection);
		}
	}
	return result;
}

double getArea(const vector<vector2>& poly) {
	double area = 0;
	for (int i=0; i<poly.size(); i++) {
		area += poly[i].cross(poly[(i+1)%poly.size()]);
	}
	return fabs(area)/2;
}

double solve() {
	vector<vector2> ret;
	for (int i=0; i<rectangle.size(); i++) {
		if (i==0) {
			ret = cutPoly(island, rectangle[i], rectangle[(i+1)%rectangle.size()]);
		}
		else
			ret = cutPoly(ret, rectangle[i], rectangle[(i+1)%rectangle.size()]);
	}
	return getArea(ret);
}

int main() {
	int C;
	double sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> x_ >> y_ >> x2 >> y2 >> numPoint;
		rectangle.clear();
		rectangle.push_back(vector2(x_, y_));
		rectangle.push_back(vector2(x2, y_));
		rectangle.push_back(vector2(x2, y2));
		rectangle.push_back(vector2(x_, y2));
		island.clear();
		for (int j=0; j<numPoint; j++) {
			cin >> x_ >> y_;
			island.push_back(vector2(x_, y_));
		}
		sols[i] = solve();
	}
	for (int i=0; i<C; i++) {
		cout << fixed << setprecision(10) << sols[i] << endl;
	}
}
