// I've read the editorial.
// Start at 01:54AM March 07, 2018
// End at 00:06AM March 07, 2018
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

bool isOdd[10];
vector<int> numZeros;
int numOdd;
int curIdx;
int len;
vector<int> nums;
string sol;
void init() {
	memset(isOdd, 0, sizeof(isOdd));
	numOdd = 0;
	curIdx = 0;
	nums = vector<int>(len);
	numZeros = vector<int>(len);
	sol = "";
}
void updateIsOdd(int n) {
	isOdd[n] = !isOdd[n];
	numOdd += isOdd[n] ? 1 : -1;
}

// check whether I can make valid sequence even after I include current idx.
bool canInclude(int n) {
	int newNumOdd = numOdd + (isOdd[n] ? -1 : 1);
	cout << curIdx << "," << n << "," << len-curIdx-1 << "," << newNumOdd <<endl;
	if (len-curIdx-1 < newNumOdd)
		return false;;
	int num0InRange = numZeros[len-1-newNumOdd] - numZeros[curIdx];
	if (num0InRange < len-curIdx-newNumOdd-1)
		return true;
	vector<int> minVal;
	isOdd[n] = !isOdd[n]; // should be recovered
	for (int i=0; i<10; i++)
		if (isOdd[i])
			minVal.push_back(i);
	isOdd[n] = !isOdd[n]; // recovered
	vector<int> orig;
	orig = vector<int>(nums.end()-newNumOdd, nums.end());
	if (minVal < orig)
		return true;
	return false;
}

void handleCantInclude() {
	int biggest;
	for (biggest=9; 0<=biggest; biggest--) {
		if (biggest<nums[curIdx] && canInclude(biggest)) {
			sol += (char)(biggest+'0');
			updateIsOdd(biggest);
			break;
		}
	}
	sol += string(len-curIdx-numOdd-1, '9');
	for (int i=9; 0<=i; i--)
		if (isOdd[i])
			sol+=(char)(i+'0');
}

void solve() {
	numZeros[0] = !nums[0];
	for (int i=1; i<len; i++) {
		numZeros[i] = numZeros[i-1] + (!nums[0]);
	}
	for (curIdx=0; curIdx<len; curIdx++) {
		if (canInclude(nums[curIdx])) {
			sol += (char)((nums[curIdx])+'0');
			updateIsOdd(nums[curIdx]);
		} else {
			handleCantInclude();
			break;
		}
	}
	cout << sol << endl;
}

int main() {
	int C;
	cin >> C;
	string s;
	for (int i=0; i<C; i++) {
		cin >> s;
		len = s.size();
		init();
		transform(s.begin(), s.end(), nums.begin(),[](char c) {
			return (int)(c-'0');
		});
		solve();
	}
}
