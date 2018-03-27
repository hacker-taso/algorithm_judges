// Start at 00:09AM March 01, 2018
// End at 00:32AM March 01, 2018
#include <iostream>
#include<vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> seq(N);
    for (int i=0; i<N; i++)
        cin >> seq[i];
    int curMin = 0;
    int curMax = 0;
    int allMin = 0;
    int allMax = 0;
    for (int i=0; i<N; i++) {
        if (seq[i] == 0)  {
            curMax += 1;
            curMin += 1;
            curMin = min(curMin, 0);
        } else {
            curMax -= 1;
            curMin -= 1;
            curMax = max(curMax, 0);
        }
        allMin = min(curMin, allMin);
        allMax = max(curMax, allMax);
    }
    cout << allMax - allMin + 1 << endl;
    return 0;
}