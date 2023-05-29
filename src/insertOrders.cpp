#include "./../include/order.h"
#include <iostream>

void Order::insertOrders()
{
	const auto mergedMenuItems{ getMergedMenuItems() };
	while (true)
	{
		std::cout << "\nEnter the number of the order to add: ";

		int input{};
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Only number accepted as input. Please try again.\n";
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input < 0 || input > mergedMenuItems.size())
		{
			std::cout << "Input must be between 1 and " << mergedMenuItems.size() << ". Please try again.\n";
			continue;
		}

		if (input == 0)
			break;

		auto itemToFind{ mergedMenuItems[input - 1] };
		auto doesItemExist{
			std::find_if(
				orders.begin(),
				orders.end(),
				[&itemToFind](const auto& item) { return item.first == itemToFind.first; }
			)
		};
		if (doesItemExist == orders.end())
			orders.push_back(std::pair(itemToFind.first, 1));
		else
			++orders[std::distance(orders.begin(), doesItemExist)].second;
		printOrders();
		std::cout << itemToFind.first << " has been added.\n";
	}
}