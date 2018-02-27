// Start at 08:20PM Feb 17, 2018
// End at 08:44PM Feb 17, 2018
#include<iostream>
#include<vector>
#include<set>
using namespace std;

struct DisjointSet {
	int root[26];
	DisjointSet() {
		for(int i=0; i<26; i++)
			root[i] = i;
	};
	void merge(int n1, int n2) {
		int r1 = find(n1);
		int r2 = find(n2);
		root[r1] = r2;
	}
	int find(int n) {
		if (root[n]==n) return n;
		int r = find(root[n]);
		root[n] = r;
		return r;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	string s1, s2;
	cin >> s1 >> s2;
	set<int> used;
	DisjointSet ds;
	for (int i=0; i<n; i++) {
		used.insert(s1[i]-'a');
		used.insert(s2[i]-'a');
		ds.merge(s1[i]-'a', s2[i]-'a');
	}
	vector<pair<char, char> > pairs;
	for (int num: used) {
		if (ds.find(num) != num) {
			pairs.push_back(make_pair((char)(num+'a'), (char)(ds.find(num)+'a')));
		}
	}
	cout << pairs.size() <<endl;
	for (int i=0; i<pairs.size(); i++)
		cout << pairs[i].first << " " << pairs[i].second <<endl;
}
