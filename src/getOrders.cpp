#include "./../include/order.h"
#include <iostream>

Order& Order::getOrders()
{
	std::cout << "\nHello, what do you want to order?\n";
	const auto mergedMenuItems{ getMergedMenuItems() };
	while (true)
	{
		std::cout << "Enter the number of the order: ";

		int input{};
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nOnly number accepted as input. Please try again.\n";
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input < 0 || input > mergedMenuItems.size())
		{
			std::cout << "\nInputs must be between 1 and " << mergedMenuItems.size() << ". Please try again.\n";
			continue;
		}

		if (input == 0)
		{
			if (orders.empty())
				std::cout << "\nDont waste my time. EITHER ORDER OR STAY AWAY!!!\n";
			else
				editOrders();
			break;
		}

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

		std::cout << "\nIf you do not wish to order anymore, enter '0'\n";
	}
	return *this;
}