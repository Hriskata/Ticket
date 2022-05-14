#ifndef __SHOW__
#define __SHOW__

#include "Hall.h"
#include <string>
#include <cstring>

class Show : protected Hall
{	
	int rows;
	int columns;
	std::string date;
	std::string name_of_show;
	Hall hall;
	int** seats = nullptr;
	
public:
	Show();
	Show(std::string _date, std::string _name_of_show,const Hall& _hall);
	~Show();
	//geturi za promenlivite na show 
	std::string Get_date() const;
	std::string Get_name_of_show() const;

	// geturi koito mi dostupvat neshtata na hall
	std::string Get_hall_name() const; // vrushta mi imato na hall ot show
	int Get_hall_row() const; // vrushta mi redovete na hall ot show 
	int Get_hall_seat() const; // vrushta mi mestata na redovete na hall ot show

	int Get_Free_Seats() const;

	void Update_Seat(int _row,int _columns, std::string _pass, int _type_res);
	int Get_Seat_Type(int _row, int _column);

};

#endif // !__SHOW__
