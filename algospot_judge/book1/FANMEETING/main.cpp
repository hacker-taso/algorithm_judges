#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void multiply(const vector<int>&, const vector<int>&, vector<int>&);

int main(void) {
	ios::sync_with_stdio(false);
	int C;
	int sols[20];
	string membersStr, fansStr;
	cin >> C;
	vector<int> multResult;
	vector<int> members;
	vector<int> fans;
	for (int i=0; i<C; i++) {
		cin >> membersStr >> fansStr;
		multResult.clear();
		members.resize(membersStr.size());
		fans.resize(fansStr.size());
		for (int j=0; j<membersStr.size(); j++) {
			members[j] = (membersStr[j] == 'M' ? 1 : 0);
		}
		for (int j=0; j<fansStr.size(); j++) {
			fans[j] = (fansStr[fansStr.size()-j-1] == 'M' ? 1 : 0);
		}
		multiply(fans, members, multResult);
		sols[i] = 0;
		for (int j=members.size()-1; j<fans.size(); j++) {
			sols[i] += (multResult[j] == 0);
		}
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

// result = a+b*10^n
void addTo(const vector<int>& a, const vector<int>& b, int n, vector<int>& result) {
	result.resize(max(b.size()+n, a.size()), 0);
	for (int i=0; i<a.size(); i++) {
		result[i] += a[i];
	}
	for (int i=0; i<b.size(); i++) {
		result[i+n] += b[i];
	}
}

void addTo(const vector<int>& a, int n, vector<int>& result) {
	result.resize(max(a.size()+n, result.size()), 0);
	for (int i=0; i<a.size(); i++) {
		result[i+n] += a[i];
	}
}

void subFrom(vector<int>& A, vector<int>& B) {
	A.resize(max(A.size(), B.size()), 0);
	for (int i=0; i < B.size(); i++) {
		A[i] = A[i] - B[i];
	}
}

void naiveMultiply(const vector<int>& a, const vector<int>& b, vector<int>& result) {
	result.resize(max(a.size()+b.size() - 1, result.size()), 0);
	for (int i=0; i<a.size(); i++) {
		for (int j=0; j<b.size(); j++) {
			result[i+j] += a[i]*b[j];
		}
	}
}
void printArr(vector<int>& a) {
	for (int i=0; i<a.size(); i++)
		cout << a[i] << " ";
	cout <<endl;
}

// len(A) <= len(B)
void multiply(const vector<int>& a, const vector<int>& b, vector<int>& result) {
	if (b.size() < a.size()) {
		multiply(b, a, result);
		return;
	}
	if (a.size() == 0 || b.size() == 0)
		return;
	else if (b.size() <= 50) {
		naiveMultiply(a, b, result);
		return;
	}
	vector<int> abl, abr;
	int mid = b.size()/2;
	int aMid = min<int>(a.size(), mid);
	vector<int> al(a.begin(), a.begin()+aMid);
	vector<int> ar(a.begin()+aMid, a.end());
	vector<int> bl(b.begin(), b.begin()+mid);
	vector<int> br(b.begin()+mid, b.end());
	multiply(al, bl, abl);
	multiply(ar, br, abr);
	addTo(abl, 0, result);
	addTo(abr, mid+mid, result);

	vector<int> aaSum, bbSum, aabbMul;
	addTo(al, ar, 0, aaSum);
	addTo(bl, br, 0, bbSum);
	multiply(aaSum, bbSum, aabbMul);

	subFrom(aabbMul, abr);
	subFrom(aabbMul, abl);
	addTo(aabbMul, mid, result);
}
