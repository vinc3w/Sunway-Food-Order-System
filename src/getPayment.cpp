#include "./../include/order.h"
#include <iostream>

Order& Order::getPayment()
{
	while (true)
	{
		std::cout << "\nPayment amount: ";
		double payment{};
		std::cin >> payment;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nPayment must be a number, dumb dumb :-)\n";
			continue;
		}

		if (std::cin.peek() != 10)
		{
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "\nPayment must ONLY be a number, silly :(\n";
			continue;
		}

		if (payment < 0)
		{
			std::cout << "\nPayment must not be a negative number...\n";
			continue;
		}

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
		}
		if (payment < totalPrice)
		{
			std::cout << "\nHEY, dont scam me. Give me the minimum amount of " << totalPrice << ". :(\n";
			continue;
		}

		std::cout << "Thank you very much for the payment\n";
		printReceipt(totalPrice, payment);
		break;
	}
	return *this;
}
