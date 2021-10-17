#include<iostream>
#include<algorithm>
using namespace std;


string solve(unsigned long long k) {
    string codeforces = "codeforces";
    unsigned long long cnts[10] = {0};
    for (int i=0; i<10; i++)
        cnts[i] = 1;
    while (true) {
        unsigned long long mul = 1;
        for (int i=0; i<10; i++)
            mul *= cnts[i];
        if (k<=mul)
            break;
        int minI = 0;
        for (int i=1; i<10; i++)
            if (cnts[i] < cnts[minI]) {
                minI = i;
            }
        cnts[minI]+=1;
    }

    string ret = "";
    for (int i=0; i<10; i++)
        ret += string(cnts[i], codeforces[i]);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    unsigned long long k;
    cin >> k;
    cout << solve(k) << endl;
}
