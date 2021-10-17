#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	string str;
	cin >> str;
	string str2=str;
	reverse(str2.begin(), str2.end());
	str += str2;
	cout << str <<endl;
}
