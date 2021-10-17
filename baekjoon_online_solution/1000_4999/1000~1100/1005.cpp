#include<iostream>
#include<vector>
using namespace std;
/*
	f(W) = the time required to build W
	f(W) = max(for any X that X->W exists, f(X)) + D(W)
	the number of comparison: O(Width^Depth) (considering the graph as tree shape with W as root)
	the number of comparison: O(K+N) (if memoizing used)
*/

int buildingTimes[1001];

int f(int W, vector<int>* YX, int* D){

	// if already knows the result of f(W)
	if (0 <= buildingTimes[W]) {
		return buildingTimes[W];
	}

	// if there's no need to wait for other buildings to be built.
	vector<int> Xs = YX[W];
	if(Xs.size() == 0) {
		buildingTimes[W] = D[W];
		return D[W];
	}

	int max = 0;
	int XsSize = Xs.size();
	for(vector<int>::size_type i=0; i<XsSize; i++){
		int buildingTime = f(Xs[i], YX, D);
		if (max < buildingTime) {
			max = buildingTime;
		}
	}
	buildingTimes[W] = max + D[W];
	return max + D[W];
}

void init(){
	for(int i=0;i<1001;i++){
		buildingTimes[i] = -1;
	}
}

int main(){

	int T, N, K;
	cin >> T;
	for (int t=0; t<T; t++){
		init();

		cin >> N >> K;

		int* D = new int[N+1];
		for(int n=1; n<=N; n++){
			cin >> D[n];
		}

		vector<int>* YX = new vector<int>[N+1];
		int x, y;
		for(int k=0; k<K; k++){
			cin >> x >> y;
			YX[y].push_back(x);
		}

		int W;
		cin >> W;
		cout << f(W, YX, D) << endl;

		delete[] D;
		delete[] YX;
	}
}
