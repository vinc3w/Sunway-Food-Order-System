#include "./../include/order.h"
#include <limits>
#include <string_view>
#include <algorithm>
#include <iostream>

int getInt(int min, int max, std::string_view message)
{
	int input{};
	while (true)
	{
		std::cout << message;
		std::cin >> input;

		// if user input failed to be extracted from input stream
		if (std::cin.fail())
		{
			// reset input stream state
			std::cin.clear();
			// wipe out input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nOnly number accepted as input. Please try again.\n";
			continue;
		}

		// if user entered letters after numbers
		if (std::cin.peek() != 10)
		{
			// wipe out input stream
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nInput must ONLY be a number, silly :(\n";
			continue;
		}

		if (input < min || input > max)
		{
			std::cout << "\nInputs must be between " << min << " and " << max << ". Please try again.\n";
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
		int categoryIndex{ getInt(orders.empty() ? 1 : 0, 3, "Enter the Category: ") };
		OrderPair* category{};

		// assign chosen category
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

		// if category is not chosen (user entered '0')
		if (category == nullptr)
		{
			printOrders();
			getPayment();
			break;
		}

		std::cout << "To choose category again, enter '0'\n";
		int input{ getInt(0, static_cast<int>(category->size()), "Enter the number of the order: ") };

		// go back to selecting category
		if (input == 0) continue;

		const auto& menuItem{ (*category)[input - 1] };
		auto it{
			std::find_if(
				orders.begin(),
				orders.end(),
				[&menuItem](const auto& item) { return item.first == menuItem.first; }
			)
		};
		int quantity{ getInt(0, std::numeric_limits<int>::max(), "Enter the quantity: ") };
		if (quantity == 0) continue;
		// if order is not already in order list
		if (it == orders.end())
			// add order to order list
			orders.push_back(std::pair(menuItem.first, quantity));
		else
			// change quantity of order
			orders[std::distance(orders.begin(), it)].second += quantity;

		std::cout << "\nAdded x" << quantity << " " << menuItem.first
				  << "\nIf you do not wish to order anymore, enter '0'\n";
	}
	return *this;
}
