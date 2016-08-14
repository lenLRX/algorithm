#include "heap.h"

void main(){
	heap<int> test;
	int testdata[] = { 8,9,10,15,12,7,6,4,11,5,3,1};
	for (int i:testdata)
	    test.add(i);
	test.print();

	while (!test.empty()){
		std::cout << test.get() << "\t";
		test.pop_front();
	}
	std::cout << std::endl;
	getchar();
}