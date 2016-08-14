#ifndef __HEAP_H__
#define __HEAP_H__
#define _SCL_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>

template<typename T>
class heap{
public:
	heap():capacity(10),size(0){
		data = new T[capacity];
	}

	void add(T& obj){
		if (size == capacity)
			IncreaseCapacity();
		int index = size;
		data[index] = obj;
		size++;
		while (data[index] < data[(index - 1) / 2]){
			std::swap(data[index] , data[(index - 1) / 2]);
			index = (index - 1) / 2;
		}
	}

	bool empty(){
		return !size;
	}

	void pop_front(){
		if (!size)
			return;
		int index = 0;
		while (index * 2 < size){
			int left = index * 2 + 1 < size ? index * 2 + 1 : 0;
			int right = index * 2 + 2 < size ? index * 2 + 2 : 0;

			if (left && right){
				if (data[left] < data[right]){
					data[index] = data[left];
					index = left;
				}
				else{
					data[index] = data[right];
					index = right;
				}
			}
			else if (left){
				data[index] = data[left];
				index = left;
			}
			else{
				break;
			}
		}
		size--;
	}

	T& get() {
		if (size)
			return data[0];
		else
			throw std::exception("empty heap");
	}

	void print(){
		for (int i = 0; i < size; i++){
			std::cout << data[i] << "\t";
		}
		std::cout << std::endl;
	}

	~heap(){
		delete[] data;
	}
private:
	int capacity;
	int size;
	T* data;

	void IncreaseCapacity(){
		int tmpCpacity = 2 * capacity;
		T* tmpdata = new T[tmpCpacity];
		std::copy(data,data + capacity, tmpdata);
		capacity = tmpCpacity;
		delete[] data;
		data = tmpdata;
	}
};

#endif