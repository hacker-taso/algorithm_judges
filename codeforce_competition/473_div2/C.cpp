#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n<6)
		cout << -1 << endl;
	else {
		cout << "1 2" <<endl;
		cout << "2 3" <<endl;
		cout << "2 4" <<endl;
		cout << "3 5" << endl;
		cout << "3 6" << endl;
		for (int i=7; i<=n; i++)
			cout << 3 << " " << i <<endl;
	}
	for (int i=1; i<n; i++) {
		cout << i << " " << i+1 << endl;
	}
}
