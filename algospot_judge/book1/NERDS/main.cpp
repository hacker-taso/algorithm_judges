// Retrospection: 
// 1. I've learned gift wrapping algorithm.(with considering parallel case)
// 2. mistake: I thought if two convexes overlap, then there should be a point which is inside other convex.
// But it is not true. counter example is two triangles which forms star shape(hexagram).
#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

struct vector2 {
	double x,y;

	explicit vector2(double x_=0, double y_=0) {x=x_;y=y_;}
	bool operator == (const vector2& rhs) const{
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const{
		return x == rhs.x ? y<rhs.y : x < rhs.x;
	}
	vector2 operator +(const vector2& rhs) const{
		return vector2(x+rhs.x, y+rhs.y);
	}
	vector2 operator -(const vector2& rhs) const{
		return vector2(x-rhs.x, y-rhs.y);
	}
	vector2 operator *(const double rhs) const{
		return vector2(x*rhs, y*rhs);
	}
	double norm() const{
		return hypot(x, y);
	}
	vector2 normalize() const{
		return vector2(x/norm(), y/norm());
	}
	double dot(const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const{
		return x*rhs.y - y*rhs.x;
	}
	vector2 project(const vector2& rhs) {
		vector2 rUnit = rhs.normalize();
		return rUnit * rUnit.dot(*this);
	}
};

int numPerson;
vector<vector2> nerds;
vector<vector2> nonNerds;

bool isInside(const vector2& point, const vector<vector2>& polygon) {
	int crossCnt = 0;
	double atX;
	int j, polySize = polygon.size();
	for (int i=0; i<polySize; i++) {
		j = (i+1)%polySize;
		if ( (point.y < polygon[i].y) != (point.y < polygon[j].y) ) {
			atX = point.y * (polygon[i].x-polygon[j].x)/(polygon[i].y-polygon[j].y)
				- polygon[j].y*(polygon[i].x-polygon[j].x)/(polygon[i].y-polygon[j].y) + polygon[j].x;
			if ( point.x < atX )
				crossCnt++;
			if (point.x == atX)
				return true;
		}
	}
	return crossCnt % 2;
}

double ccw(const vector2& a, const vector2& b, const vector2& c) {
	return (b-a).cross(c-b);
}

bool segmentIntersect(const vector2& a, const vector2& b, const vector2& c, const vector2& d) {
	double ab = ccw(a,b,c) * ccw(a,b,d);
	double cd = ccw(c,d,a) * ccw(c,d,b);
	if (ab<=1e-11 && cd<=1e-11) {
		const vector2& smallAB = min(a,b);
		const vector2& bigAB = max(a,b);
		const vector2& smallCD = min(c,d);
		const vector2& bigCD = max(c,d);
		return ! (bigCD < smallAB || bigAB < smallCD);
	}
	return ab<=0 && cd<=0;
}

void makeConvexHull(vector<vector2> points, vector<vector2>& convexHull) {
	sort(points.begin(), points.end());
	convexHull.push_back(points[0]);
	int pointsSize = points.size();
	vector2 curr, next;
	int j=0;
	while (true) {
		curr = convexHull.back();
		next = points[0];
		for (int i=0; i<pointsSize; i++) {
			double ccwVal = ccw(curr, next, points[i]);
			if (0<ccwVal) {
				next = points[i];
			} else if (ccwVal == 0) {
				// choose farther one.
				if ((curr-next).norm() < (curr-points[i]).norm())
					next = points[i];
			}
		}
		if (next == convexHull.front())
			return;
		else
			convexHull.push_back(next);
	}
}

bool solve() {
	vector<vector2> nerdConvex;
	vector<vector2> nonNerdConvex;
	makeConvexHull(nerds, nerdConvex);
	makeConvexHull(nonNerds, nonNerdConvex);
	if (isInside(nerds[0], nonNerdConvex) || isInside(nonNerds[0], nerdConvex))
		return false;
	for (int i=0; i<nerdConvex.size(); i++) {
		vector2& a = nerdConvex[i];
		vector2& b = nerdConvex[(i+1)%nerdConvex.size()];
		for (int j=0; j<nonNerdConvex.size(); j++) {
			vector2& c = nonNerdConvex[j];
			vector2& d = nonNerdConvex[(j+1)%nonNerdConvex.size()];
			if (segmentIntersect(a,b,c,d))
				return false;
		}
	}
	return true;
}

int main() {
	int C;
	double shoeSize, speed;
	bool isNerd;
	vector<bool> sols;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> numPerson;
		nerds.clear();
		nonNerds.clear();
		for (int j=0; j<numPerson; j++) {
			cin >> isNerd >> shoeSize >> speed;
			if (isNerd)
				nerds.push_back(vector2(shoeSize, speed));
			else
				nonNerds.push_back(vector2(shoeSize, speed));
		}
		sols.push_back(solve());
	}
	for (int i=0; i<C; i++) {
		if (sols[i])
			cout << "THEORY HOLDS" << endl;
		else
			cout << "THEORY IS INVALID" << endl;
	}
}
