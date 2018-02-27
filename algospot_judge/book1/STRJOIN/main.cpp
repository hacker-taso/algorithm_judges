#include<iostream>
#include<set>
using namespace std;

int main(void) {
	int C;
	int sols[50];
	int strCnt, totalCost;
	int strLenTmp;
	multiset<int>::iterator it;
	cin >> C;
	for (int i=0; i<C; i++) {
		totalCost = 0;
		cin >> strCnt;
		multiset<int> strLens;
		for (int j=0; j<strCnt; j++) {
			cin >> strLenTmp;
			strLens.insert(strLenTmp);
		}
		while (1 < strLens.size()) {
			it=strLens.begin();
			int smallest = *it;
			it++;
			int secondSmall = *it;
			totalCost += smallest + secondSmall;
			it++;
			strLens.erase(strLens.begin(), it);
			strLens.insert(smallest+secondSmall);
		}
		sols[i] = totalCost;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
