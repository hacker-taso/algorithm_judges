// I was so tired because I devoted myself to the first problem and I couldn't solve the problem.
// I saw the solution.
// small set: Let's make 20 20 ... 20.
//  1. We can make 20 U(1) with 20 seconds, 40 U(2) with 40 U(3), .., and 380 U(19) with 400 U(20)
//  2. Reversely, 1 U(100) -> 1 U(99), 1 U(98) -> 2 U(98), 1 U(97)
//      => we can make 2 U(n-2) with 1 U(n)
//  => To make 400 U(20) -> 200 U(22) -> 100 U(24) -> ... -> 1 U(31) (2^7 = 128)
//  We only need to check until 32
//  U(n) check time complexity: "n check"*"neededs material" = O(n*U)
//   => total time complexity: O(T*n^2*U) (n<=31, U<=20)
// large set:
//  - Impossible check:
//   From U(m), we can make U(m-Ax-By). And, we can make 2 U(m) from U(m+A+B)
//    (U(m+A+B)-> U(m+A) and U(m+B) -> "U(m) and U(m+A-B)" and "U(m) and U(m+B-A)"
//   => If all neededs materials are a U(m-Ax-By) form, we can make possible case.
//   => Given neededs materials U(a)s, if there exists m=Ax+By+a for all a, we can do.
//   => If for any a, m%gcd(A, B) != a%gcd(A, B), then impossible.
//      else we can make m because if a and a' is a=a' mod gcd(A,B)
//           then there exists x,y,x',y' such that a+Ax+By = a'+Ax'+By'.
//      It's because a = a'+gcd(A,B)*k, a+Ax+By=a+gcd(A,B)*l
//        => a+Ax+By = a+gcd(A,B)*l = a'+gcd(A,B)*k+gcd(A,B)*l = a'+(k+l)*gcd(A,B)
//                   = a'+Ax'+By' (with the proper k given l)
//  - possible case maximum n:
//   With A=20, we can make 2 U(a) from U(a+40) => we can make 2^x U(a) from U(a+40*x)
//   => We can make 32 U(a) from U(a+240)
//   It will be enough we have 20 U(20+240) if it's possible because making 20 U(20) wiil 
//   be most difficult and it takes U(20+240). => The upper limit is U(500).
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<pair<int,int>> neededs;
int N, A, B;
int G;

bool solvable(int n) {
    vector<int> gened(n+1, 0);
    int from = n;
    gened[from] = 1;
    for (int i=neededs.size()-1; 0<=i; i--) {
        auto [nId, nCnt] = neededs[i];
        if (from<nId)
            return false;
        for (int j=from; nId<j; j--) {
            if (1<=j-A) gened[j-A] += gened[j];
            if (1<=j-B) gened[j-B] += gened[j];
            gened[j] = 0;
        }
        if (gened[nId]<nCnt)
            return false;
        gened[nId] -= nCnt;
        from = nId;
    }
    return true;
}
int gcd(int p, int q) {
    if (q==0) return p;
    return gcd(q, p%q);
}

void solve() {
    G = gcd(A, B);
    int x = -1;
    for (auto needed: neededs) {
        if (x==-1)
            x = needed.first % G;
        else if (needed.first % G != x) {
            cout << "IMPOSSIBLE" <<endl;
            return;
        }
    }
    if (x==0)
        x = G;
    for (int i=x; i<=500; i+=G) {
        if (solvable(i)) {
            cout << i <<endl;
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, tmp;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N >> A >> B;
        neededs.clear();
        for (int j=0; j<N; j++) {
            cin >> tmp;
            if (0<tmp) {
                neededs.push_back({j+1, tmp});
            }
        }
        cout << "Case #" << (i+1) << ": ";
        solve();
    }
}
