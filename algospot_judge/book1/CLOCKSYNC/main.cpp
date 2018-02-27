#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

const int INF = 987654321;
void init();
int findMin(int, int);
list<int> connectedClockMap[10];
int clockTimes[16];

int main(){
	init();
	int C;
	int sols[30];
	int minPush;
	cin >> C;
	for (int i=0; i<C; i++) {
		for (int j=0; j<16; j++) {
			cin >> clockTimes[j];
		}
		minPush = findMin(0, 0);
		if (minPush == INF)
			sols[i] = -1;
		else
			sols[i] = minPush;
	}
	for (int i=0; i<C; i++) {
		cout << sols[i] << endl;
	}
}

int findMin(int targetButton, int numPush) {
	if (targetButton == 10) {
		int allTwelve = true;
		for (int i=0; i<16; i++) {
			if (clockTimes[i] != 12) {
				return INF;
			}
		}
		return numPush;
	}
	int minPush = findMin(targetButton+1, numPush);
	list<int> connectedClockNums = connectedClockMap[targetButton];
	for (int i=1; i<4; i++) {
		for (list<int>::iterator it=connectedClockNums.begin(); it != connectedClockNums.end(); it++) {
			clockTimes[*it] = (clockTimes[*it] + 3) % 12 == 0 ? 12 : (clockTimes[*it] + 3) % 12;
		}
		minPush = min(minPush, findMin(targetButton+1, numPush+i));
	}
	for (list<int>::iterator it=connectedClockNums.begin(); it != connectedClockNums.end(); it++) {
		clockTimes[*it] = (clockTimes[*it] + 3) % 12 == 0 ? 12 : (clockTimes[*it] + 3) % 12;
	}
	return minPush;
}

void init() {
	connectedClockMap[0].push_back(0);
	connectedClockMap[0].push_back(1);
	connectedClockMap[0].push_back(2);

	connectedClockMap[1].push_back(3);
	connectedClockMap[1].push_back(7);
	connectedClockMap[1].push_back(9);
	connectedClockMap[1].push_back(11);

	connectedClockMap[2].push_back(4);
	connectedClockMap[2].push_back(10);
	connectedClockMap[2].push_back(14);
	connectedClockMap[2].push_back(15);

	connectedClockMap[3].push_back(0);
	connectedClockMap[3].push_back(4);
	connectedClockMap[3].push_back(5);
	connectedClockMap[3].push_back(6);
	connectedClockMap[3].push_back(7);

	connectedClockMap[4].push_back(6);
	connectedClockMap[4].push_back(7);
	connectedClockMap[4].push_back(8);
	connectedClockMap[4].push_back(10);
	connectedClockMap[4].push_back(12);

	connectedClockMap[5].push_back(0);
	connectedClockMap[5].push_back(2);
	connectedClockMap[5].push_back(14);
	connectedClockMap[5].push_back(15);

	connectedClockMap[6].push_back(3);
	connectedClockMap[6].push_back(14);
	connectedClockMap[6].push_back(15);

	connectedClockMap[7].push_back(4);
	connectedClockMap[7].push_back(5);
	connectedClockMap[7].push_back(7);
	connectedClockMap[7].push_back(14);
	connectedClockMap[7].push_back(15);

	connectedClockMap[8].push_back(1);
	connectedClockMap[8].push_back(2);
	connectedClockMap[8].push_back(3);
	connectedClockMap[8].push_back(4);
	connectedClockMap[8].push_back(5);

	connectedClockMap[9].push_back(3);
	connectedClockMap[9].push_back(4);
	connectedClockMap[9].push_back(5);
	connectedClockMap[9].push_back(9);
	connectedClockMap[9].push_back(13);
}