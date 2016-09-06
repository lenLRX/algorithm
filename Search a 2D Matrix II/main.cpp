#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int rowub, rowlb, colub, collb;
		rowub = n;
		rowlb = 0;
		colub = matrix[0].size();
		collb = 0;
		while (true){

			int b = true;
			if (colub - collb >= 4){
				int t = matrix[rowlb][(colub + collb) / 2];
				if (t > target){
					colub = (colub + collb) / 2 + 1;
					b = false;
				}

				//else
				//	collb = (colub + collb) / 2 - 1 ;

			}


			if (rowub - rowlb >= 4){
				int t = matrix[(rowlb + rowub) / 2][collb];
				if (t > target){
					rowub = (rowlb + rowub) / 2 + 1;
					b = false;
				}

				//else
				//	rowlb = (rowlb + rowub) / 2 - 1;

			}

			if (b)
				break;

			if (rowub - rowlb < 4 && colub - collb < 4)
				break;
		}


		for (int i = rowub - 1; i >= 0; i--){
			for (int j = colub - 1; j >= 0; j--){
				if (matrix[i][j] == target)
					return true;
				if (j >= 1 && matrix[i][j - 1] < target){
					j = -1;
				}
			}
		}

		return false;

	}
};

int main(){
	Solution solution;
	vector<vector<int>> mat = { { 1, 4, 7, 11, 15 }, 
	                            { 2, 5, 8, 12, 19 }, 
								{ 3, 6, 9, 16, 22 }, 
								{10, 13, 14, 17, 24}, 
								{ 18, 21, 23, 26, 30 }};
	bool ret = solution.searchMatrix(mat,13);
	return 0;
}