// 1+a==b. I thought this expression is evaluated like 1+(a==b) but it isn't
// until 12:30
#include<iostream>
#include<algorithm>
using namespace std;

int gVal[1000001];
int numK[10][1000001];
int l,r,k;
int solve() {
	return numK[k][r]-numK[k][l-1];
}

void init() {
	for (int i=1; i<10; i++) {
		gVal[i] = i;
	}
	int dec[10];
	dec[0] = 1;
	for (int a=0; a<=9; a++) {
		for (int b=0; b<=9; b++) {
			for (int c=0; c<=9; c++) {
				for (int d=0; d<=9; d++) {
					for (int e=0; e<=9; e++) {
						for (int f=0; f<=9; f++) {
							int curVal = a*100000+b*10000+c*1000+d*100+e*10+f;
							gVal[curVal] = (a==0?1:a)*(b==0?1:b)*(c==0?1:c)*(d==0?1:d)*(e==0?1:e)*(f==0?1:f);
							while (10<=gVal[curVal]) {
								gVal[curVal] = gVal[gVal[curVal]];
							}
						}
					}
				}
			}
		}
	}
	gVal[1000000] = 1;
	for (int i=1; i<10; i++) {
		numK[i][0] = 0;
		for (int j=1; j<=1000000; j++) {
			numK[i][j] = numK[i][j-1] + (gVal[j]==i);
		}
	}
}

int main() {
	int numQuery;
	init();
	cin >> numQuery;
	for (int i=0; i<numQuery; i++) {
		cin >> l >> r >> k;
		cout << solve() <<endl;
	}
}
