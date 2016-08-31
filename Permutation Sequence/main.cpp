//leetcode 60. Permutation Sequence
#include <vector>
#include <set>
#include <string>
using namespace std;

class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 0)
			return "";
		if (n == 1)
			return "1";
		string ret(n, '1');
		vector<int> fact(n);
		vector<char> chars;
		fact[0] = 1;
		for (int i = 0; i < n; i++){
			chars.push_back('1' + i);
		}
		for (int i = 1; i < n; i++){
			fact[i] = fact[i - 1] * (i + 1);
		}

		int temp = k - 1;
		int pos = 0;
		while (pos <= n - 2){
			ret[pos] = chars[temp / fact[n - pos - 2]];
			chars.erase(chars.begin() + temp / fact[n - pos - 2]);
			temp = temp - temp / fact[n - pos - 2] * fact[n - pos - 2];
			pos++;
		}
		ret[n - 1] = chars[0];
		return ret;
	}
};

int main(){
	return 0;
}