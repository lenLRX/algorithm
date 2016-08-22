#include "kmp.h"
int main(){
	string text = "abcdeabcdgfg";
	string pattern = "abcdg";
	cout << kmp(text,pattern) << endl;
	getchar();
	return 0;
}