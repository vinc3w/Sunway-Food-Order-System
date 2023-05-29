#include "./../include/order.h"
#include <iomanip>
#include <algorithm>
#include <iostream>

Order& Order::printOrders()
{
	const auto mergedMenuItems{ getMergedMenuItems() };
	std::cout << "\n"
				 "-------------------------------------------------\n"
				 "|                  YOUR ORDERS                  |\n"
				 "|-----------------------------------------------|\n"
				 "|                                               |\n";

	int i{ 1 };
	for (const auto& [item, count] : orders)
	{
		auto it{
			std::find_if(
				mergedMenuItems.begin(),
				mergedMenuItems.end(),
				[&mergedMenuItems, item](const auto& menuItem) { return menuItem.first == item; }
			)
		};
		double price{ mergedMenuItems[std::distance(mergedMenuItems.begin(), it)].second };
		std::cout << "| " << std::setw(2) << i << ". "
				  << "x" << std::left << std::setw(3) << count
				  << " " << std::setw(28) << item.substr(0, 28) << "RM"
				  << std::setprecision(2) << std::right << std::fixed << std::setw(6) << price * count
				  << " |\n";
		++i;
	}

	std::cout << "|                                               |\n"
				 "-------------------------------------------------\n";

	return *this;
}