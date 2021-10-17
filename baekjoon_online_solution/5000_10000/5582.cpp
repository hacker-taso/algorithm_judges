#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int toindex(char c) {
  return c-'A';
}

struct Trie {
  Trie* children[26];
  Trie() {
    memset(children, 0, sizeof(children));
  }
  ~Trie() {
      for (int i=0; i<26; i++)
          if (children[i]) delete(children[i]);
  }
  void insert(string& s, int i) {
    if (s.size() == i)
      return;
    int next = toindex(s[i]);
    if (!children[next])
      children[next] = new Trie();
    children[next]->insert(s, i+1);
  }
  int find(string& s, int i) {
    if (s.size() == i)
      return 0;
    int next = toindex(s[i]);
    if (children[next]) {
      return 1 + children[next]->find(s, i+1);
    }
    return 0;
  }
};
string s1, s2;

int solve() {
  Trie trie;
  for (int i=0; i<s1.size(); i++) {
    trie.insert(s1, i);
  }
  int ret = 0;
  for (int j=0; j<s2.size(); j++) {
    ret = max(ret, trie.find(s2, j));
  }
  return ret;
}

int main() {
  cin >> s1 >> s2;
  cout << solve() << endl;
}