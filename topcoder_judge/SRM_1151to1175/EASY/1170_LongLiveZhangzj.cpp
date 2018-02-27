// start from 10:24PM, Jan 23, 2018
// complete at 10:36PM, Jan 23, 2018
// I used "trie" to solve this problem and it doesn't take much time unexpectedly.
// Time complexity is O(numCharInSpeech + numCharInWords).
#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int ctoIdx(char c) {
    return c-'a';
}

struct Node {
    Node*nexts[26];
    bool terminal;
    Node(): terminal(false) {
        memset(nexts, 0, sizeof(nexts));
    };
    void insert(const char* key) {
        if (*key == 0) {
            terminal = true;
            return;
        }
        int idx = ctoIdx(*key);
        if (!nexts[idx])
            nexts[idx] = new Node();
        nexts[idx]->insert(key+1);
    }
    bool exist(const char *key) {
        if (*key == 0) {
            return terminal;
        }
        int idx = ctoIdx(*key);
        if (!nexts[idx])
            return false;
        return nexts[idx]->exist(key+1);
    }
};

class LongLiveZhangzj {
private:
    public:
    int donate(vector <string> speech, vector <string> words) {
        Node* root = new Node();
        for (int i=0; i<words.size(); i++) {
            root->insert(words[i].c_str());
        }
        int numSeconds = 0;
        for (int i=0; i<speech.size(); i++) {
            numSeconds += root->exist(speech[i].c_str());
        }
        return numSeconds;
    }
};
