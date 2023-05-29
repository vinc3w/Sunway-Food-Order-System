#include "./../include/order.h"
#include <iostream>

Order& Order::getOrders()
{
	printMenu();
	std::cout << "\nHello, what do you want to order?\n";

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
			{
				printOrders();
				getPayment();
			}
			break;
		}

		auto menuItem{ mergedMenuItems[input - 1] };
		auto it{
			std::find_if(
				orders.begin(),
				orders.end(),
				[&menuItem](const auto& item) { return item.first == menuItem.first; }
			)
		};
		if (it == orders.end())
			orders.push_back(std::pair(menuItem.first, 1));
		else
			++orders[std::distance(orders.begin(), it)].second;

		std::cout << "\nAdded " << menuItem.first <<
					 "\nIf you do not wish to order anymore, enter '0'\n";
	}
	return *this;
}
