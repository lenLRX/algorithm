#ifndef __QSORTIMPL__H__
#define __QSORTIMPL__H__
using namespace std;

void qsort(int* vec,int size);

class RealQsort{
public:
	static void qsort(int* vec, int begin, int end);
};

#endif