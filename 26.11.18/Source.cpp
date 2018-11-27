#include"WarehouseConsole.h"
using namespace std;
void main()
{
	WarehouseConsole w;
	try {
		w.loadFromFile();

	}
	catch (exception&w)
	{
		cout << w.what();
		system("pause");
	}
	w.start();
	system("pause");
}
