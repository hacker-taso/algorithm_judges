// Start from 6:27PM Feb 4, 2018.
// End at 6:34PM Feb 4, 2018.
#include<iostream>
using namespace std;

class TriangleMaking {
private:
    public:
    int maxPerimeter(int a, int b, int c) {
        int l1, l2, l3;
        l1 = min(a,min(b,c));
        l3 = max(a,max(b,c));
        l2 = a+b+c - l1 - l3;
        if (l3<l1+l2)
            return l1+l2+l3;
        l3 = l1+l2-1;
        return l1+l2+l3;
    }
};
