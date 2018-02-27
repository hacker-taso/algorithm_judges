#include<iostream>
#include<algorithm>
#include<cmath>
#define _USE_MATH_DEFINES
#define INF 0x76543210
using namespace std;

struct vector2 {
	double x, y;

	explicit vector2(double x_=0, double y_=0) { x=x_; y=y_; };
	bool operator == (const vector2& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
	bool operator < (const vector2& rhs) const {
		return x == rhs.x ? y < rhs.y : x < rhs.x;
	}
	vector2 operator + (const vector2& rhs) const {
		return vector2(x+rhs.x, y+rhs.y);
	}
	vector2 operator - (const vector2& rhs) const {
		return vector2(x-rhs.x, y-rhs.y);
	}
	vector2 operator * (const double rhs) const {
		return vector2(x*rhs, y*rhs);
	}
	double norm() const { return hypot(x, y); }
	vector2 normalize() const {
		return vector2(x / norm(), y/ norm());
	}
	double polar() const { return fmod(atan2(y, x) + 2*M_PI, 2*M_PI); }
	double dot(const vector2& rhs) const {
		return x*rhs.x + y*rhs.y;
	}
	double cross(const vector2& rhs) const {
		return x*rhs.y - y*rhs.x;
	}
	vector2 projection(const vector2& rhs) const {
		vector2 r = rhs.normalize();
		return r * r.dot(*this);
	}
};

int numBlocks;
int initX, initY, dx, dy;
int x[100];
int y[100];
int r[100];
vector2 initCenter;
vector2 dir;
vector2 center[100];

vector2 perpendicular_foot(vector2 point, vector2 direction, vector2 v) {
	return point + (v-point).projection(direction-point);
}

// find conflict pos and index
int findConflictPos(vector2& pos) {
	double a, bPrime, c, p;
	double minP = INF;
	vector2 minPos;
	int minIdx = -1;
	for (int i=0; i<numBlocks; i++) {
		a = dir.dot(dir);
		bPrime = dir.dot(initCenter-center[i]);
		c = (initCenter-center[i]).dot(initCenter-center[i]) - (1+r[i])*(1+r[i]);
		if (bPrime*bPrime - a*c <0)
			continue;
		p =(-bPrime - sqrt(bPrime*bPrime - a*c))/a;
		if (0<p && p < minP) {
			minP = p;
			minPos = initCenter + dir*p;
			minIdx = i;
		}
	}
	pos = minPos;
	return minIdx;
}

// find conflict idx and update next initCenter and dir.
// returns conflicted block index. if not found -1.
int findConflictIdx() {
	vector2 conflictCenter;
	int minIdx = findConflictPos(conflictCenter);
	if (minIdx == -1) return minIdx;
	initCenter = conflictCenter;
	vector2 middleDir = (initCenter - center[minIdx]);
	vector2 minusDir = vector2() - dir;
	vector2 footDir = perpendicular_foot(initCenter, initCenter+middleDir, initCenter+minusDir) - initCenter;
	dir = footDir + footDir - minusDir;
	return minIdx;
}

void solve() {
	int conflicted;
	for (int i=0; i<100; i++) {
		conflicted = findConflictIdx();
		if (conflicted == -1)
			break;
		if (i!=0)
			cout << " ";
		cout << conflicted;
	}
	cout << endl;
}

int main() {
	int C;
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> initX >> initY >> dx >> dy >> numBlocks;
		initCenter = vector2(initX, initY);
		dir = vector2(dx, dy);
		for (int i=0; i<numBlocks; i++) {
			cin >> x[i] >> y[i] >> r[i];
			center[i] = vector2(x[i], y[i]);
		}
		solve();
	}
}
