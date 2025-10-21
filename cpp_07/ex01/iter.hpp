#ifndef ITER_TPP
#define ITER_TPP

#include <iostream>

template <typename T>

void increment(T &x){
	x +=1;
	std::cout << x;
}

template <typename T>

void print(const T& x){
	std::cout << x;
}

template <typename T>

void iter(T *array, const int length, void(*f)(T &)){
	for (int i = 0; i < length; i++){
		f(array[i]);
		std::cout << " ";
	}
}

template <typename T>

void iter(const T *array, const int length, void(*f)(const T &)){
	for (int i = 0; i < length; i++){
		f(array[i]);
		std::cout << " ";
	}
}

#endif
