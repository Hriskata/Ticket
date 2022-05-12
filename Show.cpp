#include "Show.hpp"

Show::Show(std::string _date, std::string _name, std::string _number_of_hall, Storage_of_halls _storage)
{
	std::cout << "_storage.size_of_storage : ";
	_storage.size_of_storage();
	std::cout << std::endl;
	for (size_t i = 0; i < _storage.get_size_of_storage(); i++)
	{
		std::cout << "_storage[i].get_number_of_hall : ";
		std::cout << _storage[i].get_number_of_hall();
		std::cout << std::endl;
		std::cout << " _number of hall : " << _number_of_hall << std::endl;
		if (_number_of_hall == _storage[i].get_number_of_hall())
		{
			
			std::cout << "hello uspeshno vlizane v proverka edno" << std::endl;
			std::cout <<"HALL_INFO SIZE :" << Hall_info.size() << std::endl;

			for (size_t j = 0; j < Hall_info.size(); j++)
			{
				if (_date == Hall_info[j].data)
				{
					throw std::exception("Already exist show on this date in this hall !");
				}
			}
			number_of_hall = _number_of_hall;
			name = _name;
			date = _date;
			
			Hall_of_the_Show h;
			h.data = _date;
			h.ShowsName = _name;
			int temp_rows = _storage[i].get_rows_of_hall();
			int temp_columns = _storage[i].get_columns_of_hall();
			h.copy_arr_of_seats = new int* [temp_rows];
			for (size_t k = 0; k < temp_rows; k++) 
			{
				*h.copy_arr_of_seats = new int[temp_columns];
			}
			Hall_info.push_back(h);
			std::cout << "HALL_INFO SIZE krai:" << Hall_info.size() << std::endl;
			break;
		}
	}
	
}

Show::~Show()
{
	
}

std::string Show::get_Show_name()
{
	return name;
}

std::string Show::get_Show_date()
{
	return date;
}

std::ostream& operator<<(std::ostream& os, const Show& show)
{
	os << show;
	return os;
}
