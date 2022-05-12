#ifndef __SHOW__
#define __SHOW__

#include "Storage_Halls.hpp"
#include "Hall.hpp"
#include <string>
#include <vector>

class Show : protected Storage_of_halls
{
	std::string number_of_hall;
	std::string name;
	std::string date;

	
public:

	Show() = default;
	Show(std::string _date, std::string _name, std::string _number_of_hall,Storage_of_halls other);
	~Show();
	//geturi
	std::string get_Show_name();
	std::string get_Show_date();


	friend std::ostream& operator<<(std::ostream& os, const Show& show);
	bool operator==(const Hall_of_the_Show& robj);
};

#endif // !__SHOW__

