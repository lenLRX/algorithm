#include "LCS.h"
#include <iostream>

int main(){
	string seq1 = "dzzzazbzzcz";
	string seq2 = "dxxxaxxxxbxxcxxxxx";
	cout << LCS(seq1, seq2) << endl;
	getchar();
	return 0;
}