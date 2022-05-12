#ifndef __Storage_of_halls__
#define __Storage_of_halls__

#include "Hall.hpp"
#include <vector>

class Storage_of_halls : protected Hall
{
protected:
	// vektor ot vsichki zali
	std::vector<Hall> storage_of_Halls;
public:

	// funkciq za dobavqne na zala vuv storage_of_halls
	void add_to_storage(const Hall& other);

	// funciq koqto mi printira vsichki zali do momenta 
	void print();

	void size_of_storage();
	int get_size_of_storage();

	Hall& operator[](int temp);

	friend std::ostream& operator<<(std::ostream& os, const Storage_of_halls& storage);
};

#endif // !__Storage_of_halls__

