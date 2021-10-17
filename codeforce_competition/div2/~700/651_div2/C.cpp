#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

const string FIRST_PLAYER="Ashishgup";
const string SECOND_PLAYER="FastestFinger";

#define MAX_ROOT 333333334
bool isWin[166666668];
void initIsWin() {
    memset(isWin, false, sizeof(isWin));
    isWin[1] = true;
    for (int i=2; i<=MAX_ROOT/3; i+=2) { // 짝수들.
        if (isWin[i/2] == false) { // i에서 지는 경우,
            for (int j=3; i*j<MAX_ROOT; j+=2) {
                isWin[i*j/2] = true;
            }
        }
    }
}

string solve(int n) {
    if (n==1)
        return SECOND_PLAYER;
    if (n==2)
        return FIRST_PLAYER;
    if (n%2 == 1) // odd인 경우.
        return FIRST_PLAYER;
    // when n=even number.
    // The player should find an odd divisor which can make the number even with isWin[the even] == false.
    int rootN = (int)(sqrt(n) + 1);
    for (int oddDiv=3; oddDiv<=rootN; oddDiv+=2) {
        if (n%oddDiv != 0) // div가 아닌 경우.
            continue;
        int next = n/oddDiv;
        if(isWin[next/2] == false)
            return FIRST_PLAYER;
    }
    return SECOND_PLAYER;
}

int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    int n;
    initIsWin();
    for (int i=0; i<t; i++) {
        cin >> n;
        cout << solve(n) << endl;
    }
}
