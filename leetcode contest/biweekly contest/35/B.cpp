#define MOD 1000000007
// 1. lazy propagation으로 requests의 각 구간에 1을 더함.
// 2. nums의 각 위치에 대해 sum을 알아냄. (requests에 대해)
// 3. 가장 큰 위치부터 순서대로, nums의 가장 큰 수부터 할당.
struct LazySumTree {
    vector<int> tree;
    vector<int> lazy;
    int n;
    LazySumTree(const vector<int>& arr) {
        n = arr.size();
        tree = vector<int>(4*n);
        lazy = vector<int>(4*n, 0);
        init(arr, 0, n-1, 1);
    }
    int init(const vector<int>& arr, int nl, int nr, int node) {
        if (nl == nr) return tree[node] = arr[nl];
        int mid = (nl+ nr)/2;
        return tree[node] = init(arr, nl, mid, node*2)
                        + init(arr, mid+1, nr, node*2+1);
    }
    void propagate(int nl, int nr, int node) {
        if (lazy[node] != 0) {
            if (nl != nr) {
                lazy[2*node] += lazy[node];
                lazy[2*node+1] += lazy[node];
            }
            tree[node] += lazy[node] * (nr-nl+1);
            lazy[node] = 0;
        }
    }
    int sum(int l, int r, int nl, int nr, int node) {
        if (r < nl || nr < l) return 0;
        propagate(nl, nr, node);
        if (l <= nl && nr <= r)
            return tree[node];
        int mid = (nl+nr)/2;
        int ls = sum(l, r, nl, mid, node*2);
        int rs = sum(l, r, mid+1, nr, node*2+1);
        return ls+rs;
    }
    int sum(int l, int r) {
        return sum(l, r, 0, n-1, 1);
    }
    int add(int l, int r, int val, int nl, int nr, int node) {
        propagate(nl, nr, node);
        if (r < nl || nr < l) return tree[node];
        if (l <= nl && nr <= r) {
            lazy[node] += val;
            propagate(nl, nr, node);
            return tree[node];
        }
        int mid = (nl+nr)/2;
        int ls = add(l, r, val, nl, mid, node*2);
        int rs = add(l, r, val, mid+1, nr, node*2+1);
        return tree[node] = ls+rs;
    }
    int add(int l, int r, int val) {
        return add(l, r, val, 0, n-1, 1);
    }
};
class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        vector<int> empty(nums.size(), 0);
        LazySumTree lst(empty);
        for (int i=0; i<requests.size(); i++)
            lst.add(requests[i][0], requests[i][1], 1);
        
        vector<pair<int, int>> reqCntPairs(nums.size());
        for (int i=0; i<reqCntPairs.size(); i++)
            reqCntPairs[i] = make_pair(lst.sum(i, i), i);
        
        sort(reqCntPairs.begin(), reqCntPairs.end(), greater<pair<int,int>>());
        sort(nums.begin(), nums.end(), greater<int>());
        
        int reqSum = 0;
        for (int i=0; i<nums.size(); i++) {
            int cnt = reqCntPairs[i].first;
            reqSum = ((long long int)cnt * nums[i] + reqSum)%MOD;
        }
        return reqSum;
    }
};


// lazySum안쓰고 각 위치를 포함하는 범위의 갯수를 구하는 방법:
// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation/discuss/854149/C%2B%2B-O(n-log-n)
// 범위의 시작부터 범위의 끝까지는 1이 더해지고, 그 이후에는 1이 빠지게함.