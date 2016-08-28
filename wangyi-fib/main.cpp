#include <iostream>
using namespace std;

int main(){
	long long target;
	cin >> target;
	long long fib[2000];
	fib[0] = 0;
	fib[1] = 1;
	long long last = target - 0;
	long long dis = target - 1;

	long long i = 2;
	long long t1;
	long long t2;

	long long p;

	while (true){
		fib[i] = fib[i - 1] + fib[i - 2];
		
		if (fib[i] == target){
			cout << 0 << endl;
			break;
		}
		else if ((fib[i] - target) * (fib[i - 1] - target) < 0){
			t1 = fib[i] - target;
			t2 = fib[i - 1] - target;
			p = t1 * t2;
			if (abs(fib[i] - target) < abs(fib[i - 1] - target)){
				cout << abs(fib[i] - target) << endl;
			}
			else
				cout << abs(fib[i - 1] - target) << endl;
			break;
		}

		

		i++;
	}
	cout << -142177 * -142177 << endl;
	getchar();
	getchar();
	return 0;
}