#include <iostream>
using namespace std;

int main(){
	long x_0;
	cin >> x_0;

	long base = 1000000007l;

	long big = 1000000007l;

	if (big < x_0)
		big = (x_0 / big + 1) * big;
	long t;
	long r;
	long a;
	long b;
	int count = 0;
	do{
		count++;
		r = big % x_0;

		t = big / x_0;
		big += base;

		b = -3 * t / 4 + r;
		a = t - r - b;
	} while (t - r < 0 || t % 4 || a < 0 || b < 0);



	std::cout << (t - r) <<" a " << a <<" b " << b << endl;
	getchar();
	system("pause");
	return 0;
}