#include<iostream>
using namespace std;
/*
	 time complexity for number of files N, length of files M : O(N*M)
*/
int main(){
	int N;
	cin >> N;

	string* files = new string[N];
	for(int i=0; i<N; i++){
		cin >> files[i];
	}

	int len = files[0].length();
	char common;
	string pattern = "";
	for(int x=0; x<len; x++){
		common = files[0][x];
		int y=1;

		for(; y<N; y++){
			if(common == files[y][x])
				continue;
			else
				break;
		}

		if (y==N)
			pattern += common;
		else
			pattern += '?';
	}

	cout << pattern << endl;
}

