#ifndef __SHOW__
#define __SHOW__

#include "Hall.hpp"
#include <cstring>

class Show : public Hall
{
	char* name;
	char* date;
public:
	// konstruktori, operator=, destruktor
	Show();
	Show(int _number_of_hall, const char* _name, const char* _date);
	Show(const Show& other);
	Show operator=(const Show& other);
	~Show();
	// geturi i seturi
	const char* get_shows_name() const;
	const char* get_shows_date() const;
	int get_shows_number_of_hall() const;

	void set_shows_name(char* _name);
	void set_shows_date(char* _date);
	void set_shows_number_of_hall(int _number_of_hall);

};

#endif
