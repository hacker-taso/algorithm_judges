#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


void solve(int n) {
    // 만드는 방법이 있음
    vector<pair<int,int>> allAxis;
    vector<pair<int,int>> midAxis; // x, y;
    vector<pair<int,int>> aboveAxis;
    vector<pair<int,int>> belowAxis;
    for (int i=0; i<n; i++) {
        midAxis.push_back(make_pair(i*2, 0));
        aboveAxis.push_back(make_pair(i*2, 1));
        belowAxis.push_back(make_pair(i*2, -1));
    }

    for (int i=0; i<n; i++) {
        allAxis.push_back(aboveAxis[i]);
        allAxis.push_back(midAxis[i]);
        allAxis.push_back(belowAxis[i]);
    }
    for (int i=0; i<n-1; i++) {
        allAxis.push_back(make_pair(midAxis[i].first+1, 0));
    }

    pair<int, int> leftAxis = make_pair(midAxis[0].first-1, 0);
    allAxis.push_back(leftAxis);
    pair<int, int> rightAxis = make_pair(midAxis[midAxis.size()-1].first+1, 0);
    allAxis.push_back(rightAxis);

    // 위는 기본 세팅. 아래는 추가작업.
    // left and first above (5개)
    int leftX = leftAxis.first;
    int leftY = leftAxis.second;
    allAxis.push_back(make_pair(leftX-1, leftY));
    allAxis.push_back(make_pair(leftX-1, leftY+1));
    allAxis.push_back(make_pair(leftX-1, leftY+2));
    allAxis.push_back(make_pair(leftX, leftY+2));
    allAxis.push_back(make_pair(leftX+1, leftY+2));

    int rightX = rightAxis.first;
    int rightY = rightAxis.second;
    // if n is even
    if (n%2 == 0) {
        // right and last above (5개)
        allAxis.push_back(make_pair(rightX+1, rightY));
        allAxis.push_back(make_pair(rightX+1, rightY+1));
        allAxis.push_back(make_pair(rightX+1, rightY+2));
        allAxis.push_back(make_pair(rightX, rightY+2));
        allAxis.push_back(make_pair(rightX-1, rightY+2));
        // above ((n-2)/2개 * 3개)
        for (int i=1; i<n-1; i+=2) {
            int lX = aboveAxis[i].first;
            int y = aboveAxis[i].second + 1;
            allAxis.push_back(make_pair(lX, y));
            allAxis.push_back(make_pair(lX+1, y));
            allAxis.push_back(make_pair(lX+2, y));
        }
        // below (n/2개 * 3개)
        for (int i=0; i<n-1; i+=2) {
            int lX = belowAxis[i].first;
            int y = belowAxis[i].second - 1;
            allAxis.push_back(make_pair(lX, y));
            allAxis.push_back(make_pair(lX+1, y));
            allAxis.push_back(make_pair(lX+2, y));
        }
    }

    // ---------------------------------
    // if n is odd
    if (n%2 == 1) {
        // right and last below (5개)
        allAxis.push_back(make_pair(rightX+1, rightY));
        allAxis.push_back(make_pair(rightX+1, rightY-1));
        allAxis.push_back(make_pair(rightX+1, rightY-2));
        allAxis.push_back(make_pair(rightX, rightY-2));
        allAxis.push_back(make_pair(rightX-1, rightY-2));
        // above ((n-1)/2개 * 3개)
        for (int i=1; i<n; i+=2) {
            int lX = aboveAxis[i].first;
            int y = aboveAxis[i].second + 1;
            allAxis.push_back(make_pair(lX, y));
            allAxis.push_back(make_pair(lX+1, y));
            allAxis.push_back(make_pair(lX+2, y));
        }
        // below ((n-1)/2개 * 3개)
        for (int i=0; i<n-1; i+=2) {
            int lX = belowAxis[i].first;
            int y = belowAxis[i].second - 1;
            allAxis.push_back(make_pair(lX, y));
            allAxis.push_back(make_pair(lX+1, y));
            allAxis.push_back(make_pair(lX+2, y));
        }

    }
    cout << allAxis.size() << endl;
    for (int i=0; i<allAxis.size(); i++) {
        cout << allAxis[i].first << " " << allAxis[i].second << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    solve(n);
}
