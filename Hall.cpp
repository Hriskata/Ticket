#include "Hall.h"

Hall::Hall()
{
	name_of_hall = '\0';
	row_of_hall = 0;
	seats_on_row = 0;
}

Hall::Hall(std::string _name_of_hall, int _row_of_hall, int _seats_on_row)
{
	name_of_hall = _name_of_hall;
	row_of_hall = _row_of_hall;
	seats_on_row = _seats_on_row;
}

std::string Hall::Get_name_of_hall() const
{
	return name_of_hall;
}

int Hall::Get_row_of_hall() const
{
	return row_of_hall;
}

int Hall::Get_seats_on_row() const
{
	return seats_on_row;
}

void Hall::Set_name_of_hall(std::string _name)
{
	name_of_hall = _name;
}

void Hall::Set_row_of_hall(int _row)
{
	row_of_hall = _row;
}

void Hall::Set_seats_on_row(int _seats)
{
	seats_on_row = _seats;
}

void Hall::PrintHall() const
{
	std::cout << "Name on hall : " << name_of_hall << std::endl;
	std::cout << "Rows : " << row_of_hall << std::endl;
	std::cout << "Seats on row : " << seats_on_row << std::endl;
}

//Hall& Hall::operator=(const Hall& other)
//{
//	if (this != &other)
//	{
//		name_of_hall = other.name_of_hall;
//		row_of_hall = other.row_of_hall;
//		seats_on_row = other.seats_on_row;
//	}
//	return *this;
//}


