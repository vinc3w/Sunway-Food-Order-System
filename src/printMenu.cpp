#include "./../include/order.h"
#include <iomanip>
#include <iostream>

void printItems(const OrderPair& items, int &index)
{
	for (const auto& [item, price] : items)
	{
		std::cout << "| " << std::setw(2) << index << ". "
			<< std::left << std::setw(29) << item.substr(0, 29)
			<< "RM"
			<< std::right << std::setprecision(2) << std::fixed << std::setw(6) << price
			<< " |\n";
		++index;
	}
}

Order& Order::printMenu()
{
	int index{ 1 };

	std::cout << "---------------------------------------------\n"
				 "|                                           |\n"
				 "|             SUNWAY FOOD MENU              |\n"
				 "|                                           |\n"
				 "|###########################################|\n"
				 "|                                           |\n"
				 "|                 APPETIZERS                |\n"
				 "|                                           |\n";

	printItems(appetizers, index);

	std::cout << "|                                           |\n"
				 "|                   MAINS                   |\n"
				 "|                                           |\n";

	printItems(mains, index);

	std::cout << "|                                           |\n"
				 "|                  DESERTS                  |\n"
				 "|                                           |\n";

	printItems(deserts, index);

	std::cout << "|                                           |\n"
				 "|###########################################|\n"
				 "|                                           |\n"
				 "|                SUNWAY FOODS               |\n"
				 "|                                           |\n"
				 "---------------------------------------------\n";

	return *this;
}
