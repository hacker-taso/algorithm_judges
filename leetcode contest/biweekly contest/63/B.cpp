class Solution {
public:
    bool winnerOfGame(string colors) {
        int cnts[2] = {0};
        int cnt = 0;
        for (int i=0; i<colors.size(); i++) {
            if (i == 0) {
                cnt++;
                continue;
            }
            if (colors[i] != colors[i-1]) {
                cnt = 1;
                continue;
            }
            cnt++;
            if (3<=cnt) {
                cnts[colors[i]-'A']++;
            }
        }
        return cnts[0] > cnts[1];
    }
};