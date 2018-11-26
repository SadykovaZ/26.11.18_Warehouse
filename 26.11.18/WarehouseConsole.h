#pragma once
#include"Warehouse.h"
#include"Appliances.h"
#include"BuildingMaterials.h"
#include"OfficeSupplies.h"
#include<iostream>
#include<Windows.h>
using namespace std;

class WarehouseConsole
{
public:
	Warehouse wareH;
	WarehouseConsole();
	void start();
private:
	void startMenu();
	void mainMenu();
	void addProductMenu();
	void removeProductMenu();
	void showInfo()const;
	
	void setWarhaouseNameMenu();
};

