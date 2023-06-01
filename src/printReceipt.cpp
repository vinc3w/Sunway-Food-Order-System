#include "./../include/order.h"
#include "./../include/randomInt.h"
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <string>
#include <format>
#include <iostream>

std::string getTime()
{
	const auto now{
		std::chrono::current_zone()->
		to_local(std::chrono::system_clock::now()) 
	};
	std::string time{};
	time += std::format("{:%D}", now);
	time += "    ";
	time += std::format("{:%r}", now);
	return time;
}

Order& Order::printReceipt(double totalPrice, double payment)
{
	RandomInt rand{};
	std::cout << "\n"
				 "-----------------------------------------\n"
				 "|                                       |\n"
				 "|                RECEIPT                |\n"
				 "|                                       |\n"
				 "| * * * * * * * * * * * * * * * * * * * |\n"
				 "| Sunway        " << getTime() << " |\n"
				 "| * * * * * * * * * * * * * * * * * * * |\n"
				 "|                                       |\n";

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
		std::cout << "| "
				  << "x" << std::left << std::setw(3) << count
				  << " " << std::setw(22) << item.substr(0, 22) << " RM "
				  << std::setprecision(2) << std::right << std::fixed << std::setw(6) << price * count
				  << " |\n";
	}

	std::cout << "|                                       |\n"
				 "| * * * * * * * * * * * * * * * * * * * |\n"
				 "|                                       |\n"

				 "| Total:                     RM " <<
				 std::setprecision(2) << std::fixed << std::setw(7) << totalPrice <<
				 " |\n"

				 "| Cash:                      RM " <<
				 std::setprecision(2) << std::fixed << std::setw(7) << payment <<
				 " |\n"

				 "| Change:                    RM " <<
				 std::setprecision(2) << std::fixed << std::setw(7) << payment - totalPrice <<
				 " |\n"

				 "|                                       |\n"

				 "| Bank No.          " <<
				 rand.get(4) << " " << rand.get(4) << " " << rand.get(4) <<  " " << rand.get(4) <<
				 " |\n"
				 "| Pin:                           " << rand.get(6) << " |\n"

				 "|                                       |\n"
				 "|---------------------------------------|\n"
				 "|                                       |\n"
				 "|               THANK YOU               |\n"
				 "|                                       |\n"
				 "| || ||| | || | ||| || | | | || | || || |\n"
				 "| || ||| | || | ||| || | | | || | || || |\n"
				 "| || ||| | || | ||| || | | | || | || || |\n"
				 "|                                       |\n"
				 "-----------------------------------------\n";
	return *this;
}
