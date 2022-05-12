#ifndef __HALL__
#define __HALL__

#include <iostream>
#include <string>
#include <vector>

class Hall 
{
	int rows_of_hall; // redove v zalata
	int columns_of_hall; // mesta na red v zalata
	int** arr_of_seats; // dvumeren masiv na zalata

protected:
	std::string number_of_hall; // nomerut ili imeto na zalata
	struct Hall_of_the_Show
	{
		std::string data;
		std::string ShowsName;
		int** copy_arr_of_seats = nullptr;
	};
	// problemut e che mi se suzdava vektor za vsqko show kakto beshe v nachaloto sus zalite
	// sledovatelno ako go napravq klas koito mi e storage
	std::vector<Hall_of_the_Show> Hall_info;
	
public:
	// konstrukori  i destruktor
	Hall();
	Hall(std::string _number_of_hall, int rows, int columns);
	//~Hall();

	//geturi
	std::string get_number_of_hall() const;
	int get_arr_of_seats() const;
	int get_rows_of_hall() const;
	int get_columns_of_hall() const;

	friend std::ostream& operator<<(std::ostream& os, const Hall& hall);

	void print_hall_info();
	
};

#endif // !__HALL__

