#include "kmp.h"

int kmp(string text, string pattern){
	size_t n = text.size();
	size_t m = pattern.size();
	vector<int> next = BuildNext(pattern);

	size_t q = 0;
	for (size_t i = 0; i < n; i++){
		while (q > 0 && pattern[q] != text[i]){
			q = next[q - 1];
		}
		if (pattern[q] == text[i]){
			q++;
		}
		if (q == m)
			return i - m + 1;
	}
}

vector<int> BuildNext(string pattern){
	size_t len = pattern.size();
	if (len == 0){
		return vector<int>();
	}
	else if (len == 1){
		return vector<int>(1);
	}
	vector<int> next(len,0);
	next[0] = 0;
	int k = 0;
	for (size_t i = 1; i < len; i++){
		while (k > 0 && pattern[k] != pattern[i])
			k = next[k - 1];
		if (pattern[k] == pattern[i])
			k++;
		next[i] = k;
	}
	return next;
}