#include "Hall.h"
#include "Show.h"
#include "Storage.h"

#include <iostream>

int main()
{
	Storage storagee;
	Hall zala1("huy", 1, 1);
	storagee.Add_To_Storage_Of_Halls(zala1);
	Hall h2("potka", 2, 2);
	storagee.Add_To_Storage_Of_Halls(h2);
	storagee.Size_On_Storage_Of_Halls();

	zala1.PrintHall();
	Show show1("24-02-1999", "aladin", zala1);
	storagee.Add_New_Show(show1);

	return 0;
}
