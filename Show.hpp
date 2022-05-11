#ifndef __SHOW__
#define __SHOW__

#include "Hall.hpp"
#include <cstring>

class Show : public Hall
{
	char* name;
	char* date;

	bool CheckShow(const char* _name); // ++
	// funkciq koqto shte mi proverqva dali datata e validna
	bool CheckDate(const char* _date);
	// prepravq datata na format dd-mm-yyyy ako ne e
	void DateFormat(char* _date);
	// dobavq data kum masiva s dati na edno predstavlenie
	void AddDate(const char* _date); // ++
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

	void set_shows_name(const char* _name);
	void set_shows_date(const char* _date);
	void set_shows_number_of_hall(int _number_of_hall);

	// funkciq za dobavqne na predstavlenie, koito se suhranqvat vuv vektor
	void AddShow();

	// print funkciq
	void print();

};

#endif
