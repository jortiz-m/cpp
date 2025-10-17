#ifndef ITER_TPP
#define ITER_TPP

#include <iostream>

template <typename T>

void increment(T &x){
	x +=1;
}

template <typename T>

void iter(T *array, const int length, void(*f)(T &)){
	for (int i = 0; i < length; i++){
		f(array[i]);
		std::cout << array[i] << " ";
	}
}

#endif
