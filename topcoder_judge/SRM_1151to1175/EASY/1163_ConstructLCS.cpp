// start from 10:49PM, Jan 21, 2018
// complete at 11:27PM, Jan 21, 2018
// it was not easy.
// explanation: 
// 1. Find the smallest among ab, bc, ca. (I'll assume it is ab.)
// 2. Make A and B by filling ab '1's.
// 3. Make C by filling ca '1's and add '1's to A until A's length become ca.
// 4. Then, LCS of B and C is ab and it is smaller than bc because ab is the smallest.
//  Fill B and C with 0s until LCS of B and C become bc.
// To remove duplicated code, I can use a function
//  solve(smallest, other1, other2, fromSmallest1, fromSmallest2, notFromSmallest)
// By the way, I found the algorithm by trying manually.
#include<iostream>
using namespace std;
class ConstructLCS {
private:
    public:
    string construct(int ab, int bc, int ca) {
        string A, B, C;
        if (ab <= bc && ab <= ca) {
            A = string(ca, '1');
            B = string(ab, '1');
            C = string(ca, '1');
            B += string(bc-ab, '0');
            C += string(bc-ab, '0');
        } else if (ca <= bc && ca<=ab) {
            C = string(bc, '1');
            A = string(ca, '1');
            B = string(bc, '1');
            A += string(ab-ca, '0');
            B += string(ab-ca, '0');
        } else if (bc <= ca && bc<=ab) {
            B = string(ab, '1');
            C = string(bc, '1');
            A = string(ab, '1');
            C += string(ca-bc, '0');
            A += string(ca-bc, '0');
        }
        return A + " " + B + " " + C;
    }
};
