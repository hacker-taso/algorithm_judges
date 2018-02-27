// Start at 00:35AM Feb 22, 2018
// End at 00:44AM Feb 22, 2018
#include <iostream>

using namespace std;
const int holes[] = {1,0,0,0,0,0,1,0,2,1};
int main() {
    int a, b;
    cin >> a >> b;
    int maxHole=-1, maxNum = -1;
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                int curNum = i*100+j*10 +k;
                int curHole = holes[i]+holes[j]+holes[k];
                if (curNum<a || b<curNum) continue;
                if (maxHole<curHole) {
                    maxHole = curHole;
                    maxNum = curNum;
                }
            }
        }
    }
    if (b==1000 && maxHole < holes[1]+holes[0]*3) {
        maxNum = 1000;
    }
    cout << maxNum <<endl;
    return 0;
}