#include "./../include/order.h"
#include <iomanip>
#include <iostream>

Order& Order::printCourses(OrderPair& items, std::string_view categoryName)
{
	std::cout << "\n"
				 "---------------------------------------------\n"
				 "|                                           |\n"
				 "|                 " << categoryName << "                |\n"
				 "|                                           |\n"
				 "|###########################################|\n"
				 "|                                           |\n";

	int index{ 1 };
	for (const auto& [item, price] : items)
	{
		std::cout << "| " << std::setw(2) << index << ". "
			<< std::left << std::setw(29) << item.substr(0, 29)
			<< "RM"
			<< std::right << std::setprecision(2) << std::fixed << std::setw(6) << price
			<< " |\n";
		++index;
	}

	std::cout << "|                                           |\n"
				 "---------------------------------------------\n";
	return *this;
}