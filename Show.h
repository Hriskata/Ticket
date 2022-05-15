#ifndef __SHOW__
#define __SHOW__

#include "Hall.h"
#include <string> // ИЗПОЛЗВАМ ЧУЖДА БИБЛИОТЕКА - string
#include <cstring> // ИЗПОЛЗВАМ ЧУЖДА БИБЛИОТЕКА - cstring

class Show : protected Hall
{	
	int rows;
	int columns;
	std::string date;
	std::string name_of_show;
	Hall hall;
	int** seats = nullptr;
	
public:
	// конструкто за подразбиране
	Show();
	// конструктор за създаване
	Show(std::string _date, std::string _name_of_show,const Hall& _hall);
	// копиращ конструкто
	Show(const Show& other);
	// деструктор
	~Show();

	// Селектори
	// Селектор за датата на представлението
	std::string Get_date() const;
	// Селектор за името на представлението
	std::string Get_name_of_show() const;
	// Селектор за името на залата от клас представление
	std::string Get_hall_name() const;
	// Селектор за редовете на залата от клас представление
	int Get_hall_row() const; 
	// Селектор за местата на ред на залата от клас представление
	int Get_hall_seat() const; 
	// Селектор залата от клас представление
	Hall Get_HALL() const;
	// Селектор за местата в залата от клас представление
	int Get_SEATS() const;
	// Селектор за свободните места в залата от клас представление като бройка
	int Get_Free_Seats() const;
	// Селектор за типа място по ред и място в залата от клас представление
	int Get_Seat_Type(int _row, int _column);

	// Функция, която ми променя типа на мястото (0 - свободно, 1 - купено, 2 - запазено), приема ред,място,парола,тип промяна на мястото 
	void Update_Seat(int _row, int _columns, std::string _pass, int _type_res);
};

#endif // !__SHOW__
