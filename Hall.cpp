#include "Hall.hpp"

Hall::Hall()
{
	number_of_hall = '\0';
	rows_of_hall = 0;
	columns_of_hall = 0;
	arr_of_seats = nullptr;
}

Hall::Hall(std::string _number_of_hall, int _rows, int _columns)
{
	number_of_hall = _number_of_hall;
	rows_of_hall = _rows;
	columns_of_hall = _columns;

	arr_of_seats = new int*[rows_of_hall];
	for (size_t i = 0; i < rows_of_hall; i++) {
		arr_of_seats[i] = new int[columns_of_hall];
		for (size_t j = 0; j < columns_of_hall; j++)
		{
			arr_of_seats[i][j] = 0;
		}
	}
	
}

//Hall::~Hall()
//{
//	for (size_t i = 0; i < rows_of_hall; ++i) 
//	{
//		delete[] arr_of_seats[i];
//	}
//	delete[] arr_of_seats;
//}

std::string Hall::get_number_of_hall() const
{
	//std::cout<<number_of_hall<<std::endl;
	return number_of_hall;
}

int Hall::get_arr_of_seats() const
{
	std::cout << "SEATS : "<<std::endl;
	for (int i = 0; i < rows_of_hall; i++)
	{
		for (int j = 0; j < columns_of_hall; j++)
		{
			std::cout << arr_of_seats[i][j] << " | ";
		}
		std::cout << std::endl;
	}
	return 0;
}

int Hall::get_rows_of_hall() const
{
	return rows_of_hall;
}

int Hall::get_columns_of_hall() const
{
	return columns_of_hall;
}

void Hall::print_hall_info()
{
	for (size_t i = 0; i < Hall_info.size(); i++)
	{
		std::cout << Hall_info[i].data << std::endl;
		std::cout << Hall_info[i].ShowsName << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Hall& hall)
{
	os << hall.number_of_hall << hall.rows_of_hall << hall.columns_of_hall;
	return os;
}


