#include <iostream>
#include "Serializer.hpp"

int main(void)
{
	Data data;
	data.name = "Burger42";
	data.value = 1337;

	std::cout << "Original Data:" << std::endl;
	std::cout << "       name: " << data.name << std::endl;
	std::cout << "       value: " << data.value << std::endl;
	std::cout << "       address: " << &data << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	Data* ptr = Serializer::deserialize(raw);

	std::cout << "\nAfter process:" << std::endl;
	std::cout << "  address: " << ptr << std::endl;

	if (ptr == &data)
		std::cout << "\n✅ Pointers are equal — Serialization works correctly!" << std::endl;
	else
		std::cout << "\n❌ Pointers are different — Something is wrong." << std::endl;

	return 0;
}
