#include <bitset>
#include <vector>
using namespace std;

class Solution {
public:
	int maxProduct(vector<string>& words) {
		vector<bitset<26>> bits;
		int size = words.size();
		for (int i = 0; i < size; i++){
			bitset<26> b;
			for (int j = 0; j < words[i].size(); j++){
				b[words[i][j] - 'a'] = 1;
			}
			bits.push_back(b);
		}
		int max = 0;
		for (int i = 0; i < size; i++){
			for (int j = 0; j < size && i != j; j++){
				bitset<26> t = bits[i];
				t &= bits[j];
				if (t.count() == 0){
					int product = words[i].size() * words[j].size();
					if (product > max)
						max = product;
				}
			}
		}
		return max;
	}
};