#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int nums;
	while (cin >> nums){
		auto cmp = [](const pair<int, int>& lhs, const pair<int, int>& rhs)->bool{
			if (lhs.first < rhs.first)
				return false;
			else if (lhs.first == rhs.first){
				if (lhs.second < rhs.second)
					return false;
				else
					return true;
			}
			else
				return true;
		};

		auto cmp2 = [](const pair<int, int>& lhs, const pair<int, int>& rhs)->bool{
			if (lhs.second < rhs.second)
				return false;
			else if (lhs.second == rhs.second){
				if (lhs.first < rhs.first)
					return false;
				else
					return true;
			}
			else
				return true;
		};

		priority_queue<pair<int, int>, vector<pair<int, int>>,decltype(cmp)> Q(cmp);
		for (int i = 0; i < nums; i++){
			int p, q;
			cin >> p >> q;
			Q.push(pair<int, int>(p, q));
		}
		
		double wait = 0;
		int time = 0;
		while (!Q.empty()){
			pair<int, int> _pair = Q.top();
			Q.pop();
			if (time <= _pair.first){
				//not waiting
				time = _pair.first + _pair.second;
			}
			else{
				//waiting
				wait += time - _pair.first;
				time = time + _pair.second;
			}
		}

		printf("%.4f\n", wait / nums);
	}
	return 0;
}