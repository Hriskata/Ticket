#include "Hall.hpp"

Hall::Hall()
{
	number_of_hall = 0;
	rows_of_hall = 0;
	columns_of_hall = 0;
	arr_of_seats = nullptr;
}

Hall::Hall(int _number_of_hall, int _rows_of_hall, int _columns_of_hall)
{
	number_of_hall = _number_of_hall;
	rows_of_hall = _rows_of_hall;
	columns_of_hall = _columns_of_hall;
	arr_of_seats = new int* [rows_of_hall];
	for (int i = 0; i < rows_of_hall; i++)
	{
		arr_of_seats[i] = new int[columns_of_hall];
		for (int j = 0; j < columns_of_hall; j++)
		{
			arr_of_seats[i][j] = 0;
		}
	}
}

Hall::Hall(const Hall& other)
{
	if (this != &other) {
		number_of_hall = other.number_of_hall;

		this->~Hall();

		rows_of_hall = other.rows_of_hall;
		columns_of_hall = other.columns_of_hall;
		arr_of_seats = new int* [rows_of_hall];

		for (int i = 0; i < rows_of_hall; i++)
		{
			arr_of_seats[i] = new int[columns_of_hall];
			for (int j = 0; j < columns_of_hall; j++)
			{
				arr_of_seats[i][j] = other.arr_of_seats[i][j];
			}
		}
	}
}

Hall::~Hall()
{
	for (int i = 0; i < rows_of_hall; i++)
	{
		delete[] arr_of_seats[i];
	}
	delete[] arr_of_seats;

}

void Hall::print()
{
	std::cout << number_of_hall << std::endl;
	std::cout << rows_of_hall << std::endl;
	std::cout << columns_of_hall << std::endl;
}
