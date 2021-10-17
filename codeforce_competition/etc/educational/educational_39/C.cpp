// Start at 00:15AM March 07, 2018
// End at 00:20AM March 07, 2018
#include<iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	char curChar = 'a';
	for (int i=0; i<s.size(); i++) {
		if (s[i]<=curChar) {
			s[i] = curChar;
			curChar++;
			if (curChar == ('z'+1)) {
				cout << s << endl;
				return 0;
			}
		}
	}
	cout << -1 << endl;
}
