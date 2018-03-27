// check
#include <iostream>
#include<vector>
#include<map>
using namespace std;
vector<vector<int> > tree1;
vector<vector<int> > tree2;
map<pair<int,int>, bool> cache;
int root1;
int root2;

bool check(int node1, int node2) {
    if (0 < cache.count(make_pair(node1, node2))) cache[make_pair(node1, node2)];
    if (tree1[node1].empty() && tree2[node2].empty()) return true;
    if (tree1[node1].size() != tree2[node2].size()) return false;
    if (tree1[node1].size() == 1) {
        bool res = check(tree1[node1][0], tree2[node2][0]);
        cache[make_pair(node1, node2)] = res;
        return res;
    }
    if (tree1[node1].size() == 2) {
        bool res = ((check(tree1[node1][0], tree2[node2][0]) && 
            check(tree1[node1][1], tree2[node2][1])) ||
            (check(tree1[node1][0], tree2[node2][1]) && 
            check(tree1[node1][1], tree2[node2][0])));
        cache[make_pair(node1, node2)] = res;
        return res;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int T, N, tmp;
    cin >> T;
    for (int i=0; i<T; i++) {
        cin >> N;
        tree1 = vector<vector<int> >(N, vector<int>());
        tree2 = vector<vector<int> >(N, vector<int>());
        for (int j=0; j<N; j++) {
            cin >> tmp;
            if (tmp == 0) {
                root1 = j;
                continue;
            }
            tree1[tmp-1].push_back(j);
        }
        for (int j=0; j<N; j++) {
            cin >> tmp;
            if (tmp == 0) {
                root2 = j;
                continue;
            }
            tree2[tmp-1].push_back(j);
        }
        cout << check(root1, root2) << endl;
    }
    return 0;
}
