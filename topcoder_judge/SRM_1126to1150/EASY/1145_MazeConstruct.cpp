// Start at 10:00PM Feb 22, 2018
// End at 10:29PM Feb 22, 2018
// Retrospection:
// I omitted k-- in else case.(part about at most 3 rows)
#include<iostream>
#include<vector>
using namespace std;

class MazeConstruct {
private:
    public:
    vector <string> construct(int k) {
        k++;
        vector<string> sol;
        if (50<k) {
            sol.push_back(string(50, '.')); // 1 row.
            k -= 50;
        } else {
            sol.push_back(string(k, '.'));
            return sol;
        }
        while (0<k) {
            if (4<=k) {// first: at most 5 rows, afterwards: at most 4 rows. => more than 10 times.
                if (k%2 == 1) {
                    sol.push_back(string(49, '#') + string(1, '.'));
                    k--;
                }
                int moveHorizon = min(50, (k-2)/2);
                sol.push_back(string(49, '#') + string(1, '.'));
                sol.push_back(string(50-moveHorizon, '#') + string(moveHorizon, '.'));
                sol.push_back(string(50-moveHorizon, '#') + "." + string(moveHorizon-1, '#'));
                sol.push_back(string(50-moveHorizon, '#') + string(moveHorizon, '.'));
                k -= (moveHorizon*2 + 2);
            } else {//at most 3 rows
                for (int i=0; i<k; i++) {
                    sol.push_back(string(49, '#') + string(1, '.'));
                    k--;
                }
            }
        }
        return sol;
    }
};
