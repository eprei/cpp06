#include "Data.hpp"
#include <iostream>
#include <stdint.h>

int main ( void )
{
	Data		data;
	Data*		data_ptr1 = &data;
	Data*		data_ptr2 = NULL;
	uintptr_t	uintptr;

	std::cout << std::endl << "**** initialisation of data and printing of values ****" << std::endl;
	data_ptr1->info = 4242;
	std::cout << "address stored in data_ptr1: " << data_ptr1 << std::endl;
	std::cout << "value stored in data_ptr->info: " << data_ptr1->info << std::endl << std::endl;

	std::cout << "**** serializing data_ptr1 to uintptr ****" << std::endl;
	uintptr = serialize(data_ptr1);
	std::cout << "address stored in uintptr: " << uintptr << std::endl << std::endl;

	std::cout << "**** deserializing uintptr to data_ptr2 ****" << std::endl;
	data_ptr2 = deserialize(uintptr);
	std::cout << "address stored in data_ptr2: " << data_ptr2 << std::endl;
	std::cout << "value stored in data_ptr2->info: " << data_ptr2->info << std::endl << std::endl;

	data.info = 2121;
	std::cout << "**** change of value stored in info to '2121' and printout of values ****" << std::endl;
	std::cout << "address stored in data_ptr1: " << data_ptr1 << std::endl;
	std::cout << "value stored in data_ptr->info: " << data_ptr1->info << std::endl << std::endl;
	std::cout << "address stored in data_ptr2: " << data_ptr2 << std::endl;
	std::cout << "value stored in data_ptr2->info: " << data_ptr2->info << std::endl << std::endl;

	return 0;
}
