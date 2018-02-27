// Comment long after writing this code:
// When I wrote this code, I didn't know that I shouldn't use sync_with_stdio between "cin"s.
// So, I changed my code a lot to find the reason of "wrong answer"
// and at last I changed code almost same with the code of JMBook.
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

bool wellMatched(const string& formula) {
	const string opening("({["), closing(")}]");
	stack<char> openStack;
	for (int i=0; i<formula.size(); ++i) {
		if (opening.find(formula[i]) != -1)
			openStack.push(formula[i]);
		else { // right
			if (openStack.empty()) return false;
			if (opening.find(openStack.top()) != closing.find(formula[i]))
				return false;
			openStack.pop();
		}
	}
	return openStack.empty();
}

int main() {
	int C;
	string prob;
	ios_base::sync_with_stdio(false);
	cin >> C;
	for (int i=0; i<C; i++) {
		cin >> prob;
		cout << (wellMatched(prob) ? "YES" : "NO") << endl;
	}
}
