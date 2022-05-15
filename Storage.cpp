#include "Storage.h"

Storage::Storage()
{
	storage_of_HALLS = {};
	storage_of_SHOWS = {};
}

void Storage::Save_Seats_To_File(std::ostream& _file, const Show& _show)
{
	_file << _show.Get_SEATS();
}

void Storage::Add_To_Storage_Of_Halls(const Hall& temp)
{
	storage_of_HALLS.push_back(temp);
}

void Storage::Size_On_Storage_Of_Halls() const
{
	std::cout << storage_of_HALLS.size()<<std::endl;
}

void Storage::Add_New_Show(const Show& temp)
{
	for (size_t i = 0; i < storage_of_HALLS.size(); i++)
	{
		if (temp.Get_hall_name() == storage_of_HALLS[i].Get_name_of_hall())
			throw std::exception("Invalid name of hall !");
	}

	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if (temp.Get_date() == storage_of_SHOWS[i]->Get_date() && temp.Get_hall_name() == storage_of_SHOWS[i]->Get_hall_name())
		{
			throw std::exception("Тhere are already event on that date in this hall");
		}
	}
	
	Hall temp_hall(temp.Get_hall_name(), temp.Get_hall_row(), temp.Get_hall_seat());
	Show* temp_show = new Show(temp.Get_date(), temp.Get_name_of_show(), temp_hall);
	storage_of_SHOWS.push_back(temp_show);

}

void Storage::Free_Seats(std::string _name, std::string _date)
{
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()))
		{
			std::cout << "Free seats for show with name : " << _name << " are ";
			std::cout << storage_of_SHOWS[i]->Get_Free_Seats() << "." << std::endl;
			std::cout << storage_of_SHOWS[i]->Get_SEATS() << std::endl;
		}
	}
}

void Storage::Reservation(std::string _name, std::string _date, int _row, int _column, std::string _pass)
{
	std::string pass;
	std::string answer;
	std::string note;
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()))
		{
			storage_of_SHOWS[i]->Update_Seat(_row, _column, _pass, 2);
			std::cout << "Your ticket resetvation is successfully ! " << std::endl;
		}
	}
	std::cout << "Iskate li da dobavite belejka ? Y - yes / N - no" << std::endl;
	std::cin >> answer;
	if (answer == "Y")
	{
		std::cout << "Molq vuvedete belejka. " << std::endl;
		std::cin >> note;
	}
}

void Storage::Reservation_Cancel(std::string _name, std::string _date, int _row, int _column, std::string _pass)
{
	std::string pass;
	std::string ClearPass;
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()) && (storage_of_SHOWS[i]->Get_Seat_Type(_row, _column) == 2))
		{
			storage_of_SHOWS[i]->Update_Seat(_row, _column, ClearPass, 0);
			std::cout << "Ticket reservation was successfully canceled ! " << std::endl;
		}
	}
}

void Storage::Buy_Ticket(std::string _name, std::string _date, int _row, int _column)
{
	std::string ClearPass;
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()))
		{
			if (storage_of_SHOWS[i]->Get_Seat_Type(_row, _column) != 1) // toest ne e kupeno
			{
				if (storage_of_SHOWS[i]->Get_Seat_Type(_row, _column) == 0)
				{
					storage_of_SHOWS[i]->Update_Seat(_row, _column, ClearPass, 1);
				}
				else
				{
					//pitai za tupata parola
				}
			}
			else 
			{
				std::cout << "Already sold" << std::endl;
			}
		}
	}
}

void Storage::List_Of_Reservations(std::string _name, std::string _date)
{
	std::string str;
	std::string str1 = "report-";
	std::string str2 = _name;
	std::string str3 = _date;
	std::string str4 = ".txt";

	str.append(str1);
	str.append(str2);
	str.append(str3);
	str.append(str4);

	std::fstream file;
	file.open(str, std::ios::out);

	if (file.is_open())
	{
		if (_name == "ALL")
		{
			for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
			{
				if (_date == storage_of_SHOWS[i]->Get_date())
				{
					file << "Show : " << storage_of_SHOWS[i]->Get_name_of_show() << " on date : " << _date << "\n";
					std::cout << storage_of_SHOWS[i]->Get_SEATS() << std::endl;
				}
			}
		}

		if (_date == "ALL")
		{
			for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
			{
				if (_name == storage_of_SHOWS[i]->Get_name_of_show())
				{
					file << "Show : " << _name << " on date : " << storage_of_SHOWS[i]->Get_date() << "\n";
					std::cout << storage_of_SHOWS[i]->Get_SEATS() << std::endl;
				}
			}
		}

		if (_name != "ALL" && _date != "ALL")
		{
			for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
			{
				if (_name == storage_of_SHOWS[i]->Get_name_of_show() && _date == storage_of_SHOWS[i]->Get_date())
				{
					file << "Show : " << _name << " on date : " << _date << "\n";
					std::cout << storage_of_SHOWS[i]->Get_SEATS() << std::endl;
				}
			}
		}
		file.close();
	}
	else throw std::exception("Тhe file cannot be opened !");
}

void Storage::RunTicket()
{
	std::string command;
	std::cout << "Welcome!" << std::endl;
	do
	{

		std::cout << "Possible commans : " << std::endl;
		std::cout << "Add_New_Show, Free_Seats, Reservation, Reservation_Cancel, Buy_Ticket, List_Of_Reservations, Information_For_Purchased_Tickets" << std::endl;
		std::cout << "Please enter a command." << std::endl;
		std::cin >> command;

		if (command == "Add_New_Show")
		{
			std::cout << "Please enter a date (dd-mm-yyyy) : ";
			std::string currDate;
			std::cin >> currDate;
			std::cout << "Please enter a name of the show : ";
			std::string currName;
			std::cin >> currName;
			std::cout << "Please enter a name of the hall : ";
			std::string currHall;
			std::cin >> currHall;
			for (size_t i = 0; i < storage_of_HALLS.size(); i++)
			{
				if (currHall == storage_of_HALLS[i].Get_name_of_hall())
				{
					Show currShow(currDate, currName, storage_of_HALLS[i]);
					std::fstream file_show;
					std::string file_name = currName + "_" + currDate + "_" + currHall + ".txt";
					// създавам файл за представлението
					file_show.open(file_name, std::ios::out);
					if (file_show.is_open())
					{
						file_show << currName << '\n' << currDate << '\n' << currHall << '\n' << currShow.Get_SEATS();
						file_show.close();
					}
					else throw std::exception("The file cannot be opened !");
					// добавям го във файла с другите  
					std::fstream file_storage;
					file_storage.open("Storage.txt", std::ios::app);
					if (file_storage.is_open())
					{
						file_storage << file_name << '\n';
						file_storage.close();
					}
					else throw std::exception("The file cannot be opened !");

					Add_New_Show(currShow);

					std::cout << "You successfully saved the show ! " << std::endl;
				}
			}
			std::cout << storage_of_SHOWS.size();
		}
		else {

			if (command == "Free_Seats")
			{
				std::cout << "Please enter a date (dd-mm-yyyy) : ";
				std::string currDate;
				std::cin >> currDate;
				std::cout << "Please enter a name of the show : ";
				std::string currName;
				std::cin >> currName;
				Free_Seats(currDate, currName);
			}
			else
			{

				if (command == "Reservation")
				{
					std::cout << "Please enter a date (dd-mm-yyyy) : ";
					std::string currDate;
					std::cin >> currDate;
					std::cout << "Please enter a name of the show : ";
					std::string currName;
					std::cin >> currName;
					std::cout << "Please enter a row in the hall : ";
					int currRow;
					std::cin >> currRow;
					std::cout << "Please enter a seat in the row : ";
					int currColumn;
					std::cin >> currColumn;
					std::cout << "Please enter a password : ";
					std::string currPass;
					std::cin >> currPass;
					Reservation(currName, currDate, currRow, currColumn, currPass);
				}
				else {

					if (command == "Reservation_Cancel")
					{
						std::cout << "Please enter a date (dd-mm-yyyy) : ";
						std::string currDate;
						std::cin >> currDate;
						std::cout << "Please enter a name of the show : ";
						std::string currName;
						std::cin >> currName;
						std::cout << "Please enter a row in the hall : ";
						int currRow;
						std::cin >> currRow;
						std::cout << "Please enter a seat in the row : ";
						int currColumn;
						std::cin >> currColumn;
						std::cout << "Please enter a password : ";
						std::string currPass;
						std::cin >> currPass;
						Reservation_Cancel(currName, currDate, currRow, currColumn, currPass);
					}
					else {

						if (command == "Buy_Ticket")
						{
							std::cout << "Please enter a date (dd-mm-yyyy) : ";
							std::string currDate;
							std::cin >> currDate;
							std::cout << "Please enter a name of the show : ";
							std::string currName;
							std::cin >> currName;
							std::cout << "Please enter a row in the hall : ";
							int currRow;
							std::cin >> currRow;
							std::cout << "Please enter a seat in the row : ";
							int currColumn;
							std::cin >> currColumn;
							Buy_Ticket(currName, currDate, currRow, currColumn);
						}
						else {

							if (command == "List_Of_Reservations")
							{
								std::cout << "Please enter a date (dd-mm-yyyy) : ";
								std::string currDate;
								std::cin >> currDate;
								std::cout << "Please enter a name of the show : ";
								std::string currName;
								std::cin >> currName;

								List_Of_Reservations(currDate, currName);
							}
							else {
								if (command == "Information_For_Purchased_Tickets")
								{
									std::cout << "Sorry, ne bachi !" << std::endl;
								}
								else {

									if (command == "exit")
										break;
									else {
										if (command != "Add_New_Show" || command != "Free_Seats" || command != "Reservation" || command != "Reservation_Cancel" || command != "Buy_Ticket" || command != "List_Of_Reservations" || command != "Information_For_Purchased_Tickets" || command != "exit")
										{
											std::cout << "Possible commands : " << std::endl;
											std::cout << "Add_New_Show, Free_Seats, Reservation, Reservation_Cancel, Buy_Ticket, List_Of_Reservations, Information_For_Purchased_Tickets" << std::endl;
											std::cout << "Please enter a command!" << std::endl;
											std::cin >> command;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	} while (command != "exit");
}
