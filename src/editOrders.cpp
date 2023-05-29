#include "./../include/order.h"
#include <iostream>

Order& Order::editOrders()
{
	printOrders();

	while (true)
	{
		std::cout << "\nIf you wish to still insert a new order, enter the letter 'i'\n"
			"or remove an order, enter the letter 'r'\n"
			"or proceed to pay, enter the letter 'c'\n"
			"Enter your input: ";

		char input{};
		std::cin >> input;

		if (std::cin.peek() != 10) //check if stream is empty
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInput must be either 'i', 'r' or 'c' only. Please try again.\n";
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (input != 'i' && input != 'r' && input != 'c')
		{
			std::cout << "\nInput must be either 'i', 'r' or 'c' only. Please try again.\n";
			continue;
		}

		if (input == 'i') insertOrders();
		if (input == 'r') removeOrders();
		if (input == 'c')
		{
			if (orders.empty())
			{
				std::cout << "\nYou cannot have an empty order list. Please add some :)\n";
				continue;
			}
			else
				break;
		}
	}

	return *this;
}