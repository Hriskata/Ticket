#ifndef __HALL__
#define __HALL__

#include <iostream>

// klas za zalite

class Hall {
	int number_of_hall=0; // parametur za nomer na zala
	int rows_of_hall=0; // parametur za kolko reda imam v zalata
	int columns_of_hall=0; // parametur za kolko mesta imam na red
	int** arr_of_seats=nullptr; // dvumeren masiv za mestata v zalata
public:
	// Konstruktori
	Hall();
	Hall(int _number_of_hall,int _rows_of_hall, int _columns_of_hall); // chetem ot fail // nz kak
	Hall(const Hall& other); 
	~Hall();
	// Geturi za nomer na zala i za mestata v zalata
	int get_number_of_hall();
	int get_arr_of_seats();
	// Funkciq za svobodni mesta
	int free_seats(); // vrushta masiv ot svobodni mesta

	void print();
};
#endif 

