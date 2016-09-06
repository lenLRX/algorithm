#include <limits>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
	int maxProfit(vector<int>& a) {
		int sell1 = 0;
		int sell2 = 0;
		int hold1 = INT_MIN;
		int hold2 = INT_MIN;

		for (int i : a){
			sell2 = max(sell2, hold2 + i);
			hold2 = max(hold2, sell1 - i);
			sell1 = max(sell1, hold1 + i);
			hold1 = max(hold1, -i);
		}

		return sell2;
	}
};