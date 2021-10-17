#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> arr;

int solve(int N, int K) {
    int cnt = 0;
    for (int i=0; i<N; i++) {
        if (arr[i] == K) {
            for (int j=1; j<K && i+j < N; j++) {
                if (arr[i+j-1]-1 != arr[i+j])
                    break;
                if (arr[i+j] == 1) {
                    cnt++;
                    break;
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    int T, N, K;
	cin >> T;
	for (int i=0; i<T; i++) {
	    cin >> N >> K;
	    arr = vector<int>(N);
	    for (int j=0; j<N; j++)
	        cin >> arr[j];
	    int sol = solve(N, K);
	    cout << "Case #" << i+1 << ": " << sol << endl;
	}
}