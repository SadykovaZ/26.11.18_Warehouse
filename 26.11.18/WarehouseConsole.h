#pragma once
#include"Product.h"
#include"Warehouse.h"
#include"Appliances.h"
#include"BuildingMaterials.h"
#include"OfficeSupplies.h"
#include<iostream>
#include<Windows.h>
#include <conio.h>
#include<iomanip>

using namespace std;

class WarehouseConsole
{
public:
	Warehouse wareH;
	WarehouseConsole();
	void start();
	~WarehouseConsole();
	void saveToFile()const;
	void loadFromFile();
 private:
	void startMenu();
	void mainMenu();
	void addProductMenu();
	void removeProductMenu();
	void showInfo()const;
	
	void showShortInfo() const;
	void setWarhaouseNameMenu();
};

