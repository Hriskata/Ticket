#ifndef __HALL__
#define __HALL__

#include <iostream>

class Hall
{
protected:
	std::string name_of_hall;
	int row_of_hall;
	int seats_on_row;

public:
	// конструктори
	Hall();
	Hall(std::string _name_of_hall, int _row_of_hall, int _seats_on_row);

	// Селектори
	// Селектор за името на залата от клас зала
	std::string Get_name_of_hall() const;
	// Селектор за ред на залата от клас зала
	int Get_row_of_hall() const;
	// Селектор за местата на ред от клас зала
	int Get_seats_on_row() const;

	// Мутатори
	// Мутатор за името на залата от клас зала
	void Set_name_of_hall(std::string _name);
	// Мутатор за реда на залата от клас зала
	void Set_row_of_hall(int _row);
	// Мутатор за местата на ред от клас зала
	void Set_seats_on_row(int _seats);

	// Принтира информация за залата от клас зала
	void PrintHall() const;
};

#endif // !__HALL__
