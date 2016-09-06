#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		if (nums.size() == 1)
			return 1;
		if (nums.size() == 0)
			return 0;
		sort(nums.begin(), nums.end());
		unique(nums.begin(), nums.end());
		int length = 1;
		int max = length;
		int sizem1 = nums.size() - 1;
		for (int i = 0; i < sizem1; i++){
			if (nums[i + 1] - nums[i] == 1){
				length++;
				if (max < length)
					max = length;
			}
			else
				length = 1;
		}

		return max;
	}
};

int main(){
	Solution solution;
	vector<int> testdata = { 100, 4, 200, 1, 3, 2 };
	cout << solution.longestConsecutive(testdata) << endl;
	return 0;
}