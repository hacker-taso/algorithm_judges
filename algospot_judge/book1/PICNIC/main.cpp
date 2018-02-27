#include<iostream>
#include<vector>
#include<list>
using namespace std;
int checked[10];
int friendMap[10][10];
int counter(int, int);
int main(){
	int C, n, m, i, j, person, friend_;
	int sol[50];
	cin >> C;
	for (i=0; i<C; i++)	{
		for (person=0; person<10; person++) {
			checked[person]=0;
			for (friend_=0; friend_<10; friend_++)
				friendMap[person][friend_]=0;
		}
		cin >> n >> m;
		for (j=0; j<m; j++) {
			cin >> person >> friend_;
			friendMap[person][friend_] = 1;
			friendMap[friend_][person] = 1;
		}
		sol[i] = counter(n, 0);
	}
	for (i=0; i<C; i++) {
		cout << sol[i] << endl;
	}
}

int counter(int n, int checkedNum) {
	int person=0;
	int count = 0;
	if (checkedNum==n){
		return 1;
	}
	for (person=0; person<n; person++) {
		if (checked[person] == 0)
			break;
	}

	checked[person] = 1;
	for (int friend_=person+1; friend_<n; friend_++) {
		if (friendMap[person][friend_] == 1 && checked[friend_] == 0) {
			checked[friend_] = 1;
			count += counter(n, checkedNum+2);
			checked[friend_] = 0;
		}
	}
	checked[person] = 0;
	return count;
}
