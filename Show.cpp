#include "Show.hpp"
#include <cstring>
Show::Show()
{
	number_of_hall = 0;
	name = new char [1];
	name = nullptr;
	date = new char[1];
	date = nullptr;
}

Show::Show(int _number_of_hall, const char* _name, const char* _date)
{
	number_of_hall = _number_of_hall;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
	date = new char[strlen(_date) + 1];
	strcpy(date, _date);

}

Show::Show(const Show& other)
{
	if (this != &other)
	{
		number_of_hall = other.number_of_hall;
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		date = new char[strlen(other.date) + 1];
		strcpy(date, other.date);
	}
}

Show Show::operator=(const Show& other)
{
	if (this != &other)
	{
		number_of_hall = other.number_of_hall;
		this->~Show();
		name = new char[strlen(other.name) + 1];
		strcpy(name, other.name);
		date = new char[strlen(other.date) + 1];
		strcpy(date, other.date);
	}
	return *this;
}

Show::~Show()
{
	delete name;
	name = nullptr;
	delete date;
	date = nullptr;
}

const char* Show::get_shows_name() const
{
	return name;
}

const char* Show::get_shows_date() const
{
	return date;
}

int Show::get_shows_number_of_hall() const
{
	return number_of_hall;
}

void Show::set_shows_name(char* _name)
{
	delete[] name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

void Show::set_shows_date(char* _date)
{
	delete date;
	date = new char[strlen(_date) + 1];
	strcpy(date, _date);
}
void Show::set_shows_number_of_hall(int _number_of_hall)
{
	number_of_hall = _number_of_hall;
}

