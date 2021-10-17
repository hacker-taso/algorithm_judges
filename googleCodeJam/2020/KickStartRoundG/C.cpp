    #include<iostream>
    #include<vector>
    #include<algorithm>
    using namespace std;
    int W, N;
    vector<long long int> nums;
    bool wallFound;

    int getWallLeft(int targetIdx, int wallIdx) {
        return (N+nums[wallIdx]-nums[targetIdx]) % N;
    }
    int getWallRight(int targetIdx, int wallIdx) {
        return (N+nums[targetIdx]-nums[wallIdx]) % N;
    }
    int getWallLeftCnt(int targetIdx, int wallIdx) { // wall포함안함.
        if (!wallFound)
            return N;
        return (W+wallIdx-targetIdx)%W;
    }
    int getWallRightCnt(int targetIdx, int wallIdx) { // wall포함
        if (!wallFound)
            return 0;
        return (W+targetIdx-wallIdx) % W;
    }

    long long int solve() {
        sort(nums.begin(), nums.end());
        int wallPos = -1;
        wallFound = false;
        long long int curTotalCnt = 0;
        int startIdx=1;
        for (int i=startIdx; i<W; i++) {
            int wallLeft = getWallLeft(0, i);
            int wallRight = getWallRight(0, i);
            if (wallRight <= wallLeft) {
                if (wallPos == -1) {
                    wallPos = i;
                    wallFound = true;
                }
                curTotalCnt += wallRight;
            } else {
                curTotalCnt += wallLeft;
            }
        }
        long long int ret = curTotalCnt;
        if (wallPos == -1) {
            curTotalCnt = 0;
            for (int i=++startIdx; i!=1; i=(i+1)%W) {
                int wallLeft = getWallLeft(1, i);
                int wallRight = getWallRight(1, i);
                if (wallRight <= wallLeft) {
                    if (wallPos == -1) {
                        wallPos = i;
                        wallFound = true;
                    }
                    curTotalCnt += wallRight;
                } else {
                    curTotalCnt += wallLeft;
                }
            }
            ret = min(ret, curTotalCnt);
        }
        for (int i=startIdx+1; i<W; i++) {
            int target = nums[i];
            int targetChange = nums[i] - nums[i-1];
            int wallLeft = getWallLeft(i, wallPos);
            int wallRight = getWallRight(i, wallPos);
            if (wallRight <= wallLeft || !wallFound) {
                curTotalCnt += getWallLeftCnt(i, wallPos) * targetChange;
                curTotalCnt -= getWallRightCnt(i, wallPos) * targetChange;
                ret = min(ret, curTotalCnt);
                continue;
            }

            int nextWallPos;
            wallFound = false;
            for (nextWallPos = wallPos+1; nextWallPos != wallPos; nextWallPos = (nextWallPos+1)%W) {
                int nextWallLeft = getWallLeft(i, nextWallPos);
                int nextWallRight = getWallRight(i, nextWallPos);
                if (nextWallRight <= nextWallLeft) {
                    wallFound = true;
                    break;
                }
            }
            for (int j=wallPos; j!=nextWallPos; j=(j+1)%W) {
                int prevWallRight = getWallRight(j, wallPos);
                int nextWallLeft = getWallLeft(j, nextWallPos);
                curTotalCnt -= prevWallRight;
                curTotalCnt += nextWallLeft;
            }
            int prevWallLeftCnt = getWallLeftCnt(i-1, wallPos);
            int nextWallRightCnt = getWallRightCnt(i, nextWallPos);
            curTotalCnt += prevWallLeftCnt * targetChange;
            curTotalCnt -= nextWallRightCnt * targetChange;
            ret = min(ret, curTotalCnt);
            wallPos = nextWallPos;
        }
        return ret;
    }

    int main() {
        ios_base::sync_with_stdio(false);
        int T;
        cin >> T;
        for (int i=0; i<T; i++) {
            cin >> W >> N;
            nums.resize(W);
            for (int j=0; j<W; j++)
                cin >> nums[j];
            cout << "Case #" << i+1 << ": " << solve() << endl;
        }
    }