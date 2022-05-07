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

Hall Hall::operator=(const Hall& other)
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
	return *this;
}

Hall::~Hall()
{
	for (int i = 0; i < rows_of_hall; i++)
	{
		delete[] arr_of_seats[i];
	}
	delete[] arr_of_seats;
	arr_of_seats = nullptr;
}

int Hall::get_number_of_hall() const
{
	return number_of_hall;
}

int Hall::get_arr_of_seats() const
{
	for (int i = 0; i < rows_of_hall; i++)
	{
		for (int j = 0; j < columns_of_hall; j++)
		{
			std::cout << arr_of_seats[i][j] << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << "Zala nomer : ";
	return get_number_of_hall();
}

int Hall::free_seats()
{
	std::cout << "Free seats : " << std::endl;
	// svobodni mesta kato nomera
	for (int i = 0; i < rows_of_hall; i++)
	{
		for (int j = 0; j < columns_of_hall; j++)
		{
			if (arr_of_seats[i][j] == 0)
			{
				std::cout << "Row : " << i + 1 << " Seat : " << j + 1 << std::endl;
			}
		}
		std::cout << std::endl;
	}

	// svobodni mesta kato karta
	// F - free , T - already taken
	std::cout << "F - free | T - already taken | R - reserved"<<std::endl;
	for (int i = 0; i < rows_of_hall; i++)
	{
		std::cout << "ROW : " << i + 1 << " | ";
		for (int j = 0; j < columns_of_hall; j++)
		{
			if (arr_of_seats[i][j] == 0)
			{
				std::cout << " F " << " | "; // F - free seat
			}
			if (arr_of_seats[i][j] == 1)
			{
				std::cout << " T " << " | "; // T - already taken
			}
		}
		std::cout << std::endl;
	}
	return 0;
}

void Hall::print()
{
	std::cout << number_of_hall << std::endl;
	std::cout << rows_of_hall << std::endl;
	std::cout << columns_of_hall << std::endl;
}
