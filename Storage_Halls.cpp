#include "Storage_Halls.hpp"

void Storage_of_halls::add_to_storage(const Hall& other)
{
	storage_of_Halls.push_back(other);
}

void Storage_of_halls::print()
{
	
	for (size_t i = 0; i < storage_of_Halls.size(); i++)
	{
		std::cout << "ZALA : ";
		std::cout << i + 1<<std::endl; 
		std::cout << storage_of_Halls[i].get_number_of_hall()<<std::endl;
		std::cout << storage_of_Halls[i].get_arr_of_seats()<<std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void Storage_of_halls::size_of_storage()
{
	std::cout << storage_of_Halls.size()<<std::endl;
}

int Storage_of_halls::get_size_of_storage()
{
	return storage_of_Halls.size();
}

Hall& Storage_of_halls::operator[](int temp)
{
	if (temp > storage_of_Halls.size()) {
		std::cout << "Index out of bounds" << std::endl;
		throw std::exception("Invalid argument !");
	}

	return storage_of_Halls[temp];
}


std::ostream& operator<<(std::ostream& os, const Storage_of_halls& storage)
{
	os << storage;
	return os;
}
