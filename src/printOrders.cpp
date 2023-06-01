#include "./../include/order.h"
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <iostream>

Order& Order::printOrders()
{
	std::cout << "\n"
				 "-------------------------------------------------\n"
				 "|                  YOUR ORDERS                  |\n"
				 "|-----------------------------------------------|\n"
				 "|                                               |\n";

	int i{ 1 };
	double totalPrice{};
	for (const auto& [item, count] : orders)
	{
		auto it{
			std::find_if(
				mergedMenuItems.begin(),
				mergedMenuItems.end(),
				[item](const auto& menuItem) { return menuItem.first == item; }
			)
		};
		const double price{ mergedMenuItems[std::distance(mergedMenuItems.begin(), it)].second };
		totalPrice += price * count;
		std::cout << "| " << std::setw(2) << i << ". "
				  << "x" << std::left << std::setw(3) << count
				  << " " << std::setw(26) << item.substr(0, 26) << " RM "
				  << std::setprecision(2) << std::right << std::fixed << std::setw(6) << price * count
				  << " |\n";
		++i;
	}

	std::cout << "|                                               |\n"
				 "|-----------------------------------------------|\n"
				 "|                                               |\n"
				 "| Total:                              RM " <<
				 std::setprecision(2) << std::fixed << std::setw(6) << totalPrice <<
				 " |\n"
				 "|                                               |\n"
				 "-------------------------------------------------\n";

	return *this;
}
