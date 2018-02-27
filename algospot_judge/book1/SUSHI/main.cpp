#include<iostream>
using namespace std;

int totalItemCnt;
int totalBudget;
int prices[20];
int happiness[20];

int getMaxHappiness() {
	int totalHappiness[201] = {0};
	int candidate = 0;

	for (int budget=0; budget<=totalBudget; budget++) {
		candidate = 0;
		for (int j=0; j<totalItemCnt; j++) {
			if (prices[j] <= budget)
				candidate = max(candidate, totalHappiness[(budget-prices[j])%201]+happiness[j]);
		}
		totalHappiness[budget%201] = candidate;
	}
	return totalHappiness[totalBudget%201];
}

int main() {
	int C, sols[50];
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> totalItemCnt >> totalBudget;
		totalBudget = totalBudget/100;
		for (int j=0; j<totalItemCnt; j++) {
			cin >> prices[j] >> happiness[j];
			prices[j] = prices[j]/100;
		}
		sols[i] = getMaxHappiness();
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}
