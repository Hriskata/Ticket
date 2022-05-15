#include "Storage.h"
#include <iostream>

int main()
{
	Storage storagee;
	Hall zala1("zala1", 1, 1);
	storagee.Add_To_Storage_Of_Halls(zala1);
	Hall zala2("zala2", 2, 2);
	storagee.Add_To_Storage_Of_Halls(zala2);

	try
	{
		storagee.RunTicket();
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	//zala1.PrintHall();
	//Show show1("24-02-1999", "aladin", zala1);
	//storagee.Add_New_Show(show1);

	return 0;
}
