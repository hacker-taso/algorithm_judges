#include<iostream>
using namespace std;
int main() {
	int N;
	cin >> N;
	string s;
	cin >> s;
	for (int i=1; i<s.size(); i++) {
		if (s[i-1] == s[i] && s[i] != '?') {
			cout << "No" << endl;
			return 0;
		}
	}
	if (s[0] == '?' || s[s.size()-1] == '?') {
		cout << "Yes" << endl;
		return 0;
	}
	char prevColor = -1;
	bool isOpen = false;
	for (int i=1; i<s.size(); i++) {
		if (s[i] == '?') {
			if (isOpen) {
				cout << "Yes" << endl;
				return 0;
			} else {
				isOpen = true;
				prevColor = s[i-1];
			}
		} else {
			if (isOpen) {
				if (s[i] == prevColor) {
					cout << "Yes" << endl;
					return 0;
				}
				isOpen = false;
			}
		}
	}
	cout << "No" << endl;
}
