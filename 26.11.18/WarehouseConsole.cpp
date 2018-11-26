#include "WarehouseConsole.h"
WarehouseConsole::WarehouseConsole()
	:wareH("")
{
	startMenu();
}

void WarehouseConsole::start()
{
	mainMenu();
}

void WarehouseConsole::startMenu()
{
	system("cls");
	cout << "Welcome!";
	Sleep(2000);
	this->setWarhaouseNameMenu();	
}

void WarehouseConsole::mainMenu()
{
	int choise = 0;
	while (choise != 6)
	{
		system("cls");
		cout << "Warehouse name: " << wareH.getWName();
		cout << "\nCount of products: " << wareH.getCountOfProduct();
		cout << "\n\n----------------------------\n\n";
		cout << "1. Add new product" << endl;
		cout << "2. Shipment of product"<<endl;
		cout << "3. Show warehouse info" << endl;
		cout << "4. Show the products with a critical expiration date" << endl;
		cout << "5. Show expired products" << endl;
		cout << "6. Exit" << endl;
			
		cin >> choise;
		switch (choise)
		{
		case 1:
			addProductMenu();
			break;
		case 2:
			removeProductMenu();
			break;
		case 3:
			showInfo();
			system("pause");
			break;
		case 4:
			wareH.productCriticExpDate();
			system("pause");
			break;
		case 5:
			wareH.overdueProduct();
			system("pause");
			break;
		default:
			cout << "Unknown command\nPress any key to continue\n";
			system("pause");
			system("cls");
			break;
		}
	}
	cout << "Thank you! Bye bye\n";
}

void WarehouseConsole::addProductMenu()
{
	size_t ch;
	while (1) {
		system("cls");
		cout << "Choose product to add: \n";
		cout << "1. House appliances\n2. Office supplies\n3. Building materials\n4. Main menu\n";
		cin >> ch;
		if (ch > 4) {
			cout << "uknown position\n";
			system("pause");
		}
		else
			break;
	}
	if (ch == 4)
		return;
	int price;
	string color;
	int day;
	int month;
	int year;
	
	string name;
	system("cls");
	cout << "Set product price\n";
	cin >> price;
	cout << "Set product color\n";
	cin >> color;
	cout << "Set product expiration day\n";
	cin >> day;
	cout << "Set product expiration month\n";
	cin >> month;
	cout << "Set product expiration year\n";
	cin >> year;
	Product*prod = nullptr;
	switch (ch)
	{
	case 1:
		
		cout << "Name of house appliance: \n";
		cin >> name;
		prod = new Appliances(price,color,day,month,year,name);
		break;
	case 2:
		cout << "Name of office supply: \n";
		cin >> name;
		prod = new OfficeSupplies(price, color, day, month, year, name);
		break;
	case 3:
		cout << "Name of building material: \n";
		cin >> name;
		prod = new BuildingMaterials(price, color, day, month, year, name);
		break;	
	}
	system("cls");
	wareH.addProduct(prod);
	cout << "Product added!\n";
	system("pause");
}

void WarehouseConsole::removeProductMenu()
{
}

void WarehouseConsole::showInfo() const
{
	system("cls");
	wareH.getInfo();
}

void WarehouseConsole::setWarhaouseNameMenu()
{
	system("cls");
	cout << "Set warehouse name\n";
	string name;
	cin >> name;
	wareH.setWName(name);
}
