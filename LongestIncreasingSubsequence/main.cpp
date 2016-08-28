#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dp(vector<int> seq){
	int max = 0;
	int maxpos = -1;
	int size = seq.size();
	vector<int> rec(size, 1);
	vector<int> from(size, -1);
	for (int i = 0; i < size; i++){
		for (int j = 0; j < i; j++){
			if (seq[i] > seq[j] && rec[j] + 1 > rec[i]){
				rec[i] = rec[j] + 1;
				from[i] = j;
				if (rec[i] > max){
					maxpos = i;
					max = rec[i];
				}

			}
		}
	}

	vector<int> ret;

	int curr = maxpos;

	while (curr >= 0){
		ret.push_back(seq[curr]);
		curr = from[curr];
	}
	reverse(ret.begin(),ret.end());
	return ret;
}

int main(){
	int sets;
	cin >> sets;
	for (int i = 0; i < sets; i++){
		int nums;
		cin >> nums;
		vector<int> raw(nums);
		for (int j = 0; j < nums; j++){
			cin >> raw[j];
		}
		vector<int> result = dp(raw);
		for (int j = 0; j < result.size() - 1; j++){
			cout << result[j] << " ";
		}
		cout << result[result.size() - 1] << endl;
	}
	return 0;
}