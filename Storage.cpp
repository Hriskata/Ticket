#include "Storage.h"

Storage::Storage()
{
	storage_of_HALLS = {};
	storage_of_SHOWS = {};
}

void Storage::Add_To_Storage_Of_Halls(const Hall& temp)
{
	storage_of_HALLS.push_back(temp);
}

void Storage::Size_On_Storage_Of_Halls() const
{
	std::cout << storage_of_HALLS.size()<<std::endl;
}

int Storage::size_on_vector_of_halls() const
{
	return storage_of_HALLS.size();
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
	Show* show = new Show(temp.Get_date(), temp.Get_name_of_show(), temp_hall);
	storage_of_SHOWS.push_back(show);

}

void Storage::Free_Seats(std::string _name, std::string _date)
{
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()))
		{
			std::cout << "Free seats for show with name : " << _name << " are ";
			std::cout << storage_of_SHOWS[i]->Get_Free_Seats() << "." << std::endl;
		}
	}
}

void Storage::Reservation(std::string _name, std::string _date, int _row, int _column, std::string _pass)
{
	std::string pass;
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()))
		{
			storage_of_SHOWS[i]->Update_Seat(_row, _column, _pass, 2);
			std::cout << "Your ticket resetvation is successfully ! ";
		}
	}
}

void Storage::Reservation_Cancel(std::string _name, std::string _date, int _row, int _column, std::string _pass)
{
	std::string pass;
	std::string ClearPass = '\0';
	for (size_t i = 0; i < storage_of_SHOWS.size(); i++)
	{
		if ((_name == storage_of_SHOWS[i]->Get_name_of_show()) && (_date == storage_of_SHOWS[i]->Get_date()) && (storage_of_SHOWS[i]->Get_Seat_Type(_row, _column) == 2))
		{
			storage_of_SHOWS[i]->Update_Seat(_row, _column, ClearPass, 0);
			std::cout << "Ticket reservation was successfully canceled ! ";
		}
	}
}

void Storage::Buy_Ticket(std::string _name, std::string _date, int _row, int _column)
{
	std::string ClearPass = '\0';
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
				std::cout << "Already sold";
			}
		}
	}
}
