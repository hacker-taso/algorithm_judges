// Start at 11:13PM Feb 27, 2018
// End at 00:40AM Feb 28, 2018
#include<iostream>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;

int turnAroundT, nAtoB, nBtoA;
// departure, arrival
pair<int, int> AtoB[100];
pair<int, int> BtoA[100];
bool checkedAtoB[100];
bool checkedBtoA[100];
int fromA, fromB;

void init() {
	memset(checkedAtoB, 0, sizeof(checkedAtoB));
	memset(checkedBtoA, 0, sizeof(checkedBtoA));
	fromA = 0;
	fromB = 0;
}

void updateChecked(int myIdx, int& numFromMe, int nMeToOther, int nOtherToMe,
	pair<int,int> meToOther[100], pair<int,int> otherToMe[100], bool checkedMeToOther[100], bool checkedOtherToMe[100]) {
	numFromMe++;
	while (true) {
		checkedMeToOther[myIdx] = true;
		int otherLower = meToOther[myIdx].first + turnAroundT;
		int otherIdx = 0;
		for (; otherIdx<nOtherToMe; otherIdx++) {
			if (otherLower<=otherToMe[otherIdx].second && !checkedOtherToMe[otherIdx]) break;
		}
		if (otherIdx == nOtherToMe) break;
		checkedOtherToMe[otherIdx] = true;
		int myLower = otherToMe[otherIdx].first + turnAroundT;
		for (myIdx = 0; myIdx<nMeToOther; myIdx++) {
			if (myLower<=meToOther[myIdx].second && !checkedMeToOther[myIdx]) break;
		}
		if (myIdx == nMeToOther) break;
	}
}
void fromAFunc(int aIdx) {
	updateChecked(aIdx, fromA, nAtoB, nBtoA, AtoB, BtoA, checkedAtoB, checkedBtoA);
}

void fromBFunc(int bIdx) {
	updateChecked(bIdx, fromB, nBtoA, nAtoB, BtoA, AtoB, checkedBtoA, checkedAtoB);
}

void doUntilComplete() {
	while (true) {
		bool found = false;
		int fromAIdx = 0;
		int fromBIdx = 0;
		while (true) {
			for (;fromAIdx<nAtoB; fromAIdx++) {
				if (checkedAtoB[fromAIdx] == false) break;
			}
			for (;fromBIdx<nBtoA; fromBIdx++) {
				if (checkedBtoA[fromBIdx] == false) break;
			}
			if (fromAIdx == nAtoB && fromBIdx == nBtoA) break;
			found = true;
			if (fromAIdx == nAtoB) fromBFunc(fromBIdx);
			else if (fromBIdx == nBtoA) fromAFunc(fromAIdx);
			else if (AtoB[fromAIdx].first == BtoA[fromBIdx].first) {
				if (AtoB[fromAIdx].second <= BtoA[fromBIdx].second) fromAFunc(fromAIdx);
				else fromBFunc(fromBIdx);
			} else if (AtoB[fromAIdx].first <= BtoA[fromBIdx].first) fromAFunc(fromAIdx);
			else fromBFunc(fromBIdx);
		}
		if (found == false) break;
	}
}

int main() {
	int C;
	stringstream ss;
	cin >> C;
	string tmpS, tmpS2;
	for (int i=0; i<C; i++) {
		init();
		cin >> turnAroundT;
		cin >> nAtoB;
		cin >> nBtoA;
		for (int j=0; j<nAtoB; j++) {
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int departure = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			departure += stoi(tmpS2);
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int arrival = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			arrival += stoi(tmpS2);
			AtoB[j] = make_pair(arrival, departure);
		}
		for (int j=0; j<nBtoA; j++) {
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int departure = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			departure += stoi(tmpS2);
			cin >> tmpS;
			ss = stringstream(tmpS);
			getline(ss, tmpS2, ':');
			int arrival = stoi(tmpS2)*60;
			getline(ss, tmpS2, ':');
			arrival += stoi(tmpS2);
			BtoA[j] = make_pair(arrival, departure);
		}
		sort(AtoB, AtoB+nAtoB);
		sort(BtoA, BtoA+nBtoA);
		doUntilComplete();
		cout << "Case #" << i+1 << ": " << fromA << " " << fromB << endl;
	}
}
