#include "qsortimpl.h"
#include <algorithm>

void _qsort(int* p, int begin, int end);

void qsort(int* vec, int size){
	_qsort(vec,0,size - 1);
}

void _qsort(int* p, int begin, int end){
	if (begin == end)
		return;
	int pivotpos = begin;
	int pBegin = begin;
	int pEnd = end;

	for (int i = begin + 1; i <= end; i++){
		if (p[i] < p[pivotpos]){
			swap(p[pivotpos + 1], p[i]);
			swap(p[pivotpos], p[pivotpos + 1]);
			pivotpos++;
		}
	}

	_qsort(p, begin, pivotpos);
	if (pivotpos != end)
		_qsort(p, pivotpos + 1, end);

}