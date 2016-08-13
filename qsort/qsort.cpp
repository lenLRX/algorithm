#include "qsortimpl.h"
#include <iostream>

void main(){
	int test[] = {1,5,45,2,345,74,3,12,54,2,4};
	qsort(test, 11);
	for (int i = 0; i < 11; i++)
		cout << test[i] << "\t";
	getchar();
}