#include "Show.hpp"
#include <cstring>
bool Show::CheckShow(const char* _name)
{

	static int position = 0; // poziciq v masiva
	static int capacity = strlen(_name) + 2; // kapacitet na arr_of_ShowNames , "+1" zaradi razdelitelq -> /
	static char* arr_of_ShowNames = nullptr; // masiv s imenata na predstavleniqta

	// zadelqme pamet ako sme zapulnili masiva ili ako nqmame dostatuchno mqsto v masiva za novoto ime
	if (position == capacity || strlen(_name) >= (capacity - position))
	{
		char* temp_arr = new char[capacity * 2 + 1];
		strcpy(temp_arr, arr_of_ShowNames);
		delete[] arr_of_ShowNames;
		capacity *= 2;
		arr_of_ShowNames = new char[capacity + 1];
		strcpy(arr_of_ShowNames, temp_arr);
		delete[] temp_arr;
	}
	// ako predstavlenieto go ima v masiva ot predstavleniq, shte trqbva da dobavim samo datata
	if (strstr(arr_of_ShowNames, _name) != 0)
	{
		return true;
	}

	// ako predstavlenieto go nqma , go dobavq i slaga sled nego / za da gi otdelq
	strcat(arr_of_ShowNames, _name);
	strcat(arr_of_ShowNames, "/");
	position = strlen(arr_of_ShowNames);
	arr_of_ShowNames[position] = '\0';
	
	return false;
}

bool Show::CheckDate(const char* _date)
{
	// proverqvame dali sa neobhodim broi simvoli dd-mm-yyyy (8 -> ako ima den i mesec m-d 1-9 /
	//														  9 -> ako ima den i mesec m-d 1-9 /
	//														  10 -> ako nqma)
	if (strlen(_date) < 8 || strlen(_date) > 10)
		throw std::exception("Invalid date!");

	// proverqvame za sintaksisa
	for (size_t i = 0; i < strlen(_date); i++)
	{
		if (i < '0' || i > '9' || i != '-')
			throw std::exception("Invalide syntax! ");
	}

	// 0-11-1111 - greshka ne moje den = 0
	if (_date[0] == '0' && _date[1] == '-')
		throw std::exception("Invalid date!");

	// 00-11-1111 - greshka
	if (_date[0] == '0' && _date[1] == '0')
		throw std::exception("Invalid date!");

	// 32-11-1111 -> den > 31
	if (_date[0] == '3' && _date[1] > '1')
		throw std::exception("Invalid date!");

	// 42-11-1111 -> den > 31
	if (_date[0] > '3' && _date[1] != '-')
		throw std::exception("Invalid date!");
	
	// 1-0-1111 -> greshka
	if (_date[2] == '0' && _date[3] == '-')
		throw std::exception("Invalid date");

	// 1-00-1111 -> greshka
	if (_date[2] == '0' && _date[3] == '0')
		throw std::exception("Invalid date");

	// 11-0-1111 -> greshka
	if (_date[3] == '0' && _date[4] == '-')
		throw std::exception("Invalid date");

	// 11-00-1111 -> greshak
	if (_date[3] == '0' && _date[4] == '0')
		throw std::exception("Invalid date");

	// 11-13-1111 -> mesec max 12
	if (_date[3] == '1' && _date[4] > '2')
		throw std::exception("Invalid date!");

	// 11-20-1111
	if (_date[3] > '1' && _date[4] != '-')
		throw std::exception("Invalid date!");

	// 11-11--111 / 11-11-1-11 / 11-11-11-1 / 11-11-111- 
	if (_date[6] == '-' || _date[7] == '-' || _date[8] == '-' || _date[9] == '-')
		throw std::exception("Invalid date!");

	// 11-1-* ili 1-11-*, kudeto * e greshno vyvedena godina
	if (_date[4] == '-' && (_date[5] == '-' || _date[6] == '-' || _date[7] == '-' || _date[8] == '-'))
		throw std::exception("Invalid date!");

	// 1-1-* kudeto * e greshno vyvedena godina
	if (_date[3] == '-' && (_date[4] == '-' || _date[5] == '-' || _date[6] == '-' || _date[7] == '-'))
		throw std::exception("Invalid date!");
}

void Show::DateFormat(char* _date)
{
	// 1->9-11-1111 - dobavq nula otpred i stava 01-11-1111
	if (_date[1] == '-')
	{
		char* temp = new char[strlen(_date) + 1];
		strcpy(temp, _date);
		delete[] _date;
		_date = new char[strlen(temp) + 1];
		_date[0] = '0';
		for (size_t i = 1; i < strlen(temp); i++)
		{
			_date[i] = temp[i - 1];
		}
		_date[10] = '\0';
		delete[] temp;
	}

	// 11-1-1111 stava 11-01-1111
	if (_date[2] == '-' && _date[4] == '-')
	{
		char* temp = new char[strlen(_date) + 1];
		strcpy(temp, _date);
		delete[] _date;
		_date = new char[strlen(temp) + 1];
		for (size_t i = 0; i < strlen(temp) - 5; i++)
		{
			_date[i] = temp[i];
		}
		_date[3] = '0';
		for (size_t i = 4; i < strlen(temp); i++)
		{
			_date[i] = temp[i - 1];
		}
		_date[10] = '\0';
		delete[] temp;
	}
}

void Show::AddDate(const char* _date)
{
	// masiv ot dati na edno predstavlenie
	static int position = 0; // poziciq do koqto sme zapulnili masiva
	static int capacity = strlen(_date)+2; // kapacitet na masiva, +1 zaradi razdelitelq
	static char* arr_of_dates = nullptr; // masiv ot dati na edno predstavlenie
	
	// ako datata q ima veche v masiva hvurlq exception
	if (strstr(arr_of_dates, _date) != 0)
		throw std::exception("Already exist !");
	

	// ako sme zapulnili kapaciteta , uvelichavame dvoino
	if (position == capacity)
	{
		char* temp_arr = new char[capacity * 2 + 1];
		strcpy(temp_arr, arr_of_dates);
		delete[] arr_of_dates;
		capacity *= 2;
		arr_of_dates = new char[capacity + 1];
		strcpy(arr_of_dates, temp_arr);
		delete[] temp_arr;
	}

	strcat(arr_of_dates, _date);
	strcat(arr_of_dates, "/");
	position = strlen(arr_of_dates);
	arr_of_dates[position] = '\0';
}

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
	// ako CheckShow() vurne true-dobavqme samo datata 
	//				 false - dobavqme cqloto sybitie
	if (CheckShow(_name) == 0)
	{
		number_of_hall = _number_of_hall;
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
		// vikane na funckiq CheckDate(), ako vurne false exception
		date = new char[strlen(_date) + 1];
		strcpy(date, _date);
	}
	else
	{
		// CheckDate()	
		this->AddDate(_date);
	}
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

void Show::set_shows_name(const char* _name)
{
	delete name;
	name = new char[strlen(_name) + 1];
	strcpy(name, _name);
}

void Show::set_shows_date(const char* _date)
{
	delete date;
	date = new char[strlen(_date) + 1];
	strcpy(date, _date);
}

void Show::set_shows_number_of_hall(int _number_of_hall)
{
	number_of_hall = _number_of_hall;
}

void Show::AddShow()
{
	std::cout << "Please write number of hall, name and date in that order : ";
	//Show(int _number_of_hall, const char* _name, const char* _date);

}

void Show::print()
{
	std::cout << "Hall number : " << number_of_hall << std::endl;
	std::cout << "Name of the show : " << name << std::endl;
	std::cout << "Date of the show : " <<date << std::endl;
}

