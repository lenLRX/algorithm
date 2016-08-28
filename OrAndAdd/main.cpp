#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	long long x, k;
	cin >> x >> k;

	vector<int> bits;
	vector<long long> facts(100);
	facts[0] = 1;
	for (int i = 1; i < 100; i++)
		facts[i] = facts[i - 1] * (i + 1);
	long long xx = x;
	for (int i = 0; i < sizeof(long long)* 8 - 1; i++){
		if ((xx & 1) == 0){
			bits.push_back(i);
		}
		xx = xx >> 1;
	}

	int sum = 0;

	vector<int> kbits;
	long long kk = k;
	for (int i = 0; i < sizeof(long long)* 8 - 1; i++){
		if (kk & 1){
			kbits.push_back(i);
		}
		kk = kk >> 1;
	}


	int p = 0;

	long long  y = 0;

	for (vector<int>::iterator it = kbits.begin(); it != kbits.end(); it++, p++){
		y += pow(2, bits[*it]);
	}
	cout << y << endl;

	return 0;
}