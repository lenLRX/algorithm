#include <map>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;



/*
int max(int a,int b){
	if (a > b)
		return a;
	else
		return b;
}
*/

int main(){
	int cash;
	int N;
	while (scanf("%d%d", &cash, &N) != EOF){
		if (0 == cash || 0 == N){
			cout << 0 << endl;
			continue;
		}

		vector<int> nums(N);
		vector<int> denominations(N);
		for (int i = 0; i < N; i++){
			cin >> nums[i];
			cin >> denominations[i];
		}
		int max = 0;
		int f[110005] = { 0 };
		//memset(f,0,sizeof(f));
		for (int i = 0; i < N; i++){
			int note_count[110005] = {0};
			//memset(note_count,0,sizeof(note_count));
			for (int j = 1; j <= cash; j++){
				if (j - denominations[i] >= 0
					&& 
					note_count[j - denominations[i]] < nums[i]
					&& 
					f[j] < f[j - denominations[i]] + denominations[i]){
					
					f[j] = f[j - denominations[i]] + denominations[i];

					note_count[j] = note_count[j - denominations[i]] + 1;

				}
				//else if(f[j -1] > f[j]){
				//	f[j] = f[j - 1];
				//}
			}
		}
		
		cout << f[cash] << endl;
	}
	return 0;
}
