#include<iostream>
#include<iomanip>
using namespace std;
/*
	X is the least number that for some natural number Y, N - N % 100 + X = F * Y (X < 100, F <= 100)

	Prop: For some Y, (N - N % 100) + X = F * Y, then for some Y2, (((N - N % 100) / 100) % F) * 100 + X = F * Y2
	substitue "N - N % 100" with  "Z * 100"
	=> Prop': For some Y, Z * 100 + X = F * Y, then for some Y2, ((Z * 100 / 100) % F) * 100 + X = (Z % F) * 100 + X = F * Y2
	premise: Z * 100 + X = F * Y
	=> ((Z - Z % F) + Z % F) * 100 + X = F * Y
	=> (F*Y' + Z % F) * 100 + X = F * Y		(because Z - Z % F = F * Y'. (because Z = F*Y' + Z%F ))
	=> (((F*Y' + Z % F) * 100) + X ) % F = F*Y % F
	=> (((F*Y' + Z % F) * 100) % F + X % F) % F = 0		(because (A + B) % C = (A % C + B % C) % C )
	=> ((F*Y'* 100 + (Z % F) * 100) % F + X % F) % F = 0
	=> (((F*Y' * 100 % F + (Z % F * 100)) % F) % F + (X % F) % F) % F = 0
	((((Z % F) * 100) % F) % F + (X % F) % F) % F = 0
	(((Z % F) * 100) % F + X % F ) % F=  0
	(((Z%F)*100) + X) % F = 0
	(Z % F) * 100  + X = F * Y2   => conclusion
	
	from the prop, (((N - N % 100) / 100) % F) * 100 + X = F * Y2 => ((((N- N%100)/100) % F) * 100 + X) % F = 0
*/

int main(){
	int N, F;
	cin >> N >> F;
	int remain100 = ((N/100) % F) * 100;
	int X = 0;
	for (; X<100; X++) {
		if ((remain100 + X) % F ==	0) {
			break;
		}
	}
	cout << setfill('0') << setw(2) << X << endl;;
}

