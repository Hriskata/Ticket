#include "Show.h"


Show::Show() : Hall()
{
	date = '\0';
	name_of_show = '\0';
	rows = 0;
	columns = 0;
	seats = nullptr;
	
}

Show::Show(std::string _date, std::string _name_of_show, const Hall& _hall) : hall(hall)
{
	date = _date;
	name_of_show = _name_of_show;
	rows = hall.Get_row_of_hall();
	columns = hall.Get_seats_on_row();
	seats = new int*[rows];
	for (size_t i = 0; i < rows; i++) 
	{
		seats[i] = new int[columns];
		for (size_t j = 0; j < columns; j++)
		{
			seats[i][j] = 0;
		}
	}
}

Show::~Show()
{
	int rows = hall.Get_row_of_hall();
	for (int i = 0; i < rows; i++)
	{
		delete seats[i];
	}
	delete[] seats;
}


std::string Show::Get_date() const
{
	return date;
}

std::string Show::Get_name_of_show() const
{
	return name_of_show;
}

std::string Show::Get_hall_name() const
{
	return Get_name_of_hall();
}

int Show::Get_hall_row() const
{
	return Get_row_of_hall();
}

int Show::Get_hall_seat() const
{
	return Get_seats_on_row();
}

int Show::Get_Free_Seats() const
{
	int counter = 0;
	for (int i = 0; i < hall.Get_row_of_hall(); i++)
	{
		for (int j = 0; j < hall.Get_seats_on_row(); j++)
		{
			if (seats[i][j] == 0)
				counter++;
		}
	}
	return counter;
}

void Show::Update_Seat(int _row, int _columns, std::string _pass, int _type_res)
{
	std::string pass = _pass;
	int type_res = _type_res;
	seats[_row][_columns] = type_res; // 0 - svobodno , 1 - zaeto , 2 - rezervirano
}

int Show::Get_Seat_Type(int _row, int _column)
{
	return seats[_row][_column];
}

