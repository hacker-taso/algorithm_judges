class Solution {
public:
    // prim
    int minCostConnectPoints(vector<vector<int>>& points) {
        int ret = 0, V = points.size();
        vector<bool> added(V, false);
        vector<int>minWeight(V, numeric_limits<int>::max());
        minWeight[0] = 0;
        for(int i=0; i<V; i++) {
            int u = -1;
            for (int v=0; v<V; v++)
                if (!added[v] && (u==-1 || minWeight[v] < minWeight[u]))
                    u = v;
            ret += minWeight[]u;
            added[u] = true;
            int x = points[u][0], y = points[u][1];
            for (int v=0; v<V; v++) {
                if (added[v])
                    continue;
                int x2 = points[v][0], y2 = points[v][1];
                int xW = x2 < x ? x-x2 : x2-x;
                int yW = y2 < y ? y-y2 : y2-y;
                int weight = xW+yW;
                if (weight < minWeight[v]) {
                    minWeight[v] = weight;
                }
            }
        }
        return ret;
    }
};