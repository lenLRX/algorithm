#include <vector>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int half = n / 2;
		for (int i = 0; i < half; i++){
			for (int j = i; j < n - i - 1; j++){
				int temp = matrix[n - 1 - j][i];
				matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];
				matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];
				matrix[j][n - 1 - i] = matrix[i][j];
				matrix[i][j] = temp;
			}
		}
	}
};

int main(){
	Solution solution;
	vector<vector<int>> mat = { { 1, 2 }, { 3, 4 } };
	solution.rotate(mat);
	return 0;
}