#include "WarehouseConsole.h"
WarehouseConsole::WarehouseConsole()
	:wareH("")
{
	//startMenu();
}

void WarehouseConsole::start()
{
	mainMenu();
}

WarehouseConsole::~WarehouseConsole()
{
	saveToFile();
}

void WarehouseConsole::saveToFile() const
{
	ofstream file("warehouse.txt");
	file << wareH.getWName() << ";"
		<< to_string(wareH.getCountOfProduct()) << "\n";
	for (size_t i = 0; i < wareH.getCountOfProduct(); i++)
	{
		file << wareH[i].getStringFileInfo();
		if (i != wareH.getCountOfProduct() - 1) file << endl;
	}
	file.close();
}

void WarehouseConsole::loadFromFile()
{
	ifstream file("warehouse.txt");
	if (!file)
		throw exception("Cannot open file!");

	string s;
	getline(file, s);
	wareH.setWName(s.substr(0, s.find(';')));
	s = s.substr(s.find(';') + 1);
	if (s[s.size() - 1] == ';')	s.pop_back();
	
	while (!file.eof())
	{
		getline(file, s);
		string type = s.substr(0, s.find(';'));
		Product*prod = nullptr;
		if (type == "Appliances") {
			prod = new Appliances;
		}
		else if (type == "OfficeSupplies") {
			prod = new OfficeSupplies;
		}
		else if (type == "BuildingMaterials") {
			prod = new BuildingMaterials;
		}
		s = s.substr(s.find(';') + 1);
		prod->readStringInfo(s);
		wareH.addProduct(prod);
	}
	file.close();
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
		case 6:
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
	
	string color;
	string name;
	int price;
	date_ day;
	
	string purpose;
	string type;
	system("cls");
	cout << "Set product name\n";
	cin >> name;
	cout << "Set product price\n";
	cin >> price;
	cout << "Set product color\n";
	cin >> color;	
	cout << "Set product expiration day\n";
	cin >> day;
	
	Product*prod = nullptr;
	switch (ch)
	{
	case 1:		
		cout << "Purpose of house appliance: \n";
		cin >> purpose;
		prod = new Appliances(name,price,color,day,purpose);
		break;
	case 2:
		int count;
		cout << "Count of office supply: \n";
		cin >> count;
		prod = new OfficeSupplies(name, price, color, day, count);
		break;
	case 3:
		cout << "Type of building material: \n";
		cin >> type;
		prod = new BuildingMaterials(name, price, color, day, type);
		break;	
	}
	system("cls");
	wareH.addProduct(prod);
	cout << "Product added!\n";
	system("pause");
}

void WarehouseConsole::removeProductMenu()
{
	while (1) {
		system("cls");
		cout << "Choose Id of product for shipment" << endl;
		showShortInfo();
		int ch;
		cin >> ch;
		if (!wareH.removeProductById(ch)) {
			cout << "incorrect id!\n";
			system("pause");
			continue;
		}
		cout << "Product shipped!\n";
		system("pause");
		return;
	}
}

void WarehouseConsole::showInfo() const
{
	system("cls");
	wareH.getInfo();
}


void WarehouseConsole::showShortInfo() const
{
	for (int i = 0; i < wareH.getCountOfProduct(); i++)
	{
		cout << setw(3) << left << wareH[i].getId()<<" "
			<< setw(10) << left << string(typeid(wareH[i]).name()).substr(6)<<" "
			<< setw(10) << left << wareH[i].getName() << endl;
	}
}

void WarehouseConsole::setWarhaouseNameMenu()
{
	system("cls");
	cout << "Set warehouse name\n";
	string name;
	cin >> name;
	wareH.setWName(name);
}
