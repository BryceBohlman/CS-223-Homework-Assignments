//Assign01_InventoryStruct.cpp
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct inventoryItemType
{
	string itemCode;
	string itemName;
	double itemPrice;
	int    itemQuantity;
};

inventoryItemType inventoryLookup(inventoryItemType inv[], int count, string code, int quantity);
void			  inventoryReport(inventoryItemType inv[], int count);
int main()
{
	inventoryItemType inventoryRec[20];																		//Variable declarations
	inventoryItemType inventoryMatch;																		//
																																
	char   dollarSign      = '$';																			//
	int    purchaseCount   = 0;																				//
	int    itemCount       = 0;																				//
	
	string purchaseNum;																						//
	string purchaseItem;																					//
	double purchaseAmnt;																					//	Stores value (# of specific item purchased * price of item) 
	int    purchaseQty;																						//

	int mainWhileLoopCount = 0;																				//
	int invalidFlagCount   = 0;																				//

	ifstream inventoryFile;																					//
	ifstream purchasesFile;																					//

	inventoryFile.open("Inventory.txt");

	if (!inventoryFile)																						//Failsafe for error in opening infile
	{
		cout << "\n\nInventory file not found. Terminating program.\n" << endl;	
		system("pause");
		return -1;
	}

	purchasesFile.open("Purchases.txt");

	if (!purchasesFile)																						//Failsafe for error in opening infile
	{
		cout << "\n\nPurchases file not found. Terminating program.\n" << endl;
		system("pause");
		return -1;
	}
	
	while (true)																							//Reads in overview of current store stock
	{
		inventoryFile >> inventoryRec[itemCount].itemCode     >> inventoryRec[itemCount].itemPrice
			          >> inventoryRec[itemCount].itemQuantity >> inventoryRec[itemCount].itemName;

		if (inventoryFile.eof())
			break;
		
		itemCount++;
	}

	inventoryFile.close();

	switch (itemCount)																						//Outputs number of different products in stock
	{
	case 0:
		cout << "\nNo records processed.";
		break;
	case 1:
		cout << "\n1 record processed.";
		break;
	default:
		cout << "\n" << itemCount << " records processed.";
	}

	cout << "\n\nPurchases:\n\n";

	while (true)
	{
		purchasesFile >> purchaseNum >> purchaseItem >> purchaseQty;										//Reads in account of purchases made

		if (purchasesFile.eof())
			break;

		mainWhileLoopCount++;

		inventoryMatch = inventoryLookup(inventoryRec, itemCount, purchaseItem, purchaseQty);				//Finds item in stock which corresponds to item purchased
		purchaseAmnt   = inventoryMatch.itemPrice * purchaseQty;											//Calculates price of each item order
		
		if (inventoryMatch.itemName == "!!!INVALID ENTRY!!!")
			invalidFlagCount++;

		cout << fixed << setprecision(2);
		cout << purchaseNum << "   "  << purchaseItem << "   " << setw(4) << purchaseQty					//Outputs account of items purchased
			 << "   @ " << dollarSign << setw(8) << inventoryMatch.itemPrice << "  "
			 << dollarSign << setw(8) << purchaseAmnt << "   " << inventoryMatch.itemName
			 << '\n';

		dollarSign = ' ';
	}

	purchasesFile.close();

	switch (mainWhileLoopCount)																				//Outputs number of items purchased
	{
	case 0:
		cout << "\nNo item purchased.";
		break;
	case 1:
		cout << "\n1 item purchased.";
		break;
	default:
		cout << "\n" << mainWhileLoopCount << " items purchased.";
	}

	switch (invalidFlagCount)																				//Outputs amount of invalid entries
	{
	case 0:
		cout << "   No invalid entries.\n";
		break;
	case 1:
		cout << "   1 invalid entry.\n";
		break;
	default:
		cout << "   " << invalidFlagCount << " invalid entries.\n";
	}

	inventoryReport(inventoryRec, itemCount);

	cout << endl;
	system("pause");
	return 0;	
}

inventoryItemType inventoryLookup(inventoryItemType inv[], int count, string code, int quantity)
{
	for (int i = 0; i <= count; i++)
	{
		if (inv[i].itemCode == code)
		{
			inv[i].itemQuantity -= quantity;																//Subract number of items purchased from in-store stock
			return inv[i];
		}
	}

	inventoryItemType invalidEntry;
	invalidEntry.itemCode     = "!!!INVALID ENTRY!!!";
	invalidEntry.itemName     = "!!!INVALID ENTRY!!!";
	invalidEntry.itemPrice    = 0.0;
	invalidEntry.itemQuantity = 0;

	return invalidEntry;
}

void inventoryReport(inventoryItemType inv[], int count)
{
	char dollarSign = '$';
	cout << "\nItems on hand:\n";
	
	for (int i = 0; i < count; i++)
	{
		cout << '\n'    << inv[i].itemCode   << ' ' << dollarSign											//Outputs account of remaining stock after purchases are made
			 << setw(8) << inv[i].itemPrice  << setw(8)
			 << inv[i].itemQuantity << "   " << inv[i].itemName;

		dollarSign = ' ';
	}
	cout << "\n\n";
}