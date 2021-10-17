class Solution {
public:
    vector<vector<int>> adjlist;
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        adjlist = vector<vector<int>>(n, vector<int>());
        for (int i=0; i<edges.size(); i++) {
            int src = edges[i][0];
            int dst = edges[i][1];
            adjlist[src].push_back(dst);
            adjlist[dst].push_back(src);
        }
        vector<int> dists(n, 0);
        queue<pair<int, int>> q;
        q.push({0, 0});
        while(!q.empty()) {
            auto [cur, d] = q.front();
            q.pop();
            if (dists[cur] != 0)
                continue;
            dists[cur] = d;
            for (auto next: adjlist[cur]) {
                q.push({next, d+1});
            }
        }
        int ret = 0;
        for (int i=1; i<n; i++) {
            int cur = dists[i]*2 / patience[i] * patience[i];
            if (cur == dists[i]*2)
                cur-=patience[i];
            cur += dists[i]*2 + 1;
            ret = max(ret, cur);
        }
        return ret;
    }
};