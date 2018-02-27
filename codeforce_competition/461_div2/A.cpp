#include<iostream>
using namespace std;

int goalCopy, goalOrig;

bool solve() {
    if (goalOrig<=0) return false;
    int initCopy = goalOrig-1;
    if (initCopy == 0 && 0<goalCopy) return false;
    return initCopy<=goalCopy && (goalCopy-initCopy)%2 == 0;
}

int main() {
    cin >> goalCopy >> goalOrig;
    if (solve()) {
    	cout << "Yes"<<endl;
    } else {
    	cout << "No"<<endl;
    }
}
