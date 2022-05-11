#ifndef __HALL__
#define __HALL__

#include <iostream>
#include <vector>

// klas za zalite


class Hall 
{
	int rows_of_hall=0; // parametur za kolko reda imam v zalata
	int columns_of_hall=0; // parametur za kolko mesta imam na red
	int** arr_of_seats=nullptr; // dvumeren masiv za mestata v zalata
	
protected:
	int number_of_hall = 0; // parametur za nomer na zala

	// funciq dali veche sushtestvuva takava zala
	bool NumberExist(int _number_of_hall);

public:
	// konstruktori, operator=, destruktor
	Hall();
	Hall(int _number_of_hall,int _rows_of_hall, int _columns_of_hall); // chetem ot fail // nz kak
	Hall(const Hall& other); 
	Hall operator=(const Hall& other);
	~Hall();

	// Geturi za nomer na zala i za mestata v zalata
	int get_number_of_hall() const;
	int get_arr_of_seats() const;

	// operator<< CHECKNI GO za masiva dali trqbva
	friend std::ostream& operator<<(std::ostream& os, const Hall& hall);

	// Funkciq za svobodni mesta
	int free_seats(); // vrushta masiv ot svobodni mesta

	// pokazva koq zala kakvi harakteristiki ima
	void print();

	int get_capacity() const;
	void add_number_in_arr_of_numbers(int _number_of_hall);
};
#endif 

