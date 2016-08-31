#include <set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {

		return insert(n);
	}

	vector<string> insert(int n){
		vector<string> ret;
		if (n == 1){
			ret.push_back("()");
			return ret;
		}
		set<string> strs;
		vector<string> prev = insert(n - 1);
		for (int i = 0; i < prev.size(); i++){
			
			for (int j = 0; j <= prev[i].size(); j++){
				string p = prev[i];
				strs.insert(p.insert(j, "()"));
			}
		}

		for (set<string>::iterator it = strs.begin(); it != strs.end(); it++){
			ret.push_back(*it);
		}
		return ret;
	}
};

int main(){
	Solution solution;
	auto ret = solution.generateParenthesis(3);
	return 0;
}