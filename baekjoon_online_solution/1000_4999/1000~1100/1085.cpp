#include<iostream>
using namespace std;
int main(){
	int x,y,w,h;
	cin >> x >> y >> w >> h;
	int distances[4] = {x,y,w-x,h-y};
	int min = distances[0];
	for(int i=1;i<4;i++)
		if(distances[i] < min)
			min = distances[i];
	cout << min;
}
