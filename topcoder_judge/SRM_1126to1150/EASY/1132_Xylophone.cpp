// Start at 06:10 PM Feb 15, 2018
// End at 06:18 PM Feb 15, 2018
#include<iostream>
#include<vector>
using namespace std;

class Xylophone {
private:
    public:
    int countKeys(vector <int> keys) {
        bool hits[7] = {0};
        for (int i=0; i<keys.size(); i++) {
            hits[keys[i]%7] = true;
        }
        int cnt=0;
        for (int i=0; i<7; i++)
            cnt += (int)hits[i];
        return cnt;
    }
};
