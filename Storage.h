#ifndef __STORAGE__
#define __STORAGE__

#include "Hall.h"
#include "Show.h"

#include <vector>

class Storage : protected Show
{
	std::vector<Hall> storage_of_HALLS;
	std::vector<Show*> storage_of_SHOWS;

public:
	Storage();
	// dobavqme vuv vektora nova zala
	void Add_To_Storage_Of_Halls(const Hall& temp);
	// izvejda ni razmera na vektora
	void Size_On_Storage_Of_Halls() const;
	// wrushta ni razmera
	int size_on_vector_of_halls() const;
	// dobavqne na novo predstavlenie
	void Add_New_Show(const Show& temp);
	// izvejda brojka svobodni mesta v zala za dadeno predstavlenie na dadena data 
	void Free_Seats(std::string _name, std::string _date);
	// pravi rezervaciq na bilet za predstavlenie po ime, data, red, mqsto, parola
	void Reservation(std::string _name, std::string _date, int _row, int _column, std::string _pass);
	// otkazvane na rezervaciq na bilet za predstavlenie po ime, data, red, mqsto, parola
	void Reservation_Cancel(std::string _name, std::string _date, int _row, int _column, std::string _pass);
	// kupuvane na bilet
	void Buy_Ticket(std::string _name, std::string _date, int _row, int _column);
	//void List_Of_Reservations()
	//void Information_For_Purchased_Tickets()

};

#endif // !__STORAGE__

