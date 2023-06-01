#include "./../include/order.h"
#include <limits>
#include <algorithm>
#include <iostream>

int getInt(int min, int max, std::string message)
{
	int input{};
	while (true)
	{
		std::cout << message;
		std::cin >> input;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nOnly number accepted as input. Please try again.\n";
			continue;
		}

		if (std::cin.peek() != 10)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nPayment must ONLY be a number, silly :(\n";
			continue;
		}

		if (input < min || input > max)
		{
			std::cout << "\nInputs must be between 1 and " << max << ". Please try again.\n";
			continue;
		}

		break;
	}
	return input;
}

Order& Order::getOrders()
{
	printMenu();
	std::cout << "\nHello, what do you want to order?\n";

	while (true)
	{
		std::cout << "\nCategories"
					 "\n1. Appetizer"
					 "\n2. Main course"
					 "\n3. Deserts\n";
		int categoryIndex{ getInt(0, 3, "Enter the Category: ") };
		OrderPair* category{};

		switch (categoryIndex)
		{
		case 1:
			category = &appetizers;
			printCourses(*category, "APPETIZERS");
			break;
		case 2:
			category = &mains;
			printCourses(*category, "  MAINS   ");
			break;
		case 3:
			category = &deserts;
			printCourses(*category, " DESERTS  ");
			break;
		}

		if (category == nullptr)
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

		int input{ getInt(0, static_cast<int>(category->size()), "Enter the number of the order: ") };

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

		const auto& menuItem{ (*category)[input - 1] };
		auto it{
			std::find_if(
				orders.begin(),
				orders.end(),
				[&menuItem](const auto& item) { return item.first == menuItem.first; }
			)
		};
		int quantity{ getInt(0, std::numeric_limits<int>::max(), "Enter the quantity: ") };
		if (it == orders.end())
		{
			orders.push_back(std::pair(menuItem.first, quantity));
		}
		else
			orders[std::distance(orders.begin(), it)].second += quantity;

		std::cout << "\nAdded x" << quantity << " " << menuItem.first <<
					 "\nIf you do not wish to order anymore, enter '0'\n";
	}
	return *this;
}
