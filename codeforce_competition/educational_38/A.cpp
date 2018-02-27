// Start at  00:05AM Feb 17, 2018
// End at 00:13AM Feb 17, 2018
#include<iostream>
using namespace std;
const string vowels = "aeiouy";
int main() {
	int n;
	string s;
	cin >> n >> s;
	for (int i=1; i<s.size(); i++) {
		if (vowels.find(s[i-1]) != string::npos && vowels.find(s[i]) != string::npos) {
			s.erase(i, 1);
			i--;
		}
	}
	cout << s <<endl;
}
