#ifndef __STORAGE__
#define __STORAGE__

#include "Show.h"

#include <vector> // ИЗПОЛЗВАМ ЧУЖДА БИБЛИОТЕКА - vector
#include <fstream> // ИЗПОЛЗВАМ ЧУЖДА БИБЛИОТЕКА - fstream

class Storage : protected Show
{
	std::vector<Hall> storage_of_HALLS;
	std::vector<Show*> storage_of_SHOWS;

public:
	Storage();

	// Функция, която ми записва местата във файл 
	void Save_Seats_To_File(std::ostream& _file, const Show& _show);

	// Добавя към вектора със зали
	void Add_To_Storage_Of_Halls(const Hall& temp);

	// Извежда ни размера на вектора от зали
	void Size_On_Storage_Of_Halls() const;

	// ОПЕРАЦИЯ - Добавяне на представление
	void Add_New_Show(const Show& temp);

	// ОПЕРАЦИЯ - Свободни места по име и дата
	void Free_Seats(std::string _name, std::string _date);

	// ОПЕРАЦИЯ - Прави резервация по име, дата, ред, място, парола
	void Reservation(std::string _name, std::string _date, int _row, int _column, std::string _pass);

	// ОПЕРАЦИЯ - Отказване на резервация по име, дата, ред, място, парола
	void Reservation_Cancel(std::string _name, std::string _date, int _row, int _column, std::string _pass);

	// ОПЕРАЦИЯ - Купуване на билет
	void Buy_Ticket(std::string _name, std::string _date, int _row, int _column);

	// ОПЕРАЦИЯ - Списък с резервации
	void List_Of_Reservations(std::string _name, std::string _date);

	// ОПЕРАЦИЯ - Справка за закупени билет по въведен период за дадена зала
	//void Information_For_Purchased_Tickets()

	// Запалва чудото - подкарва програмата
	void RunTicket();

};

#endif // !__STORAGE__

