// 12:22 ~ 38?
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> l;
int n;
string table;

bool solve() {
	int start, end;
	for (int i=0; i<table.size(); i++) {
		if (table[i] == '1') {
			start = i;
			while (i<table.size() && table[i] == '1') {
				i++;
			}
			end = i;
			i--;
			sort(l.begin()+start, l.begin()+end+1);
		}
	}
	for (int i=0; i<l.size(); i++) {
		if (i+1!=l[i])
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	l = vector<int>(n, 0);
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	cin >> table;
	if (solve())
		cout << "YES" <<endl;
	else
		cout << "NO" << endl;
}
