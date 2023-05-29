#include "./../include/order.h"
#include <iostream>

void Order::removeOrders()
{
	const auto mergedMenuItems{ getMergedMenuItems() };
	while (true)
	{
		std::cout << "\nEnter the number of the order to remove: ";

		int index{};
		std::cin >> index;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Only number accepted as input. Please try again.\n";
			continue;
		}

		if (index < 0 || index > orders.size())
		{
			std::cout << "Input must be between 1 and " << orders.size() << ". Please try again.\n";
			continue;
		}

		if (index == 0)
			break;

		auto itemToRemove{ orders[index - 1] };
		if (itemToRemove.second == 1)
			orders.erase(orders.begin() + index - 1);
		else
			--orders[index - 1].second;
		printOrders();
		std::cout << itemToRemove.first << " has been removed\n";
		
	}
}