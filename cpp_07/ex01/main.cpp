#include "iter.hpp"

int main(){
	int array[3] = {1, 2, 3};
	iter(array, 3, increment);

	std::cout << "\n";

	const int constarray[3] = {7, 8, 9};
	iter(constarray, 3, print);
}
