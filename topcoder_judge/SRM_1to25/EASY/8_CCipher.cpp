// start from 11:49PM, Jan 14, 2018
// complete at PM, Jan 14, 2018
#include<iostream>
using namespace std;
class CCipher {
    public:
    string decode(string cipherText, int shift) {
        string decoded;
        int len = cipherText.size();
        char chNum;
        for (int i=0; i<len; i++) {
            chNum = (cipherText[i] - 'A');
            chNum = (chNum+26-shift)%26;
            decoded += chNum+'A';
        }
        return decoded;
    }
};
