#include "LCS.h"

int LCS(string seq1, string seq2){
	size_t size1 = seq1.size();
	size_t size2 = seq2.size();
	if (0 == size1 || 0 == size2)
		return 0;
	vector<int> c(size1 * size2, 0);
	if (seq1[0] == seq2[0]){
		for (size_t i = 0; i < size1; i++)
			c[i * size2] = 1;
		for (size_t j = 0; j < size2; j++)
			c[j] = 1;
	}
	for (size_t i = 1; i < size1; i++){
		for (size_t j = 1; j < size2; j++){
			if (seq1[i] == seq2[j]){
				c[i * size2 + j] = c[(i - 1) * size2 + j - 1] + 1;
			}
			else if (c[(i - 1) * size2 + j] > c[i * size2 + j - 1]){
				c[i * size2 + j] = c[(i - 1) * size2 + j];
			}
			else{
				c[i * size2 + j] = c[i * size2 + j - 1];
			}
		}//for i
	}//for j
	return c[size1 * size2 - 1];
}