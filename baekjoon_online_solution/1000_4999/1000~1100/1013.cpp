#include<iostream>
#include<regex>
#include<string>
using namespace std;
int main() {
	int T;
	string seq;
	cin >> T;
	regex pattern("(100+1+|01)+");
	for (int i=0; i<T; i++) {
		cin >> seq;
		if (regex_match(seq, pattern))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}

