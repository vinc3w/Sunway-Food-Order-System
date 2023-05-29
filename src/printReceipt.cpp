#include "./../include/order.h"
#include <iomanip>
#include <random>
#include <chrono>
#include <cmath>
#include <string>
#include <iostream>

int randomInt(int length)
{
	std::random_device rd{};
	std::seed_seq ss{
		static_cast<std::mt19937::result_type>(
			std::chrono::steady_clock::now().time_since_epoch().count()
		),
		rd(), rd(), rd(), rd(), rd(), rd(), rd(), rd()
	};
	std::mt19937 mt{ ss };
	std::uniform_int_distribution dist{
		static_cast<int>(std::pow(10, length - 1)),
		static_cast<int>(std::pow(10, length))
	};
	return dist(mt);
}

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
		double price{ mergedMenuItems[std::distance(mergedMenuItems.begin(), it)].second };
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
				 randomInt(4) << " " << randomInt(4) << " " << randomInt(4) <<  " " << randomInt(4) <<
				 " |\n"
				 "| Pin:                           " << randomInt(6) << " |\n"

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
