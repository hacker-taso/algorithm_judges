#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, m;
vector<vector<int>> topicBlogs;
vector<int> topics;
vector<vector<int>> adjList;
vector<vector<int>> completedList;

void solve() {
	topicBlogs = vector<vector<int>>(n+1);
	for (int blog=1; blog<=n; blog++) {
		topicBlogs[topics[blog]].push_back(blog);
	}

	vector<int> order;
	for (int topic=1; topic<=n; topic++) {
		for (int i=0; i<topicBlogs[topic].size(); i++) {
			int blog = topicBlogs[topic][i];
			if (completedList[blog].size()+1 != topic) {
				cout << -1 << endl;
				return;
			}

			for (int j=0; j<adjList[blog].size(); j++) {
				completedList[adjList[blog][j]].push_back(blog);
			}
			order.push_back(blog);
		}
	}

	bool isFirst = true;
	for (int i=0; i<order.size(); i++) {
		if (isFirst) {
			cout << order[i];
			isFirst = false;
		} else {
			cout << " " << order[i];
		}
	}
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	int v1, v2;
	cin >> n >> m;
	topics = vector<int>(n+1);
	adjList = vector<vector<int>>(n+1);
	completedList = vector<vector<int>>(n+1);
	for (int i=0; i<m; i++) {
		cin >> v1 >> v2;
		adjList[v1].push_back(v2);
		adjList[v2].push_back(v1);
	}
	for (int i=1; i<=n; i++)
		cin >> topics[i];
	solve();
}
