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

//TODO: rewrite by my self
void RealQsort::qsort(int* vec, int begin,int end){
	if (!vec)
		return;
	if (begin < end){
		int l = begin;
		int r = end;
		int pivot = vec[l];
		while (l < r){
			while (l < r && vec[r] >= pivot)
				r--;
			if (l < r)
			    swap(vec[r], vec[l]);
			while (l < r && vec[l] < pivot)
				l++;
			if (l < r)
			    swap(vec[r], vec[l]);
		}
		vec[l] = pivot;
		qsort(vec,begin,l - 1);
		qsort(vec, r + 1, end);
	}
}