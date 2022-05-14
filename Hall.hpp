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
	// konstruktor po podrazbirane, konstruktor, destruktor
	Hall();
	Hall(std::string _name_of_hall, int _row_of_hall, int _seats_on_row);

	// geturi
	std::string Get_name_of_hall() const;
	int Get_row_of_hall() const;
	int Get_seats_on_row() const;

	void Set_name_of_hall(std::string _name);
	void Set_row_of_hall(int _row);
	void Set_seats_on_row(int _seats);
	// printira samata zala
	void PrintHall() const;

	// overload operator=
	//Hall& operator=(const Hall& other);
};

#endif // !__HALL__
