#include "./../include/order.h"
#include "./../include/randomInt.h"
#include <iomanip>
#include <chrono>
#include <algorithm>
#include <time.h>
#include <iostream>

void printTime()
{
	auto now{ std::chrono::system_clock::now() };
	auto now_timet = std::chrono::system_clock::to_time_t(now);
	struct tm timeInfo;
	::localtime_s(&timeInfo, &now_timet);
	std::cout << std::put_time(&timeInfo, "%m/%d/%y")
			  << "       "
			  << std::put_time(&timeInfo, "%H:%M:%S");
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
				 "| Sunway        ";
	printTime();
	std::cout << " |\n"
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
